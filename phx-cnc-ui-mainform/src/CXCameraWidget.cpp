#include "CXCameraWidget.h"

#include <QMessageBox>
#include <QVideoRendererControl>
#include <QVideoWindowControl>
#include <QCameraViewfinderSettingsControl>
#include <QAbstractVideoSurface>

CXCameraWidget::CXCameraWidget() :
    AXBaseWindow()
{
  setupUi(this);

  mCamera = NULL;
  mCameraView->setAspectRatioMode(Qt::KeepAspectRatio);

  updateDevices();

  connect(mRefreshButton, SIGNAL(clicked()), this, SLOT(updateDevices()));
  connect(mCameraDevices, SIGNAL(currentIndexChanged(int)), this, SLOT(setCurrentCamera(int)));

  registerManager();
}

CXCameraWidget::~CXCameraWidget()
{

}

void CXCameraWidget::updateDevices()
{
  mCameraDevices->blockSignals(true);
  mCameraDevices->clear();

  foreach(const QByteArray& deviceName, QCamera::availableDevices())
  {
    QString description = QCamera::deviceDescription(deviceName);

    mCameraDevices->addItem(description, deviceName);
  }

  mCameraDevices->blockSignals(false);
  mCameraDevices->setCurrentIndex(-1);
}

void CXCameraWidget::setCurrentCamera(int aIndex)
{
  if (mCamera != NULL)
  {

	  auto s = mCamera->service();

	  auto enc = s->requestControl<QVideoRendererControl*>();
	  if (enc != NULL)
	  {
		  auto surf = enc->surface();
		  if (surf != NULL)
			  auto list = surf->nativeResolution();
		  s->releaseControl(enc);
	  }

	  auto VideoWindowControl = s->requestControl<QVideoWindowControl*>();
	  if (VideoWindowControl != NULL)
	  {
		  auto size = VideoWindowControl->nativeSize();
		  s->releaseControl(VideoWindowControl);
	  }

	  auto CameraViewfinderSettingsControl = s->requestControl<QCameraViewfinderSettingsControl*>();
	  if (CameraViewfinderSettingsControl != NULL)
	  {
		  auto size = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);
		  auto size1 = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::PixelAspectRatio);
		  s->releaseControl(CameraViewfinderSettingsControl);
	  }

	  delete mCamera;
  }

  QByteArray deviceName = mCameraDevices->itemData(aIndex).toByteArray();

  if (deviceName.length() == 0) return;

  mCamera = new QCamera(deviceName);

  connect(mCamera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));
  connect(mCamera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(onStateChange(QCamera::State)));

  auto s = mCamera->service();

  auto enc = s->requestControl<QVideoRendererControl*>();
  if (enc != NULL)
  {
	  auto surf = enc->surface();
	  if (surf != NULL)
		  auto list = surf->nativeResolution();
	  s->releaseControl(enc);
  }

  auto VideoWindowControl = s->requestControl<QVideoWindowControl*>();
  if (VideoWindowControl != NULL)
  {
	  auto size = VideoWindowControl->nativeSize();
	  s->releaseControl(VideoWindowControl);
  }

  auto CameraViewfinderSettingsControl = s->requestControl<QCameraViewfinderSettingsControl*>();
  if (CameraViewfinderSettingsControl != NULL)
  {
	  auto size = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);
	  auto size1 = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::PixelAspectRatio);
	  s->releaseControl(CameraViewfinderSettingsControl);
  }

  mCamera->setCaptureMode(QCamera::CaptureViewfinder);
  mCamera->setViewfinder(mCameraView);
  mCamera->setCaptureMode(QCamera::CaptureViewfinder);

  enc = s->requestControl<QVideoRendererControl*>();
  if (enc != NULL)
  {
	  auto surf = enc->surface();
	  if (surf != NULL)
		  auto list = surf->nativeResolution();
	  s->releaseControl(enc);
  }

  VideoWindowControl = s->requestControl<QVideoWindowControl*>();
  if (VideoWindowControl != NULL)
  {
	  auto size = VideoWindowControl->nativeSize();
	  s->releaseControl(VideoWindowControl);
  }

  CameraViewfinderSettingsControl = s->requestControl<QCameraViewfinderSettingsControl*>();
  if (CameraViewfinderSettingsControl != NULL)
  {
	  auto size = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);
	  auto size1 = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::PixelAspectRatio);
	  s->releaseControl(CameraViewfinderSettingsControl);
  }

  mCamera->start();
}

void CXCameraWidget::displayCameraError()
{
    QMessageBox::warning(NULL, tr("Ошибка камеры"), mCamera->errorString());
}

void CXCameraWidget::onStateChange(QCamera::State state)
{
	auto s = mCamera->service();

	auto enc = s->requestControl<QVideoRendererControl*>();
	if (enc != NULL)
	{
		auto surf = enc->surface();
		if (surf != NULL)
			auto list = surf->nativeResolution();
		s->releaseControl(enc);
	}

	auto VideoWindowControl = s->requestControl<QVideoWindowControl*>();
	if (VideoWindowControl != NULL)
	{
		auto size = VideoWindowControl->nativeSize();
		s->releaseControl(VideoWindowControl);
	}

	auto CameraViewfinderSettingsControl = s->requestControl<QCameraViewfinderSettingsControl*>();
	if (CameraViewfinderSettingsControl != NULL)
	{
		auto size = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::Resolution);
		auto size1 = CameraViewfinderSettingsControl->viewfinderParameter(QCameraViewfinderSettingsControl::PixelAspectRatio);
		s->releaseControl(CameraViewfinderSettingsControl);
	}
}
