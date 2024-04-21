//cpp
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_total(int& x_wins, int& o_wins, int& ties) const {
    x_wins = this->x_win;
    o_wins = this->o_win;
    ties = this->ties;
}

void TicTacToeManager::display_games() const {
    for (const auto& game : games) {
        std::cout << *game;
    }
}


std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    for (const auto& game : manager.games) {
        out << *game;
    }
    return out;
}


void TicTacToeManager::update_winner_count(const std::string& winner) {
    std::cout << "Updating count for winner: " << winner << std::endl;
    if (winner == "X") x_win++;
    else if (winner == "O") o_win++;
    else if (winner == "Tie") ties++;
}