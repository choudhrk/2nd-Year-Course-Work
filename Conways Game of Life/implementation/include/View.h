/**
 * \file View.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief View object for a given game Model.
 * \date April 9th 2019
 */
 
#ifndef A4_VIEW_H_
#define A4_VIEW_H_
#include <string>
#include "CellT.h"
#include "Grid.h"
#include "Model.h"

class View{
	public:
		Model Game_State;
		/**
		 *  \brief Constructor for View.
		 *  \details An empty constructor.
		 */
		View();
		
		/**
		 *  \brief Constructor for View object.
		 *  \details Creates a new instance of View containing specified model to output.
		 *  \param State model which is to be viewed.
		 */
		View(Model State);
		
		/**
		 *  \brief Outputs a given model to a console screen.
		 *  \details Loops through each row and column of a give model 
		 			 and prints each CellT object's state to the console screen.
		 */
		void Console_Output();
		
		/**
		 *  \brief Writes a model's state to a .txt file.
		 *  \details Writes each CellT members state to given .txt file.
		 *  \param element String corresponding to desired output file's path.
		 *  \throw invalid_argument if the given file isn't a .txt file.
		 */
		void Write_Output(std::string FileName);
};

#endif