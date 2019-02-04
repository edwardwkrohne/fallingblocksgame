// Some sort of brief comment here
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

class GameGrid;

class Block {
public:
    //constructor
    Block(int y, int x, int pieceId );


    char get(int row, int col);

    bool checkCollision(GameGrid& grid);

    void rotateCW();
    void rotateCCW();

    void print(std::ostream& out);
private:
    void copy_pieces(char (&dest)[5][5], const char (&src)[5][5]);
    int x;
    int y;


    char data[5][5];

};

#endif
