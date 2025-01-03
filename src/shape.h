#ifndef __TETRISSHAPE__H
#define __TETRISSHAPE__H
#include <vector>
#include "gamestate.h"
#include "tetriscontroller.h"

struct Box {
    int x; int y;
    Box(int x, int y): x(x), y(y) {};
};

class Shape {
    public:
        virtual void rotate() = 0;
        virtual bool canRotate() = 0;
        virtual void move(Move m) = 0;
        virtual bool canMove(Move m, GameState &gs) = 0;
        virtual std::vector<Box> getBoxes() = 0;
        virtual int drop(GameState &gs) = 0;
};

class Square : public Shape{
    std::vector<Box> boxes;
    public:
        void rotate();
        bool canRotate();
        void move(Move m);
        bool canMove(Move m, GameState &gs);
        int drop(GameState &gs);
        std::vector<Box> getBoxes();
        Square(int x, int y);
};

#endif
