#include <iostream>
#include "gameboard.h"

void loadInitState(GameBoard *gb, int centerX, int centerY){
  gb->putCell(centerX - 1, centerY + 0, ALIVE);
  gb->putCell(centerX + 0, centerY - 1, ALIVE);
  gb->putCell(centerX + 1, centerY - 1, ALIVE);
  gb->putCell(centerX + 1, centerY + 0, ALIVE);
  gb->putCell(centerX + 1, centerY + 1, ALIVE);
}

int main(int argc, char **argv) {
    int w = 10;
    int h = 10;
    GameBoard *gb = new GameBoard(w, h);
    char c;
    
    loadInitState(gb, 4, 4);
    int i = 0;

    while(i < 20) {
      for(int i = 0; i < w; i++){
	for(int j = 0; j < h; j++){
	  std::cout << gb->getCell(i, j) << " ";
	}
	std::cout << std::endl;
      }
      //std::cin >> c;
      std::cout << "-------------------------------------------" << std::endl;
      gb->stepSystem();
      i++; 
    }
    
    delete gb;
    return 0;
}
