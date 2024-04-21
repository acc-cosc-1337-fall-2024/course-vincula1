//tic_tac_toe.h

#pragma once
#include <string>
#include <vector>
#include <iostream>

class TicTacToe {
public:

    explicit TicTacToe(int size);
    virtual ~TicTacToe() {
    }

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over() const;
    void display_board() const;
    std::string get_player() const;
    std::string get_winner() const;
    void reset_game();
    bool check_board_full() const;

    const std::vector<std::string>& get_pegs() const {
        return pegs;
    }
    //friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
    //friend std::istream& operator>>(std::istream& is, TicTacToe& game);

protected:
    virtual bool check_column_win() const { return false; }
    virtual bool check_row_win() const { return false; }
    virtual bool check_diagonal_win() const { return false; }
    
    std::vector<std::string> pegs;

private:

    void set_next_player();
    void clear_board();

    std::string player;
};

std::ostream& operator<<(std::ostream& os, const TicTacToe& game);