#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected", "[TicTacToe]") {
	TicTacToe game;
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
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}


TEST_CASE("Test first player set to O", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}


TEST_CASE("Test game over if 9 slots are selected - Tie", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(7);
    game.mark_board(4);
    game.mark_board(6);
    game.mark_board(9);
    game.mark_board(8);
    REQUIRE(game.get_winner() == "Tie");
}


TEST_CASE("Test win by first column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3);
    game.mark_board(2);
    game.mark_board(6);
    game.mark_board(1);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(4);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(2);
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(4);
    game.mark_board(8);
    game.mark_board(5);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(2);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test TicTacToeManager tracking", "[TicTacToeManager]") {
    TicTacToeManager manager;
    TicTacToe game;
    int x_wins, o_wins, ties;

    game.reset_game();
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    manager.save_game(game);

    game.reset_game();
    game.start_game("O");
    game.mark_board(4);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(2);
    game.mark_board(6);
    manager.save_game(game);

    game.reset_game();
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(5);
    game.mark_board(6);
    game.mark_board(7);
    game.mark_board(4);
    game.mark_board(9);
    game.mark_board(8);
    manager.save_game(game);

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}