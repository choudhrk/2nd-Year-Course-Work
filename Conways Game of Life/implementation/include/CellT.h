/**
 * \file CellT.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief CellT abstract object and its possible states.
 * \date April 7th 2019
 */
 
#ifndef A4_CELLT_H_
#define A4_CELLT_H_
#include <string>

/**
 *  \brief Class defining a cell type object.
 *  \details Implements setters that make a cell dead or alive.
 */
class CellT{
	public:
		std::string state;
		
		/**
		 *  \brief Constructor for a new cell.
		 *  \details Creates a new instance of empty cell.
		 */
		CellT();
		
		/**
		 *  \brief Method for creating a live cell.
		 *  \details Sets the state of CellT object to "[A]"
		 */
		void cell_genesis();
		
		/**
		 *  \brief Method for creating a dead cell.
		 *  \details Sets the state of CellT object to "[]"
		 */
		void cell_mortem();
};
#endif