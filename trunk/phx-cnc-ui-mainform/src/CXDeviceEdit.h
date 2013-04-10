#ifndef CXDEVICEEDIT_H
#define CXDEVICEEDIT_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRegExpValidator>

/*!
	Структура с данными редакторов устройства.
*/
struct SXDeviceEditors
{
	//! Конструктор.
	SXDeviceEditors()
	{
		mLabel = NULL;
		mLineEdit = NULL;
	}

	//! Метка с именем поля устройства.
	QLabel* mLabel;

	//! Редактируемое поле устройства.
	QLineEdit* mLineEdit;
};

/*!
	Класс для редактирования данных устройства.
*/
class CXDeviceEdit : public QDialog
{
	Q_OBJECT

public:
	//! Конструктор.
	CXDeviceEdit(QWidget* parent = 0);

	//! Деструктор.
	~CXDeviceEdit();

	/*!
		Функция установки объекта устройства для редактирования.
		\param aData - экземпляр объект устройства.
	*/
	void setData(const QString& aData);

	/*
		Функция получения редактируемого объекта устройства.
		\return Экземпляр объект устройства с новыми данными.
	*/
	QString getData();

public slots:
	//! Переопределенный слот применения изменений.
	virtual void accept();

private:
	QGridLayout* mCentralLayout;
	QRegExpValidator* mValidator;
	QVector <SXDeviceEditors> mEditList;
	QString mDeviceData;
};

#endif // CXDEVICEEDIT_H
