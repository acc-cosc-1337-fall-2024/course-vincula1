//cpp

#include "tic_tac_toe.h"
#include <limits>
#include <iostream>
#include <algorithm>

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if(position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        set_next_player();
    }
}

void TicTacToe::reset_game() {
    pegs = std::vector<std::string>(9, " ");
    player = "";
}

bool TicTacToe::game_over() {
    std::string result = get_winner();
    if (result == "X" || result == "O" || result == "Tie") {
        return true;
    }
    return false;
}



void TicTacToe::display_board() const {
    for (int i = 0; i < 9; i += 3) {
        std::cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
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



bool TicTacToe::check_board_full() {
    for (auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    pegs = std::vector<std::string>(9," ");
}

std::ostream& operator<<(std::ostream& os, const TicTacToe& game) {

    game.display_board();
    return os;

}

std::istream& operator>>(std::istream& is, TicTacToe& game) {
    std::cout << "Player " << game.get_player() << "'s turn. Enter a position 1-9 : ";
    int position;
    is >> position;
    if (!is) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input. \n";
    } else {
        game.mark_board(position);
    }
    return is;
}
