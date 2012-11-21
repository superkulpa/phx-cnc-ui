#include "CXLazerDirectionDialog.h"

#include <QClipboard>

CXLazerDirectionDialog::CXLazerDirectionDialog(QWidget* parent) : QDialog(parent)
{
	setupUi(this);

	mXEdit->setValidator(new QRegExpValidator(QRegExp("(\\+|-)?\\d*\\.?\\d*")));
	mYEdit->setValidator(new QRegExpValidator(QRegExp("(\\+|-)?\\d*\\.?\\d*")));
	mFrameEdit->setValidator(new QRegExpValidator(QRegExp("(\\+|-)?\\d*\\.?\\d*")));

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
}

CXLazerDirectionDialog::~CXLazerDirectionDialog()
{

}

QPointF CXLazerDirectionDialog::getPosition()
{
	return QPointF(mXEdit->text().toDouble(), mYEdit->text().toDouble());
}

void CXLazerDirectionDialog::onAbsolute()
{
	done(1);
}

void CXLazerDirectionDialog::onRelative()
{
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
