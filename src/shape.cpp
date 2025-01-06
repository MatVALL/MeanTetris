#include "shape.h"

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

Box ConcreteShape::getCenter() {
    int center_x = 0;
    int center_y = 0;

    for (auto b: boxes) {
        center_x += b.x;
        center_y += b.y;
    }

    return Box(center_x/boxes.size(), center_y/boxes.size());
}
void ConcreteShape::rotate() {
    Box center = getCenter();
    // rotate around a coordinate:
    // re-center them: box = box - center
    for (size_t i = 0; i < boxes.size(); i++) {
        boxes[i] = boxes[i] - center;
        /* 2D matrix for 90° rotation:
         *        [0  -1]
         *        [1   0]
         * [x   y][y  -x]
         * */
        boxes[i] = Box(boxes[i].y, -boxes[i].x, boxes[i].c);
        boxes[i] = boxes[i] + center;
    }

    // rotate them (matrix of rotation)
    // then re-place them
}
void ConcreteShape::move(Move m) {
    if (m == ROTATE) {
        rotate();
        return;
    }
    for (auto &b:boxes) {
        switch(m) {
            case LEFT:
                b.x --;
                break;
            case DOWN:
                b.y --;
                break;
            case RIGHT:
                b.x ++;
                break;
            case DROP:
                /* TODO */
                break;
            case NONE:
                break;
            case ROTATE:
                break;
        }
    }
}
bool ConcreteShape::canMove(Move m, GameState &gs) {
    /* TODO: handle this on Box to avoid code duplication*/
    for (auto &b:boxes) {
        int x = b.x;
        int y = b.y;
        switch(m) {
            case RIGHT:
                x++;
                break;
            case LEFT:
                x--;
                break;
            case DOWN:
                y--;
                break;
            /* TODO */
            case DROP:
            case NONE:
                break;
            case ROTATE:
                return canRotate(gs);
        }
        if (x < 0 || x >= gs.size_x || y < 0 || gs.occupied(x, y)) {
            return false;
        }
    }
    return true;
}
std::vector<Box> ConcreteShape::getBoxes() {
    return boxes;
}

bool ConcreteShape::canRotate(GameState& gs) {
    ConcreteShape shp = *this;
    shp.rotate();

    for (auto b: shp.boxes) {
        if (gs.occupied(b.x, b.y)) {
            return false;
        }
    }
    return true;
}

int ConcreteShape::drop(GameState &gs) {
    for (auto b: boxes) {
        if (gs.occupied(b.x, b.y)) {
            return -1;
        }
        gs.set(b.x, b.y, b.c);
    }
    return 0;
}
