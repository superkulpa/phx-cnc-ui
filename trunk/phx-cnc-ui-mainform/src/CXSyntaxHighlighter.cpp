#include "CXSyntaxHighlighter.h"

CXSyntaxHighlighter::CXSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{
	mMTextFormat.setFontWeight(QFont::Bold);
	mMTextFormat.setForeground(Qt::red);

	mGTextFormat.setFontWeight(QFont::Bold);
	mGTextFormat.setForeground(Qt::darkGreen);

	mCoordTextFormat.setFontWeight(QFont::Bold);
	mCoordTextFormat.setForeground(Qt::blue);
}

CXSyntaxHighlighter::~CXSyntaxHighlighter()
{

}

void CXSyntaxHighlighter::highlightBlock(const QString& text)
{
	highlight(text, "(M)(\\d+)", mMTextFormat);
	highlight(text, "(G)(\\d+)", mGTextFormat);
	highlight(text, "(X|Y|Z)(\\d+)", mCoordTextFormat);
}

void CXSyntaxHighlighter::highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat)
{
	QRegExp expression(aPattern);
	expression.setCaseSensitivity(Qt::CaseInsensitive);

	int index = aText.indexOf(expression);
	while (index >= 0)
	{
		int length = expression.matchedLength();
		setFormat(index, length, aFormat);
		index = aText.indexOf(expression, index + length);
	}
}
