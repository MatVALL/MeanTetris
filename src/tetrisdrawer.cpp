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


void NCursesDisplay::showBox(int x, int y, unsigned char c) {
    y = MAX_Y - y;
    mvwaddch(win, y, 2*x, c);
}
void NCursesDisplay::removeBox(int x, int y) {
    showBox(x, y, ' ');
}
void NCursesDisplay::show(TetrisGame &tg)
{
    erase();
    for (int j = 0; j < MAX_Y; j++) {
        for (int i = 0; i < MAX_X; i++) {
            if (tg.gs.occupied(i, j)) {
                showBox(i, j, 'X');
            } else {
                showBox(i, j, '.');
            }
        }
    }
    if (tg.shape != nullptr) {
        for (auto b: tg.shape->getBoxes()) {
            showBox(b.x, b.y, 'O');
        }
    }
    wrefresh(win);
}
