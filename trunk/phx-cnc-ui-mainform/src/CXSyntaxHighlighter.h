#ifndef CXSYNTAXHIGHLIGHTER_H
#define CXSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

/*!
	����� ��������� ���������� ��� ����� ���� ����.
*/
class CXSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! �����������.
	CXSyntaxHighlighter(QTextDocument* parent);

	//! ����������.
	~CXSyntaxHighlighter();

protected:
	//! ���������������� ������� ��������� ���������.
	virtual void highlightBlock(const QString& text);

private:
	/*! ��������� ����� ������
		\param aText - ����� ��� ���������.
		\param aPattern - ���������� ��������� ��� ������ ����� ���������.
		\param aFormat - ������ ��� ��������� ���������� �����.
		\param aCapNumber - ������ ����� � ���������� ���������, ������� ���� ����������.
	*/
	void highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat, int aCapNumber = 0);

private:
	//! ����� ��������� ����� Mdddd, Tdddd, M"text".
	QTextCharFormat mMTextFormat;

	//! ����� ��������� ����� Gdddd.
	QTextCharFormat mGTextFormat;

	//! ����� ��������� ����� Ldddd, Hdddd, Fdddd, Ddddd.
	QTextCharFormat mLHFTextFormat;

	//! ����� ��������� ����� Xdddd, Ydddd, Zdddd, Idddd, Jdddd.
	QTextCharFormat mCoordTextFormat;

	//! ����� ��������� ���� ������ Xdddd, Ydddd, Zdddd.
	QTextCharFormat mNumbersTextFormat;

	//! ����� ��������� ����� ����������� ������������ // � ������������ (  ).
	QTextCharFormat mCommentTextFormat;
};

/*!
	����� ��������� ���������� ��� ini-�����.
*/
class CXIniSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! �����������.
	CXIniSyntaxHighlighter(QTextDocument* parent);

	//! ����������.
	~CXIniSyntaxHighlighter();

protected:
	//! ���������������� ������� ��������� ���������.
	virtual void highlightBlock(const QString& text);

private:
	void highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat);

private:
	//! ����� ��������� ini-������ [Section].
	QTextCharFormat mSectionFormat;

	//! ����� ��������� �������� ���������.
	QTextCharFormat mParameterFormat;

	//! ����� ��������� �����������.
	QTextCharFormat mCommentFormat;
};

/*!
	����� ��������� ���������� ��� xml-�����.
*/
class CXXmlSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	//! �����������.
	CXXmlSyntaxHighlighter(QTextDocument* parent);

	//! ����������.
	~CXXmlSyntaxHighlighter();

protected:
	//! ���������������� ������� ��������� ���������.
	virtual void highlightBlock(const QString& text);

private:
	//! ���������� ��������� ��� ������ ������ xml-����.
	QRegExp tagBodyStart;

	//! ���������� ��������� ��� ������ ��������� xml-����.
	QRegExp tagBodyEnd;

	//! ���������� ��������� ��� ������ ����� xml-����.
	QRegExp tagNameEnd;

	//! ���������� ��������� ��� ������ ����� xml-��������.
	QRegExp attrName;

	//! ���������� ��������� ��� ������ ������ �������� xml-��������.
	QRegExp attrBodyStart;

	//! ���������� ��������� ��� ������ ��������� �������� xml-��������.
	QRegExp attrBodyEnd;

	//! ����� �������� ����� ������ < >.
	QTextCharFormat tagBodyFormat;

	//! ����� ��������� ����� xml-����.
	QTextCharFormat tagNameFormat;

	//! ����� ��������� xml-��������.
	QTextCharFormat attrNameFormat;

	//! ����� ��������� �������� xml-��������.
	QTextCharFormat attrBodyFormat;
};

#endif // CXSYNTAXHIGHLIGHTER_H
