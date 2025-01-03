#include "tetrisdrawer.h"

void TerminalDisplay::show(TetrisGame &tg)
{
    char printedboard[MAX_X][MAX_Y];
    for (int j = 0; j < MAX_Y; j++) {
        for (int i = 0; i < MAX_X; i++) {
            printedboard[i][j] = (tg.gs.occupied(i, j)? '#':'.');
        }
    }
    std::cout << tg.shape << std::endl;
    if (tg.shape != nullptr) {
        for (auto b: tg.shape->getBoxes()) {
            std::cout << b.x << b.y << std::endl;
            printedboard[b.x][b.y] = 'o';
        }
    }

    std::cout << std::endl;
    for (int j = MAX_Y-1; j >= 0; j--) {
        for (int i = 0; i < MAX_X; i++) {
            std::cout << printedboard[i][j];
        }
        std::cout << std::endl;
    }

}
