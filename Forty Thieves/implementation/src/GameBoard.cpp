#include <iostream>
#include "../include/GameBoard.h"
#include <vector>
#include <stdexcept>
#include <algorithm>

BoardT::BoardT(){}
BoardT::BoardT(std::vector<CardT> deck){
	if(two_decks(deck) == false){
		throw std::invalid_argument("Invalid deck!");
	}
	(this->undistributed_deck) = deck;
	(this->tableau) = tab_deck(deck);
	(this->foundation) = init_seq(8);
	std::vector<CardT> remaining_deck;
	for(int j = 40; j < 104; j++){
		remaining_deck.push_back(deck[j]);
	}
	for(int i = 0; i < 64; i++){
		(this->deck).push(remaining_deck[i]);	
	}
}
bool BoardT::is_valid_tab_mv(CategoryT type, unsigned int n_1, unsigned int n_2){
	bool tab_valid;
	if(type == Tableau){
		bool n1_tab = is_valid_pos(Tableau, n_1);
		bool n2_tab = is_valid_pos(type, n_2);
		if((n1_tab && n2_tab) == false){throw std::out_of_range("Invalid tableau to tableau!");}
		tab_valid = valid_tab_tab(n_1, n_2);
	}
	if(type == Foundation){
		bool n1_tab = is_valid_pos(Tableau, n_1);
		bool n2_tab = is_valid_pos(type, n_2);
		if((n1_tab && n2_tab) == false){throw std::out_of_range("Invalid tableau to foundation!");}
		tab_valid = valid_tab_foundation(n_1, n_2);
	}
	if(type == Deck){tab_valid = false;}
	if(type == Waste){tab_valid = false;}
	return tab_valid;
}
bool BoardT::is_valid_waste_mv(CategoryT type, unsigned int n){
	bool waste_valid;
	if((this->waste).size() == 0){throw std::invalid_argument("Cannot move from empty waste.");}
	if(type == Tableau){
		bool n_tab = is_valid_pos(type, n);
		if(n_tab == false){throw std::out_of_range("Invalid waste to tableau!");}
		waste_valid = valid_waste_tab(n);
	}
	if(type == Foundation){
		bool n_tab = is_valid_pos(type, n);
		if(n_tab == false){throw std::out_of_range("Invalid waste to foundation!");}
		waste_valid = valid_waste_foundation(n);
	}
	if(type == Deck){waste_valid = false;}
	if(type == Waste){waste_valid = false;}
	return waste_valid;
}
bool BoardT::is_valid_deck_mv(){
	return ((this->deck).size() > 0);
}
void BoardT::tab_mv(CategoryT type, unsigned int n_1, unsigned int n_2){
	if(is_valid_tab_mv(type, n_1, n_2) == false){
		throw std::invalid_argument("Invalid tableau move.");
	}
	if(type == Tableau){
		(this->tableau)[n_2].push((this->tableau)[n_1].top());
		(this->tableau)[n_1].pop();
	}
	if(type == Foundation){
		(this->foundation)[n_2].push((this->tableau)[n_1].top());
		(this->tableau)[n_1].pop();
	}
}
void BoardT::waste_mv(CategoryT type, unsigned int n){
	if(is_valid_waste_mv(type, n) == false){
		throw std::invalid_argument("Invalid waste move.");
	}
	if(type == Tableau){
		(this->tableau)[n].push((this->waste).top());
		(this->waste).pop();
	}
	if(type == Foundation){
		(this->foundation)[n].push((this->waste).top());
		(this->waste).pop();
	}
}
void BoardT::deck_mv(){
	if(is_valid_deck_mv() == false){
		throw std::invalid_argument("Invalid deck move.");
	}
	(this->waste).push((this->deck).top());
	(this->deck).pop();
}
CardStackT BoardT::get_tab(unsigned int n){
	if(is_valid_pos(Tableau, n) == false){
		throw std::out_of_range("This tableau doesn't exist.");
	}
	return (this->tableau)[n];
}
CardStackT BoardT::get_foundation(unsigned int n){
	if(is_valid_pos(Foundation, n) == false){
		throw std::out_of_range("This foundation doesn't exist.");
	}
	return (this->foundation)[n];
}
CardStackT BoardT::get_deck(){
	return (this->deck);
}
CardStackT BoardT::get_waste(){
	return (this->waste);
}
bool BoardT::valid_mv_exists(){
	bool valid_tab_mv, valid_waste_mv;
	for(unsigned int i = 0; i < 10; i++){
		for(unsigned int j = 0; j < 10; j++){
			for(int c = 0; c <= 1; c++){
				CategoryT ct = (CategoryT) c;
				if((is_valid_pos(Tableau, i)) && (is_valid_pos(ct, j))){
					valid_tab_mv = valid_tab_mv || is_valid_tab_mv(ct, i, j);
				}
			}
		}
	}
	for(unsigned int j = 0; j < 10; j++){
		for(int c = 0; c <= 1; c++){
			CategoryT ct = (CategoryT) c;
			if(is_valid_pos(ct, j)){
				valid_waste_mv = valid_waste_mv || is_valid_waste_mv(ct, j);
			}
		}
	}
	return (valid_tab_mv || valid_waste_mv || is_valid_deck_mv());
}
bool BoardT::is_win_state(){
	bool is_win = true;
	for(int i = 0; i < 8; i++){
		if(((this->foundation)[i].size() > 0) && ((this->foundation)[i].top().rank == KING)){
			is_win = is_win && true;
		}
		else{
			is_win = is_win && false;
		}
	}
	return is_win;
}

