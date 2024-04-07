//cpp

#include "tic_tac_toe.h"
#include <limits>
#include <iostream>

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

bool TicTacToe::game_over() {
    return check_board_full();
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

std::ostream& operator>>(std::ostream& os, const TicTacToe& game) {

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
