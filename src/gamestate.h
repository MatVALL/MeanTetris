#ifndef __GAMESTATETETRIS__H
#define __GAMESTATETETRIS__H

enum Color {
    RED=1,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    BLACK,
};

struct Box {
    Color c;
    int x; int y;
    Box(int x, int y, Color c=WHITE): c(c), x(x), y(y) {};
};
inline Box operator+ (Box a, const Box& b);
inline Box operator- (Box a, const Box& b);


/* avoid circular dependency from tetris and shapefactory */
class GameState {
    Box ***boxes;
    public:
    const int size_x, size_y;
    GameState(int x, int y) : size_x(x), size_y(y) {
        boxes = new Box**[size_x];
        for (int i = 0; i < size_x; i++) {
            boxes[i] = new Box*[size_y];
        }
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                boxes[i][j] = nullptr;
            }
        }
    }
    ~GameState() {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                if (boxes[i][j] != nullptr) {
                    delete boxes[i][j];
                }
            }
            delete[] boxes[i];
        }
        delete[] boxes;
    }
    private:
        void clearLine(int j);
    public:
        bool occupied(int x, int y);
        void set(int x, int y, Color c);
        bool lineIsFull(int j);
        int lineClear();
        Color getColor(int x, int y);
        bool posIsCorrect(int x, int y);
};

#endif
