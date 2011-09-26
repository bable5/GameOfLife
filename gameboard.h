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


#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define ALIVE 1;
#define DEAD 0;

typedef int cell;

class GameBoard
{

private:
  cell *data;
  cell *swapdata;
  int width;
  int height;
  int cellLoc(int x, int y){ return x*width + y; }
  void putCell(int x, int y, cell newData, cell *dest){ dest[cellLoc(x, y)] = newData; }
  void putCellSwap(int x, int y, cell newData){putCell(x, y, newData, swapData)}
  private void swap();
public:
    GameBoard(int width, int height);
    virtual ~GameBoard();
    void putCell(int x, int y, cell newData){ putCell(x, y, newData, data)}
    cell getCell(int x, int y){ return  data[cellLoc(x, y)]; }
    void putCell(int x, int y, cell newData){ data[cellLoc(x, y)] = newData; }
    
    void stepSystem();
};

#endif // GAMEBOARD_H
