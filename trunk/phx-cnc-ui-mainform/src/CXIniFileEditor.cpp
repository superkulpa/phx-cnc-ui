#include "CXIniFileEditor.h"

#include <QTextStream>
//#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

#include "CXSyntaxHighlighter.h"
#include "CXFtp.h"
#include "CXSettingsXML.h"

CXIniFileEditor::CXIniFileEditor() : AXBaseWindow()
{
	setupUi(this);

	mIsUpload = false;
	mProgressBar = NULL;

	mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());

	registerManager();
}

CXIniFileEditor::~CXIniFileEditor()
{

}

void CXIniFileEditor::onOpenFile(const QString& aFileName)
{
	mFileName = aFileName;

	QFile file(mFileName);
	file.open(QIODevice::ReadOnly);

	QTextStream in(&file);
	in.setCodec("UTF-8");

	mIniFileEdit->setPlainText(in.readAll());

	file.close();

	if (mIniFileEdit->toPlainText().at(0) == '<' && mHighlighter->metaObject()->className() != QString("CXXmlSyntaxHighlighter"))
	{
		delete mHighlighter;
		mHighlighter = new CXXmlSyntaxHighlighter(mIniFileEdit->document());
	}
	else if (mHighlighter->metaObject()->className() != QString("CXXmlSyntaxHighlighter"))
	{
		delete mHighlighter;
		mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());
	}
}

void CXIniFileEditor::onSave()
{
	if (!mFileName.isEmpty() && QFile::exists(mFileName))
	{
//		if (QMessageBox::question(this, trUtf8(""), trUtf8("Вы действительно хотите перезаписать файл?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

		QFile file(mFileName);
		file.open(QIODevice::WriteOnly);

		QTextStream out(&file);
		out.setCodec("UTF-8");

		out << mIniFileEdit->toPlainText();

		file.close();

		loadFiles(true);

//		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
	}
}

void CXIniFileEditor::loadFiles(bool aIsUpload)
{
	mIsUpload = aIsUpload;

	mProgressBar = new QProgressBar;
	mProgressBar->setWindowFlags(Qt::FramelessWindowHint);
	mProgressBar->setAlignment(Qt::AlignCenter);
	mProgressBar->setWindowModality(Qt::ApplicationModal);

	QSize size = QApplication::desktop()->availableGeometry().size();
	mProgressBar->resize(size.width() * 0.7, size.height() * 0.05);

	QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

	mFtp = new CXFtp(this);
	mFtp->setConnectData(host, 21, "ftp", "ftp");
	mFtp->setLoadFilesData(QApplication::applicationDirPath() + "/jini", "pub/updates/jini");

	connect(mFtp, SIGNAL(progressMaximumChanged(int)), mProgressBar, SLOT(setMaximum(int)));
	connect(mFtp, SIGNAL(progressValueChanged(int)), mProgressBar, SLOT(setValue(int)));
	connect(mFtp, SIGNAL(progressTextChanged(const QString&)), this, SLOT(setProgressText(const QString&)));
	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));
	connect(mFtp, SIGNAL(errorReceived()), this, SLOT(closeFtp()));

	if (aIsUpload) mFtp->onFtpUpload(QStringList() << "*.ini" << "*.xml");
	else mFtp->onFtpDownload(QStringList() << "ini" << "xml");

	mProgressBar->show();
}

void CXIniFileEditor::setProgressText(const QString& aText)
{
	if (mIsUpload) mProgressBar->setFormat(trUtf8("Сохранение ") + aText + " (%p%)");
	else mProgressBar->setFormat(trUtf8("Загружается ") + aText + " (%p%)");
}

void CXIniFileEditor::closeFtp()
{
	if (mProgressBar == NULL) return;

	mProgressBar->close();
	delete mProgressBar;
	mProgressBar = NULL;

	disconnect(mFtp, 0, 0, 0);

	mFtp->deleteLater();
	mFtp = NULL;
}

void CXIniFileEditor::onAllFilesIsLoaded(bool aIsUpload)
{
	Q_UNUSED(aIsUpload);

	closeFtp();
}
