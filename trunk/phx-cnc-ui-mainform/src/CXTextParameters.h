#ifndef CXTEXTPARAMETERS_H
#define CXTEXTPARAMETERS_H

#include "AXBaseWindow.h"

#include <QTextEdit>

/*!
	Класс отображения текста в группе по управлению лазером.
*/
class CXTextParameters : public AXBaseWindow
{
	Q_OBJECT

public:
	//! Конструктор.
	CXTextParameters();

	//! Деструктор.
	~CXTextParameters();

public slots:
	//! Слот сброса предупреждений и аварий.
	void onResetAlarms();

signals:
	/*!
		Сигнал на ошибку.
		\param aError - текстовая строка с ошибкой.
	*/
	void errorReceived(const QString& aError);

private slots:
	//! Слот получения команды от ядра.
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
	QTextEdit* mTextEdit;
};

#endif // CXTEXTPARAMETERS_H
