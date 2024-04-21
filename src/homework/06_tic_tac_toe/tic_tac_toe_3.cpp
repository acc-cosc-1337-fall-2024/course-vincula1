#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

bool TicTacToe3::check_column_win() const {
    for (int col = 0; col < 3; ++col) {
        if (pegs[col] != " " && pegs[col] == pegs[col + 3] && pegs[col + 3] == pegs[col + 6]) {
            return true;
        }
    }
    return false;
}


/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/

bool TicTacToe3::check_row_win() const {
    for (int row = 0; row < 9; row += 3) {
        if (pegs[row] != " " && pegs[row] == pegs[row + 1] && pegs[row + 1] == pegs[row + 2]) {
            return true;
        }
    }
    return false;
}


/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/

bool TicTacToe3::check_diagonal_win() const {
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) {
        return true;
    }
    if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]) {
        return true;
    }
    return false;
}