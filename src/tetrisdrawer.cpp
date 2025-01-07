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

void NCursesDisplay::showBox(int x, int y, unsigned char c, Color color) {
    y = MAX_Y - y;
	wattron(win, COLOR_PAIR(color));
    mvwaddch(win, y, 2*x+1, c);
    mvwaddch(win, y, 2*x+2, c);
	wattroff(win, COLOR_PAIR(color));
}
void NCursesDisplay::removeBox(int x, int y) {
    showBox(x, y, ' ');
}
void NCursesDisplay::displayScore(TetrisGame &tg)
{
    erase();
    box(score, 0, 0);
    /* TODO: score */
    mvwprintw(score, 1, 1, "Scores:%8d", 0);
    mvwprintw(score, 2, 1, "Lines:%9ld", tg.lines);
    wrefresh(score);
}
void NCursesDisplay::show(TetrisGame &tg)
{
    erase();
    box(win, 0, 0);

    for (int j = 0; j < MAX_Y; j++) {
        for (int i = 0; i < MAX_X; i++) {
            if (tg.gs.occupied(i, j)) {
                showBox(i, j, '0', tg.gs.getColor(i, j));
            } else {
                showBox(i, j, ' ', Color::BLACK);
            }
        }
    }
    if (tg.shape != nullptr) {
        for (auto b: tg.shape->getBoxes()) {
            showBox(b.x, b.y, 'O', b.c);
        }
    }

    displayScore(tg);
    wrefresh(win);
    wrefresh(score);
}
