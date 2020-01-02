/**
 * \file testStack.cpp
 * \brief Implementation of Stack<T> tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 24th 2019
*/

#include "../catch/catch.h"
#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include <stdexcept>

TEST_CASE( "tests for Stack<CardT>" , "[CardStackT]" ) {
  std::vector<CardT> test_stack;
  CardT ace_of_spades = {Spade, ACE}; test_stack.push_back(ace_of_spades);
  CardT two_of_spades = {Spade, 2}; test_stack.push_back(two_of_spades);
  CardT three_of_spades = {Spade, 3}; test_stack.push_back(three_of_spades);
  CardT four_of_spades = {Spade, 4}; test_stack.push_back(four_of_spades);
  CardT five_of_spades = {Spade, 5}; test_stack.push_back(five_of_spades);
  CardT six_of_spades = {Spade, 6}; test_stack.push_back(six_of_spades);
  CardT seven_of_spades = {Spade, 7}; test_stack.push_back(seven_of_spades);
  CardT eight_of_spades = {Spade, 8}; test_stack.push_back(eight_of_spades);
  CardT nine_of_spades = {Spade, 9}; test_stack.push_back(nine_of_spades);
  CardT ten_of_spades = {Spade, 10}; test_stack.push_back(ten_of_spades);
  CardT jack_of_spades = {Spade, JACK}; test_stack.push_back(jack_of_spades);
  CardT queen_of_spades = {Spade, QUEEN}; test_stack.push_back(queen_of_spades);
  CardT king_of_spades = {Spade, KING}; test_stack.push_back(king_of_spades);

  SECTION("test constuctor"){
    CardStackT CS_emp;
  	CardStackT CS_input(test_stack);

    REQUIRE(CS_emp.size() == 0);
    REQUIRE(CS_input.size() == 13);
  }
  CardStackT CS_input(test_stack);
  SECTION("Push() test"){
  	CardT king_of_hearts = {Heart, KING}; 
	CardStackT new_stack1 = CS_input.push(king_of_hearts);
    REQUIRE(new_stack1.size() == 14);
  }

  SECTION("Pop() test"){
	CardStackT new_stack1 = CS_input.pop();
    REQUIRE(new_stack1.size() == 12);
  }
  
  SECTION("Exception Pop() test"){
    CardStackT CS_emp;
    REQUIRE_THROWS_AS(CS_emp.pop(), std::out_of_range);
  }
	
  SECTION("Normal Top() test"){
    CardStackT CS_emp, new_stack1; 
  	for(int i = 0; i < 11; i++){
		new_stack1 = CS_input.pop();
	} 
    CardT new_stack1_top = CS_input.top();
	REQUIRE(new_stack1_top.rank == 2);
	REQUIRE(new_stack1_top.suit == Spade);
  }
  SECTION("Exception Top() test"){
    CardStackT CS_emp; 
	
    REQUIRE_THROWS_AS(CS_emp.top(), std::out_of_range);
  }
  
  SECTION("Size() test"){
    CardStackT new_stack1; 
	
  	for(int i = 0; i < 13; i++){
		new_stack1 = CS_input.pop();
	}
	for(int i = 0; i < 13; i++){
		new_stack1 = CS_input.push({Heart, (RankT)(i+1)});
	}
	
	REQUIRE(new_stack1.size() == CS_input.size());
  }
  
  SECTION("toSeq test"){
  	std::vector<CardT> test_vector = CS_input.toSeq();
    REQUIRE(test_vector.front().rank == ACE);
	REQUIRE(test_vector.back().suit == Spade);
  }
	
}