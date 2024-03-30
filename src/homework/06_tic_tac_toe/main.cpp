#include "tic_tac_toe.h"
#include <iostream>
#include <string>

int main() 
{
	do {
		std::string first_player;
		do {
			std::cout << "Enter first player (X and O): ";
			std::cin >> first_player;
		} while (first_player != "X" && first_player != "O");

		TicTacToe game;
		game.start_game(first_player);

		while (!game.game_over()) {
			game.display_board();
			std::cout << "Player " << game.get_player() << "'s turn. Enter a position (1-9): ";
			int position;
			std::cin >> position;
			game.mark_board(position);
		}

		game.display_board();
		std::cout << "Game Over. The board is full.\n";

		std::cout << "Play again? (Y/N): ";
		char play_again;
		std::cin >> play_again;
		if (play_again == 'n' || play_again == 'N') {
			std::cout << "Thank you for playing!\n";
			break;
		}

	} while (true);

	return 0;
}