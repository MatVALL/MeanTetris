QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN'"
QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN'/src/"
LIBS += -lncurses -lUnitTest++
LIBS += /usr/lib/x86_64-linux-gnu/libUnitTest++.so
LIBS += ../libtetris.so
INCLUDEPATH += /usr/include/UnitTest++/
INCLUDEPATH += ../src/
SOURCES = tetris_test.cpp
HEADERS = tetriscontroller.h
TARGET = tetristest
DESTDIR = ..