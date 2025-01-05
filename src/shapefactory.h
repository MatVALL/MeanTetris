#ifndef __TETRISSHAPEFACTORY__H
#define __TETRISSHAPEFACTORY__H
#include "gamestate.h"
#include "shape.h"

class ShapeFactory {
    public:
        virtual Shape *getShape(GameState &gs) = 0;
        virtual ~ShapeFactory() = default;
};

class RandomFactory : public ShapeFactory {
    Shape* getShape(GameState &gs) {
        switch (rand()%5) {
            case 0: return new Squiggle(gs.size_x/2, gs.size_y -1);
            case 1: return new LeftSquiggle(gs.size_x/2, gs.size_y -1);
            case 2: return new Square(gs.size_x/2, gs.size_y -1);
            case 3: return new Straight(gs.size_x/2, gs.size_y -1);
            case 4: return new TShape(gs.size_x/2, gs.size_y -1);

        }
        return NULL;
    }

};
#endif
