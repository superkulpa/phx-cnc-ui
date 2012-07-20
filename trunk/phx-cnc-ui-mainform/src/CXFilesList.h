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
	void onDirectoryLoaded(const QString& path);

	//! ���� �� ��������� �������� ����������� ��������.
	void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);

	//! ���� ���������� �������� ���������� ����� ����.
	void onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

	//! ���� �� ������ �������� ���������� ����� ����.
	void onProcessError(QProcess::ProcessError aError);

private:
	QFileSystemModel* mModel;
	QModelIndex mRootIndex;
};

#endif // CXFILESLIST_H
