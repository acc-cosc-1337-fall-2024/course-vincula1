#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include "tic_tac_toe_manager.h"
#include <limits>

int main() 
{
	TicTacToeManager manager;

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

			while (!std::cin || position < 1 || position > 9) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input, please enter number 1-9: ";
				std::cin >> position;
			}
			game.mark_board(position);
		}

		game.display_board();
		
		std::string winner = game.get_winner();
		if (winner == "X" || winner == "O") {
			std::cout << "Gmae Over. Winner is: " << winner << "\n";
		} else {
			std::cout << "Game Over. Its a tie.\n";
		}

		manager.save_game(game);

		std::cout << "Play again? (Y/N): ";
		char play_again;
		std::cin >> play_again;
		if (play_again == 'n' || play_again == 'N') {
			std::cout << "Thank you for playing!\n";

			std::cout << "\nGame history:\n";
			std::cout << manager;

			int x_wins, o_wins, ties;
			manager.get_winner_total(x_wins, o_wins, ties);
			std::cout << "Summary:\nX Wins: " << x_wins << "\nO Wins: " << o_wins << "\nTies: " << ties << std::end

			break;
		}

	} while (true);

	return 0;
}