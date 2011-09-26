/*
    Copyright 2011 Sean Mooney <bable4@gmail.com>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


#include "gameboard.h"

GameBoard::GameBoard(int width, int height)
{
  this->width = width;
  this->height = height;
  this->data = new cell[width * height];
  this->swapdata = new cell[width * height];

  //init all to 0
  const int numCells = width * height;
  for(int i = 0; i < numCells; i++){
    data[i] = DEAD;
    swapdata[i] = DEAD;
  }
}

GameBoard::~GameBoard()
{
  delete [] data;
}

void GameBoard::swap(){
    cell *tmp;
    tmp = data;
    data = swapdata;
    swapdata = tmp;
}

void GameBoard::stepSystem(){
    int x, y;
    int count;
    int value;

    for(x = 0; x < width; x++){
        for(y = 0; y < height; y++){
            count = numNeighbors(x, y);    
            value = getCell(x, y);
            
            if( value == ALIVE ) {
                if( count < 2 || count > 3 ){
                    putCellSwap(x, y, DEAD);
                }else{
		    putCellSwap(x, y, value);
		}
            } 
            else {
                if( count == 3 ){
                    putCellSwap(x, y, ALIVE);
                }else{
		    putCellSwap(x, y, value);
		}
            }
        }
    }

    swap();
}

int GameBoard::numNeighbors(int x, int y){
    int count = 0;
    int x1, y1;
    
    //left
    if(x > 0){
      x1 = x-1;
      //up
      if(y > 0){
	count += getCell(x1, y - 1);
      }
      
      count += getCell(x1, y);
      
      if( y < (height-1) ){
	count += getCell(x1, y+1);
      }
    }
    
    //up
    if(y > 0){
      count += getCell(x, y - 1);
    }
    
    //right
    if(x < width - 1){
      x1 = x+1;
      //up
      if(y > 0){
	count += getCell(x1, y - 1);
      }
      
      count += getCell(x1, y);
      
      if( y < (height-1) ){
	count += getCell(x1, y+1);
      }
    }
    
    //down
    if( y < (height-1) ){
	count += getCell(x, y+1);
    }
    
    return count;
}
