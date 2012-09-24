#ifndef CXSYNTAXHIGHLIGHTER_H
#define CXSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

/*!
	Класс подсветки синтаксиса для файла пути реза.
*/
class CXSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! Конструктор.
	CXSyntaxHighlighter(QTextDocument* parent);

	//! Деструктор.
	~CXSyntaxHighlighter();

protected:
	//! Переопределенная функция обработки подсветки.
	virtual void highlightBlock(const QString& text);

private:
	/*! Подсветка блока текста
		\param aText - текст для подсветки.
		\param aPattern - регулярное выражение для поиска блока подсветки.
		\param aFormat - формат для выделения найденного блока.
		\param aCapNumber - индекс блока в регулярном выражении, который надо подсветить.
	*/
	void highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat, int aCapNumber = 0);

private:
	//! Стиль подсветки блока Mdddd, Tdddd, M"text".
	QTextCharFormat mMTextFormat;

	//! Стиль подсветки блока Gdddd.
	QTextCharFormat mGTextFormat;

	//! Стиль подсветки блока Ldddd, Hdddd, Fdddd, Ddddd.
	QTextCharFormat mLHFTextFormat;

	//! Стиль подсветки блока Xdddd, Ydddd, Zdddd, Idddd, Jdddd.
	QTextCharFormat mCoordTextFormat;

	//! Стиль подсветки цифр блоков Xdddd, Ydddd, Zdddd.
	QTextCharFormat mNumbersTextFormat;

	//! Стиль подсветки блока односточных комментариев // и многосточных (  ).
	QTextCharFormat mCommentTextFormat;
};

/*!
	Класс подсветки синтаксиса для ini-файла.
*/
class CXIniSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! Конструктор.
	CXIniSyntaxHighlighter(QTextDocument* parent);

	//! Деструктор.
	~CXIniSyntaxHighlighter();

protected:
	//! Переопределенная функция обработки подсветки.
	virtual void highlightBlock(const QString& text);

private:
	void highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat);

private:
	//! Стиль подсветки ini-секции [Section].
	QTextCharFormat mSectionFormat;

	//! Стиль подсветки названия параметра.
	QTextCharFormat mParameterFormat;

	//! Стиль подсветки комментария.
	QTextCharFormat mCommentFormat;
};

/*!
	Класс подсветки синтаксиса для xml-файла.
*/
class CXXmlSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! Конструктор.
	CXXmlSyntaxHighlighter(QTextDocument* parent);

	//! Деструктор.
	~CXXmlSyntaxHighlighter();

protected:
	//! Переопределенная функция обработки подсветки.
	virtual void highlightBlock(const QString& text);

private:
	//! Регулярное выражение для поиска начала xml-тега.
	QRegExp tagBodyStart;

	//! Регулярное выражение для поиска окончания xml-тега.
	QRegExp tagBodyEnd;

	//! Регулярное выражение для поиска имени xml-тега.
	QRegExp tagNameEnd;

	//! Регулярное выражение для поиска имени xml-атрибута.
	QRegExp attrName;

	//! Регулярное выражение для поиска начала значения xml-атрибута.
	QRegExp attrBodyStart;

	//! Регулярное выражение для поиска окончания значения xml-атрибута.
	QRegExp attrBodyEnd;

	//! Стиль подсвети блока внутри < >.
	QTextCharFormat tagBodyFormat;

	//! Стиль подсветки имени xml-тега.
	QTextCharFormat tagNameFormat;

	//! Стиль подсветки xml-атрибута.
	QTextCharFormat attrNameFormat;

	//! Стиль подсветки значения xml-атрибута.
	QTextCharFormat attrBodyFormat;
};

#endif // CXSYNTAXHIGHLIGHTER_H
