#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>
#include <QMap>
#include <QSqlDriver>

int main(int argc, char *argv[])
{
	if (argc != 6)
	{
		return -1;
	}

	QString fileName;
	QString deviceName;
	QString resFileName = argv[5];

	for (int i = 0; i < argc; i++)
	{
		if (QString(argv[i]) == "-f" && i + 1 < argc)
		{
			fileName = argv[i + 1];
		}
		else if (QString(argv[i]) == "-d" && i + 1 < argc)
		{
			deviceName = argv[i + 1];
		}
	}

	if (resFileName.isEmpty() || !QFile::exists(fileName))
	{
		return -1;
	}

	QString path = QFileInfo(fileName).absolutePath();

	if (QFile::exists(resFileName)) QFile::remove(resFileName);

	QSqlDatabase dataBase = QSqlDatabase::addDatabase("QSQLITE");
	dataBase.setDatabaseName(resFileName);

	bool ok = dataBase.open();

	if (!ok)
	{
		return -1;
	}

	QString createTable = "\
							CREATE TABLE [tbl_fields_configs] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_fields_configs_id_seq\"''::text)::regclass)', 'description' TEXT, 'plasma_source' INTEGER NOT NULL, 'reserve_field_number' INTEGER NOT NULL, 'reserve_field_name' TEXT NOT NULL, 'reserve_field_min' REAL NOT NULL, 'reserve_field_max' REAL NOT NULL);\
							CREATE TABLE [tbl_gas_types] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_gas_types_id_seq\"''::text)::regclass)', 'gases' TEXT NOT NULL, 'mixed' INTEGER NOT NULL DEFAULT 'false', 'description' TEXT);\
							CREATE TABLE [tbl_cons_angle] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_cons_angle_id_seq\"''::text)::regclass)', 'name' TEXT NOT NULL);\
							CREATE TABLE [tbl_parts_groups] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_parts_groups_id_seq\"''::text)::regclass)', 'description' TEXT, 'part_1' INTEGER, 'part_2' INTEGER, 'part_3' INTEGER, 'part_4' INTEGER, 'part_5' INTEGER, 'part_6' INTEGER, 'part_7' INTEGER, 'part_8' INTEGER, 'part_9' INTEGER, 'part_10' INTEGER);\
							CREATE TABLE [tbl_plasma_metal_types] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_plasma_metal_types_id_seq\"''::text)::regclass)', 'name' TEXT NOT NULL, 'description' TEXT);\
							CREATE TABLE [tbl_plasma_params] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_plasma_params_id_seq\"''::text)::regclass)', 'cons_angle' INTEGER NOT NULL, 'plasma_source' INTEGER NOT NULL, 'metal_type' INTEGER NOT NULL, 'min_thickness' REAL NOT NULL, 'max_thickness' REAL NOT NULL, 'gases' INTEGER NOT NULL, 'amperage' INTEGER NOT NULL, 'out_description' TEXT, 'out_under_water' INTEGER NOT NULL DEFAULT 'false', 'out_voltage' INTEGER NOT NULL, 'out_feed' INTEGER NOT NULL, 'out_burning_z_distance' REAL NOT NULL, 'out_cutting_z_distance' REAL NOT NULL, 'out_kerf' REAL NOT NULL, 'out_ignition_distance' REAL NOT NULL, 'out_burning_feed' INTEGER NOT NULL, 'out_burning_time' REAL NOT NULL, 'out_parts_group' INTEGER NOT NULL, 'out_gases_mix1' REAL, 'out_gases_mix2' REAL, 'out_plasma_preflow_pressure' REAL NOT NULL, 'out_shield_preflow_pressure' REAL NOT NULL, 'out_plasma_cutflow_pressure' REAL NOT NULL, 'out_shield_cutflow_pressure' REAL NOT NULL, 'out_plasma_preflow_rate' REAL NOT NULL, 'out_shield_preflow_rate' REAL NOT NULL, 'out_plasma_cutflow_rate' REAL NOT NULL, 'out_shield_cutflow_rate' REAL NOT NULL, 'out_additional_field_1' REAL, 'out_additional_field_2' REAL, 'out_additional_field_3' REAL, 'out_additional_field_4' REAL, 'out_additional_field_5' REAL);\
							CREATE TABLE [tbl_plasma_sources] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_plasma_sources_id_seq\"''::text)::regclass)', 'name' TEXT NOT NULL, 'description' TEXT, 'manufacturer' INTEGER NOT NULL, 'amperage_min' INTEGER NOT NULL, 'amperage_max' INTEGER NOT NULL, 'plasma_preflow_pressure_min' REAL NOT NULL, 'plasma_preflow_pressure_max' REAL NOT NULL, 'shield_preflow_pressure_min' REAL NOT NULL, 'shield_preflow_pressure_max' REAL NOT NULL, 'plasma_cutflow_pressure_min' REAL NOT NULL, 'plasma_cutflow_pressure_max' REAL NOT NULL, 'shield_cutflow_pressure_min' REAL NOT NULL, 'shield_cutflow_pressure_max' REAL NOT NULL, 'plasma_preflow_rate_min' REAL NOT NULL, 'plasma_preflow_rate_max' REAL NOT NULL, 'shield_preflow_rate_min' REAL NOT NULL, 'shield_preflow_rate_max' REAL NOT NULL, 'plasma_cutflow_rate_min' REAL NOT NULL, 'plasma_cutflow_rate_max' REAL NOT NULL, 'shield_cutflow_rate_min' REAL NOT NULL, 'shield_cutflow_rate_max' REAL NOT NULL);\
							CREATE TABLE [tbl_torch_parts] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_torch_parts_id_seq\"''::text)::regclass)', 'type' INTEGER NOT NULL, 'number' TEXT NOT NULL, 'image' BLOB, 'manufacturer' INTEGER NOT NULL, 'description' TEXT);\
							CREATE TABLE [tbl_torch_parts_types] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_torch_parts_types_id_seq\"''::text)::regclass)', 'name' TEXT NOT NULL, 'position' INTEGER NOT NULL, 'manufacturer' INTEGER NOT NULL, 'description' TEXT);\
							CREATE TABLE [tbl_writer_params] ('id' INTEGER NOT NULL PRIMARY KEY DEFAULT 'nextval((''\"tbl_writer_params_id_seq\"''::text)::regclass)', 'name' TEXT NOT NULL, 'plasma_source' INTEGER NOT NULL, 'metal_type' INTEGER NOT NULL, 'gases' INTEGER NOT NULL, 'amperage' INTEGER NOT NULL, 'out_description' TEXT, 'out_voltage' INTEGER NOT NULL, 'out_feed' INTEGER NOT NULL, 'out_cutting_z_distance' REAL NOT NULL, 'out_parts_group' INTEGER NOT NULL, 'out_plasma_preflow_rate' REAL NOT NULL, 'out_shield_preflow_rate' REAL NOT NULL, 'out_plasma_cutflow_rate' REAL NOT NULL, 'out_shield_cutflow_rate' REAL NOT NULL, 'out_additional_field_1' REAL, 'out_additional_field_2' REAL, 'out_additional_field_3' REAL, 'out_additional_field_4' REAL, 'out_additional_field_5' REAL);";

	QStringList createTables = createTable.split(";", QString::SkipEmptyParts);

	QSqlQuery query(dataBase);

	foreach (QString queryString, createTables)
	{
		if (!query.exec(queryString))
		{
			auto s = query.lastError().text();
			return -1;
		}
	}

	QFile sourceFile(fileName);
	if (sourceFile.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&sourceFile);

		QMap <QString, int> metalTypes;
		QMap <QString, int> gasesTypes;
		QMap <QString, int> consAngles;
		QMap <QString, int> imagesMap;
		QMap <QString, int> imagesGroups;
		QMap <QString, int> imagesTypes;

		QString queryText("INSERT INTO tbl_plasma_params VALUES(NULL, :cons_angle, :plasma_source, :metal_type, :min_thickness, :max_thickness, :gases, :amperage, :out_description,\
						  :out_under_water, :out_voltage, :out_feed, :out_burning_z_distance, :out_cutting_z_distance, :out_kerf, :out_ignition_distance, :out_burning_feed,\
						  :out_burning_time, :out_parts_group, :out_gases_mix1, :out_gases_mix2, :out_plasma_preflow_pressure, :out_shield_preflow_pressure, :out_plasma_cutflow_pressure,\
						  :out_shield_cutflow_pressure, :out_plasma_preflow_rate, :out_shield_preflow_rate, :out_plasma_cutflow_rate, :out_shield_cutflow_rate, :out_additional_field_1,\
						  :out_additional_field_2, :out_additional_field_3, :out_additional_field_4, :out_additional_field_5);");

		stream.readLine();

		QStringList sourceData;
		QString temp;
		QString temp2;

		dataBase.driver()->beginTransaction();

		while (!stream.atEnd())
		{
			sourceData = stream.readLine().split(";");
			if (sourceData.count() >= 36)
			{
				query.prepare(queryText);

				temp = sourceData.at(35);
				if (!consAngles.contains(temp)) consAngles.insert(temp, consAngles.count() + 1);
				query.bindValue(":cons_angle", consAngles.value(temp));

				query.bindValue(":plasma_source", 1);

				temp = sourceData.at(2);
				if (!metalTypes.contains(temp)) metalTypes.insert(temp, metalTypes.count() + 1);
				query.bindValue(":metal_type", metalTypes.value(temp));

				temp = sourceData.at(3);
				query.bindValue(":min_thickness", temp.toDouble());
				query.bindValue(":max_thickness", temp.toDouble());

				temp = sourceData.at(5) + "/" + sourceData.at(6);
				if (!gasesTypes.contains(temp)) gasesTypes.insert(temp, gasesTypes.count() + 1);
				query.bindValue(":gases", gasesTypes.value(temp));

				query.bindValue(":amperage", sourceData.at(4).toDouble());
				query.bindValue(":out_description", "");
				query.bindValue(":out_under_water", false);
				query.bindValue(":out_voltage", sourceData.at(19).toDouble());
				query.bindValue(":out_feed", sourceData.at(21).toDouble());
				query.bindValue(":out_burning_z_distance", sourceData.at(23).toDouble() / 100.0 * sourceData.at(22).toDouble());
				query.bindValue(":out_cutting_z_distance", sourceData.at(20).toDouble());
				query.bindValue(":out_kerf", sourceData.at(25).toDouble());
				query.bindValue(":out_ignition_distance", sourceData.at(22).toDouble());
				query.bindValue(":out_burning_feed", sourceData.at(21).toDouble());
				query.bindValue(":out_burning_time", sourceData.at(24).toDouble());

				temp2 = "";
				for (int i = 26; i <= 32; i++)
				{
					temp = sourceData.at(i);

					if (temp.isEmpty()) continue;

					if (!imagesMap.contains(temp)) imagesMap.insert(temp, imagesMap.count() + 1);

					if (!temp2.isEmpty()) temp2.append(",");
					temp2.append(QString::number(imagesMap.value(temp)));
				}

				if (!imagesGroups.contains(temp2)) imagesGroups.insert(temp2, imagesGroups.count() + 1);
				query.bindValue(":out_parts_group", imagesGroups.value(temp2));

				query.bindValue(":out_gases_mix1", sourceData.at(13).toDouble());
				query.bindValue(":out_gases_mix2", sourceData.at(14).toDouble());
				query.bindValue(":out_plasma_preflow_pressure", 8.3);
				query.bindValue(":out_shield_preflow_pressure", 8.3);
				query.bindValue(":out_plasma_cutflow_pressure", 8.3);
				query.bindValue(":out_shield_cutflow_pressure", 8.3);
				query.bindValue(":out_plasma_preflow_rate", sourceData.at(9).toDouble());
				query.bindValue(":out_shield_preflow_rate", sourceData.at(10).toDouble());
				query.bindValue(":out_plasma_cutflow_rate", sourceData.at(11).toDouble());
				query.bindValue(":out_shield_cutflow_rate", sourceData.at(12).toDouble());
				query.bindValue(":out_additional_field_1", "");
				query.bindValue(":out_additional_field_2", "");
				query.bindValue(":out_additional_field_3", "");
				query.bindValue(":out_additional_field_4", "");
				query.bindValue(":out_additional_field_5", "");

				if (!query.exec())
				{
					QString error = query.lastError().text();
				}
			}
		}

		queryText = "INSERT INTO tbl_plasma_sources VALUES(1, :name, :description, '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '');";
		query.prepare(queryText);

		query.bindValue(":name", deviceName);
		query.bindValue(":description", deviceName);

		query.exec();


		queryText = "INSERT INTO tbl_plasma_metal_types VALUES(:id, :name, :description);";

		QMap <QString, int>::iterator mapIter;

		for (mapIter = metalTypes.begin(); mapIter != metalTypes.end(); mapIter++)
		{
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());
			query.bindValue(":name", mapIter.key());
			query.bindValue(":description", "");

			query.exec();
		}

		queryText = "INSERT INTO tbl_gas_types VALUES(:id, :gases, :mixed, :description);";

		for (mapIter = gasesTypes.begin(); mapIter != gasesTypes.end(); mapIter++)
		{
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());
			query.bindValue(":gases", mapIter.key());
			query.bindValue(":mixed", false);
			query.bindValue(":description", "");

			query.exec();
		}

		queryText = "INSERT INTO tbl_cons_angle VALUES(:id, :name);";

		for (mapIter = consAngles.begin(); mapIter != consAngles.end(); mapIter++)
		{
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());
			query.bindValue(":name", mapIter.key());

			query.exec();
		}

		queryText = "INSERT INTO tbl_torch_parts VALUES(:id, :type, :number, :image, :manufacturer, :description);";
		QFile tempFile;
		QDir imagesDir(path + "images/");
		QStringList files;
		int imageType = -1;

		for (mapIter = imagesMap.begin(); mapIter != imagesMap.end(); mapIter++)
		{
			imageType = -1;
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());

			temp = mapIter.key();
			query.bindValue(":number", temp);

			files = imagesDir.entryList(QStringList() << temp+"*.bmp");

			if (!files.isEmpty())
			{
				temp = files.first();

				if (temp.split(QRegExp("( |\\.)")).count() >= 2)
				{
					temp2 = temp.split(QRegExp("( |\\.)")).at(1);

					if (!imagesTypes.contains(temp2)) imagesTypes.insert(temp2, imagesTypes.count() + 1);
					imageType = imagesTypes.value(temp2);
				}

				tempFile.setFileName(path + "images/" + temp);

				if (tempFile.exists() && tempFile.open(QIODevice::ReadOnly))
				{
					query.bindValue(":image", tempFile.readAll());
					tempFile.close();
				}
				else query.bindValue(":image", "");
			}
			else query.bindValue(":image", "");

			if (imageType != -1) query.bindValue(":type", imageType);
			else query.bindValue(":type", "");

			query.bindValue(":manufacturer", "");
			query.bindValue(":description", "");

			query.exec();
		}

		queryText = "INSERT INTO tbl_torch_parts_types VALUES(:id, :name, :position, :manuf, :description);";

		for (mapIter = imagesTypes.begin(); mapIter != imagesTypes.end(); mapIter++)
		{
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());
			query.bindValue(":name", mapIter.key());
			query.bindValue(":position", "");
			query.bindValue(":manuf", "");
			query.bindValue(":description", "");

			query.exec();
		}

		queryText = "INSERT INTO tbl_parts_groups VALUES(:id, :description, :part_1, :part_2, :part_3, :part_4, :part_5, :part_6, :part_7, :part_8, :part_9, :part_10);";

		for (mapIter = imagesGroups.begin(); mapIter != imagesGroups.end(); mapIter++)
		{
			query.prepare(queryText);

			query.bindValue(":id", mapIter.value());
			query.bindValue(":description", "");

			sourceData = mapIter.key().split(",");

			for (int i = 1; i <= 10; i++)
			{
				if (i - 1 >= sourceData.count()) query.bindValue(QString(":part_%1").arg(i), "");
				else query.bindValue(QString(":part_%1").arg(i), sourceData.at(i - 1));
			}

			query.exec();
		}

		dataBase.driver()->commitTransaction();

		sourceFile.close();
	}

	return 0;
}
