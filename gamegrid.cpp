#include "gamegrid.h"

GameGrid::GameGrid(const char (&copy)[20][10]){

    for (int i =0; i < 20; i++){
        for (int j =0; j < 10; j++){
            data[i][j] = copy[i][j] ;
        }
    }
}
