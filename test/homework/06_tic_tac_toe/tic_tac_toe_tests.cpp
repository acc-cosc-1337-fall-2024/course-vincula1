#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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