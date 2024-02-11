#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else_if.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify the and truth table", "verification")
{
	REQUIRE(get_and_result(true, true) == true);
	REQUIRE(get_and_result(true, false) == false);
	REQUIRE(get_and_result(false, true) == false);
	REQUIRE(get_and_result(false, false) == false);
}

TEST_CASE("Verify the or truth table", "verification")
{
	REQUIRE(get_or_result(true, true) == true);
	REQUIRE(get_or_result(true, false) == true);
	REQUIRE(get_or_result(false, true) == true);
	REQUIRE(get_or_result(false, false) == false);
}

TEST_CASE("Verify the not operator")
{
	REQUIRE(get_not_result(true) == false);
	REQUIRE(get_not_result(false) == true);
}

TEST_CASE("Verify the boolean logic order of precendence")
{
	REQUIRE((!true && true || true) == true);
}

TEST_CASE("Verify the get generation function")
{
	REQUIRE(get_generation(2000) == "Centennial");
	REQUIRE(get_generation(1980) == "Millenial");
}