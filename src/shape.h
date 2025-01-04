#ifndef __TETRISSHAPE__H
#define __TETRISSHAPE__H
#include <vector>
#include "gamestate.h"
#include "tetriscontroller.h"

struct Box {
    int x; int y;
    Box(int x, int y): x(x), y(y) {};
};

inline Box operator+ (Box a, const Box& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline Box operator- (Box a, const Box& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

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
        virtual ~ConcreteShape() = default;
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

class Squiggle : public ConcreteShape{
    public:
        Squiggle(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x, y),
                    Box(x -1, y-1),
                    Box(x +1, y-1),
                    Box(x, y-1)});
        }
};

#endif
