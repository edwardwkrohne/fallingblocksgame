#include "piece.h"

using namespace std;

const char piece_L[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', '*', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

const char piece_J[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', '*', '*', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

const char piece_I[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' '}
};

const char piece_T[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', '*', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

const char piece_O[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', '*', ' '},
    {' ', ' ', '*', '*', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

const char piece_S[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', '*', '*', ' '},
    {' ', ' ', ' ', '*', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

const char piece_Z[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', '*', '*', ' ', ' '},
    {' ', '*', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

Block::Block(int _y, int _x, int pieceId) {
    y = _y;
    x = _x;

    switch (pieceId) {
        case 0:
        copy_pieces(data, piece_L);
        break;
        case 1:
        copy_pieces(data, piece_J);
        break;
        case 2:
        copy_pieces(data, piece_I);
        break;
        case 3:
        copy_pieces(data, piece_T);
        break;
        case 4:
        copy_pieces(data, piece_O);
        break;
        case 5:
        copy_pieces(data, piece_S);
        break;
        case 6:
        copy_pieces(data, piece_Z);
        break;
    }
}

void Block::copy_pieces(char (&dest)[5][5], const char (&src)[5][5]) {
    for (int i; i < 5; i++){
        for (int j; j < 5; j++){
            dest[i][j] = src[i][j];
        }
    }
}

char Block::get(int row, int col) {
    return data[row][col];
}


void Block::rotateCW() {
    char temp_block[5][5];
    for (int i =0;i < 5; i++){
        for (int j =0; j < 5; j++){
            temp_block[j][4-i]=  data[i][j] ;
        }
    }
    for (int i =0;i < 5; i++){
        for (int j =0; j < 5; j++){
            data[i][j] = temp_block[i][j] ;
        }
    }
}

void Block::rotateCCW() {
    //create a tempoary array here bc u want it destroyed after fuction is done
    char temp_block[5][5];
    //rotating block to a temp block
    for (int i =0; i < 5; i++){
        for (int j =0; j < 5; j++){
            temp_block[4-j][i]=  data[i][j] ;
        }
    }
    //copying tempblock to block
    for (int i =0; i < 5; i++){
        for (int j =0; j < 5; j++){
            data[i][j] = temp_block[i][j] ;
        }
    }
}

void Block::print(ostream& out) {
    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            out << data[i][j] << " ";
        }
        out << endl;
    }
}
