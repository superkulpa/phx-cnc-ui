TEMPLATE = app
QT      += xml


# Input
HEADERS	+=	src/AXBaseWindow.h \
			src/CXWindowsManager.h \
			src/CXPanelWindow.h \
			src/CXPathView.h \
			src/flowlayout.h \
			src/CXFilesList.h \
			src/CXSyntaxHighlighter.h

SOURCES +=	src/main.cpp \
			src/AXBaseWindow.cpp \
			src/CXWindowsManager.cpp \
			src/CXPanelWindow.cpp \
			src/CXPathView.cpp \
			src/flowlayout.cpp \
			src/CXFilesList.cpp \
			src/CXSyntaxHighlighter.cpp

FORMS +=	src/CXFilesList.ui