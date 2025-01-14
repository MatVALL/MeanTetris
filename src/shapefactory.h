#ifndef __TETRISSHAPEFACTORY__H
#define __TETRISSHAPEFACTORY__H
#include "gamestate.h"
#include "shape.h"
#include <functional>

class ShapeBuilder {
    public:
        std::function<std::unique_ptr<Shape>(void)> build;
        ShapeBuilder(std::function<std::unique_ptr<Shape>(void)> build) : build(build) {};
};

class ShapeFactory {
    public:
        virtual std::unique_ptr<Shape> getShape(GameState &gs) = 0;
        virtual ~ShapeFactory() = default;
};


class RandomFactory : public ShapeFactory {
    private:
        std::vector<ShapeBuilder> builders;
    public:
        std::unique_ptr<Shape> getShape(GameState &gs) {
            (void)gs;
            ShapeBuilder b = builders[rand()%builders.size()];
            return b.build();
        }

        void addBuilder(ShapeBuilder sb) {
            builders.push_back(sb);
        }

        void fillShapeFactory(int x, int y);
        RandomFactory(int max_x, int max_y) {
            fillShapeFactory(max_x/2, max_y-1);
        }
};


#endif
