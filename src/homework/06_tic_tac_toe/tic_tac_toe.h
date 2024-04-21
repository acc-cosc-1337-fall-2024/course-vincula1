//tic_tac_toe.h

#pragma once
#include <string>
#include <vector>
#include <iostream>

class TicTacToe {
public:

    explicit TicTacToe(int size);
    virtual ~TicTacToe() = default;

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    std::string get_player() const;
    std::string get_winner() const;
    void reset_game();


    const std::vector<std::string>& get_pegs() const { return pegs; }
    //friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
    //friend std::istream& operator>>(std::istream& is, TicTacToe& game);

protected:
    virtual bool check_column_win() { return false; }
    virtual bool check_row_win() { return false; }
    virtual bool check_diagonal_win() { return false; }


private:

    void set_next_player();
    bool check_board_full();
    void clear_board();

    std::string player;
    std::vector<std::string> pegs;
};

std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
std::istream& operator>>(std::istream& is, TicTacToe& game);
