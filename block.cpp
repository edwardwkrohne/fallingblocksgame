#include "block.h"

using namespace std;

void rotateCW(char (&block)[5][5]) {


}

void printBlock(const char (&block)[5][5], ostream& out) {
    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            out << block[i][j] << " ";
        }
        out << endl;
    }
}
