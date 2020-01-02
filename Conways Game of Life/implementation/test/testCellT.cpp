/**
 * \file testCellR.cpp
 * \brief Implementation of CellT() tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 9th 2019
*/

#include "../catch/catch.h"
#include "../include/CellT.h"
#include <stdexcept>

TEST_CASE( "tests for CellT object" ) {

  SECTION("test constuctor"){
    CellT object;
    REQUIRE(object.state == "");
  }
  
  SECTION("test cell genesis"){
    CellT object;
	object.cell_genesis();
    REQUIRE(object.state == "A");
  }
  
  SECTION("test cell mortem"){
    CellT object;
	object.cell_mortem();
    REQUIRE(object.state == "*");
  }
 	
}