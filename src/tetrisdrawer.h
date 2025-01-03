#ifndef __TETRISDRAW__H
#define __TETRISDRAW__H
#include "tetris.h"
#include <curses.h>

class TetrisDisplay {
    public:
        virtual void show(TetrisGame&) = 0;
};

class TerminalDisplay : public TetrisDisplay {
    public:
        void show(TetrisGame &tg);
};

class NCursesDisplay : public TetrisDisplay {
    public:
        WINDOW *win;
        NCursesDisplay(int sizex, int sizey) {
            win = newwin(sizey, 4*sizex, 0, 0);
        }
        ~NCursesDisplay() {
            delwin(win);
        }
        void showBox(int x, int y, unsigned char c);
        void removeBox(int x, int y);
        void show(TetrisGame &tg);
};
#endif
