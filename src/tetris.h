#ifndef __TETRIS__H
#define __TETRIS__H
#include <iostream>
#include <cstdint>
#include "tetriscontroller.h"
#include "gamestate.h"
#include "shape.h"
#include "shapefactory.h"

const int MAX_X = 12;
const int MAX_Y = 25;

class TetrisGame {
    public:
        int64_t score = 0;
        Shape *shape = nullptr;
        ShapeFactory *sf;
        GameState gs = GameState(MAX_X, MAX_Y);
        TetrisGame(ShapeFactory *sp);
        void play(Move);
        void gameLoop(void);
        void linesCleared(int lines);
};
#endif
