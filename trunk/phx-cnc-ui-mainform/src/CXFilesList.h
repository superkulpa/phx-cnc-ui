#ifndef CXFILESLIST_H
#define CXFILESLIST_H

#include <QWidget>
#include <QFileSystemModel>
#include <QProcess>

#include "ui_CXFilesList.h"

/*!
	����� ������ ������ ��� ��������� ����.
*/
class CXFilesList : public QWidget, public Ui::CXFilesList
{
	Q_OBJECT

public:
	//! �����������.
	CXFilesList(QWidget* parent = 0);

	//! ����������.
	~CXFilesList();

public slots:
	//! ���� �������� ������ �����.
	void onCreateNewFile();

	//! ��������� �������������� ������.
	void setButton(QPushButton* aButton);

	//! 
	void onTurn();

signals:
	/*!
		������ �� �������� ����� ����.
		\param aFileName - ��� ����� ��� ��������������.
	*/
	void fileOpened(const QString& aFileName);

	/*!
		������ �� �������� ���� ����.
		\param aMainFile - ���� � �������� ����� ����.
		\param aMoveFile - ���� � ������� ������� ��� ����.
	*/
	void fileCreated(const QString& aMainFile, const QString& aMoveFile);

private slots:
	//! ���� ������ ����� �� ������.
	void onItemActivate(const QModelIndex&);

	//! ���� ��������� ���������� ����� � ������.
	void onDownList();

	//! ���� ��������� ����������� ����� � ������.
	void onUpList();

	//! ���� �������� �����/�����.
	void onOpen();

	//! ���� ���������� ������������ �������� ������ ����� � ������.
	void onDirectoryLoaded();

	//! ���� �� ��������� �������� ��������.
	void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);

	/*! ���� ��������� �������� �������� �� ������.

		\return ������� �������.
	*/
	QModelIndex setCurrentItemToFirst();

	//! ���� ������� ���������� �����.
	void onCompileFile();

	//! ���� ��������/�������� �����.
	void onLoadCheckFile();

	//! ���� �� ��������� ������.
	void onTextChanged(bool aIsSaved);

	//! ���� ���������� �������� ���������� ����� ����.
	void onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

	//! ���� �� ������ �������� ���������� ����� ����.
	void onProcessError(QProcess::ProcessError aError);

	//! ��������� �������� ��������� ��������� � ����� ��������.
	QString getConfigAttribute(const QString& aAttributeName);

private:
	QString mRootPath;
	QString mFileName;
	QFileSystemModel* mModel;
	QModelIndex mRootIndex;
	QPushButton* mButton;
	bool mIsModifier;
	bool mIsCompileNeed;
};

#endif // CXFILESLIST_H
