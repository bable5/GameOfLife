#include <iostream>
#include "gameboard.h"

int main(int argc, char **argv) {
    GameBoard *gb = new GameBoard(5, 5);
    
    
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        std::cout << gb->getCell(i, j) << " ";
      }
      std::cout << std::endl;
    }
    
    delete gb;
    return 0;
}
