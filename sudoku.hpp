#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

    /// Creating a two dimensional array containing 72 entries
    /// There was a bug with [8][8] array so the 9th column was
    /// added (which cannot be manipulated by the player)
    int field [8][9] = {0};

class SudokuMinigame
{
    private:

        /// Adding the starting numbers to the grid,
        /// which is represented by the variable FIELD.
        void startingNumbers()
        {
            field [0][1]=6; field [0][3]=3; field [0][6]=8; field [0][8]=4; 
            field [1][0]=5; field [1][1]=3; field [1][2]=7; field [1][4]=9;
            field [2][1]=4; field [2][5]=6; field [2][6]=3; field [2][8]=7;
            
            field [3][1]=9; field [3][4]=5; field [3][5]=1; field [3][6]=2; field [3][7]=3; field [3][8]=8;
            field [5][0]=7; field [5][1]=1; field [5][2]=3; field [5][3]=6; field [5][4]=2; field [5][7]=4;
            
            field [6][0]=3; field [6][2]=6; field [6][3]=4; field [6][7]=1;
            field [7][4]=6; field [7][6]=5; field [7][7]=2; field [7][8]=3;
            field [8][0]=1; field [8][2]=2; field [8][5]=9; field [8][7]=8;
        }
        
        /// Test function
        /// Representing the full board, with the empty spaces.
        void emptyStartingNumbers()
        {
            field [0][0]=0; field [0][1]=6; field [0][2]=1; field [0][3]=0; field [0][4]=0; field [0][5]=0; field [0][6]=8; field [0][7]=0; field [0][8]=4;
            field [1][0]=5; field [1][1]=3; field [1][2]=7; field [1][3]=0; field [1][4]=9; field [1][5]=0; field [1][6]=0; field [1][7]=0; field [1][8]=0; 
            field [2][0]=0; field [2][1]=4; field [2][2]=0; field [2][3]=0; field [2][4]=0; field [2][5]=6; field [2][6]=3; field [2][7]=0; field [2][8]=7; 
            
            field [3][0]=0; field [3][1]=9; field [3][2]=0; field [3][3]=0; field [3][4]=5; field [3][5]=1; field [3][6]=2; field [3][7]=3; field [3][8]=8;  
            field [4][0]=0; field [4][1]=0; field [4][2]=0; field [4][3]=0; field [4][5]=0; field [4][6]=0; field [4][7]=0; field [4][8]=0; 
            field [5][0]=7; field [5][1]=1; field [5][2]=3; field [5][3]=6; field [5][4]=2; field [5][5]=0; field [5][6]=0; field [5][7]=4; field [5][8]=0; 
            
            field [6][0]=3; field [6][1]=0; field [6][2]=6; field [6][3]=4; field [6][4]=0; field [6][5]=0; field [6][6]=0; field [6][7]=1; field [6][8]=0; 
            field [7][0]=0; field [7][1]=0; field [7][2]=0; field [7][3]=0; field [7][4]=6; field [7][5]=0; field [7][6]=5; field [7][7]=2; field [7][8]=3; 
            field [8][0]=1; field [8][1]=0; field [8][2]=2; field [8][3]=0; field [8][4]=0; field [8][5]=9; field [8][6]=0; field [8][7]=8; field [8][8]=0;
        }

