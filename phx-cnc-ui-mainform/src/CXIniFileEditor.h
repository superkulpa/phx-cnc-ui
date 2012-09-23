#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QSyntaxHighlighter>

#include "ui_CXIniFileEditor.h"

/*!
	����� ���� ��������� ini-������, �� ������� ������, � ���������� ���������� � ����������� ���������.
*/
class CXIniFileEditor : public QWidget, public Ui::CXIniFileEditor
{
	Q_OBJECT

public:
	//! �����������.
	CXIniFileEditor(QWidget* parent = 0);

	//! ����������.
	~CXIniFileEditor();

public slots:
	/*!
		���� ������ ����� �� ������ �� ��������������.
	*/
	void onOpenFile(const QString& aFileName);

	//! ���� ���������� ��������� � ������ �����.
	void onSave();

private:
	QString mFileName;
	QSyntaxHighlighter* mHighlighter;
};

#endif // CXINIFILEEDITOR_H
