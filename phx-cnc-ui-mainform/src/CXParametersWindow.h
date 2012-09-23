#ifndef CXPARAMETERSWINDOW_H
#define CXPARAMETERSWINDOW_H

#include <QTabWidget>
#include <QProgressBar>
#include <QPushButton>

class CXFtp;

/*!
	����� ��� ����������� � �������������� ����������.
*/
class CXParametersWindow : public QTabWidget
{
	Q_OBJECT

public:
	CXParametersWindow(QWidget* parent, bool aIsSystem);
	~CXParametersWindow();

	//! ������� ��������� ������ ������, ������� ����� ��������� �����.
	void setButtons(const QList <QPushButton*>& aButtons);

public slots:
	//! ���� �������� ������ � ������ �� FTP.
	void loadParametersFromFtp();

	//! ���� �������� ���������� � �����.
	void loadParameters();

	//! ���� ���������� ��������� ����������.
	void saveParameters();

	//! ���� �������� �������� ����������.
	void makeTabs(bool aIsSystem);

	//! ���� ��������� ������ � �������� ��������.
	void setProgressText(const QString& aText);

	//! ����, ���������� �� ��������� ��������.
	void onAllFilesIsLoaded(bool aIsUpload);

private slots:
	//! ���� �� ������� ������.
	void buttonClicked();

private:
	//! ������� �������� ������ ��/� FTP-�������.
	void loadFiles(bool aIsUpload);

	//! ������� ������� ������.
	void clearData();

	//! ������� ������� ��������.
	void clearTables();

	//! ������� ���������� �������� ������.
	void updateButtonsText();

private:
	QProgressBar* mProgressBar;
	CXFtp* mFtp;
	bool mIsSystem;

	QList <QPushButton*> mButtons;
};

#endif // CXPARAMETERSWINDOW_H