        /// Test function
        /// Filling all squares except one.
        /// Used to skip the solving when testing.
        void testCase()
        {
            field [0][0]=2; field [0][1]=6; field [0][2]=1; field [0][3]=3; field [0][4]=7; field [0][5]=5; field [0][6]=8; field [0][7]=9; field [0][8]=4;
            field [1][0]=5; field [1][1]=3; field [1][2]=7; field [1][3]=8; field [1][4]=9; field [1][5]=4; field [1][6]=1; field [1][7]=6; field [1][8]=2; 
            field [2][0]=9; field [2][1]=4; field [2][2]=8; field [2][3]=2; field [2][4]=1; field [2][5]=6; field [2][6]=3; field [2][7]=5; field [2][8]=7; 
            
            field [3][0]=6; field [3][1]=9; field [3][2]=4; field [3][3]=7; field [3][4]=5; field [3][5]=1; field [3][6]=2; field [3][7]=3; field [3][8]=8;  
            field [4][0]=8; field [4][1]=2; field [4][2]=5; field [4][3]=9; field [4][5]=3; field [4][6]=6; field [4][7]=7; field [4][8]=1; 
            field [5][0]=7; field [5][1]=1; field [5][2]=3; field [5][3]=6; field [5][4]=2; field [5][5]=8; field [5][6]=9; field [5][7]=4; field [5][8]=5; 
            
            field [6][0]=3; field [6][1]=5; field [6][2]=6; field [6][3]=4; field [6][4]=8; field [6][5]=2; field [6][6]=7; field [6][7]=1; field [6][8]=9; 
            field [7][0]=4; field [7][1]=8; field [7][2]=9; field [7][3]=1; field [7][4]=6; field [7][5]=7; field [7][6]=5; field [7][7]=2; field [7][8]=3; 
            field [8][0]=1; field [8][1]=7; field [8][2]=2; field [8][3]=5; field [8][4]=3; field [8][5]=9; field [8][6]=4; field [8][7]=8; field [8][8]=6; 
        }
    
