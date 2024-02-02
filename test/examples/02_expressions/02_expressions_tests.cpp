#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "casting.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test implicit data type casting", "verify that ints are converted to doubles on run time" ) {
	REQUIRE(convert_to_double(10, .5) == 5.0);
}

TEST_CASE("Test implicit data type casing double to int", "Verify double to int conversion")
{
	REQUIRE(convert_double_to_int(10.99) == 10);
}

TEST_CASE("Test explicit data type casting")
{
	REQUIRE(static_cast_double_int(10.99) == 10);
}