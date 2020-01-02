/**
 * \file Grid.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief Grid module that creates a grid.
 * \date April 9th 2019
 */

#ifndef A4_READ_H_
#define A4_READ_H_
#include <vector>
#include <string>
#include "CellT.h"
/**
 *  \brief Class that creates an instance of a grid.
 *  \details Creates a grid of size n x n.
 */
 
class Grid{
	public:
		std::vector< std::vector<CellT> > GameGrid;
		unsigned int grid_size;
		
		/**
		 *  \brief Constructor for grid.
		 *  \details An empty constructor.
		 */
		Grid();
		
		/**
		 *  \brief Constructor for a new grid of cells.
		 *  \details Creates a new instance of grid where all the cells are dead cells.
		 *  \param size size of the n x n grid.
		 */
		Grid(unsigned int size);
		
		/**
		 *  \brief Returns size of grid.
		 *  \details Returns this->size.
		 */
		unsigned int size();
		
		/**
		 *  \brief Adds pattern to grid.
		 *  \details Modifies grid object to include live cells.
		 *  \param element String corresponding to desired file's path.
		 *  \throw invalid_argument if the file isn't a .txt file.
		 */
		void read_pattern(std::string Filename);
};
#endif