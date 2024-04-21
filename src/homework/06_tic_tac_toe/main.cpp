#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>
#include <iostream>
#include <limits>
#include <string>

int read_int(const std::string& prompt, int min, int max) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < min || value > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
    }
    return value;
}

int main() {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;

    do {
        int game_type = read_int("Choose game type (3 for TicTacToe3, 4 for TicTacToe4): ", 3, 4);

        if (game_type == 3) {
            game = std::make_unique<TicTacToe3>();
        } else if (game_type == 4) {
            game = std::make_unique<TicTacToe4>();
        }

        std::string first_player;
        std::cout << "Enter first player (X or O): ";
        while (!(std::cin >> first_player) || (first_player != "X" && first_player != "O")) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter X or O: ";
        }

        game->start_game(first_player);

        while (!game->game_over()) {
            game->display_board();
            int position = read_int("Player " + game->get_player() + "'s turn. Enter a position: ", 1, game_type == 3 ? 9 : 16);
            game->mark_board(position);
            game->display_board();

            if (game->game_over()) {
                std::string winner = game->get_winner();
                if (winner == "X" || winner == "O") {
                    std::cout << "Game Over. Winner is: " << winner << "\n";
                } else {
                    std::cout << "Game Over. It's a tie.\n";
                }
                break;
            }
        }

        manager.save_game(game);

        char play_again;
        std::cout << "Play again? (Y/N): ";
        std::cin >> play_again;
        if (play_again == 'N' || play_again == 'n') {
            std::cout << "Thank you for playing!\n";
            manager.display_games();
            break;
        }
    } while (true);

    return 0;
}
