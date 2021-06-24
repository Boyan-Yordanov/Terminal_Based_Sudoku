#include  "sudoku.hpp"

int main()
{
/////////////////////////////////////////
/// Initialising a object to call the ///
/// Function that runs the mini game  ///
/////////////////////////////////////////
   SudokuMinigame a;
   while (!a.startSudoku())
   {
      a.startSudoku();
   }
}