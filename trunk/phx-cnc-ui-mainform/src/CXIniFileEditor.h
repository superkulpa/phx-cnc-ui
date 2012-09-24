#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QSyntaxHighlighter>
#include <QProgressBar>

#include "ui_CXIniFileEditor.h"

class CXFtp;

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
	
	//! ������� �������� ������ ��/� FTP-�������.
	void loadFiles(bool aIsUpload);

	//! ���� ��������� ������ � �������� ��������.
	void setProgressText(const QString& aText);

	//! ����, ���������� �� ��������� ��������.
	void onAllFilesIsLoaded(bool aIsUpload);

private:
	QString mFileName;
	QSyntaxHighlighter* mHighlighter;

	QProgressBar* mProgressBar;
	CXFtp* mFtp;
};

#endif // CXINIFILEEDITOR_H
