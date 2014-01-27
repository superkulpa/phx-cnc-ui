#include <QtCore/QCoreApplication>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTextCodec>
#include <QSqlQuery>

#include "CXBaseClient.h"
#include "CXParamData.h"

bool contains(const QString& aKey, KeyValueMap& aKeys, const KeyValueList& aAvailableKeys, const QString& aType)
{
	if (!aKeys.contains(aKey)) return false;

	QString keyValue = aKeys.value(aKey);

	QString value;
	foreach (Pair curValue, aAvailableKeys)
	{
		if (curValue.first == keyValue)
		{
			value = curValue.second;
			break;
		}
	}

	if (value.isEmpty()) return false;

	QString res = aKeys.value(aKey);
	aKeys.insert(aKey, value);

	CXParamData::setValues(aType + "/Keys", PairsList() << QPair<QString,QString>(aKey, res));

	return true;
}

int check(const KeyValueList& aAvailableKeys, const QString& aCurKey, KeyValueMap& aKeys, const QString& aType)
{
	if (aAvailableKeys.isEmpty())
	{
		CXParamData::close();
		return -1;
	}

	QStringList list;
	foreach (Pair curValue, aAvailableKeys)
	{
		list.append(curValue.first);
	}

	CXParamData::setKeysArray(aCurKey, list);

	if (!contains(aCurKey, aKeys, aAvailableKeys, aType))
	{
		CXParamData::close();
		return 0;
	}

	return 1;
}

