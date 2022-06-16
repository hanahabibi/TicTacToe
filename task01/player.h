#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include "gameboard.h"
#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
 * definition of class Player, its methods and elements
 */
class Player{

	protected:
		Player(int playernum);
	
	public:
		int turn;
		virtual void play(GameBoard *gb) = 0;
		friend std::ostream& operator<<(std::ostream& o, Player& p);
};

/**
 * definition of class HumanPlayer which publicly inherits from class Player
 */
class HumanPlayer : public Player{

	public :	
		HumanPlayer(int playernum);
		void play(GameBoard *gb) override;		
};

enum Mode{RANDOM, MINIMAX};

/**
 * definition of class ComputerPlayer which publicly inherits from class Player
 */
class ComputerPlayer : public Player{
	
	private:
		Mode mode;
	public:
		ComputerPlayer(int playernum, Mode mode = RANDOM);
		void play(GameBoard *gb) override;
};

#endif
