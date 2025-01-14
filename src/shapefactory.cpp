#include "shapefactory.h"

void RandomFactory::fillShapeFactory(int x, int y)
{
    std::vector<std::function<std::unique_ptr<Shape>(void)>> builders;
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>(new Squiggle(x,y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new LeftSquiggle(x, y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new Square(x, y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new Straight(x, y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new TShape(x, y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new LShape(x, y));});
    builders.push_back([=](void) -> std::unique_ptr<Shape> {return std::unique_ptr<Shape>( new LeftL(x, y));});

    for (auto builder:builders)
    {
        ShapeBuilder sb(builder);
        addBuilder(sb);
    }
}

