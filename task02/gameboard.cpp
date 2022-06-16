#include <iostream>
#include "gameboard.h"

/**
 * constructor
 * Gameboard
 * (0) (1) (2)
 * (3) (4) (5)
 * (6) (7) (8)
 * allocate and intialize with 0s an array of size 3x3
 * @param int size
 */
GameBoard::GameBoard(int size){
	this->size = size;
	board = (int*)calloc(size*size, sizeof(int));
	winner = 0;	
}

/**
 * deconstructor Gameboard
 * deallocate the array
 */
GameBoard::~GameBoard(){
	free(board);
}


/**
 * insert player sign in coordinate (x, y)
 * @param playernum (1 or 2, 0 if it's free)
 * @param x (row number)
 * @param y (column number)
 */
void GameBoard::insert(int playernum, int x, int y){
	board[x*3 + y] = playernum;
}

/**
 * check if space with coordinate x, y is free
 * @param x (row number)
 * @param y (column number)
 * @return false if (x, y) not free
 * @return true, if (x, y) is free
 */
bool GameBoard::isFree(int x, int y){
	if(board[x*3+y])
		return false;
	return true;
}

/**
 * check if there is a winner
 * check diagonally, horizontally and vertically three fields in a row
 * if there are 3 fields in a row with the same player number set winner with that player number
 */
void GameBoard::evaluate(){
	if((board[0] == board[4]) && (board[4] == board[8])){
		if (board[0] == 1)
			winner = 1;
		if (board[0] == 2)
			winner = 2;
	}
	else if ((board[2] == board[4]) && (board[4] == board[6])){
		if (board[2] == 1)
			winner = 1;
		if (board[2] == 2)
			winner = 2;
	}
	else {
		for(int i = 0; i < 3; i++){
			if((board[3*i] == board[3*i + 1]) && (board[3*i + 1] == board[3*i + 2])){
				if (board[3*i] == 1){
					winner = 1;
					break;
				}
				if (board[3*i] == 2){
					winner = 2;
					break;
				}
			}
			if((board[i] == board[3 + i]) && (board[3 + i] == board[6 + i]) ){
				if (board[i] == 1){
					winner = 1;
					break;
				}
				if (board[i] == 2){
					winner = 2;
					break;
				}
			}
		}
	}
} 

/**
 * give the winner of the game
 * @return winner of the game
 */
int GameBoard::getWinner(){
	return winner;
}

/**
 * check if there are still available moves in the gameboard 
 * @return true, if there are
 * @return false, if not
 */
bool GameBoard::hasAvailableMoves(){
	for (int i = 0; i < 9; i++){
		if(board[i] == 0)
			return true;
	}
	return false;
}

/**
 * get Symbol of the x. element of the gameboard array
 * @return X, if it's the first player
 * @return O, if it's the second player
 * @return empty space, if it's empty
 */
char GameBoard::getSymbol(int x) {
	if(board[x]== 1)	
		return 'X';
	else if (board[x]== 2)
		return 'O';
	else 
		return ' ';
}


/**
 * print the gameboard out like this
 *     1   2   3
 *   -------------
 * 1 | 1 | 2 | 3 |
 *   -------------
 * 2 | 4 | 5 | 6 |
 *   -------------
 * 3 | 7 | 8 | 9 |
 * @param ostream o
 * @param GameBoard gb
 * @return ostream o, after modifying it so that it prints out the gameboard
 */
std::ostream& operator<<(std::ostream& o, GameBoard& gb){
	
	
	o<<"    1   2   3  \n";
	o<<"  -------------"<<std::endl	;       
    o<<"1 | "<<gb.getSymbol(0) <<" | "<< gb.getSymbol(1) <<" | "<< gb.getSymbol(2) <<" |"<<std::endl;
    o<<"  -------------"<<std::endl;
    o<<"2 | "<< gb.getSymbol(3) <<" | "<< gb.getSymbol(4) <<" | "<< gb.getSymbol(5) <<" |"<<std::endl;
    o<<"  -------------"<<std::endl;
    o<<"3 | "<< gb.getSymbol(6) <<" | "<< gb.getSymbol(7) <<" | "<< gb.getSymbol(8) <<" |"<<std::endl;
    
    return o;
}
