#include "block.h"

using namespace std;

void rotateCW(char (&block)[5][5]) {
    char new_block[5][5];

    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            new_block[j][4-i] = block[i][j];
        }
    }

    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            block[i][j] = new_block[i][j];
        }
    }
}

void printBlock(const char (&block)[5][5], ostream& out) {
    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            out << block[i][j] << " ";
        }
        out << endl;
    }
}
