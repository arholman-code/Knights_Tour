/*******************************************************************
I understand and have abided by the UNCG Academic Integrity Policy:
Andrew Holman
********************************************************************
********************************************************************
CSC 330
Spring 2010
Dr. Fu
********************************************************************
The following program will implement the knight's tour problem 
for a board size and starting position chosen by the user.
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void iBoard(int **board, int xSize, int ySize);
void dBoard(int **board, int xSize, int ySize);
bool tour(int **board, int i, int j, int xSize, int ySize, int moveNum);
bool valid(int **board, int i, int j, int xSize, int ySize);

int main()
{
	//x and ySize are the board dimensions
	//i and j are the starting positions i = x, j = y
	int xSize, ySize, i, j;
	int **board;

	cout << "Knight's Tour " << endl;
 
	cout << "Enter the size of the board 'n' to set it n x n: ";
	cin >> xSize;
	ySize = xSize;
	
    do
    {
		cout << "\nEnter starting COLUMN in the range of 0-" << (xSize-1) << ":";
        cin >> j;
	}while ((j > (ySize-1)) || (j < 0) || (j >7));

    do
    {
		cout << "\nEnter starting ROW in the range of 0-" << (ySize-1) << ":";
        cin >> i;
	}while ((i > (xSize-1)) || (i < 0) || (i >7));


  
	// Display user input.
	cout << "\nYou have entered the following:\n\n";
    cout << "Rows: " << xSize << "; Columns: " << ySize << endl;
    cout << "Starting Position of\nX Coordinate: " << j << " :: Y Coordinate: " << i << endl;
  
  
    cout << "\n---------------------------------------------------" << endl << endl;

	//Create the board based on user input
    board = new int *[xSize];
	int **temp = board;
	for (int a = 0; a < xSize; a++)
    {
		*temp = new int[ySize];
        (temp)++;
    }

	//Initialize the board
    iBoard(board, xSize, ySize);
	//Display the empty board
    dBoard(board, xSize, ySize);

	// Run the tour algorithm...
    cout << endl << "---------------------------------------------------" << endl;
        
	//Output the solution that was found
    if (!tour(board, i, j, xSize, ySize, 1))
    {
		cout << "\n\nSolution found: " << endl << endl;
        dBoard(board, xSize, ySize);
    }

	//Output the failed solution and inform the user.
    else
    {
        cout << "\n\nNo solution found." << endl << endl;
        dBoard(board,xSize,ySize);
	}
        
	// Free up memory allocated for board.
    for(int a = 0; a < xSize; a++)
    {
		delete [] (*board);
        (board)++;
	}

    return 0;
}


//Function to initialize the board
void iBoard(int **board, int xSize, int ySize)
{
	int x, y;
  
    for (x = 0; x < xSize; x++)
    {
		for (y = 0; y < ySize; y++)
        {
			board[x][y] = 0;
        }
	}
}

//Function to display the board
void dBoard(int **board, int xSize, int ySize)
{
	int x, y;
  
	for (x = 0; x < xSize; x++)
    {
		for (y = 0; y < ySize; y++)
        {
			cout << setw(3) << board[x][y];
        }
		cout << endl;
    }
}
  
/*Checks for validity of possible moves based on the 
information input. */
bool valid(int **board, int i, int j, int xSize, int ySize)
{
	if ((i < 0) || (i >= xSize))
    {
		return false;
    }
  
    if ((j < 0) || (j >= ySize))
    {
		return false;
    }  
    
	if (board[i][j] != 0)
    {
        return false;
    }
  
    return true;
}
  
/*Runs through the possible moves based on coordinates given
in the book.
(i+2, j+1), (i+1, j+2), (i-1, j+2), (i-2, j+1),
(i-2, j-1), (i-1, j-2), (i+1, j-2), (i+1, j-1) */
bool tour(int **board, int i, int j, int xSize, int ySize, int moveNum)
{
	if (!valid(board, i, j, xSize, ySize))
    {
		return false;
    }
  
    board[i][j] = moveNum;
  
    if ((xSize * ySize) == moveNum)
    {
		return true;
    }
         
	cout << "::Tour::  Column: " << j << ", Row: " << i << ",   Move Number: " << moveNum << endl;
  
    if (!tour(board, (i - 1), (j - 2), xSize, ySize, (moveNum + 1)))
		if (!tour(board, (i - 2), (j - 1), xSize, ySize, (moveNum + 1)))
			if (!tour(board, (i - 2), (j + 1), xSize, ySize, (moveNum + 1)))
				if (!tour(board, (i - 1), (j + 2), xSize, ySize, (moveNum + 1)))
					if (!tour(board, (i + 1), (j + 2), xSize, ySize, (moveNum + 1)))
						if (!tour(board, (i + 2), (j + 1), xSize, ySize, (moveNum + 1)))
							if (!tour(board, (i + 2), (j - 1), xSize, ySize, (moveNum + 1)))
								if (!tour(board, (i + 1), (j - 2), xSize, ySize, (moveNum + 1)))
								//All moves are exhausted at this point.
									return false;
}