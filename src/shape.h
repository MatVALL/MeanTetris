#ifndef __TETRISSHAPE__H
#define __TETRISSHAPE__H
#include <vector>
#include "gamestate.h"
#include "tetriscontroller.h"

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
        Square(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x, y, Color::RED),
                    Box(x -1, y-1, Color::RED),
                    Box(x-1, y, Color::RED),
                    Box(x, y-1, Color::RED)});
        }
};

class TShape : public ConcreteShape{
    public:
        TShape(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x, y, Color::WHITE),
                    Box(x -1, y-1, Color::WHITE),
                    Box(x +1, y-1, Color::WHITE),
                    Box(x, y-1, Color::WHITE)});
        }
};

class Squiggle : public ConcreteShape{
    public:
        Squiggle(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x + 1, y, Color::GREEN),
                    Box(x + 1, y-1, Color::GREEN),
                    Box(x, y-1, Color::GREEN),
                    Box(x, y-2, Color::GREEN)});
        }
};

class LeftSquiggle : public ConcreteShape{
    public:
        LeftSquiggle(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x , y, Color::MAGENTA),
                    Box(x , y-1, Color::MAGENTA),
                    Box(x + 1, y-1, Color::MAGENTA),
                    Box(x + 1, y-2, Color::MAGENTA)});
        }
};

class LeftL : public ConcreteShape{
    public:
        LeftL(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x +1 , y, Color::CYAN),
                    Box(x +1 , y-1, Color::CYAN),
                    Box(x +1 , y-2, Color::CYAN),
                    Box(x, y-2, Color::CYAN)});
        }
};
class LShape : public ConcreteShape{
    public:
        LShape(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x - 1 , y, Color::YELLOW),
                    Box(x - 1 , y - 1, Color::YELLOW),
                    Box(x - 1 , y - 2, Color::YELLOW),
                    Box(x, y - 2, Color::YELLOW)});
        }
};

class Straight : public ConcreteShape{
    public:
        Straight(int x, int y) {
            boxes = std::vector<Box>({
                    Box(x, y, Color::BLUE),
                    Box(x + 1, y, Color::BLUE),
                    Box(x + 2, y, Color::BLUE),
                    Box(x + 3, y, Color::BLUE)});
        }
};

#endif
