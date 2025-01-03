#include "gamestate.h"

bool GameState::occupied(int x, int y) {
    return boxes[x][y];
}
void GameState::set(int x, int y) {
    boxes[x][y] = true;
}
