#include "shape.h"

void Square::rotate() {}
bool Square::canRotate() { return true;}
void Square::move(Move m) {
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
        }
    }
}

bool Square::canMove(Move m, GameState &gs) {
    /* TODO: avoid code duplication*/
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
        }
        if (x < 0 || x >= gs.size_x || y < 0 || gs.occupied(x, y)) {
            return false;
        }
    }
    return true;
}
std::vector<Box> Square::getBoxes() {
    return boxes;
}
Square::Square(int x, int y) {
    boxes = std::vector<Box>({
            Box(x, y),
            Box(x -1, y-1),
            Box(x-1, y),
            Box(x, y-1)});
}
int Square::drop(GameState &gs) {
    for (auto b: boxes) {
        if (gs.occupied(b.x, b.y)) {
            return -1;
        }
        gs.set(b.x, b.y);
    }
    return 0;
}
