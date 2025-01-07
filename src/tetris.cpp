#include "tetris.h"

TetrisGame::TetrisGame(ShapeFactory *sf): sf(sf) {
    shape = sf->getShape(gs);
};

void TetrisGame::play(Move move) {
    if (shape->canMove(move, gs)) {
        shape->move(move);
    }
}

void TetrisGame::linesCleared(int lines) {
    /* TODO: make score */
    this->lines += lines;
}
