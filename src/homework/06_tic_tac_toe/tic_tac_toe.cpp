#include <cmath>
#include "tic_tac_toe.h"
#include <limits>
#include <iostream>
#include <algorithm>


TicTacToe::TicTacToe(int size) {
    pegs = std::vector<std::string>(size * size, " ");
}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= pegs.size() && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        if (!game_over()) {
            set_next_player(); // Move this inside a condition to check if the game isn't over
        }
    }
}

void TicTacToe::reset_game() {
    pegs = std::vector<std::string>(pegs.size(), " ");
    player = "";
}

bool TicTacToe::game_over() const {
    std::cout << "Checking game over conditions.\n";
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        return true;
    }
    if (check_board_full() && !check_row_win() && !check_column_win() && !check_diagonal_win()) {
        return true;
    }
    return false;
}


void TicTacToe::display_board() const {
    int board_size = static_cast<int>(std::sqrt(pegs.size()));
    for (int i = 0; i < pegs.size(); i += board_size) {
        for (int j = 0; j < board_size; j++) {
            std::cout << pegs[i + j];
            if (j < board_size - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (i < pegs.size() - board_size)
            std::cout << std::string(board_size * 2 - 1, '-') << "\n";
    }
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::set_next_player() {
    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}

std::string TicTacToe::get_winner() const {
    const std::vector<std::vector<int>> winning_combinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    // Check each winning combination
    for (const auto& combination : winning_combinations) {
        if (pegs[combination[0]] != " " &&
            pegs[combination[0]] == pegs[combination[1]] &&
            pegs[combination[1]] == pegs[combination[2]]) {
            std::cout << "Winner found: " << pegs[combination[0]] << std::endl;
            return pegs[combination[0]];
        }
    }

    if (std::none_of(pegs.begin(), pegs.end(), [](const std::string& peg) { return peg == " "; })) {
        std::cout << "Game is a tie, no empty spaces left." << std::endl;
        return "Tie";
    }

    std::cout << "No winner yet, game continues." << std::endl;
    return "No Winner";
}

bool TicTacToe::check_board_full() const {  // Must also include const here
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false;  // If any spot is empty, the board is not full
        }
    }
    return true;  // All spots are filled
}




void TicTacToe::clear_board() {
    std::fill(pegs.begin(), pegs.end(), " ");  // Reset all pegs to " "
}

std::ostream& operator<<(std::ostream& os, const TicTacToe& game) {
    const auto& pegs = game.get_pegs(); // Accessing pegs using get_pegs() function
    int size = static_cast<int>(std::sqrt(pegs.size()));
    for (int i = 0; i < pegs.size(); i++) {
        os << pegs[i] << (i % size == size - 1 ? "\n" : "|");
        if (i % size == size - 1 && i < pegs.size() - 1) {
            os << std::string(size * 2 - 1, '-') << "\n";
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, TicTacToe& game) {
    int position;
    const auto& pegs = game.get_pegs();
    std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
    is >> position;
    if (!is) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please enter a number between 1 and 9." << std::endl;
    } else if (position >= 1 && position <= pegs.size()) {
        game.mark_board(position);
    } else {
        std::cout << "Invalid position. " << std::endl;
        is.clear(std::ios_base::failbit);
    }
    return is;
}
