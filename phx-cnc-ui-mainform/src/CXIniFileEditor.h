#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QFileSystemModel>
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

private slots:
	/*!
		���� ������ ����� �� ������ �� ��������������.
	*/
	void onItemActivate(const QModelIndex&);

	//! ���� ���������� ��������� � ������ �����.
	void onSave();

private:
	QString mFileName;
	QFileSystemModel* mModel;
	QSyntaxHighlighter* mHighlighter;
};

#endif // CXINIFILEEDITOR_H
