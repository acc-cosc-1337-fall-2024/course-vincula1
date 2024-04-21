// tic_tac_toe4.h
#pragma once
#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe {
public:
    TicTacToe4() : TicTacToe(4) {}
    ~TicTacToe4() override {
    }
    bool check_column_win() const override;
    bool check_row_win() const override;
    bool check_diagonal_win() const override;
protected:
};
