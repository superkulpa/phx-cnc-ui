#include "CXDeviceEdit.h"

#include <QMessageBox>

#include "CXTouchButton.h"

CXDeviceEdit::CXDeviceEdit(QWidget* parent) : QDialog(parent)
{
	setWindowTitle(trUtf8("Редактор устройства"));
	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setMargin(7);
	layout->setSpacing(7);

	mCentralLayout = new QGridLayout;
	mCentralLayout->setMargin(0);
	mCentralLayout->setSpacing(7);

	layout->addLayout(mCentralLayout);

	CXTouchButton* acceptButton = new CXTouchButton(trUtf8("Применить"), this);
	acceptButton->setDefault(true);
	layout->addWidget(acceptButton);

	mValidator = new QRegExpValidator(QRegExp("[^=,]*"), this);

	connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
}

CXDeviceEdit::~CXDeviceEdit()
{

}

void CXDeviceEdit::setData(const QString& aData)
{
	QStringList dataList = aData.split(",");

	while (mEditList.count() > dataList.count())
	{
		const SXDeviceEditors& deviceEditors = mEditList.at(mEditList.count() - 1);

		delete deviceEditors.mLineEdit;
		delete deviceEditors.mLabel;

		mEditList.remove(mEditList.count() - 1);
	}

	while (mEditList.count() < dataList.count())
	{
		SXDeviceEditors deviceEditors;

		deviceEditors.mLabel = new QLabel(this);
		deviceEditors.mLineEdit = new QLineEdit(this);
		deviceEditors.mLineEdit->setValidator(mValidator);

		mCentralLayout->addWidget(deviceEditors.mLabel, mEditList.count(), 0);
		mCentralLayout->addWidget(deviceEditors.mLineEdit, mEditList.count(), 1);

		mEditList.append(deviceEditors);
	}

	for (int i = 0; i < dataList.count(); i++)
	{
		QString curData = dataList.at(i);
		const SXDeviceEditors& deviceEditors = mEditList.at(i);
		deviceEditors.mLabel->setText(curData.left(curData.indexOf("=")));
		deviceEditors.mLineEdit->setText(curData.mid(curData.indexOf("=") + 1));
	}
}

QString CXDeviceEdit::getData()
{
	return mDeviceData;
}

void CXDeviceEdit::accept()
{
	mDeviceData = "";

	for (int i = 0; i < mEditList.count(); i++)
	{
		const SXDeviceEditors& curData = mEditList.at(i);

		if (curData.mLineEdit->text().isEmpty())
		{
			QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Введите данные поля %1.").arg(curData.mLabel->text()));

			curData.mLineEdit->setFocus();

			return;
		}

		if (!mDeviceData.isEmpty()) mDeviceData.append(",");

		mDeviceData.append(curData.mLabel->text());
		mDeviceData.append("=");
		mDeviceData.append(curData.mLineEdit->text());
	}

	QDialog::accept();
}
