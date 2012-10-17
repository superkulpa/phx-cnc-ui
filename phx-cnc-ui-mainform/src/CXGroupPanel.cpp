#include "CXGroupPanel.h"

//#include <QApplication>
//#include <QDesktopWidget>
#include <QProcess>

#include "flowlayout.h"

CXGroupPanel::CXGroupPanel() : AXBaseWindow()
{
	setObjectName("CXGroupPanel");
/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->setMargin(8);
	centralLayout->setSpacing(8);
/**/

	QPushButton* button = NULL;
//	int buttonSize = QApplication::desktop()->availableGeometry().width() / 20;

	for (int i = 1; i < 11; ++i)
	{
        button = new QPushButton(QString("F%1\n").arg(i), this);
		button->setFocusPolicy(Qt::NoFocus);
//		button->setFont(QFont("", buttonSize / 7));
//		button->setFixedSize(buttonSize + 20, buttonSize);

		centralLayout->addWidget(button);

        mButtonsList.append(button);
	}
}

CXGroupPanel::~CXGroupPanel()
{

}

void CXGroupPanel::setButtonsText(const QStringList& aTexts)
{
    for (int i = 0; i < mButtonsList.count(); ++i)
    {
        if (i < aTexts.count()) mButtonsList.at(i)->setText(QString("F%1\n%2").arg(i + 1).arg(aTexts.at(i)));
    }
}

QPushButton* CXGroupPanel::getButton(quint8 aButtonNumber)
{
    return mButtonsList.at(aButtonNumber);
}

void CXGroupPanel::setButtonText(int aButtonNumber, const QString& aText)
{
    if (mButtonsList.at(aButtonNumber) != NULL)
    {
        mButtonsList.at(aButtonNumber)->setText(QString("F%1\n%2").arg(aButtonNumber).arg(aText));
    }
}

void CXGroupPanel::directoryCommand()
{
    QProcess::execute("bash ./fm.sh");
}

void CXGroupPanel::macroCommand()
{
    QProcess::execute("bash ./macro.sh");
}
