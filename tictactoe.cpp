/*
	Tic Tac Toe Game

	Programming Practice

	Despina Patronas
	11/24/2018
*/

#include <iostream>
#include <string>

using namespace std;

const int GridColumns = 3;
const int GridRows 	  = GridColumns;
const int GridSize	  = GridColumns * GridRows;

void printBoard( char gameGrid [GridRows][GridColumns] );
void initializeBoard( char gameGrid [GridRows][GridColumns] );
void getPlayerInput ( char gameGrid [GridRows][GridColumns] , char currentPlayer );
bool winCondition ( char gameGrid [GridRows][GridColumns] );
char getNextPlayer (char currentPlayer);
bool playAgainCheck();
void play();

int main() {

	cout << "Welcome to Tic-Tac-Toe. Game ends in a draw after " << GridSize <<  " turns. " << endl << endl;

	do
	{
		play();
	} while( playAgainCheck() == true );

	cout << "Copyright Despina Patronas 2019" << endl;

	return 0;
}

void play()
{
	char gameGrid[GridRows][GridColumns];
	char currentPlayer = 'X';
	int index = 0;
	bool win = false;

	initializeBoard(gameGrid);
	printBoard(gameGrid);

	while( index < GridSize )
	{
		getPlayerInput ( gameGrid, currentPlayer );
		printBoard     ( gameGrid );

		win = winCondition ( gameGrid );
		if ( win == true ) {
			cout << currentPlayer << " has won the game!" << endl;
			break;
		}

		currentPlayer = getNextPlayer (currentPlayer);
		index++;
	}

	if(win == false) {
		cout << "Tie!" << endl;
	}
}

bool winCondition ( char grid[3][3] ) {

	// row, column check
	for(int i = 0; i < 3; i++)
	{
		if( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] )
		{
			return true;
		}

		if( grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] )
		{
			return true;
		}
	}

	// diagonal check
	if ( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] )
		return true;

	// diagnoal check
	if ( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] )
		return true;

	// no winnner
	return false;
}

void initializeBoard( char gameGrid [GridRows][GridColumns] )
{
	
}

void printBoard( char grid [GridRows][GridColumns] ) {
	for (int r = 0; r < GridRows; r++) { 
	  for (int c = 0; c < GridColumns; c++) { 
		cout << grid[r][c] << " " ;
	  }
		cout << endl;
	}
}

//player turn
void getPlayerInput ( char grid [GridRows][GridColumns] , char currentPlayer ) {
	int location;

	while (1)
	{
		cout << "Player " << currentPlayer << ": Please indicate the number of your tile on the grid to put your mark: ";
		cin >> location;

		if( location < 1 || location > GridSize )
		{
			cout << "Location is out of bound, please choose another one" << endl;
			continue;
		}

		// adjust location to start from zero
		location = location - 1;

		// gridIndex = rowIndex * NumberOfCols + colIndex
		int row = location / GridColumns;
		int col = location - row * GridColumns;

		if( grid[row][col] == 'X' || grid[row][col] == 'O' )
		{
			cout << "Location is occupied, please choose another one" << endl;
			continue;
		}

		grid[row][col] = currentPlayer;
		break;
	}
}

char getNextPlayer (char currentPlayer) {
	if (currentPlayer == 'X')
	{
		return 'O';
	}
	else 
	{
		return 'X';
	}
}

bool playAgainCheck (){
	string reset;
	cout << "Would you like to play again? Enter Y for yes." << endl;
	cin >> reset;

	if (reset == "Y"){
	  return true;
	}

	return false;
}
