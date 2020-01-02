/**
 * \file CardTypes.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief Defining card type and deck information.
 *\ date March 18th 2019
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Total cards used in the game.
 */
#define TOTAL_CARDS 104

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Suit types.
 */
enum SuitT {Heart, Diamond, Club, Spade};

/**
 * \brief Card categories.
 */
enum CategoryT{Tableau, Foundation, Deck,  Waste};

/**
 * \brief CardT structure.
 */
struct CardT{
	SuitT suit;
	RankT rank;
};
#endif
