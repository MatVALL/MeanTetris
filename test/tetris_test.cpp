#define __TESTING
#include <UnitTest++/UnitTest++.h>
#include "tetris.h"
#include "tetrisdrawer.h"
#include "shapefactory.h"

TEST(CheckRotation)

{
    /* TODO */
}

void gameStatSet(GameState &gs, bool boxes[5][5]) {
    for (int i=0; i < 5 ; i++) {
        for (int j = 0; j < 5; j++) {
            if (boxes[i][j]) gs.set(i, j);
        }
    }
}
bool gameStateEqual(GameState &gs, bool boxes[5][5]) {
    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (boxes[i][j] != gs.occupied(i, j)) {
                std::cout<< i << j << std::endl;
                return false;
            }
        }
    }
    return true;
}

TEST(ClearLine)
{
    GameState gs = GameState(5, 5);
    bool boxes[5][5] = {{1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1}};
    bool boxes2[5][5] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};

    gameStatSet(gs, boxes);
    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << gs.occupied(i, j) << " ";
        }
        std::cout << std::endl;
    }
    for (int i=0; i < gs.size_y; i++)
    {
        CHECK(gs.lineIsFull(i));
    }
    gs.lineClear();
    CHECK(gameStateEqual(gs, boxes2));
    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << gs.occupied(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
  return UnitTest::RunAllTests();
}
#undef __TESTING
