#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include "player.h"
#include "gameboard.h"

/**
 * constructor of class Player
 * when a player is created it shows which symbol is assigned to the player 
 * @param int playernum (turn)
 */
Player::Player(int playernum){
	turn = playernum;
	if(playernum == 1){
		turn = 1;
		std::cout<<"Player 1: X"<<std::endl;
	}
	else if(playernum == 2){
		turn = 2;
		std::cout<<"Player 2: O"<<std::endl;
	}
	else{
		std::cout<<"Wrong player number"<<std::endl;
	}
}

/**
 * the string when a player is printed out is modified
 * @param ostream o 
 * @param player p
 * @return the modified ostream o 
 */
std::ostream& operator<<(std::ostream& o, Player& p){
	if(p.turn == 1)	
		o<<"Player 1's turn\n";
	else if(p.turn == 2)
		o<<"Player 2's turn\n";
	else
		o<<"Player number is wrong"<<p.turn;
	
	return o;
}

/**
 * constructor of class HumanPlayer which inherits from Player
 * @param int playernum (turn)
 */
HumanPlayer::HumanPlayer(int playernum): Player(playernum){
	;
}


/**
 * method play of HumanPlayer
 * takes a correct input(row and column) from the user and inserts the player number (turn) in the gameboard
 * checks if the input is correct and if the field is free
 * @param Gameboard* gb, where it'll insert the new symbol
 */
void HumanPlayer::play(GameBoard *gb){
	int row;
	int column;
	
	while (true){
		std::cout<<"Select a row: ";
		std::cin>>row;
		if (std::cin.fail() || row < 1 || row > 3){
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"Invalid field selection"<<std::endl;
			continue;
		}
	
		std::cout<<"Select a column: ";
		std::cin>>column;
		if (std::cin.fail() || column < 1 || column > 3){
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"Invalid field selection"<<std::endl;
			continue;
		}
		
		if(gb->isFree(row-1, column-1) == false){
			std::cout<<"Invalid field selection"<<std::endl;
			continue;
		}
		else{
			gb->insert(turn, row-1, column-1);
			std::cout<<"Player "<< turn <<": "<< row << "|" << column <<std::endl;
			break;
		}
	}
}

/**
 * constructor of class ComputerPlayer which inherits from Player
 * it has the RANDOM mode and the MINIMAX mode
 * @param int playernum (turn)
 * @param the mode m
 */
ComputerPlayer::ComputerPlayer(int num, Mode m) : Player(num){
	mode = m;
	srand(time(NULL));
}

/**
 * method play of ComputerPlayer
 * if mode is RANDOM it inserts the symbol in a random field(row and column) if it's free
 * @param Gameboard* gb, where it'll insert the new symbol
 */
void ComputerPlayer::play(GameBoard *gb){
	int row, col;
	if(mode == RANDOM){
		row = (rand() % 3);
		col = (rand() % 3);
	
		while(gb->isFree(row,col) == false){
			row = (rand() % 3);
			col = (rand() % 3);
		}
	}
	else if(mode == MINIMAX){
		;
		
	}
	gb->insert(turn, row, col);
	std::cout<<"Player "<< turn <<": "<< row+1 << "|" << col+1 <<std::endl;
}


