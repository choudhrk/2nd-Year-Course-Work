#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "../include/CellT.h"
#include "../include/Grid.h"

Grid::Grid(){}

Grid::Grid(unsigned int size){
	(this->grid_size) = size;
	for(unsigned int i = 0; i < size; i++){
		std::vector<CellT> addCells;
		for(unsigned int j = 0; j < size; j++){
			CellT addCell;
			addCell.cell_mortem();
			addCells.push_back(addCell);
		}
		(this->GameGrid).push_back(addCells);
	}
}
unsigned int Grid::size(){
	return (this->grid_size);
}
void Grid::read_pattern(std::string Filename){
	int n = Filename.length();
	bool correct_file = (Filename[n-4] == '.') && (Filename[n-3] == 't') && (Filename[n-2] == 'x') && (Filename[n-1] == 't');
	if(!correct_file){
		throw std::invalid_argument("Invalid file type!");
	}
	else{
		std::ifstream pattern_file;
		pattern_file.open(Filename, std::ifstream::in);
		std::vector<std::string> file_lines;
		if(!pattern_file.is_open()){
			std::cout << "Failed to open file" << std::endl;
		}
		else{
			std::string line;
			while(pattern_file){
				if(pattern_file.eof()){
					break;
				}
				getline(pattern_file, line);
				file_lines.push_back(line);
			}
			for (unsigned int i = 0; i < file_lines.size(); i++) { 
				for (unsigned int j = 0; j < file_lines[i].size(); j++) { 
					if(file_lines[i][j] == 'A'){
						(this->GameGrid)[i][j].cell_genesis();
					}
				}
				std::cout << std::endl;
		 	}
			pattern_file.close();
		}
	}
}