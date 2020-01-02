/**
 * \file testModel.cpp
 * \brief Implementation of Model object tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 9th 2019
*/

#include "../catch/catch.h"
#include "../include/CellT.h"
#include "../include/Grid.h"
#include "../include/Model.h"
#include <stdexcept>

TEST_CASE( "tests for Model object" ) {

  SECTION("test constuctor"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE(test_Model.Model_Grid.GameGrid[1][1].state == "A");
  }
  
  SECTION("test live neighbour count"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	int test_neighbour_count = test_Model.count_live_neighbours(1, 1);
    REQUIRE(test_neighbour_count == 3);
  }
  
  SECTION("test live neighbour count exception"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE_THROWS_AS(test_Model.count_live_neighbours(5, 1), std::out_of_range);
  }
  
  SECTION("is_underpopulation"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	bool test_is_underpopulation = test_Model.is_underpopulation(1, 1);
    REQUIRE(test_is_underpopulation == false);
  }
  
  SECTION("is_underpopulation exception"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE_THROWS_AS(test_Model.is_underpopulation(1, 5), std::out_of_range);
  }
  
  SECTION("is_next_gen"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	bool test_is_next_gen = test_Model.is_next_gen(1, 1);
    REQUIRE(test_is_next_gen == true);
  }
  
  SECTION("is_next_gen exception"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE_THROWS_AS(test_Model.is_next_gen(1, 5), std::out_of_range);
  }
  
  SECTION("is_overpopulation"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	bool test_is_overpopulation = test_Model.is_overpopulation(1, 1);
    REQUIRE(test_is_overpopulation == false);
  }
  
  SECTION("is_overpopulation exception"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE_THROWS_AS(test_Model.is_overpopulation(1, 5), std::out_of_range);
  }
  
  SECTION("is_reproduction"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	bool test_is_reproduction = test_Model.is_reproduction(1, 0);
    REQUIRE(test_is_reproduction == true);
  }
  
  SECTION("is_reproduction"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	bool test_is_reproduction = test_Model.is_reproduction(1, 1);
    REQUIRE(test_is_reproduction == false);
  }
  
  SECTION("is_reproduction exception"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
    REQUIRE_THROWS_AS(test_Model.is_next_gen(5, 5), std::out_of_range);
  }
  
  SECTION("game of life"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	Model test_game_play = test_Model.game_of_life();
    REQUIRE(test_game_play.Model_Grid.GameGrid[1][0].state == "A");
	REQUIRE(test_game_play.Model_Grid.size() == 10);
  }
	
}