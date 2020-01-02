/**
 * \file testView.cpp
 * \brief Implementation of view object tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 9th 2019
*/

#include "../catch/catch.h"
#include "../include/CellT.h"
#include "../include/Grid.h"
#include "../include/Model.h"
#include "../include/View.h"
#include <stdexcept>

TEST_CASE( "tests for View object" ) {

  SECTION("test constuctor"){
    Grid object(5);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	View test_View(test_Model);
    REQUIRE(test_View.Game_State.Model_Grid.GameGrid[1][1].state == "A");
  }
  
  SECTION("Write_Output exception"){
    Grid object(4);
	object.read_pattern("./test/test_cells.txt");
	Model test_Model(object);
	View test_View(test_Model);
    REQUIRE_THROWS_AS(test_View.Write_Output("./test/test_game_state.doc"), std::invalid_argument);
  }
}