#ifndef CXCOMPILEEDIT_H
#define CXCOMPILEEDIT_H

#include "AXBaseWindow.h"

#include <QTextEdit>

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
	//! Слот обновления информации в 
	void setText(const QString& aText);

private:
	QTextEdit* mTextEdit;
};

#endif // CXCOMPILEEDIT_H
