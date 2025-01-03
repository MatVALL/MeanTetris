#include "tetris.h"
#include "tetrisdrawer.h"
#include "shapefactory.h"

void gameOver() {
}

int main() {
    TetrisGame tg;
    TerminalDisplay disp;
    TetrisController ctrl(5);
    ShapeFactory *sf = new RandomFactory();

    disp.show(tg);
    tg.shape = sf->getShape(tg.gs);
    for (;;) {
        do {
            Move m = ctrl.getMove();
            getchar();
            tg.play(m);
            disp.show(tg);
            std::cout << "canMove:" <<tg.shape->canMove(Move::DOWN, tg.gs);
        } while (tg.shape->canMove(Move::DOWN, tg.gs));
        if (tg.shape->drop(tg.gs) < 0) {
            gameOver();
            break;
        }
        tg.shape = sf->getShape(tg.gs);
    }

    delete sf;
    return 0;
}
