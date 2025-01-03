#include "tetris.h"

TetrisGame::TetrisGame() {
};

void TetrisGame::play(Move move) {
    if (shape->canMove(move, gs)) {
        shape->move(move);
    }
}

