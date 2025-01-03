QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN'"
QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN'/src/"
LIBS += -lncurses -lUnitTest++
LIBS += -Lsrc/
QMAKE_CXXFLAGS += -fdebug-prefix-map=.=src/
LIBS += ../libtetris.so
LIBS += /usr/lib/x86_64-linux-gnu/libUnitTest++.so
INCLUDEPATH += /usr/include/UnitTest++/
INCLUDEPATH += ../src/
QMAKE_CXXFLAGS += -g
SOURCES = main.cpp
TARGET = ../tetris

