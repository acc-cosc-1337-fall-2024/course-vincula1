//h
#include "tic_tac_toe.h"
#include <vector>

class TicTacToeManager {
public:
    void save_game(const TicTacToe& b);
    void get_winner_total(int& o, int& w, int& t) const;

    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

private:
    std::vector<TicTacToe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(const std::string& winner);
}