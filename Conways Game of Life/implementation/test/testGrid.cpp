/**
 * \file testGrid.cpp
 * \brief Implementation of Grid object tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 9th 2019
*/

#include "../catch/catch.h"
#include "../include/CellT.h"
#include "../include/Grid.h"
#include <stdexcept>

TEST_CASE( "tests for Grid object" ) {

  SECTION("test constuctor"){
    Grid object(5);
    REQUIRE(object.GameGrid[1][1].state == "*");
  }
  
  SECTION("test grid size"){
    Grid object(6);
	int size_check = object.size();
    REQUIRE(size_check == 6);
  }
  
  SECTION("read_pattern"){
    Grid object(4);
	object.read_pattern("./test/test_cells.txt");
    REQUIRE(object.GameGrid[1][0].state == "*");
	REQUIRE(object.GameGrid[1][1].state == "A");
  }
  
  SECTION("read_pattern exception"){
    Grid object(4);
    REQUIRE_THROWS_AS(object.read_pattern("./test/test_cells.doc"), std::invalid_argument);
  }
	
}