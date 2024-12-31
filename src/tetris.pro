SOURCES = tetris.cpp
HEADERS = tetriscontroller.h  tetrisdrawer.h  tetris.h
QMAKE_CXXFLAGS += -g
QT += core
LIBS += /usr/lib/x86_64-linux-gnu/libQt6*.so
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt6/QtWidgets/
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt6/
TARGET = tetris
