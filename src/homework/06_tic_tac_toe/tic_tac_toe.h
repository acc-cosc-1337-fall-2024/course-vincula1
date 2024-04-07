//h

#include <string>
#include <vector>

class TicTacToe {
public:

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    std::string get_player() const;

    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

private:

    void set_next_player();
    bool check_board_full();
    void clear_board();

    std::string player;
    std::vector<std::string> pegs = std::vector<std::string>(9, " ");
};