int main(int argc, char *argv[])
{
//	QCoreApplication a(argc, argv);

	QString fileName;
	QString type;

	for (int i = 0; i < argc; i++)
	{
		if (QString(argv[i]) == "-f" && i + 1 < argc)
		{
			fileName = argv[i + 1];
		}

		if (QString(argv[i]) == "-t" && i + 1 < argc)
		{
			type = argv[i + 1];
		}
	}

	QFile logFile("log.txt");
	logFile.open(QIODevice::WriteOnly);

	QTextStream out(&logFile);
	out.setCodec(QTextCodec::codecForName("UTF-8"));

	if (type.isEmpty() || !QFile::exists(fileName))
	{
		out << "missing parameters:\n";
		if (type.isEmpty()) out << "type (-t)\n";
		if (!QFile::exists(fileName)) out << "file (-f)\n";

		return -1;
	}

	CXParamData::open(fileName);

	KeyValueMap keys = CXParamData::getValues(type + "/Keys");
	CXParamData::deleteKeys(QStringList() << type);
/**/
	QStringList allKeys;
	allKeys << "Manufactor/Keys" << "Source/Keys" << "MetallType/Keys" << "Thickness/Keys" << "Power/Keys" << "GasTypes/Keys" << type + "/Common";
	CXParamData::deleteKeys(allKeys);
/**/
	CXBaseClient client;
	KeyValueMap dataBase = CXParamData::getValues("Database");

	QString resString = client.connectToDataBase(dataBase.value("hosts"), dataBase.value("name"), dataBase.value("port").toInt(), dataBase.value("user"), dataBase.value("password"));

	if (!resString.isEmpty())
	{
		out << "connection error:\n";
		out << resString;
		out << "\n";

		return -1;
	}
/**/
	QString curKey = "Manufactor";
	KeyValueList availableKeys = client.execute("tbl_manufacturers", "id, name", "", "name");

	int res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

	curKey = "Source";
	availableKeys = client.execute("tbl_plasma_sources", "id, name", QString("manufacturer=%1").arg(keys.value("Manufactor")), "name");

	res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

	curKey = "MetallType";
	availableKeys = client.execute("tbl_plasma_metal_types as a, tbl_plasma_params as b", "DISTINCT metal_type, a.name", "metal_type=a.id", "a.name");

	res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

	curKey = "Thickness";
	QString w = QString("plasma_source=%1 AND metal_type=%2").arg(keys.value("Source")).arg(keys.value("MetallType"));
	availableKeys = client.execute("tbl_plasma_params", "DISTINCT min_thickness, min_thickness", w, "min_thickness");

	res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

	curKey = "Power";
	w += QString(" AND max_thickness=%1").arg(keys.value("Thickness"));
	availableKeys = client.execute("tbl_plasma_params", "DISTINCT amperage, amperage", w, "amperage");

	res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

	curKey = "GasTypes";
	w += QString(" AND amperage=%1").arg(keys.value("Power"));
	availableKeys = client.execute("tbl_gas_types as a, tbl_plasma_params as b", "DISTINCT b.gases, a.gases", w + " AND b.gases=a.id", "a.gases");

	res = check(availableKeys, curKey, keys, type);
	if (res <= 0)
	{
		if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
		else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

		return res;
	}

/* Загрузка значений полей */
	w += QString(" AND gases=%1").arg(keys.value("GasTypes"));

	KeyValueMap columnValuesMap;

	columnValuesMap.insert("min_thickness", "MinThickness");
	columnValuesMap.insert("max_thickness", "MaxThickness");

	columnValuesMap.insert("amperage", "Power");
	columnValuesMap.insert("out_description", "Description");
	columnValuesMap.insert("out_under_water", "UnderWater");
	columnValuesMap.insert("out_voltage", "SVRVoltage");
	columnValuesMap.insert("out_feed", "CuttingFeed");
	columnValuesMap.insert("out_burning_z_distance", "BurningZDistance");
	columnValuesMap.insert("out_cutting_z_distance", "CuttingZDistance");
	columnValuesMap.insert("out_kerf", "Kerf");
	columnValuesMap.insert("out_ignition_distance", "IgnitionDistance");
	columnValuesMap.insert("out_burning_feed", "BurningFeed");
	columnValuesMap.insert("out_burning_time", "BurningTime");
	columnValuesMap.insert("out_parts_group", "PartsNumber");
	columnValuesMap.insert("out_gases_mix1", "Mixes1");
	columnValuesMap.insert("out_gases_mix2", "Mixes2");
	columnValuesMap.insert("out_plasma_preflow_pressure", "Gas1PreflowPressure");
	columnValuesMap.insert("out_shield_preflow_pressure", "Gas2PreflowPressure");
	columnValuesMap.insert("out_plasma_cutflow_pressure", "Gas1CutflowPressure");
	columnValuesMap.insert("out_shield_cutflow_pressure", "Gas2CutflowPressure");
	columnValuesMap.insert("out_plasma_preflow_rate", "Gas1PreflowRate");
	columnValuesMap.insert("out_shield_preflow_rate", "Gas2PreflowRate");
	columnValuesMap.insert("out_plasma_cutflow_rate", "Gas1CutflowRate");
	columnValuesMap.insert("out_shield_cutflow_rate", "Gas2CutflowRate");

	KeyValueMap values = client.getValues("tbl_plasma_params", QStringList(columnValuesMap.keys()).join(","), w);
	if (!values.isEmpty())
	{
		PairsList resValues;
		QMap<QString, QString>::iterator iter;
		QString value;

		for (iter = columnValuesMap.begin(); iter != columnValuesMap.end(); iter++)
		{
			value = values.value(iter.key());

			if (value == "false") value = "0";
			if (value == "true") value = "1";

			resValues.append(QPair<QString,QString>(iter.value(), value));
		}

		CXParamData::setValues(type + "/Common", resValues);
	}
/**/
/*
	for (int i = 2; i <= 76; i++)
	{
		//client.getImageData("tbl_torch_parts_types as a, tbl_torch_parts as b", "a.name, a.description, b.image", QString("b.id=%1").arg(i), QString("d:/%1.bmp").arg(i));

		QFile file(QString("d:/!images!/%1.bmp").arg(i));
		if (!file.open(QIODevice::ReadOnly)) continue;
		QByteArray byteArray = file.readAll();

		QString queryString = QString("UPDATE tbl_torch_parts SET image=? WHERE id=?;");

		QSqlQuery query;
		query.prepare(queryString);
		query.addBindValue(byteArray);
		query.addBindValue(i);
		bool b = query.exec();
		b = b;
	}
*/
/* Загрузка картинок */
	bool isBreak = false;
	int imageIndex = 1;
	KeyValueMap imageParts = client.getValues("tbl_parts_groups", "part_1,part_2,part_3,part_4,part_5,part_6,part_7,part_8,part_9,part_10", QString("id=%1").arg(values.value("out_parts_group")));
	QString curPart;
	QFileInfo fileInfo(fileName);

	QDir imagesDir(fileInfo.absoluteDir().path() + "/images");
	if (!imagesDir.exists()) imagesDir.mkpath(imagesDir.path());

	while (!isBreak)
	{
		curPart = QString("part_%1").arg(imageIndex);
		values = CXParamData::getValues(QString("%1/Image%2").arg(type).arg(imageIndex));

		if (values.isEmpty() || !imageParts.contains(curPart)) isBreak = true;
		else
		{
			values = client.getImageData("tbl_torch_parts_types as a, tbl_torch_parts as b", "a.name, a.description, b.image", "b.id=" + imageParts.value(curPart), imagesDir.path() + "/" + values.value("Image"));

			PairsList imageValues;
			QMap<QString, QString>::iterator iter;
			for (iter = values.begin(); iter != values.end(); iter++)
			{
				imageValues << QPair<QString, QString>(iter.key(), iter.value());
			}

			CXParamData::setValues(QString("%1/Image%2").arg(type).arg(imageIndex), imageValues);
		}

		imageIndex++;
	}
/**/
	CXParamData::close();
	return 0;
}
