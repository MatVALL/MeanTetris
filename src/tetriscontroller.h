#ifndef __TETRISCTRL__H
#define __TETRISCTRL__H

enum Move{NONE, LEFT, RIGHT, DOWN, DROP};

class TetrisController {
    private:
        int speed;
        Move m = NONE;
    public:
        TetrisController(int speed = 0) : speed(speed) {
            m = Move::DOWN;
        }
        Move getMove();
};

class TerminalController {
};
#endif
