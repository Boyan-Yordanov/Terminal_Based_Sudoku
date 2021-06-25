#include <iostream>
using namespace std;

    /// Creating a two dimensional array containing 90 entries
    /// There was a bug with [8][8] array so I added the 9th
    /// Column (which cannot be manipulated by the player)
    int field [8][9];

class SudokuMinigame
{
    private:

        /// Adding the starting numbers to the grid.
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
        
        /// Yet another test case. It represents the full board, with the empty spaces
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

        /// This is a simple test case, fills all the
        /// Squares except one, so I can showcase the ending.
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
        /// I am puting one array in each empty square.
        /// If You are not using codio put "\033[2J\033[1;1H" infront.
        void sudokuLayout() 
        {
            std::cout <<"\033c"<<"\033[35m"<< "C\\R| 0 | 1 | 2 || 3 | 4 | 5 || 6 | 7 | 8 |"<< endl;
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

        /// The next function will print the rules of
        /// Sudoku and it is also coloured with
        /// The uppermentioned method.
        void rulesOfSudoku()
        {
                cout <<"\033[35m"<< " The objective is to fill the grid so that each row, each column, and each of the nine 3x3 boxes \n contains the digits from 1 to 9. Remember thare canrow be repeating digits in any of the rows, columns and 3 by 3 boxes. \n Good Luck!" <<"\033[0m"<< endl;
        }

        /// This function checks if the user input for column is correct
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

        /// This function checks if the user input for row is correct
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

        /// This function checks if the user input for NUMBER IN GRID is correct
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

        /// This function checks the finished grid
        /// It is called only when the grid is filled 
        /// With numbers different than 0's.
        bool gameFinishCheck(bool won)
        {
            int sum=0;
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
                std::cout <<"\033[1m\033[31m"<< "YOU FILLED THE BOARD, BUT IT SEEMS LIKE YOU MADE A MISTAKE, TRY AGAIN <3" <<"\033[0m"<< endl;
                return false;
                /// At this point the game should probably restart or something, but
                /// I'm going to give an easy sudoku hoping for a solve without any mistakes
            }
            else
            {
                std::cout << "Congratulations! You finished the Sudoku!" <<"\033[0m"<< std::endl;
                return true;     
                /// Returns the won variable (which was false at the beginning),
                /// Which breaks the loop and then game ends
            }
        }

        /// This function checks if the whole board is filled with numbers
        /// If not, the value of boardFull is returned and set to false.
        bool isBoardFull(bool boardFull)
        {
            for (int i=0; i<8; ++i)
            {                                        /// This part of the code took me the longest to debug but,
                for (int j=0; j<8; ++j)              /// With a little bit of help from David Croft, who suggested
                {                                    /// To flip my logic arround (searching for numbers in grid
                    if (field[i][j] == 0)            /// not for the 0's) I managed to get it working
                        return boardFull = false;
                }
            }
            return boardFull = true;
        }

        /// This is the main fucntion for this .h file, the name speaks for itself
        /// A basic while loop is used to check whether the game has to keep
        /// Calling all the other functions in this .h file. When the game is
        /// Complete it returns the boolean won to the main function of the text
        /// Adventure Game.
    public:

        bool startSudoku(bool isItPlayed)
        {
        
            if (!isItPlayed)
            {
                startingNumbers();
                testCase();
                sudokuLayout();
                std::cout<<endl;    
                std::cout<<endl;   
                rulesOfSudoku();  
            }
            else
            {
                isItPlayed = false;
                fill(field[0], field[0] + 8 * 9, 0);
                emptyStartingNumbers();
                sudokuLayout();
                std::cout<<endl;
                std::cout<<endl;
                std::cout << "You would have to try again, you made a mistake while trying to fill the board!" << std::endl;
            }
            string toBeTestedPlayerInputNumber;       /// Number that player wants to insert into the grid.
            string input_column;                      /// ID if the columnl that the answer needs to be inserted.
            string input_row;                         /// ID of the row that the answer needs to be inserted.
            bool won = false;
            bool boardFull = false;

            while (won == false)
            {
                std::cout<<endl;
                std::cout<<endl;

                /// Asking for a column, checking if the input is acceptable.
                std::cout << "\033[1m" <<"Column:" << endl;
                std::getline(cin,input_column);
                int column = inputColumnChecker(input_column);
                while (column == -1) 
                {
                    std::cout << "\033[1m" <<"Please enter a valid column:" << endl;
                    std::getline(cin,input_column);
                    column = inputColumnChecker(input_column);
                }

                /// Asking for a row, checking if the input is acceptable.
                std::cout << "\033[1m" <<"Row:" << endl;
                std::getline(cin,input_row);
                int row = inputRowChecker(input_row);
                while (row == -1)
                {
                    std::cout << "\033[1m" <<"Please enter a valid row:" << endl;
                    std::getline(cin,input_row);
                    row = inputRowChecker(input_row);
                }

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

                /// Making a simple check if the place given by the player is
                /// Taken by another integer, if it is empty (A.K.A.= 0) it
                /// Will place it in the given box
                if (field[stoi(input_column)][stoi(input_row)] == 0)
                {
                    field[stoi(input_column)][stoi(input_row)] = stoi(toBeTestedPlayerInputNumber);
                    sudokuLayout();

                    /// Here we need to check if the whole board is filled with
                    /// Numbers(isBoardFull function), if it is, then the
                    /// gameFinishCheck is run, where the validity of the answers
                    /// Given by the player is taken. If the board is filled 
                    /// Correctly, then the boolean won is set to true,
                    /// Which breaks the While Loop
                    boardFull = isBoardFull(boardFull);
                    if (boardFull == true)
                    {
                        won = gameFinishCheck(won);
                        return won;
                    }
                    else 
                    {
                        return won;
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
