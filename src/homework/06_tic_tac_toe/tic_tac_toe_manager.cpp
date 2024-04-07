//cpp
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"

void TicTacToeManager::save_game(const TicTacToe& b) {
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t) const {
    o = o_win;
    w = x_win;
    t = ties;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    for (const auto& game : manager.games) {
        out << game;
    }
    return out;
}

void TicTacToeManager::update_winner_count(const std::string& winner) {
    if (winner == "X") x_win++;
    else if (winner == "O") o_win++;
    else if (winner == "Tie") ties++;
}