//Local functions implementation.
bool BoardT::two_decks(std::vector<CardT> deck){
	bool two_decks_bool;
	unsigned int count_hearts = 0, count_diamonds = 0, count_clubs = 0, count_spades = 0;
	for(unsigned int i = 0; i < deck.size(); i++){
		bool is_rank = (deck[i].rank >= 1) && (deck[i].rank <= 13);
		if(is_rank){
			if(deck[i].suit == Heart){count_hearts += 1;}
			if(deck[i].suit == Diamond){count_diamonds += 1;}
			if(deck[i].suit == Club){count_clubs += 1;}
			if(deck[i].suit == Spade){count_spades += 1;}
		}
	}
	two_decks_bool = (count_hearts == 26) && (count_diamonds == 26) && (count_clubs == 26) && (count_spades == 26);
	return two_decks_bool;
}
unsigned int BoardT::cnt_cards_seq(SeqCardStackT seq){
	unsigned int seq_count = 0;
	for(unsigned int i = 0; i < seq.size(); i++){
		seq_count += cnt_cards_stack(seq[i]);
	}
	return seq_count;
}
unsigned int BoardT::cnt_cards_stack(CardStackT stck){
	unsigned int stack_count = 0;
	std::vector<CardT> check = stck.toSeq();
	bool is_suit, is_rank;
	for(unsigned int i = 0; i < check.size(); i++){
		is_suit = (check[i].suit >= 0) && (check[i].suit <= 3);
		is_rank = (check[i].rank >= 1) && (check[i].rank <= 13);
		if(is_suit && is_rank){stack_count += 1;}
	}	
	return stack_count;
}
unsigned int BoardT::cnt_cards(SeqCardStackT T, SeqCardStackT F, CardStackT D, CardStackT W){
	return (cnt_cards_seq(T)+cnt_cards_seq(F)+cnt_cards_stack(D)+cnt_cards_stack(W));	
}
SeqCardStackT BoardT::init_seq(unsigned int n){
	SeqCardStackT seq;
	for(unsigned int i = 0; i < n; i++){
		CardStackT tab_member;
		seq.push_back(tab_member);
	}
	return seq;
}
SeqCardStackT BoardT::tab_deck(std::vector<CardT> deck){
	SeqCardStackT Tab = init_seq(10);
	for(int i = 0; i < 10; i++){
		CardStackT tab_member;
		for(int j = 4*i; j < 4*i+4; j++){
			tab_member.push(deck[j]);
		}
		Tab[i] = (tab_member);
	}
	return Tab;
}
bool BoardT::is_valid_pos(CategoryT type, unsigned int n){
	bool tab_case, foundation_case, valid_tab_size, valid_foundation_size;
	valid_tab_size = ((n >= 0) && (n <= 9));
	valid_foundation_size = ((n >= 0) && (n <= 7));
	if((type == Tableau) && valid_tab_size){
		tab_case = true;
		return tab_case;
	}
	else if((type == Foundation) && valid_foundation_size){
		foundation_case = true;
		return foundation_case;
	}
	else{return false;}
}
bool BoardT::valid_tab_tab(unsigned int n_1, unsigned int n_2){
	bool case_1, case_2;
	
	if((this->tableau)[n_1].size() > 0){
		if((this->tableau)[n_2].size() > 0){case_1 = tab_placeable((this->tableau)[n_1].top(), (this->tableau)[n_2].top());}
		else if((this->tableau)[n_2].size() == 0){case_1 = true;}
	}
	
	if((this->tableau)[n_1].size() == 0){case_2 = false;}
	
	if(case_1 || case_2){return true;}
	else{ return false;}
}
bool BoardT::valid_tab_foundation(unsigned int n_1, unsigned int n_2){
	bool case_1 = false , case_2;
	
	if((this->tableau)[n_1].size() > 0){
		if((this->foundation)[n_2].size() > 0){case_1 = foundation_placeable((this->tableau)[n_1].top(), (this->foundation)[n_2].top());}
		else if((this->foundation)[n_2].size() == 0){case_1 = ((this->tableau)[n_1].top().rank == ACE);}
	}
	if((this->tableau)[n_1].size() == 0){case_2 = false;}
	
	if(case_1 || case_2){return true;}
	else{ return false;}
}
bool BoardT::valid_waste_tab(unsigned int n){
	bool case_1, case_2;
	
	if((this->tableau)[n].size() > 0){case_1 = tab_placeable(waste.top(), (this->tableau)[n].top());}
	else{case_1 = false;}
	
	if((this->tableau)[n].size() == 0){case_2 = true;}
	else{case_2 = false;}
	
	if(case_1 || case_2){return true;}
	else{return false;} 
}
bool BoardT::valid_waste_foundation(unsigned int n){
	bool case_1, case_2;
	
	if((this->foundation)[n].size() > 0){case_1 = foundation_placeable((this->waste).top(), (this->foundation)[n].top());}
	else{case_1 = false;}
	
	if((this->foundation)[n].size() == 0){case_2 = ((this->waste).top().rank == ACE);}
	else{case_2 = false;}
	
	if(case_1 || case_2){return true;}
	else{ return false;}
}
bool BoardT::tab_placeable(CardT c_1, CardT c_2){
	bool suit_match = (c_1.suit == c_2.suit);
	bool rank_order = (c_1.rank == ((c_2.rank)-1));
	
	if(suit_match && rank_order){return true;} 
	else{return false;}
}
bool BoardT::foundation_placeable(CardT c_1, CardT c_2){
	bool suit_match = (c_1.suit == c_2.suit);
	bool rank_order = (c_1.rank == ((c_2.rank)+1));
	
	if(suit_match && rank_order){return true;} 
	else{return false;}
}