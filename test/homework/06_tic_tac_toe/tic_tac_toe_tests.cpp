#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected", "[TicTacToe]") {
	TicTacToe game(3);
	game.start_game("X");
	std::vector<int> positions = {1, 2, 3, 4, 5, 7, 6, 9, 8};

	SECTION("Playing all positions should end the game") {
		for (int i = 0; i < positions.size(); ++i) {
			game.mark_board(positions[i]);
			bool expected_game_over = (i >= 8);
			REQUIRE(game.game_over() == expected_game_over);
		}
	}
}


TEST_CASE("Test first player set to X", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}


TEST_CASE("Test first player set to O", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}


TEST_CASE("Test game over if 9 slots are selected - Tie", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.get_winner() == "Tie");
}


TEST_CASE("Test win by first column", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");

    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left", "[TicTacToe]") {
    TicTacToe game(3);
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager tracking", "[TicTacToeManager]") {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    int x_wins, o_wins, ties;

    game->reset_game();
    game->start_game("X");
    game->mark_board(1);
    REQUIRE(game->game_over() == false);
    game->mark_board(4);
    REQUIRE(game->game_over() == false);
    game->mark_board(2);
    REQUIRE(game->game_over() == false);
    game->mark_board(5);
    REQUIRE(game->game_over() == false);
    game->mark_board(3);
    REQUIRE(game->game_over() == true);
    manager.save_game(game);

    game->reset_game();
    game->start_game("O");
    game->mark_board(4);
    REQUIRE(game->game_over() == false);
    game->mark_board(1);
    REQUIRE(game->game_over() == false);
    game->mark_board(5);
    REQUIRE(game->game_over() == false);
    game->mark_board(2);
    REQUIRE(game->game_over() == false);
    game->mark_board(6);
    REQUIRE(game->game_over() == true);
    manager.save_game(game);

    game->reset_game();
    game->start_game("X");
    game->mark_board(1);
    REQUIRE(game->game_over() == false);
    game->mark_board(2);
    REQUIRE(game->game_over() == false);
    game->mark_board(3);
    REQUIRE(game->game_over() == false);
    game->mark_board(5);
    REQUIRE(game->game_over() == false);
    game->mark_board(6);
    REQUIRE(game->game_over() == false);
    game->mark_board(7);
    REQUIRE(game->game_over() == false);
    game->mark_board(4);
    REQUIRE(game->game_over() == false);
    game->mark_board(9);
    REQUIRE(game->game_over() == false);
    game->mark_board(8);
    REQUIRE(game->game_over() == true);
    manager.save_game(game);

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}


TEST_CASE("Test win at first row 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at second row 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at third row 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at fourth row 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(13);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(14);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(15);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at first column", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(13);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at second column", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(14);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at third column", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(15);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win at fourth column", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win column left to right 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win column right to left 4x4", "[TicTacToe]") {
    TicTacToe game(4);
    game.start_game("X");
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.game_over() == true);
}