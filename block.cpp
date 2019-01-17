#include "block.h"

using namespace std;


void rotateCW(char (&block)[5][5]) {
  char temp_block[5][5];
  for (int i =0;i < 5; i++){
    for (int j =0; j < 5; j++){
      temp_block[j][4-i]=  block[i][j] ;
    }
  }
  for (int i =0;i < 5; i++){
    for (int j =0; j < 5; j++){
      block[i][j] = temp_block[i][j] ;
    }
  }
}

void rotateCCW(char (&block)[5][5]) {
//create a tempoary array here bc u want it destroyed after fuction is done
  char temp_block[5][5];
//rotating block to a temp block
  for (int i =0;i < 5; i++){
    for (int j =0; j < 5; j++){
      temp_block[4-j][i]=  block[i][j] ;
    }
  }
//copying tempblock to block
  for (int i =0;i < 5; i++){
    for (int j =0; j < 5; j++){
      block[i][j] = temp_block[i][j] ;
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
