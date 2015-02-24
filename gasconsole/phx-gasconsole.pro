#-------------------------------------------------
#
# Project created by QtCreator 2014-05-16T09:38:15
#
#-------------------------------------------------
TEMPLATE = app

INCLUDEPATH += ./src ./GeneratedFiles

QT       += core gui xml xmlpatterns network

UI_DIR  += ./GeneratedFiles

CONFIG += debug_and_release

_install-release.depends = $(SOURCES)
_install-debug.depends = $(SOURCES)
win32 {
_install-release.commands = cp ./release/phx-gasconsole*  ../install
_install-debug.commands = cp ./debug/phx-gasconsole*  ../install

}
unix {
_install-debug.commands = cp ./phx-gasconsole*  ../../phx-cnc-ui-mainform/install
}
QMAKE_EXTRA_TARGETS += _install-release _install-debug

QMAKE_CXXFLAGS += -std=c++11


#TARGET = phx-gasconsole

SOURCES += src/main.cpp \
           src/qgasconsole.cpp \
           src/utils/CXSettingsXML.cpp \
           src/CXUdpManager.cpp

HEADERS  += src/qgasconsole.h \
            src/utils/CXSettingsXML.h \
            src/CXUdpManager.h

FORMS    += src/forms/qgasconsole.ui
