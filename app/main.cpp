#include "tetris.h"
#include "tetrisdrawer.h"
#include "shapefactory.h"

void gameOver() {
}

int main() {
    TetrisGame tg;
    NCursesController ctrl(5);
    NCursesDisplay disp(MAX_X, MAX_Y);
    ShapeFactory *sf = new RandomFactory();

    disp.show(tg);
    /* maybe the TetrisGame should own the factory.*/
    tg.shape = sf->getShape(tg.gs);
    for (;;) {
         while (tg.shape->canMove(Move::DOWN, tg.gs)){
            do {
                Move m = ctrl.getMove();
                tg.play(m);
                disp.show(tg);
                ctrl.sleep();
            } while(!ctrl._timeout());
            ctrl.update();
            tg.play(Move::DOWN);
        }
        if (tg.shape->drop(tg.gs) < 0) {
            gameOver();
            break;
        }
        tg.shape = sf->getShape(tg.gs);
    }

    delete sf;
    return 0;
}
