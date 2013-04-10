#ifndef CXDEVICEVIEW_H
#define CXDEVICEVIEW_H

#include "AXBaseWindow.h"
#include "ui_CXDeviceView.h"

#include "SXChannelData.h"
#include "CXDeviceEdit.h"
#include "CXChannelEdit.h"

/*!
	Класс для предоставления данных об устройстве и каналах.
*/
class CXDeviceView : public AXBaseWindow, public Ui::CXDeviceView
{
	Q_OBJECT

public:
	//! Конструктор.
	CXDeviceView(const QString& aDeviceName, QWidget* parent = 0);

	//! Деструктор.
	~CXDeviceView();

	//! Функция загрузки данных для устройства.
	void load();

	/*!
		Статическая функция загрузки устройств.
		\param aGroupNumber - номер группы для окон.
		\param aChannelEditButton - кнопка редактирования канала.
		\param aDeviceEditButton - кнопка редактирования устройства.
	*/
	static void loadDevices(int aGroupNumber, QPushButton* aChannelEditButton, QPushButton* aDeviceEditButton);

protected:
	//! Переопределенная функция фильтрации событий.
	virtual bool eventFilter(QObject* watched, QEvent* e);

	//! Переопределенная функция таймера.
	virtual void timerEvent(QTimerEvent* e);

	//! Переопределенная функция обработки нажатий клавиш клавиатуры.
	virtual void keyPressEvent(QKeyEvent* e);

private slots:
	//! Слот на измение текущего активного виджета.
	void onFocusChange(QWidget* old, QWidget* now);

	/*!
		Слот установки описания для канала.
		\param aIndex - номер канала.
		\param aDescription - описание.
	*/
	void setDescription(int aIndex, const QString& aDescription);

	//! Слот редактирования данных устройства.
	void editDevice();

	void timerEditChannel();

	//! Слот на редактирование данных канала.
	void editChannel();

	//! Слот получения команды от ядра.
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

protected:
	//! Последнее вью в фокусе.
	static CXDeviceView* mLastView;

	//! Экземпляр редактора устройства.
	static CXDeviceEdit* mDeviceEdit;

	//! Экземпляр редактора канала.
	static CXChannelEdit* mChannelEdit;

	//! Задержка на нажатие.
	static int mDelay;

private:
	QString mDeviceName;
	QString mDeviceData;
	int mChannelCount;
	QVector <SXChannelData> mChannelList;
	int mClickTimer;
	int mCurrentRow;
};

#endif // CXDEVICEVIEW_H
