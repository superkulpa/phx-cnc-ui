#ifndef CXFILESLIST_H
#define CXFILESLIST_H

#include <QWidget>
#include <QFileSystemModel>
#include <QProcess>

#include "ui_CXFilesList.h"

class CXFilesList : public QWidget, public Ui::CXFilesList
{
	Q_OBJECT

public:
	CXFilesList(QWidget *parent = 0);
	~CXFilesList();

signals:
	void fileCreated(const QString& aMainFile, const QString& aMoveFile);

private slots:
	void onItemDoubleClick(const QModelIndex&);
	void onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);
	void onProcessError(QProcess::ProcessError aError);

private:
	QFileSystemModel* mModel;
};

#endif // CXFILESLIST_H
