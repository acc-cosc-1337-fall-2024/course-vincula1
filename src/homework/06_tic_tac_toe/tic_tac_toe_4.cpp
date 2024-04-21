#include "tic_tac_toe_4.h"
#include <cmath>
#pragma once

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/

bool TicTacToe4::check_column_win() const {
    for (int i = 0; i < 4; ++i) { // Check each column
        if (pegs[i] != " " && pegs[i] == pegs[i + 4] && pegs[i + 4] == pegs[i + 8] && pegs[i + 8] == pegs[i + 12]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win() const {
    for (int i = 0; i < 16; i += 4) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i + 1] == pegs[i + 2] && pegs[i + 2] == pegs[i + 3]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win() const {
    int size = static_cast<int>(std::sqrt(pegs.size()));
    // Check main diagonal
    bool main_diagonal_win = true;
    for (int i = 0; i < size; ++i) {
        if (pegs[i * size + i] == " " || pegs[i * size + i] != pegs[0]) {
            main_diagonal_win = false;
            break;
        }
    }
    if (main_diagonal_win) return true;

    // Check secondary diagonal
    bool secondary_diagonal_win = true;
    for (int i = 0; i < size; ++i) {
        if (pegs[(size - 1) * (i + 1)] == " " || pegs[(size - 1) * (i + 1)] != pegs[size - 1]) {
            secondary_diagonal_win = false;
            break;
        }
    }
    return secondary_diagonal_win;
}
