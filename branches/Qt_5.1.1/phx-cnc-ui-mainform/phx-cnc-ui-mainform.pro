TEMPLATE = app
INCLUDEPATH += ./src ./GeneratedFiles
QT      += xml xmlpatterns network widgets multimedia multimediawidgets
UI_DIR	+= ./GeneratedFiles

CONFIG += debug_and_release

_install.depends = $(SOURCES)
_install.commands = cp ./phx-cnc-ui-mainform  ../install
QMAKE_EXTRA_TARGETS += _install

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS += -pg

QMAKE_LFLAGS += -pg

# Input
HEADERS	+=	src/AXBaseWindow.h \
			src/CXWindowsManager.h \
			src/CXPathView.h \
			src/CXPathWindow.h \
			src/flowlayout.h \
			src/CXFilesList.h \
			src/CXSyntaxHighlighter.h \
			src/CXEditPathFile.h \
			src/CXIniFileEditor.h \
			src/CXGroupPanel.h \
			src/CXTitleWindow.h \
			src/CXIniFileList.h \
			src/CXParametersWindow.h \
			src/CXParameterData.h \
			src/CXParametersView.h \
			src/CXFtp.h \
			src/iniFile.h \
			src/CXProcessingParametersWindow.h \
			src/CXTurnDialog.h \
			src/CXOperDirectionWindow.h \
			src/CXOperDirectionView.h \
			src/CXOperVelocityView.h \
			src/CXOperTechnology.h \
			src/CXTextParameters.h \
			src/CXCompileEdit.h \
			src/CXTouchButton.h \
			src/CXOperDirectionDialog.h \
			src/CXExitDialog.h \
			src/CXVirtualKeyboard.h \
			src/CXUtilsWindow.h \
			src/CXUdpManager.h \
			src/CXSettingsXML.h \
			src/CXProcess.h \
			src/SXChannelData.h \
			src/CXDeviceView.h \
			src/CXChannelEdit.h \
			src/CXDeviceEdit.h \
			src/CXCameraWidget.h \
			src/QFtp/qftp.h \
			src/QFtp/qurlinfo.h

SOURCES +=	src/main.cpp \
			src/AXBaseWindow.cpp \
			src/CXWindowsManager.cpp \
			src/CXPathView.cpp \
			src/CXPathWindow.cpp \
			src/flowlayout.cpp \
			src/CXFilesList.cpp \
			src/CXSyntaxHighlighter.cpp \
			src/CXEditPathFile.cpp \
			src/CXIniFileEditor.cpp \
			src/CXGroupPanel.cpp \
			src/CXTitleWindow.cpp \
			src/CXIniFileList.cpp \
			src/CXParametersWindow.cpp \
			src/CXParameterData.cpp \
			src/CXParametersView.cpp \
			src/CXFtp.cpp \
			src/iniFile.cpp \
			src/CXProcessingParametersWindow.cpp \
			src/CXTurnDialog.cpp \
			src/CXOperDirectionWindow.cpp \
			src/CXOperDirectionView.cpp \
			src/CXOperVelocityView.cpp \
			src/CXOperTechnology.cpp \
			src/CXTextParameters.cpp \
			src/CXCompileEdit.cpp \
			src/CXTouchButton.cpp \
			src/CXOperDirectionDialog.cpp \
			src/CXExitDialog.cpp \
			src/CXVirtualKeyboard.cpp \
			src/CXUtilsWindow.cpp \
			src/CXUdpManager.cpp \
			src/CXSettingsXML.cpp \
			src/CXProcess.cpp \
			src/CXDeviceView.cpp \
			src/CXChannelEdit.cpp \
			src/CXDeviceEdit.cpp \
			src/CXCameraWidget.cpp \
			src/QFtp/qftp.cpp \
			src/QFtp/qurlinfo.cpp

FORMS +=	src/CXFilesList.ui \
			src/CXEditPathFile.ui \
			src/CXIniFileEditor.ui \
			src/CXIniFileList.ui \
			src/CXProcessingParametersWindow.ui \
			src/CXOperTechnology.ui \
			src/CXTurnDialog.ui \
			src/CXOperDirectionDialog.ui \
			src/CXExitDialog.ui \
			src/CXVirtualKeyboard.ui \
			src/CXDeviceView.ui \
			src/CXChannelEdit.ui \
			src/CXCameraWidget.ui

RESOURCES += resource.qrc
