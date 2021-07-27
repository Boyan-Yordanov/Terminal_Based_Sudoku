#include  "sudoku.hpp"

int main()
{

   /// Initialising a object to call the
   /// Function that runs the mini game 

   bool isItPlayed = false;
   SudokuMinigame instance;
   bool won = false;

   while (42)
   { 
      won = instance.startSudoku(isItPlayed);
      if (won)
      {
         break;
      }
      else
      {
         isItPlayed = true;
      }
   }
};
