#include "CXSyntaxHighlighter.h"

CXSyntaxHighlighter::CXSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{
	mMTextFormat.setFontWeight(QFont::Bold);
	mMTextFormat.setForeground(Qt::red);

	mGTextFormat.setFontWeight(QFont::Bold);
	mGTextFormat.setForeground(Qt::darkGreen);

	mLHFTextFormat.setFontWeight(QFont::Bold);
	mLHFTextFormat.setForeground(Qt::magenta);

	mCoordTextFormat.setFontWeight(QFont::Bold);
	mCoordTextFormat.setForeground(Qt::blue);

	mCommentTextFormat.setForeground(Qt::gray);
}

CXSyntaxHighlighter::~CXSyntaxHighlighter()
{

}


void CXSyntaxHighlighter::highlightBlock(const QString& text)
{
	setCurrentBlockState(previousBlockState());

	//многострочный комментарий
	if (currentBlockState() == 1)
	{
		if (text.indexOf(")") >= 0)
		{
			setFormat(0, text.indexOf(")") + 1, mCommentTextFormat);
			setCurrentBlockState(0);
		}
		else
		{
			setFormat(0, text.length(), mCommentTextFormat);

			return;
		}
	}

	highlight(text, "(M|T)(\\d+)", mMTextFormat);
	highlight(text, "M\"[^\"]*\"", mMTextFormat);
	highlight(text, "(G)(\\d+)", mGTextFormat);
	highlight(text, "(L|H|F|D)(\\d+)", mLHFTextFormat);
	highlight(text, "(X|Y|Z|I|J)(-?\\d+)", mCoordTextFormat);
	highlight(text, "//.*", mCommentTextFormat);
	highlight(text, "^%.*", mCommentTextFormat);

	int index = 0;
	if ((index = text.indexOf("(")) >= 0)
	{
		if (text.indexOf(")") >= 0)
		{
			setFormat(index, text.indexOf(")") - index + 1, mCommentTextFormat);
		}
		else
		{
			setCurrentBlockState(1);
			setFormat(index, text.length() - index + 1, mCommentTextFormat);
		}
	}
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

//***

CXIniSyntaxHighlighter::CXIniSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{
	mSectionFormat.setFontWeight(QFont::Bold);
	mSectionFormat.setForeground(Qt::darkMagenta);
	mParameterFormat.setFontWeight(QFont::Bold);
	mParameterFormat.setForeground(Qt::red);
}

CXIniSyntaxHighlighter::~CXIniSyntaxHighlighter()
{

}
void CXIniSyntaxHighlighter::highlightBlock(const QString& text)
{
	highlight(text, "^[^=]+", mParameterFormat);
	highlight(text, "^\\[[^\\]]+\\]$", mSectionFormat);
}

void CXIniSyntaxHighlighter::highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat)
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

//***

enum eHighlightFlags
{
	E_NoneHighlight = 0,	//нету никакой подсветки.
	E_TagBody,				//идет подсветка внутренности xml-элемента.
	E_AttributeBody1,		//идет подсветка значения атрибута с двойной кавычкой.
	E_AttributeBody2		//идет подсветка значения атрибута с одинарной кавычкой.
};

CXXmlSyntaxHighlighter::CXXmlSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{
	tagBodyFormat.setForeground(Qt::blue);
	tagNameFormat.setForeground(Qt::blue);
	attrNameFormat.setForeground(Qt::red);
	attrBodyFormat.setForeground(QColor("#8000ff"));
	attrBodyFormat.setFontWeight(QFont::Bold);

	tagBodyStart = QRegExp("(</|<\\?|<)");
	tagBodyEnd = QRegExp("(>|/>|\\?>)");
	tagNameEnd = QRegExp("(\\s|\\t|>|/>|\\?>)");
	attrName = QRegExp("[a-zA-Z]+");
	attrBodyStart = QRegExp("=(\\s|\\t)*");
	attrBodyEnd = QRegExp("(\\s|\\t|>)");
}

CXXmlSyntaxHighlighter::~CXXmlSyntaxHighlighter()
{

}

void CXXmlSyntaxHighlighter::highlightBlock(const QString& aText)
{
	int prevBlockState = previousBlockState();
	setCurrentBlockState(E_NoneHighlight);

    int startIndex = 0;
	int endIndex = 0;
	int tempIndex = 0;
	int length = 0;

	if (prevBlockState <= E_NoneHighlight) startIndex = tagBodyStart.indexIn(aText);

	//если идет подсветка атрибута 
	if (prevBlockState == E_AttributeBody1 || prevBlockState == E_AttributeBody2)
	{
		QChar c;

		if (prevBlockState == E_AttributeBody1) c = '"';
		else c = '\'';

		startIndex = aText.indexOf(c);
		if (startIndex >= 0)
		{
			setFormat(0, startIndex + 1, attrBodyFormat);

			startIndex++;
		}
		else
		{
			setFormat(0, aText.length(), attrBodyFormat);
			setCurrentBlockState(prevBlockState);
		}
	}

	while (startIndex >= 0)
	{
		//Поиск завершающего тега xml.
		endIndex = tagBodyEnd.indexIn(aText, startIndex);
		if (endIndex < 0)
		{
			setCurrentBlockState(E_TagBody);
			endIndex = aText.length();
		}
		else endIndex += tagBodyEnd.matchedLength();

		setFormat(startIndex, endIndex - startIndex, tagBodyFormat);

		//поиск имени тега.
		if (prevBlockState <= E_NoneHighlight)
		{
			startIndex += tagBodyStart.matchedLength();

			endIndex = tagNameEnd.indexIn(aText, startIndex);

			if (endIndex < 0) endIndex = aText.length();

			setFormat(startIndex, endIndex - startIndex, tagNameFormat);
			startIndex = endIndex;
		}

		//Поиск атрибутов
		tempIndex = 0;
		while (tempIndex >= 0)
		{
			//Поиск имени атрибута
			tempIndex = attrName.indexIn(aText, startIndex);
			if (tempIndex >= 0)
			{
				setFormat(tempIndex, attrName.matchedLength(), attrNameFormat);
				startIndex = tempIndex + attrName.matchedLength();

				tempIndex = attrBodyStart.indexIn(aText, startIndex);

				//Поиск значения атрибута
				if (tempIndex >= 0 && (attrName.indexIn(aText, startIndex) < 0 || tempIndex <= attrName.indexIn(aText, startIndex)))
				{
					startIndex = tempIndex + attrBodyStart.matchedLength();

					const QChar c = aText.at(startIndex);

					if (c == '"' || c == '\'')
					{
						tempIndex = aText.indexOf(c, startIndex + 1);

						if (tempIndex < 0)
						{
							tempIndex = aText.length();

							if (c == '"') setCurrentBlockState(E_AttributeBody1);
							else setCurrentBlockState(E_AttributeBody2);
						}

						length = 1;
					}
					else
					{
						tempIndex = attrBodyEnd.indexIn(aText, startIndex);
						
						if (tempIndex < 0) tempIndex = aText.length();

						length = attrBodyEnd.matchedLength();
					}

					setFormat(startIndex, tempIndex - startIndex + 1, attrBodyFormat);

					tempIndex += length;
				}
				else tempIndex = startIndex;

				startIndex = tempIndex;
			}
		}

		startIndex = aText.indexOf(tagBodyStart, endIndex);
	}
}
