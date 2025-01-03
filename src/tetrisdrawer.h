#ifndef __TETRISDRAW__H
#define __TETRISDRAW__H
#include "tetris.h"

class TetrisDisplay {
    public:
        virtual void show(TetrisGame&) = 0;
};

class TerminalDisplay : public TetrisDisplay {
    public:
        void show(TetrisGame &tg);
};
#endif
