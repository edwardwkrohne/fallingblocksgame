#include <iostream>

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

void rotateCW(char (&block)[5][5]);
void rotateCCW(char (&block)[5][5]);

void printBlock(const char (&block)[5][5], std::ostream& out = std::cout);

#endif // BLOCK_H_INCLUDED
