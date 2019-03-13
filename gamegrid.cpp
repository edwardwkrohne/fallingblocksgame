#include "gamegrid.h"

GameGrid::GameGrid(const char (&copy)[20][10]){

    for (int i =0; i < 20; i++){
        for (int j =0; j < 10; j++){
            data[i][j] = copy[i][j] ;
        }
    }
}


int GameGrid::lineComplete(){
    bool allStarsSoFar;

    for(int y = 19;y >= 0;y--){
        allStarsSoFar = true;
        for(int x = 0;x < 10;x++){
            if (!(data[y][x] == '*') ){
                allStarsSoFar = false;
                break;
            }
        }
        if (allStarsSoFar == true){
            return y;
        }
    }
    return -1;
}

char GameGrid::getData(int y, int x){
    return data[y][x];
}

void GameGrid::shift(int y){
    for (int i = y; i > 0;i--){
        for(int j = 0; j< 10; j++){
            data[i][j] = data[i-1][j];
        }
    }
    for(int j = 0; j< 10; j++){
        data[0][j] = ' ';
    }
}
