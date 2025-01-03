#ifndef __TETRISCTRL__H
#define __TETRISCTRL__H
#include <iostream>
/* TODO: portability */
#include <curses.h>
/* timing*/
#include <iostream>
#include <chrono>
#include <ctime>
/* sleep */
#include <thread>         // std::this_thread::sleep_for

enum Move{NONE, LEFT, RIGHT, DOWN, DROP};

class TetrisController {
    private:
        int speed;
    public:
        TetrisController(int speed = 0) : speed(speed) {}
        virtual Move getMove();
        virtual void update();
        virtual bool _timeout();
};

/* TODO: make this an observer pattern */
class NCursesController : public TetrisController{
    private:
        int speed;
        std::chrono::system_clock::time_point last_update;
    public:
        NCursesController(int speed = 0);
        ~NCursesController();
        Move getMove();
        void update();
        bool _timeout();
        void sleep();
};
#endif
