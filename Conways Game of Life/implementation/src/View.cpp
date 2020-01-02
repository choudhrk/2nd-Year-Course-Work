#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/CellT.h"
#include "../include/Grid.h"
#include "../include/Model.h"
#include "../include/View.h"

View::View(){}
View::View(Model State){
	(this->Game_State) = State;
}
void View::Console_Output(){
	Grid output_grid = (this->Game_State).Model_Grid;
	for (unsigned int i = 0; i < output_grid.size(); i++) { 
		for (unsigned int j = 0; j < output_grid.GameGrid[i].size(); j++) { 
			std::cout << output_grid.GameGrid[i][j].state;
		}
		std::cout << std::endl;
    } 
}

void View::Write_Output(std::string Filename){
	int n = Filename.length();
	bool correct_file = (Filename[n-4] == '.') && (Filename[n-3] == 't') && (Filename[n-2] == 'x') && (Filename[n-1] == 't');
	if(!correct_file){
		throw std::invalid_argument("Invalid file type!");
	}
	
	std::ofstream state_file;
	state_file.open(Filename);
	if(!state_file.is_open()){
			std::cout << "Failed to open file" << std::endl;
	}
	else{
		Grid write_grid = (this->Game_State).Model_Grid;
		for (unsigned int i = 0; i < write_grid.size(); i++) { 
			for (unsigned int j = 0; j < write_grid.GameGrid[i].size(); j++) { 
				state_file << write_grid.GameGrid[i][j].state;
			}
			if(i == write_grid.size() - 1){
				break;
			}
		state_file << std::endl;
    	} 
	}
	state_file.close();
} 