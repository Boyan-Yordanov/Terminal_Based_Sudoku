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
      std::cout << "calling instance" << std::endl;
      won = instance.startSudoku(isItPlayed);
      std::cout << "won is: "<< won << std::endl;
      if (won)
      {
         break;
      }
      else
      {
         isItPlayed = true;
         std::cout << "set played to true" << std::endl;
         std::cout << isItPlayed << std::endl;
      }
   }
};
