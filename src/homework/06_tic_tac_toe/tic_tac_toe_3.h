// tic_tac_toe_3.h
#pragma once
#include "tic_tac_toe.h"

class TicTacToe3 : public TicTacToe {
public:
    TicTacToe3() : TicTacToe(3) {}
    ~TicTacToe3() override {
        std::cout << "Destroying TicTacToe4 derived class\n";
    }

protected:
    bool check_column_win() const override;
    bool check_row_win() const override;
    bool check_diagonal_win() const override;
};
