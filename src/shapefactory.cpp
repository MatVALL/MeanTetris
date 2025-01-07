#include "shapefactory.h"

void RandomFactory::fillShapeFactory(int x, int y)
{
    std::vector<std::function<Shape*(void)>> builders;
    builders.push_back([=](void) -> Shape* {return (Shape*) new Squiggle(x,y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new LeftSquiggle(x, y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new Square(x, y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new Straight(x, y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new TShape(x, y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new LShape(x, y);});
    builders.push_back([=](void) -> Shape* {return (Shape*) new LeftL(x, y);});

    for (auto builder:builders)
    {
        ShapeBuilder sb(builder);
        addBuilder(sb);
    }
}

