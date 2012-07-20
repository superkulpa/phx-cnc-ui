#ifndef CXEDITPATHFILE_H
#define CXEDITPATHFILE_H

#include <QWidget>
#include "ui_CXEditPathFile.h"

/*!
	����� ���� ��������� ������ � ������� ��� ���������� ���� ����, ���������� ���������� � ����������� ���������.
*/
class CXEditPathFile : public QWidget, public Ui::CXEditPathFile
{
	Q_OBJECT

public:
	//! �����������.
	CXEditPathFile(QWidget* parent = 0);

	//! ����������.
	~CXEditPathFile();

public slots:
	/*!
		���� ���������� �������������� �����.
		\param aFileName - ���� � ������ ����� ��� ��������������.
	*/
	void openFile(const QString& aFileName);

	//! ���� ���������� ��������� � ������ �����.
	void onSave();

private:
	QString mFileName;
};

#endif // CXEDITPATHFILE_H
