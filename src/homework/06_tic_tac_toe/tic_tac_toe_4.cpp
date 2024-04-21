#include "tic_tac_toe_4.h"
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
    std::cout << "Checking columns for win...\n";
    for (int i = 0; i < 4; ++i) { // Check each column
        if (pegs[i] != " " && pegs[i] == pegs[i + 4] && pegs[i + 4] == pegs[i + 8] && pegs[i + 8] == pegs[i + 12]) {
            std::cout << "Column win detected in column starting at index " << i << "\n";
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win() const {
    std::cout << "Checking rows for win...\n";
    for (int i = 0; i < 16; i += 4) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i + 1] == pegs[i + 2] && pegs[i + 2] == pegs[i + 3]) {
            std::cout << "Row win detected in row starting at index " << i << "\n";
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win() const {
    std::cout << "Checking diagonals for win...\n";

    // Check main diagonal (top-left to bottom-right)
    std::cout << "Main diagonal values: " << pegs[0] << ", " << pegs[5] << ", " << pegs[10] << ", " << pegs[15] << "\n";
    if (pegs[0] != " " && pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15]) {
        std::cout << "Main diagonal win detected\n";
        return true;
    }

    // Check secondary diagonal (top-right to bottom-left)
    std::cout << "Secondary diagonal values: " << pegs[3] << ", " << pegs[6] << ", " << pegs[9] << ", " << pegs[12] << "\n";
    if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12]) {
        std::cout << "Secondary diagonal win detected\n";
        return true;
    }

    std::cout << "No diagonal win detected.\n";
    return false;
}
