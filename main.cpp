#include  "sudoku.hpp"

int main()
{
   /////////////////////////////////////////
   /// Initialising a object to call the ///
   /// Function that runs the mini game  ///
   /////////////////////////////////////////
   bool isItPlayed = false;
   SudokuMinigame a;
   while (!a.startSudoku(isItPlayed))
   {
      isItPlayed = true;
      a.startSudoku(isItPlayed);
   }
};
