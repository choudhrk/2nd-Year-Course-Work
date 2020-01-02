/**
 * \file testGameBoard.cpp
 * \brief Implementation of the forty thieves game board tests.
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \date March 25th 2019
*/

#include "../catch/catch.h"
#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include "../include/GameBoard.h"

TEST_CASE( "tests for GameBoard" ) {

	std::vector<CardT> d;
  	for (RankT rank = KING; rank >= ACE; rank--) {
    	for (unsigned int suit = 0; suit <= 3; suit++) {
      		CardT n = { static_cast<SuitT>(suit), rank };
      		d.push_back(n);
      		d.push_back(n);
    	}
  	}
	BoardT test_board(d);

	SECTION("Constructor test"){
		CardStackT test_corr_seq = test_board.get_tab(0);
		REQUIRE(test_corr_seq.top().rank == KING);
	}

	SECTION("Constructor exception test"){
		std::vector<CardT> c;
  		for (RankT rank = KING; rank >= ACE; rank--) {
    		for (unsigned int suit = 0; suit < 3; suit++) {
      			CardT n = { static_cast<SuitT>(suit), rank };
      			c.push_back(n);
      			c.push_back(n);
    		}
  		}
		REQUIRE_THROWS_AS(BoardT(c), std::invalid_argument);
	}
	
	//Test cases for tableau moves.
	SECTION("Valid Tableau to Tableau Existence check1"){
		bool test_tab_bool = test_board.is_valid_tab_mv(Tableau, 9, 3);
		REQUIRE(test_tab_bool == false);
	}
	
	SECTION("Valid Tableau to Tableau Existence check2"){
		bool test_tab_bool = test_board.is_valid_tab_mv(Tableau, 5, 3);
		REQUIRE(test_tab_bool == true);
	}
	
	SECTION("Valid Tableau to Foundation check1"){
		bool test_tab_bool = test_board.is_valid_tab_mv(Foundation, 9, 3);
		REQUIRE(test_tab_bool == false);
	}
	
	SECTION("get_tab check"){
		CardStackT test_tab_curr = test_board.get_tab(3);
		REQUIRE(test_tab_curr.top().rank == QUEEN);
	}
	
	SECTION("Tableau move check"){
		test_board.tab_mv(Tableau, 5,3);
		CardStackT test_old_tab_now = test_board.get_tab(5);
		CardStackT test_new_tab_now = test_board.get_tab(3);
		REQUIRE(test_old_tab_now.top().suit == Spade);
		REQUIRE(test_new_tab_now.top().rank == JACK);
	}
	
	//Test cases for deck moves.
	SECTION("Valid Deck to Waste move check1"){
		bool test_deck_bool = test_board.is_valid_deck_mv();
		REQUIRE(test_deck_bool == true);
	}
	
	SECTION("Deck to Waste move check1"){
		test_board.deck_mv();
		CardStackT test_deck = test_board.get_deck();
		REQUIRE(test_deck.top().rank == ACE);
	}
	
	SECTION("get_deck test"){
		for(int i = 0; i < 12; i++){
			test_board.deck_mv();
		}
		CardStackT test_deck = test_board.get_deck();
		REQUIRE(test_deck.top().rank == 2);
	}
	
	
	//Test cases for waste moves.
	SECTION("Valid Waste to Foundation check1"){
		test_board.deck_mv();
		bool test_waste_found_bool = test_board.is_valid_waste_mv(Foundation, 3);
		REQUIRE(test_waste_found_bool == true);
	}
	
	SECTION("Valid Waste to Foundation check exception"){
		test_board.deck_mv();
		REQUIRE_THROWS_AS(test_board.is_valid_waste_mv(Foundation, 9), std::out_of_range);
	}
	
	SECTION("Valid Waste to Tableau check"){
		test_board.deck_mv();
		bool test_waste_tab_bool = test_board.is_valid_waste_mv(Tableau, 9);
		REQUIRE(test_waste_tab_bool == false);
	}
	
	SECTION("Valid Waste to Tableau check exception"){
		test_board.deck_mv();
		REQUIRE_THROWS_AS(test_board.is_valid_waste_mv(Tableau, 12), std::out_of_range);
	}
	
	SECTION("get_waste check"){
		for(int i = 1; i <= 24; i++){
			test_board.deck_mv();
		}
		CardStackT test_waste = test_board.get_waste();
		REQUIRE(test_waste.top().rank == 3);
		REQUIRE(test_waste.top().suit == Heart);
	}
	
	//Now for some gameplay...
	
	SECTION("valid_mv_exists test"){
		bool yes_should_exist = test_board.valid_mv_exists();
		REQUIRE(yes_should_exist == true);
	}
	
	SECTION("get_foundation test"){
		for(int i = 1; i <= 64; i++){
	
			CardStackT temp = test_board.get_deck();
			if(temp.top().suit == Spade){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(3);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 3);
				else{
					test_board.waste_mv(Foundation, 7);
				}
			}
			if(temp.top().suit == Club){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(2);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 2);
				else{
					test_board.waste_mv(Foundation, 6);
				}
			}
			if(temp.top().suit == Diamond){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(1);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 1);
				else{
					test_board.waste_mv(Foundation, 5);
				}
			}
			if(temp.top().suit == Heart){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(0);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 0);
				else{
					test_board.waste_mv(Foundation, 4);
				}
			}
		}
		CardStackT foundation0, foundation1, foundation2, foundation3, foundation4, foundation5, foundation6, foundation7;
		foundation0 = test_board.get_foundation(0); bool top_check0 = (foundation0.top().rank == 8);
		foundation1 = test_board.get_foundation(1); bool top_check1 = (foundation1.top().rank == 8);
		foundation2 = test_board.get_foundation(2); bool top_check2 = (foundation2.top().rank == 8);
		foundation3 = test_board.get_foundation(3); bool top_check3 = (foundation3.top().rank == 8);
		foundation4 = test_board.get_foundation(4); bool top_check4 = (foundation4.top().rank == 8);
		foundation5 = test_board.get_foundation(5); bool top_check5 = (foundation5.top().rank == 8);
		foundation6 = test_board.get_foundation(6); bool top_check6 = (foundation6.top().rank == 8);
		foundation7 = test_board.get_foundation(7); bool top_check7 = (foundation7.top().rank == 8);
		bool overall = top_check0 && top_check1 && top_check2 && top_check3 && top_check4 && top_check5 && top_check6 && top_check7;
		REQUIRE(overall == true);
	}
	
	SECTION("Win state test"){
		for(int i = 1; i <= 64; i++){

			CardStackT temp = test_board.get_deck();
			if(temp.top().suit == Spade){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(3);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 3);
				else{
					test_board.waste_mv(Foundation, 7);
				}
			}
			if(temp.top().suit == Club){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(2);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 2);
				else{
					test_board.waste_mv(Foundation, 6);
				}
			}
			if(temp.top().suit == Diamond){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(1);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 1);
				else{
					test_board.waste_mv(Foundation, 5);
				}
			}
			if(temp.top().suit == Heart){
				test_board.deck_mv();
				CardStackT temp_found = test_board.get_foundation(0);
				if(temp_found.size() == temp.top().rank-1)
					test_board.waste_mv(Foundation, 0);
				else{
					test_board.waste_mv(Foundation, 4);
				}
			}
		}
		
		for(int i = 9; i < 0; i = i-2){
			test_board.tab_mv(Foundation, i, 7);
			test_board.tab_mv(Foundation, i, 3);
			test_board.tab_mv(Foundation, i, 6);
			test_board.tab_mv(Foundation, i, 2);
			test_board.tab_mv(Foundation, i-1, 5);
			test_board.tab_mv(Foundation, i-1, 1);
			test_board.tab_mv(Foundation, i-1, 4);
			test_board.tab_mv(Foundation, i-1, 0);
			bool test_win_state = test_board.is_win_state();
			REQUIRE(test_win_state == true);
		}
	}

}