        /// This is the layout of the game,
        /// The "\033[36m" is baically a way to colour the different
        /// Sections of the grid, for better visibility.
        /// Placing one element of FIELD in each section.
        /// If "\033[2J\033[1;1H" does not erase the previous board state,
        /// use "\033c" instead."\033c"<<
        void sudokuLayout()
        {
            std::cout <<"\033[35m"<< "C\\R| 0 | 1 | 2 || 3 | 4 | 5 || 6 | 7 | 8 |"<< endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+"<< endl;
            std::cout <<"\033[35m"<<" 0 "<< "\033[36m"<< "| "<< field[0][0] <<" | "<< field[0][1] <<" | "<< field[0][2] <<" |"<<"\033[33m"<<"| "<< field[0][3] <<" | "<< field[0][4] <<" | "<< field[0][5] <<" |"<<"\033[36m"<<"| "<< field[0][6] <<" | "<< field[0][7] <<" | "<< field[0][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 1 "<< "\033[36m"<< "| "<< field[1][0] <<" | "<< field[1][1] <<" | "<< field[1][2] <<" |"<<"\033[33m"<<"| "<< field[1][3] <<" | "<< field[1][4] <<" | "<< field[1][5] <<" |"<<"\033[36m"<<"| "<< field[1][6] <<" | "<< field[1][7] <<" | "<< field[1][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 2 "<< "\033[36m"<< "| "<< field[2][0] <<" | "<< field[2][1] <<" | "<< field[2][2] <<" |"<<"\033[33m"<<"| "<< field[2][3] <<" | "<< field[2][4] <<" | "<< field[2][5] <<" |"<<"\033[36m"<<"| "<< field[2][6] <<" | "<< field[2][7] <<" | "<< field[2][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            std::cout <<"\033[35m"<<"---"<< "\033[33m"<< "+---+---+---+"<<"\033[36m"<<"+---+---+---+"<<"\033[33m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 3 "<< "\033[33m"<< "| "<< field[3][0] <<" | "<< field[3][1] <<" | "<< field[3][2] <<" |"<<"\033[36m"<<"| "<< field[3][3] <<" | "<< field[3][4] <<" | "<< field[3][5] <<" |"<<"\033[33m"<<"| "<< field[3][6] <<" | "<< field[3][7] <<" | "<< field[3][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[33m"<< "+---+---+---+"<<"\033[36m"<<"+---+---+---+"<<"\033[33m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 4 "<< "\033[33m"<< "| "<< field[4][0] <<" | "<< field[4][1] <<" | "<< field[4][2] <<" |"<<"\033[36m"<<"| "<< field[4][3] <<" | "<< field[4][4] <<" | "<< field[4][5] <<" |"<<"\033[33m"<<"| "<< field[4][6] <<" | "<< field[4][7] <<" | "<< field[4][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[33m"<< "+---+---+---+"<<"\033[36m"<<"+---+---+---+"<<"\033[33m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 5 "<< "\033[33m"<< "| "<< field[5][0] <<" | "<< field[5][1] <<" | "<< field[5][2] <<" |"<<"\033[36m"<<"| "<< field[5][3] <<" | "<< field[5][4] <<" | "<< field[5][5] <<" |"<<"\033[33m"<<"| "<< field[5][6] <<" | "<< field[5][7] <<" | "<< field[5][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[33m"<< "+---+---+---+"<<"\033[36m"<<"+---+---+---+"<<"\033[33m"<<"+---+---+---+" << endl;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 6 "<< "\033[36m"<< "| "<< field[6][0] <<" | "<< field[6][1] <<" | "<< field[6][2] <<" |"<<"\033[33m"<<"| "<< field[6][3] <<" | "<< field[6][4] <<" | "<< field[6][5] <<" |"<<"\033[36m"<<"| "<< field[6][6] <<" | "<< field[6][7] <<" | "<< field[6][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 7 "<< "\033[36m"<< "| "<< field[7][0] <<" | "<< field[7][1] <<" | "<< field[7][2] <<" |"<<"\033[33m"<<"| "<< field[7][3] <<" | "<< field[7][4] <<" | "<< field[7][5] <<" |"<<"\033[36m"<<"| "<< field[7][6] <<" | "<< field[7][7] <<" | "<< field[7][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" << endl;
            std::cout <<"\033[35m"<<" 8 "<< "\033[36m"<< "| "<< field[8][0] <<" | "<< field[8][1] <<" | "<< field[8][2] <<" |"<<"\033[33m"<<"| "<< field[8][3] <<" | "<< field[8][4] <<" | "<< field[8][5] <<" |"<<"\033[36m"<<"| "<< field[8][6] <<" | "<< field[8][7] <<" | "<< field[8][8] <<" |" << endl;
            std::cout <<"\033[35m"<<"---"<< "\033[36m"<< "+---+---+---+"<<"\033[33m"<<"+---+---+---+"<<"\033[36m"<<"+---+---+---+" <<"\033[0m"<< endl;
        }

        /// Function to print the rules of sudoku
        void rulesOfSudoku()
        {
                cout <<"\033[35m"<< " The objective is to fill the grid so that each row, each column, and each of the nine 3x3 boxes \n contains the digits from 1 to 9. Remember thare canrow be repeating digits in any of the rows, columns and 3 by 3 boxes. \n Good Luck!" <<"\033[0m"<< endl;
        }

        /// Function that checks if the user input for COLUMN is correct
        /// If not, returns a message for the player.
        int inputColumnChecker(string column)
        {
            bool validColumn = true; 
            if (column.empty())
            {
                return -1;
            }
            for (int i = 0; i < column.length(); i++)
                if (isdigit(column[i]) == false)
                validColumn = false;
            if (validColumn)
            {
                if(stoi(column)<0 || stoi(column)>8)
                {
                    return -1;
                }
                return stoi(column);
            }
            else
            {
                return -1;
            }
        }

        /// Function that checks if the user input for ROW is correct
        /// If not, returns a message for the player.
        int inputRowChecker(string row)
        {
            bool validRow = true;
            if (row.empty())
            {
                return -1;
            }
            for (int i = 0; i < row.length(); i++)
                if (isdigit(row[i]) == false)
                validRow = false;
            if (validRow)
            {
                if(stoi(row)<0 || stoi(row)>8)
                {
                    return -1;
                }
                return stoi(row);
            }
            else
            {
                return -1;
            }
        }

        /// Function that checks if the user input for NUMBER IN GRID is correct
        /// If not, returns a message for the player.
        int inputPlayerChecker(string playerInput)
        {
            bool validInput = true;
            if (playerInput.empty())
            {
                return -1;
            }
            for (int i = 0; i < playerInput.length(); i++)
                if (isdigit(playerInput[i]) == false)
                validInput = false;
            if (validInput)
            {    
                if(stoi(playerInput)>0 && stoi(playerInput)<=9)
                {
                    return stoi(playerInput);
                }
                return -1;
            }
            else
            {
                std::cout << "Please enter a valid number!" << endl;
                return -1;
            }    
        }

        /// Function that checks the finished grid
        /// It is called only when the FIELD is filled 
        /// With numbers different than 0's.
        bool gameFinishCheck(bool won)
        {
            int sum = 0;
            for (int r=0; r<9; r++)
            {
                for (int c=0; c<9; c++)
                {
                    /// This loop collects all the numbers in the grid and adds them
                    sum += field[c][r];
                }
            }
            /// Checking if everything is correct, the sum of the cells
            /// Should be exactly 405, which is 9*(1+2+3+4+5+6+7+8+9)
            if (sum != 405) 
            {
                std::cout <<"\033[1m\033[31m"<< "YOU FILLED THE BOARD, BUT IT SEEMS LIKE YOU MADE A MISTAKE, TRY AGAIN/// gamefinishcheck" <<"\033[0m"<< endl;
                won = false;
                return won;
            }
            else
            {
                std::cout << "Congratulations! You finished the Sudoku!" <<"\033[0m"<< std::endl;
                won = true;
                return won;
                /// Returns the won variable (which was false at the beginning),
                /// Which breaks the loop and then game ends
            }
        }

        /// Initializing a variable containing the board size.
        int boardSize = 8;

        /// Function that checks if the whole board is filled with numbers.
        /// If not, the value of boardFull is set to false and returned.
        bool isBoardFull(bool boardFull)
        {
            for (int i=0; i<boardSize; ++i)
            {                                        /// This part of the code took me the longest to debug but,
                for (int j=0; j<boardSize; ++j)      /// With a little bit of help from David Croft, who suggested
                {                                    /// To flip my logic arround (searching for numbers in grid
                    if (field[i][j] == 0)            /// not for the 0's) I managed to get it working
                        return boardFull = false;
                }
            }
            return boardFull = true;
        }

        /// Function that checks if the game was played before.
        /// Called at the start of the while loop.
        /// If the game was played before, this function clears out
        /// the field and sets a new one.
        void ifPlayed(bool isItPlayed)
        {
            if (isItPlayed)
            {
                std::cout << "do we even go here?" << std::endl;//////////////////////////////////////////////////////////////////////////////////////////////////////////
                isItPlayed = false;
                
                memset(field, 0, 8*9*(sizeof(int)));
                //////////////////////
                // field [8][9] = {0};
                //////////////////////
                // for (int i=0; i<8; ++i)
                // {
                //         for (int j=0; j<8; ++j)
                //         {
                //             field[i][j] = 0;           
                //         }
                // }
                testCase();
                sudokuLayout();
                emptyPrint(2);
                std::cout << "do we go here?" << std::endl;///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                std::cout << field << std::endl;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                std::cout <<"\033[1m\033[31m"<< "YOU FILLED THE BOARD, BUT IT SEEMS LIKE YOU MADE A MISTAKE, TRY AGAIN/// this is the start func" <<"\033[0m"<< std::endl;
                std::cout << field << std::endl; /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            }
            else
            {
                std::cout << "else statement in start func" << std::endl;/////////////////////////////////////////////////////////////////////////////////////////////////
                testCase();
                sudokuLayout();
                emptyPrint(2);
                rulesOfSudoku();
            }
        }

        /// Function that takes number as argument
        /// and prints out that many empty lines
        void emptyPrint(int number)
        {
            for (int i = 0; i < number; i++)
            {
                std::cout << std::endl;
            }
        }

        /// Function that asks for column input.
        /// Checks if the input is valid.
        /// Returns the valid input only.
        string askingForColumn(string inputColumn)
        {
            /// Asking for a column, checking if the input is acceptable.
            std::cout << "\033[1m" <<"Column:" << endl;
            std::getline(cin,inputColumn);
            int column = inputColumnChecker(inputColumn);

            while (column == -1)
            {
                std::cout << "\033[1m" <<"Please enter a valid column:" << endl;
                std::getline(cin,inputColumn);
                column = inputColumnChecker(inputColumn);
            }

            return inputColumn;
        }

        /// Function that asks for row input.
        /// Checks if the input is valid.
        /// Returns the valid input only.
        string askingForRow(string inputRow)
        {
            /// Asking for a row, checking if the input is acceptable.
            std::cout << "\033[1m" <<"Row:" << endl;
            std::getline(cin,inputRow);
            int row = inputRowChecker(inputRow);

            while (row == -1)
            {
                std::cout << "\033[1m" <<"Please enter a valid row:" << endl;
                std::getline(cin,inputRow);
                row = inputRowChecker(inputRow);
            }

            return inputRow;
        }   

        /// Function that asks the player for a number.
        /// Checks if the number is valid.
        /// Returns the valid number only.
        string playerInput(string toBeTestedPlayerInputNumber)
        {
            /// Asking for a number, checking if the input is acceptable.
            std::cout << "\033[1m" <<"Number:"<<endl;
            std::getline(cin, toBeTestedPlayerInputNumber);
            int playerInput = inputPlayerChecker(toBeTestedPlayerInputNumber);

            while (playerInput == -1)
            {
                std::cout << "\033[1m" <<"please enter a valid number:"<<endl;
                std::getline(cin, toBeTestedPlayerInputNumber);
                playerInput = inputPlayerChecker(toBeTestedPlayerInputNumber);  
            }

            return toBeTestedPlayerInputNumber;
        }

    public:

        /// Function that starts the game
        /// A while loop is used to keep the game running
        /// until the function "GameFinishCheck" returns true
        bool startSudoku(bool isItPlayed)
        {
            ifPlayed(isItPlayed);
            
            string toBeTestedPlayerInputNumber;      /// Number that player wants to insert into the grid.
            string inputColumn;                      /// ID if the COLUMN that the answer needs to be inserted.
            string inputRow;                         /// ID of the ROW that the answer needs to be inserted.
            bool won = false;
            bool boardFull = false;
            int counter = 1;

            while (won == false)
            {
                std::cout << "start func While loop iteration:"<< counter++ << std::endl;/////////////////////////////////////////////////////////////////////////////////
                emptyPrint(2);

                inputColumn = askingForColumn(inputColumn);
                inputRow = askingForRow(inputRow);
                toBeTestedPlayerInputNumber = playerInput(toBeTestedPlayerInputNumber);

                /// Making a simple check if the place given by the player is
                /// Taken by another integer, if it is empty (A.K.A.= 0) it
                /// Will place it in the given box
                if (field[stoi(inputColumn)][stoi(inputRow)] == 0)
                {
                    field[stoi(inputColumn)][stoi(inputRow)] = stoi(toBeTestedPlayerInputNumber);
                    sudokuLayout();

                    boardFull = isBoardFull(boardFull);
                    std::cout << "boardfull: " << boardFull << std::endl;//////////////////////////////////////////////////////////////////
                    if (boardFull == true)
                    {
                        won = gameFinishCheck(won);
                    }
                }
                else
                {
                    /// If the selected box in which the player wants to put their
                    /// Number is taken, this else statement lets the player know
                    /// That this action is illegal
                    sudokuLayout();
                    std::cout <<"\033[1m\033[31m"<< "Wrong cell! This cell has number in it already. Please try again:" <<"\033[0m"<< endl;
                }
            }
            return won;
        }
};
