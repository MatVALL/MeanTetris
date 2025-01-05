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
        virtual bool canRotate(GameState &gs) = 0;
        virtual void move(Move m) = 0;
        virtual bool canMove(Move m, GameState &gs) = 0;
        virtual std::vector<Box> getBoxes() = 0;
        virtual int drop(GameState &gs) = 0;
};

class ConcreteShape: public Shape {
    public:
        std::vector<Box> boxes;
        Box getCenter();
        void rotate();
        void move(Move m);
        bool canMove(Move m, GameState &gs);
        std::vector<Box> getBoxes();
        bool canRotate(GameState& gs);
        int drop(GameState &gs);
        ConcreteShape& operator=(const ConcreteShape& t)
        {
            boxes = t.boxes;
            return *this;
        }
};

/* TODO: override getcenter for cleaner rotations */
class Square : public ConcreteShape{
    public:
        Square(int x, int y);
};

class TShape : public ConcreteShape{
    public:
        TShape(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x, y),
                    Box(x -1, y-1),
                    Box(x +1, y-1),
                    Box(x, y-1)});
        }
};

class Squiggle : public ConcreteShape{
    public:
        Squiggle(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x + 1, y),
                    Box(x + 1, y-1),
                    Box(x, y-1),
                    Box(x, y-2)});
        }
};

class LeftSquiggle : public ConcreteShape{
    public:
        LeftSquiggle(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x , y),
                    Box(x , y-1),
                    Box(x + 1, y-1),
                    Box(x + 1, y-2)});
        }
};

class LeftL : public ConcreteShape{
    public:
        LeftL(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x +1 , y),
                    Box(x +1 , y-1),
                    Box(x +1 , y-2),
                    Box(x, y-2)});
        }
};
class LShape : public ConcreteShape{
    public:
        LShape(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x - 1 , y),
                    Box(x - 1 , y - 1),
                    Box(x - 1 , y - 2),
                    Box(x, y - 2)});
        }
};

class Straight : public ConcreteShape{
    public:
        Straight(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x , y),
                    Box(x + 1, y),
                    Box(x + 2, y),
                    Box(x + 3, y)});
        }
};

#endif
