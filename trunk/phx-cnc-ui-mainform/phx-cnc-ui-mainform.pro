TEMPLATE = app
INCLUDEPATH += ./src ./GeneratedFiles
QT      += xml xmlpatterns network
UI_DIR	+= ./GeneratedFiles

CONFIG += debug_and_release

_install-release.depends = $(SOURCES)
_install-debug.depends = $(SOURCES)
win32 {
_install-release.commands = cp ./release/phx-cnc-ui-mainform*  ../install
_install-debug.commands = cp ./debug/phx-cnc-ui-mainform*  ../install
}
unix {
_install-release.commands = cp ./phx-cnc-ui-mainform*  ../install
_install-debug.commands = cp ./phx-cnc-ui-mainform*  ../install
}
QMAKE_EXTRA_TARGETS += _install-release _install-debug

QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++0x

#QMAKE_CXXFLAGS += -pg
#QMAKE_LFLAGS += -pg

INCLUDEPATH += ../include

QMAKE_LIBDIR += ../install/libs
#LIBS += -lglog
# Input
HEADERS	+=	src/AXBaseWindow.h \
			src/CXWindowsManager.h \
			src/CXPathView.h \
			src/CXPathWindow.h \
			src/utils/flowlayout.h \
			src/CXFilesList.h \
			src/utils/CXSyntaxHighlighter.h \
			src/CXEditPathFile.h \
			src/CXIniFileEditor.h \
			src/CXGroupPanel.h \
			src/CXTitleWindow.h \
			src/CXIniFileList.h \
			src/CXParametersWindow.h \
			src/CXParameterData.h \
			src/CXParametersView.h \
			src/utils/CXFtp.h \
			src/utils/iniFile.h \
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
      src/utils/CXSettingsXML.h \
      src/utils/CXProcess.h \
      src/SXChannelData.h \
      src/CXDeviceView.h \
      src/CXChannelEdit.h \
      src/CXDeviceEdit.h \
      src/CXWarmingUpDlg.h \
      src/terminalCtrl.h \
      src/CXTechDlg.h \
      src/CXVirtualKeyboardNum.h \
      src/CXOperFeedDlg.h \
      src/CXParamui.h \
      src/CXZParamui.h \
      src/CXSupports.h \ 
      src/CXAdditionalOperDirectionWindow.h \  
      src/utils/CXParamData.h \
      src/utils/CXMLReader.h

SOURCES +=	src/main.cpp \
			src/AXBaseWindow.cpp \
			src/CXWindowsManager.cpp \
			src/CXPathView.cpp \
			src/CXPathWindow.cpp \
			src/utils/flowlayout.cpp \
			src/CXFilesList.cpp \
			src/utils/CXSyntaxHighlighter.cpp \
			src/CXEditPathFile.cpp \
			src/CXIniFileEditor.cpp \
			src/CXGroupPanel.cpp \
			src/CXTitleWindow.cpp \
			src/CXIniFileList.cpp \
			src/CXParametersWindow.cpp \
			src/CXParameterData.cpp \
			src/CXParametersView.cpp \
			src/utils/CXFtp.cpp \
			src/utils/iniFile.cpp \
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
			src/utils/CXSettingsXML.cpp \
			src/utils/CXProcess.cpp \
			src/CXDeviceView.cpp \
			src/CXChannelEdit.cpp \
			src/CXDeviceEdit.cpp \
      src/CXWarmingUpDlg.cpp \  
      src/terminalCtrl.cpp \
      src/CXVirtualKeyboardNum.cpp \
      src/CXTechDlg.cpp \
      src/CXOperFeedDlg.cpp \
      src/CXParamui.cpp \
      src/CXZParamui.cpp \
      src/CXSupports.cpp \   
      src/CXAdditionalOperDirectionWindow.cpp \
      src/utils/CXParamData.cpp \
			src/utils/CXMLReader.cpp

FORMS +=	src/forms/CXFilesList.ui \
      src/forms/CXTechDlg.ui \
      src/forms/CXEditPathFile.ui \
      src/forms/CXOperFeedDlg.ui \
			src/forms/CXIniFileEditor.ui \
			src/forms/CXIniFileList.ui \
			src/forms/CXProcessingParametersWindow.ui \
			src/forms/CXOperTechnology.ui \
			src/forms/CXTurnDialog.ui \
			src/forms/CXOperDirectionDialog.ui \
			src/forms/CXExitDialog.ui \
			src/forms/CXVirtualKeyboard.ui \
			src/forms/CXDeviceView.ui \
      src/forms/CXWarmingUpDlg.ui \		
      src/forms/CXVirtualKeyboardNum.ui \
      src/forms/CXParam.ui \
      src/forms/CXZParam.ui \
      src/forms/CXSupports.ui \   
			src/forms/CXChannelEdit.ui

RESOURCES += resource.qrc
