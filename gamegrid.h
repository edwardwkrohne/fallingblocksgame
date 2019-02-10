
#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "block.h"

class GameGrid {
public:
    GameGrid(const char (&copy)[20][10]);

    friend bool Block::hasCollisionOccurred(GameGrid& grid);

private:
    char data[20][10];

};

#endif
