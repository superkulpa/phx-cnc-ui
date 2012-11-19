#ifndef CXCOMPILEEDIT_H
#define CXCOMPILEEDIT_H

#include "AXBaseWindow.h"

#include <QTreeWidget>

/*!
	Класс отображения текста лога компиляции.
*/
class CXCompileEdit : public AXBaseWindow
{
	Q_OBJECT

public:
	//! Конструктор.
	CXCompileEdit();

	//! Деструктор.
	~CXCompileEdit();

public slots:
	//! Слот обновления информации.
	void setText(const QString& aText);

signals:
	/*!
		Сигнал об ошибке компиляции в строке.
		\param aText - текст ошибки.
		\param aLineNumber - номер строки с ошибкой.
	*/
	void error(const QString& aText, int aLineNumber);

private:
	QTreeWidget* mTreeWidget;
};

#endif // CXCOMPILEEDIT_H
