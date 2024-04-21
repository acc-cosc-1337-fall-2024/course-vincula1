#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>
#include <iostream>
#include <limits>
#include <string>

int main() {
    // Destructor testing code
    std::cout << "Testing destructors for TicTacToe3 and TicTacToe4...\n";
    {
        std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
        std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
    } // unique_ptr automatically calls destructors when going out of scope
    std::cout << "Destructor testing complete.\n\n";

    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;

    do {
        std::string first_player;
        int game_type;
        std::cout << "Choose game type (3 for TicTacToe3, 4 for TicTacToe4): ";
        std::cin >> game_type;
        while (game_type != 3 && game_type != 4) {
            std::cout << "Invalid input. Please enter 3 for TicTacToe3 or 4 for TicTacToe4: ";
            std::cin >> game_type;
        }

        if (game_type == 3) {
            game = std::make_unique<TicTacToe3>();
        } else if (game_type == 4) {
            game = std::make_unique<TicTacToe4>();
        }

        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;
        while (first_player != "X" && first_player != "O") {
            std::cout << "Invalid input. Please enter X or O: ";
            std::cin >> first_player;
        }

        game->start_game(first_player);

        while (!game->game_over()) {
            game->display_board();
            std::cout << "Player " << game->get_player() << "'s turn. Enter a position: ";
            int position;
            std::cin >> position;

            while (!std::cin || position < 1 || (game_type == 3 && position > 9) || (game_type == 4 && position > 16)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input, please enter a number between 1 and " << (game_type == 3 ? "9" : "16") << ": ";
                std::cin >> position;
            }
            game->mark_board(position);

            game->display_board();

            if (game->game_over()) {
                game->display_board();
                std::string winner = game->get_winner();
                if (winner == "X" or winner == "O") {
                    std::cout << "Game Over. Winner is: " << winner << "\n";
                } else {
                    std::cout << "Game Over. It's a tie.\n";
                }
                break;
            }
        }

        manager.save_game(game);

        std::cout << "Play again? (Y/N): ";
        char play_again;
        std::cin >> play_again;
        if (play_again == 'n' || play_again == 'N') {
            std::cout << "Thank you for playing!\n";
            std::cout << "\nGame history:\n";
            manager.display_games();

            int x_wins, o_wins, ties;
            manager.get_winner_total(x_wins, o_wins, ties);
            std::cout << "Summary:\nX Wins: " << x_wins << "\nO Wins: " << o_wins << "\nTies: " << ties << std::endl;
            
            break;
        }
    } while (true);

    return 0;
}
