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
        return new Squiggle(gs.size_x/2, gs.size_y -1);
    }

};
#endif
