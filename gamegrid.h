
#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "block.h"

class GameGrid {
public:
    GameGrid(const char (&copy)[20][10]);

    friend bool Block::hasCollisionOccurred(GameGrid& grid);

    int lineComplete();
    void shift(int y);
    char getData(int y, int x);

private:
    char data[20][10];

};


#endif
