TEMPLATE = app
QT      += xml


# Input
HEADERS	+=	src/AXBaseWindow.h \
			src/CXWindowsManager.h \
			src/CXPanelWindow.h \
			src/flowlayout.h

SOURCES +=	src/main.cpp \
			src/AXBaseWindow.cpp \
			src/CXWindowsManager.cpp \
			src/CXPanelWindow.cpp \
			src/flowlayout.cpp

FORMS	+=	src/CXPanelWindow.ui