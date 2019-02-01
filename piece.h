// Some sort of brief comment here
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "gamegrid.h"


class Block {
public:
  //constructor
  Block(int y, int x, int pieceId );


  char get(int row, int col);
  // other functions that you want go here.

bool checkCollision(GameGrid& grid);

private:
  void copy_pieces(char (&dest)[5][5], const char (&src)[5][5]);
  int x;
  int y;


  char data[5][5];

};

#endif
