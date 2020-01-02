/**
 * \file GameBoard.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief Defining the gameboard and various move properties.
 * \date March 23rd 2019
 */

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_
#include <vector>
#include "CardTypes.h"
#include "CardStack.h"
typedef std::vector<CardStackT> SeqCardStackT;
/**
 *  \brief BoardT class to define the gameboard.
 *  \details Implements a game board with various class members, local functions and general class functions.
 */
class BoardT{
	private:
		//State variants.
		SeqCardStackT tableau; //Size needs to be 10
		SeqCardStackT foundation;//Size needs to be 8
		CardStackT deck;
		CardStackT waste;
		std::vector<CardT> undistributed_deck;
		//Local methods.
		bool two_decks(std::vector<CardT> deck);
		unsigned int cnt_cards_seq(SeqCardStackT);
		unsigned int cnt_cards_stack(CardStackT);
		unsigned int cnt_cards(SeqCardStackT T, SeqCardStackT F, CardStackT D, CardStackT W); 
		SeqCardStackT init_seq(unsigned int n);
		SeqCardStackT tab_deck(std::vector<CardT> deck);
		bool is_valid_pos(CategoryT type, unsigned int n);
		bool valid_tab_tab(unsigned int n_1, unsigned int n_2);
		bool valid_tab_foundation(unsigned int n_1, unsigned int n_2);
		bool valid_waste_tab(unsigned int n);
		bool valid_waste_foundation(unsigned int n); 
		bool tab_placeable(CardT c_1, CardT c_2);
		bool foundation_placeable(CardT c_1, CardT c_2);
	public: 
	
		/**
		 *  \brief Constructor for a new BoardT object.
		 *  \details An empty constructor.
		 */
		BoardT();
		
		/**
		 *  \brief Constructor for a new BoardT object.
		 *  \details Creates Tableau, Foundation, Deck and Waste piles in addition to an undistributed deck member.
		 *  \param deck A vector of type CardT representing two decks.
		 *  \throw invalid_argument If there doesn't exist two of each unique card in the given deck.
		 */
		BoardT(std::vector<CardT> deck);
		
		/**
		 *  \brief Checks for valid tableau moves.
		 *  \details Makes use of valid_tab_tab(unsigned int n_1, unsigned int n_2) and 
		 *           valid_tab_foundation(unsigned int n_1, unsigned int n_2).
		 *  \param type Category of stack to be added to.
		 *  \param n_1 Index of tableau stack to be added from.
		 *  \param n_2 Index of tableau or foundation stack to be added to.
		 *  \throw out_of_range If either tableau or foundation stacks to be added to aren't at a valid position.
		 */
		bool is_valid_tab_mv(CategoryT type, unsigned int n_1, unsigned int n_2);
		
		/**
		 *  \brief Checks for valid waste moves.
		 *  \details Makes use of valid_waste_tab(unsigned int n) and 
		 *           valid_waste_foundation(unsigned int n).
		 *  \param type Category of stack to be added to.
		 *  \param n Index of tableau or foundation stack to be added to.
		 *  \throw invalid_argument If either waste is empty.
		 */
		bool is_valid_waste_mv(CategoryT type, unsigned int n);
		
		/**
		 *  \brief Checks for valid deck moves.
		 *  \details Checks if size of deck is greater than 0.
		 */
		bool is_valid_deck_mv(); 
		
		/**
		 *  \brief Performs a tableau move.
		 *  \details Implements tableau move by pushing top of Tableau[n_1] stack
		 *           to desired Tableau/Foundation[n_2] stack and then performs a pop() 
		 *           operation on Tableau[n_1] stack.
		 *  \param type Category of stack to be added to.
		 *  \param n_1 Index of tableau stack to be added from.
		 *  \param n_2 Index of tableau or foundation stack to be added to.
		 *  \throw invalid_argument If either is_valid_tab_mv(type, n_1, n_2) 
		 *                          for tableau or foundation is false.
		 */
		void tab_mv(CategoryT type, unsigned int n_1, unsigned int n_2);
		
		/**
		 *  \brief Performs a waste move.
		 *  \details Implements waste move by pushing top of Waste stack
		 *           to desired Tableau/Foundation[n] stack and performs a pop() 
		 *           operation on Waste stack.
		 *  \param type Category of stack to be added to.
		 *  \param n Index of tableau or foundation stack to be added to.
		 *  \throw invalid_argument If is_valid_waste_mv(type, n) is false.
		 */
		void waste_mv(CategoryT type, unsigned int n);
		
		/**
		 *  \brief Performs a Deck move.
		 *  \details Implements deck move by pushing top of Deck stack
		 *           to desired Waste stack and performs a pop() 
		 *           operation on Deck stack.
		 *  \throw invalid_argument If is_valid_deck_mv() is false.
		 */
		void deck_mv(); 
		
		/**
		 *  \brief Returns specified Tableau stack.
		 *  \details Returns Tableau vector member at index n.
		 *  \param n Index of desired stack.
		 *  \throw out_of_range If is_valid_pos(Tableau, n) is false.
		 */
		CardStackT get_tab(unsigned int n);
		
		/**
		 *  \brief Returns specified Foundation stack.
		 *  \details Returns Foundation vector member at index n.
		 *  \param n Index of desired stack.
		 *  \throw out_of_range If is_valid_pos(Foundation, n) is false.
		 */
		CardStackT get_foundation(unsigned int n);
		
		/**
		 *  \brief Returns Deck stack.
		 *  \details Returns (this->deck).
		 */
		CardStackT get_deck();
		
		/**
		 *  \brief Returns Waste stack.
		 *  \details Returns (this->waste).
		 */
		CardStackT get_waste();
		
		/**
		 *  \brief Checks if theres a valid move.
		 *  \details Returns boolean result of checking 
		 *           whether a valid tableau move or valid waste move or valid deck move exists .
		 */
		bool valid_mv_exists();
		
		/**
		 *  \brief Checks if game board is in win state.
		 *  \details Returns boolean result of checking if the top of all foundations is of rank KING .
		 */
		bool is_win_state();
		
};
#endif
