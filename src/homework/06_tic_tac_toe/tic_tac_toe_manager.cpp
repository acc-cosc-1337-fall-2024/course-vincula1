//cpp
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"

void TicTacToeManager::save_game(const TicTacToe& b) {
    //std::cout << "Entering save_game method." << std::endl;
    games.push_back(b);
    std::string winner = b.get_winner();
    //std::cout << "Saving game. Winner reported as: " << winner << std::endl;
    update_winner_count(winner);
}

void TicTacToeManager::get_winner_total(int& x_wins, int& o_wins, int& ties) const {
    x_wins = this->x_win;
    o_wins = this->o_win;
    ties = this->ties;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    for (const auto& game : manager.games) {
        out << game;
    }
    return out;
}

void TicTacToeManager::update_winner_count(const std::string& winner) {
    std::cout << "Updating count for winner: " << winner << std::endl;
    if (winner == "X") x_win++;
    else if (winner == "O") o_win++;
    else if (winner == "Tie") ties++;
}