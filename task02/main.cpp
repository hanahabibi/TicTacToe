#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include "player.h"
#include "gameboard.h"

/**
 * main method controls the game 
 * asks the user to input a game mode
 * checks if the input is valid and starts the game in the mode that the user input
 * if the game ended, the selection menu will show up again until the user enters 5 (exit option)
 * @return 0, if successful
 */
int main(void){
	while(true){
		std::cout<<"Choose your game mode."<<std::endl;
		std::cout<<"(1) Human vs. Human" <<std::endl;
		std::cout<<"(2) Human vs. Computer (Minimax)"<<std::endl;
		std::cout<<"(3) Human vs. Computer (Random)"<<std::endl;
		std::cout<<"(4) Computer (Minimax) vs. Computer (Minimax)"<<std::endl;
		std::cout<<"(5) Exit Program"<<std::endl;

		int x;
		std::cin>>x;
		
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			x = 0;
		}
		
		else if(x == 5)
			exit(0);
		
		else if(x>5 || x <1)
			continue;	

		else{
		
			GameBoard *board = new GameBoard(3);
			std::cout<<*(board);
			Player *player1;
			Player *player2;
			
		
			switch(x){
				case 1:
					player1 = new HumanPlayer(1);
					player2 = new HumanPlayer(2);
					break;
				case 2:
					player1 = new HumanPlayer(1);
					player2 = new ComputerPlayer(2, MINIMAX);
					break;
				case 3:
					player1 = new HumanPlayer(1);
					player2 = new ComputerPlayer(2, RANDOM);
					break;
				case 4:
					player1 = new ComputerPlayer(1, MINIMAX);
					player2 = new ComputerPlayer(2, MINIMAX);
					break;
				default:
					std::cout<<"Something went wrong"<<std::endl;
					break;
			}
			
			while(board->hasAvailableMoves()){
				std::cout<<*(player1);
				player1->play(board);
				std::cout<<*(board);
				board->evaluate();
				if(board->getWinner() == 1){
					std::cout<<"Winner is Player 1 (x)\n";
					break;
				}
				else if(board->getWinner() == 2){
					std::cout<<"Winner is Player 2 (O)\n";
					break;
				}
				else if(!board->hasAvailableMoves()){
					std::cout<<"A draw!\n";
					break;
				}
				
				std::cout<<*(player2);
				player2->play(board);
				std::cout<<*(board);
				board->evaluate();
				if(board->getWinner() == 1){
					std::cout<<"Winner is: Player 1\n";
					break;
				}
				else if(board->getWinner() == 2){
					std::cout<<"Winner is: Player 2\n";
					break;
				}
				else if(!board->hasAvailableMoves()){
					std::cout<<"A draw\n";
					break;
				}
			}
		}
	}
	return 0;
}
