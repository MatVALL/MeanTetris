#include "gamestate.h"

bool GameState::posIsCorrect(int x, int y) {
    return (x >= 0 && x < size_x &&  y >= 0  && y < size_y);
}

bool GameState::occupied(int x, int y) {
    return posIsCorrect(x, y) && boxes[x][y] != nullptr;
}

void GameState::set(int x, int y, Color c) {
    if (!posIsCorrect(x, y)) {
        return;
    }
    if (boxes[x][y] != nullptr) {
        delete boxes[x][y];
    }
    boxes[x][y] = new Box(0, 0, c);
}

Color GameState::getColor(int x, int y) {
    return boxes[x][y]->c;
}

bool GameState::lineIsFull(int j) {
    for (int i = 0 ; i < size_x; i++) {
        if (not occupied(i, j)) {return false;}
    }
    return true;
}

int GameState::lineClear() {
    int lines = 0;

    for (int j = size_y - 1; j >= 0 ; j--) {
        if (lineIsFull(j)) {
            lines++;
            clearLine(j);
        }
    }

    return lines;
}

void GameState::clearLine(int j) {
    for(int i = 0; i < size_x; i++) {
            delete boxes[i][j];
            boxes[i][j] = nullptr;
    }
    for (int y = j + 1; y < size_y-1; y++) {
        for (int x = 0; x < size_x; x++) {
            boxes[x][y-1] = boxes[x][y];
        }
    }
}
