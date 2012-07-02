#ifndef CXSYNTAXHIGHLIGHTER_H
#define CXSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CXSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	CXSyntaxHighlighter(QTextDocument* parent);
	~CXSyntaxHighlighter();

protected:
	virtual void highlightBlock(const QString& text);

private:
	void highlight(const QString& aText, const QString& aPattern, const QTextCharFormat& aFormat);

private:
	QTextCharFormat mMTextFormat;
	QTextCharFormat mGTextFormat;
	QTextCharFormat mCoordTextFormat;
};

#endif // CXSYNTAXHIGHLIGHTER_H
