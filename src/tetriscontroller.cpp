#include "tetriscontroller.h"

Move TetrisController::getMove() {
    getchar();
    return Move::DOWN;;
}
void TetrisController::update() {}
bool TetrisController::_timeout() {
    return true;
}

/* {{{ NCursesController */

NCursesController::NCursesController(int speed) : speed(speed) {
    initscr();//init curses
    noecho(); //do not echo outputs
    keypad(stdscr, TRUE); // capture arrows
    nodelay(stdscr, TRUE); // NONBLOCKING
    curs_set(0); /* hide cursor */
    update();
}
NCursesController::~NCursesController() {
    endwin();
}
Move  NCursesController::getMove() {
    int ch;
    if ((ch = getch()) == ERR) {
        return Move::NONE;
    }
    else {
        switch(ch) {
            case KEY_LEFT:
                return Move::LEFT;
            case KEY_RIGHT:
                return Move::RIGHT;
            case KEY_DOWN:
                return Move::DOWN;
            case ' ':
                return Move::ROTATE;
        }
    }
    return Move::NONE;
}
void NCursesController::update() {
    last_update = std::chrono::system_clock::now();
}
bool NCursesController::_timeout() {
    auto now = std::chrono::system_clock::now();
    return now > (last_update + std::chrono::milliseconds(100*speed));
}
void NCursesController::sleep() {
    flushinp();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

/* }}} */
