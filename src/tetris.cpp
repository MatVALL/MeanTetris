#include "tetris.h"

TetrisGame::TetrisGame() {
};

void TetrisGame::play(Move move) {
    (void) move;
    shape->move(Move::DOWN);
}

