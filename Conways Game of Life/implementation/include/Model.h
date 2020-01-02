/**
 * \file Model.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief Model that handles state of the game.
 * \date April 9th 2019
 */

#ifndef A4_MODEL_H_
#define A4_MODEL_H_
#include <vector>
#include <string>
#include "CellT.h"
#include "Grid.h"

/**
 *  \brief Class that creates an model of a given pattern.
 *  \details Creates an initial model of the game using a grid containing an initial pattern.
 */
class Model{
	public:
		Grid Model_Grid;
		
		/**
		 *  \brief Constructor for model.
		 *  \details An empty constructor for model.
		 */
		Model();
		
		/**
		 *  \brief Constructor for model of the game of life.
		 *  \details Takes in a grid and performs various operations on the grid.
		 *  \param Input_Grid grid on which gameplay will be modelled.
		 */
		Model(Grid Input_Grid);	
		
		/**
		 *  \brief Counts the live neighbours of a given cell.
		 *  \details Checks whether the following cells are within correct range:
		 			 [i-1][j-1], [i-1][j], [i-1][j+1], 
					 [i][j-1],             [i][j+1], 
					 [i+1][j-1], [i+1][j], [i+1][j+1],
					 for a given [i][j]
					 Then it checks for said cells are dead or alive and 
					 increments count by 1 for every live neighbour and returns the count.
		 *  \param i Specifies row element.
		 *  \param j Specifies column element.
		 *  \throw out_of_range if i or j doesn't belong to the set of grid indices.
		 */
		int count_live_neighbours(unsigned int i, unsigned int j);
		
		/**
		 *  \brief Checks if a given cell will die by underpopulation.
		 *  \details Checks if a given cell is alive and then its neighbours. 
		 			 If neighbours are less than on equal to 1 it dies.
		 *  \param i Specifies row element.
		 *  \param j Specifies column element.
		 *  \throw out_of_range if i or j doesn't belong to the set of grid indices.
		 */
		bool is_underpopulation(unsigned int i, unsigned int j);
		
		/**
		 *  \brief Checks if a given cell will live on to the next generation.
		 *  \details Checks if a given cell is alive and then its neighbours. 
		 			 If neighbours are equal to 2 or 3 it lives on.
		 *  \param i Specifies row element.
		 *  \param j Specifies column element.
		 *  \throw out_of_range if i or j doesn't belong to the set of grid indices.
		 */
		bool is_next_gen(unsigned int i, unsigned int j);
		
		/**
		 *  \brief Checks if a given cell will die by overpopulation.
		 *  \details Checks if a given cell is alive and then its neighbours. 
		 			 If neighbours are greater than 3 it dies.
		 *  \param i Specifies row element.
		 *  \param j Specifies column element.
		 *  \throw out_of_range if i or j doesn't belong to the set of grid indices.
		 */
		bool is_overpopulation(unsigned int i, unsigned int j);
		
		/**
		 *  \brief Checks if a given cell will take birth.
		 *  \details Checks if a given cell is dead and then its neighbours. 
		 			 If neighbour count is exactly 3 it takes birth.
		 *  \param i Specifies row element.
		 *  \param j Specifies column element.
		 *  \throw out_of_range if i or j doesn't belong to the set of grid indices.
		 */
		bool is_reproduction(unsigned int i, unsigned int j);
		
		/**
		 *  \brief Performs actual gameplay.
		 *  \details Returns a new model with a new grid configuration 
		 	         based on the boolean functions 
					 is_underpopulation,is_next_gen, is_overpopulation, and is_reproduction.
		 */
		Model game_of_life();
};

#endif