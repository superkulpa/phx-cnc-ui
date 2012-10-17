TEMPLATE = app
QT      += xml network script


# Input
HEADERS	+=	src/AXBaseWindow.h \
			src/CXWindowsManager.h \
			src/CXPanelWindow.h \
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
			src/CXLazerDirectionWindow.h \
			src/CXLazerDirectionView.h \
			src/CXLazerVelocityView.h \
			src/CXLazerSettings.h \
			src/CXLazerVelocity.h \
			src/CXTextParameters.h

SOURCES +=	src/main.cpp \
			src/AXBaseWindow.cpp \
			src/CXWindowsManager.cpp \
			src/CXPanelWindow.cpp \
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
			src/CXLazerDirectionWindow.cpp \
			src/CXLazerDirectionView.cpp \
			src/CXLazerVelocityView.cpp \
			src/CXLazerSettings.cpp \
			src/CXLazerVelocity.cpp \
			src/CXTextParameters.cpp

FORMS +=	src/CXFilesList.ui \
			src/CXEditPathFile.ui \
			src/CXIniFileEditor.ui \
			src/CXIniFileList.ui \
			src/CXProcessingParametersWindow.ui \
			src/CXLazerVelocity.ui \
			src/CXTurnDialog.ui

RESOURCES += resource.qrc