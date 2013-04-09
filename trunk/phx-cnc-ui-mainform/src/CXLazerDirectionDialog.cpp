#include "CXLazerDirectionDialog.h"

#include <QClipboard>

#include "CXUdpManager.h"

CXLazerDirectionDialog::CXLazerDirectionDialog(QWidget* parent) : QDialog(parent)
{
	setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

	mUdpManager = NULL;

	QRegExp regExp("(\\+|-)?\\d*\\.?\\d*");
	mXEdit->setValidator(new QRegExpValidator(regExp, mXEdit));
	mYEdit->setValidator(new QRegExpValidator(regExp, mYEdit));
	mFrameEdit->setValidator(new QRegExpValidator(regExp, mFrameEdit));

	connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(mAbsoluteButton, SIGNAL(clicked()), this, SLOT(onAbsolute()));
	connect(mRelativeButton, SIGNAL(clicked()), this, SLOT(onRelative()));

	connect(mButton0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton5, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton6, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton7, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton8, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButton9, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButtonPlus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButtonMinus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButtonBackspace, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButtonDel, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(mButtonEnter, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

	connect(mStepMoveButton, SIGNAL(clicked()), this, SLOT(onStepMove()));
	connect(mStepSetButton, SIGNAL(clicked()), this, SLOT(onStepSet()));
	connect(mBurnMoveButton, SIGNAL(clicked()), this, SLOT(onBurnMove()));
	connect(mBurnSetButton, SIGNAL(clicked()), this, SLOT(onBurnSet()));
}

CXLazerDirectionDialog::~CXLazerDirectionDialog()
{

}

QPointF CXLazerDirectionDialog::getPosition()
{
  return QPointF(mXEdit->text().toDouble() * 100, mYEdit->text().toDouble() * 100);
}

void CXLazerDirectionDialog::onAbsolute()
{
	if (mUdpManager != NULL && !mXEdit->text().isEmpty() && !mYEdit->text().isEmpty())
	{
		QString res("0=%1,1=%2");
		res = res.arg(mXEdit->text().toDouble() * 100).arg(mYEdit->text().toDouble() * 100);

		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_ABSOLUTE_MOVING, res.toStdString());
	}

	done(1);
}

void CXLazerDirectionDialog::onRelative()
{
	if (mUdpManager != NULL && !mXEdit->text().isEmpty() && !mYEdit->text().isEmpty())
	{
		QString res("0=%1,1=%2");
		res = res.arg(mXEdit->text().toDouble() * 100).arg(mYEdit->text().toDouble() * 100);

		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_COMPARATIVE_MOVING, res.toStdString());
	}

	done(2);
}

void CXLazerDirectionDialog::onButtonClicked()
{
	QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
	QLineEdit* lineEdit = qobject_cast<QLineEdit*>(focusWidget());

	if (clickedButton != NULL && lineEdit != NULL)
	{
		QMap <QKeySequence, QString> keyValues;
		keyValues.insert(Qt::Key_0, "0");
		keyValues.insert(Qt::Key_1, "1");
		keyValues.insert(Qt::Key_2, "2");
		keyValues.insert(Qt::Key_3, "3");
		keyValues.insert(Qt::Key_4, "4");
		keyValues.insert(Qt::Key_5, "5");
		keyValues.insert(Qt::Key_6, "6");
		keyValues.insert(Qt::Key_7, "7");
		keyValues.insert(Qt::Key_8, "8");
		keyValues.insert(Qt::Key_9, "9");
		keyValues.insert(Qt::Key_Plus, "+");
		keyValues.insert(Qt::Key_Minus, "-");

		if (keyValues.contains(clickedButton->shortcut()))
		{
			QString text;
			text = keyValues.value(clickedButton->shortcut());

			if (text == "+" || text == "-")
			{
				QString s = lineEdit->text().replace(QRegExp("(\\+|-)"), "");
				lineEdit->setText(text + s);
			}
			else
			{
				QClipboard* clipboard = QApplication::clipboard();
				clipboard->setText(text);
				lineEdit->paste();
			}

			return;
		}

		switch (clickedButton->shortcut())
		{
			case Qt::Key_Backspace:
			{
				lineEdit->backspace();

				break;
			}
			case Qt::Key_Delete:
			{
				lineEdit->del();

				break;
			}
			case Qt::Key_Enter:
			{

				break;
			}
		}
	}
}

void CXLazerDirectionDialog::onStepMove()
{
	if (mUdpManager != NULL && !mFrameEdit->text().isEmpty())
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_GOTO_STEP, mFrameEdit->text().toStdString());
}

void CXLazerDirectionDialog::onStepSet()
{
	if (mUdpManager != NULL && !mFrameEdit->text().isEmpty())
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FROM_STEP, mFrameEdit->text().toStdString());
}

void CXLazerDirectionDialog::onBurnMove()
{
	if (mUdpManager != NULL && !mFrameEdit->text().isEmpty())
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FROM_BURN, mFrameEdit->text().toStdString());
}

void CXLazerDirectionDialog::onBurnSet()
{
	if (mUdpManager != NULL && !mFrameEdit->text().isEmpty())
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_GOTO_BURN, mFrameEdit->text().toStdString());
}
