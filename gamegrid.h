
#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "piece.h"

class GameGrid {
public:
    GameGrid(const char (&copy)[20][10]);

    friend Block::checkCollision(GameGrid& grid);

private:
};

#endif
