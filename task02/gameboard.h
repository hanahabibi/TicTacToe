#include <iostream>
#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

/**
 * defintion of the class GameBoard and its variables and methods
 */
class GameBoard{

	private:
		int size = 3;
		int *board;
		int winner;
	public:		
		GameBoard(int size);
		~GameBoard();
		void insert (int playernum, int x, int y);
		bool isFree(int x, int y);
		int getSize() const;
		void evaluate();
		int getWinner();
		char getSymbol(int x);
		bool hasAvailableMoves();
		friend std::ostream& operator<<(std::ostream& o, GameBoard& gb);

};

#endif
