#ifndef CXINIFILELIST_H
#define CXINIFILELIST_H

#include <QFileSystemModel>

#include "AXBaseWindow.h"
#include "ui_CXIniFileList.h"

class CXIniFileList : public QWidget, public Ui::CXIniFileList
{
	Q_OBJECT

public:
	CXIniFileList(QWidget* parent = 0);
	~CXIniFileList();

signals:
	//! ������ �� �������� �����.
	void fileOpened(const QString& aFileName);

	//! ������ �� ���������� ��������� � �����.
	void fileSaved();

private slots:
	/*!
		���� ������ ����� �� ������ �� ��������������.
	*/
	void onItemActivate(const QModelIndex& aIndex);

private:
	QFileSystemModel* mModel;
};

#endif // CXINIFILELIST_H
