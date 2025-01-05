#ifndef __GAMESTATETETRIS__H
#define __GAMESTATETETRIS__H

/* avoid circular dependency from tetris and shapefactory */
class GameState {
    bool **boxes;
    public:
    const int size_x, size_y;
    GameState(int x, int y) : size_x(x), size_y(y) {
        boxes = new bool*[size_x];
        for (int i = 0; i < size_x; i++) {
            boxes[i] = new bool[size_y];
        }
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                boxes[i][j] = false;
            }
        }
    }
    ~GameState() {
        for (int i = 0; i < size_x; i++) {
            delete[] boxes[i];
        }
        delete[] boxes;
    }
    private:
        void clearLine(int j);
    public:
        bool occupied(int x, int y);
        void set(int x, int y);
        bool lineIsFull(int j);
        void lineClear();
};

#endif
