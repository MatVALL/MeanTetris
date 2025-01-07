#ifndef __TETRISDRAW__H
#define __TETRISDRAW__H
#include "tetris.h"
#include <curses.h>

#define TEXT 8

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
        WINDOW *score;
        NCursesDisplay(int sizex, int sizey) {
            win = newwin(sizey+2, 2*sizex+2, 1, 1);
            score = newwin(5, 18, sizey-2, 2*sizex+4);
            start_color();
            init_pair(1, COLOR_RED, COLOR_RED);
            init_pair(2, COLOR_GREEN, COLOR_GREEN);
            init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
            init_pair(4, COLOR_BLUE, COLOR_BLUE);
            init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
            init_pair(6, COLOR_CYAN, COLOR_CYAN);
            init_pair(7, COLOR_WHITE, COLOR_WHITE);
            init_pair(TEXT, COLOR_WHITE, COLOR_BLACK);
        }
        ~NCursesDisplay() {
            delwin(win);
            delwin(score);
        }
        void showBox(int x, int y, unsigned char c, Color color = Color::WHITE);
        void removeBox(int x, int y);
        void show(TetrisGame &tg);
        void displayScore(TetrisGame &tg);
};
#endif
