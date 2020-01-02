#include <iostream>
#include <vector>
#include <string>
#include "../include/CellT.h"
#include "../include/Grid.h"
#include "../include/Model.h"

Model::Model(){}

Model::Model(Grid Input_Grid){
	(this->Model_Grid) = Input_Grid;
}

int Model::count_live_neighbours(unsigned int i, unsigned int j){
	int live_neighbours = 0;
	std::vector< std::vector<CellT>> check_cell;
	check_cell = (this->Model_Grid).GameGrid;
	unsigned int n = check_cell.size();
	bool correct_i = (i >= 0 && i < n);
	bool correct_j = (j >= 0 && j < n);
	if(!(correct_i && correct_j)){
		throw std::out_of_range("Invalid cell");
	}
	bool correct_row_1 = (i-1 >= 0 && i-1 < n);
	bool correct_row_2 = (i+1 > 0 && i+1 < n);
	bool correct_col_1 = (j-1 >= 0 && j-1 < n);
	bool correct_col_2 = (j+1 > 0 && j+1 < n);
	
	bool correct_left_upper_diagonal = correct_row_1 && correct_col_1;
	bool correct_upper_vertical = correct_row_1 && correct_j;
	bool correct_right_upper_diagonal = correct_row_1 && correct_col_2;
	bool correct_left_horizontal = correct_i && correct_col_1;
	bool correct_right_horizontal = correct_i && correct_col_2;
	bool correct_left_lower_diagonal = correct_row_2 && correct_col_1;
	bool correct_lower_vertical = correct_row_2 && correct_j;
	bool correct_right_lower_diagonal = correct_row_2 && correct_col_2;
	
	//Left-upper diagonal
	if(!correct_left_upper_diagonal){ live_neighbours = live_neighbours + 0;}
	else{ if(check_cell[i-1][j-1].state == "A"){ live_neighbours++; } }
	
	//Upper vertical
	if(!correct_upper_vertical){ live_neighbours = live_neighbours + 0; }
	else{ if(check_cell[i-1][j].state == "A"){ live_neighbours++; } }
	
	//Right-upper diagonal
	if(!correct_right_upper_diagonal){ live_neighbours = live_neighbours + 0; }
	else{ if(check_cell[i-1][j+1].state == "A"){ live_neighbours++; } }
	
	//Left horizontal
	if(!correct_left_horizontal){ live_neighbours = live_neighbours + 0; }
	else{ if(check_cell[i][j-1].state == "A"){ live_neighbours++; } }
	
	//Right horizontal
	if(!correct_right_horizontal){live_neighbours = live_neighbours + 0; } 
	else{if(check_cell[i][j+1].state == "A"){ live_neighbours++; } }
	
	//Left-lower diagonal
	if(!correct_left_lower_diagonal){live_neighbours = live_neighbours + 0;}
	else{ if((check_cell[i+1][j-1].state == "A")){ live_neighbours++; } }
	
	//Lower vertical
	if(!correct_lower_vertical){live_neighbours = live_neighbours + 0;}
	else{ if((check_cell[i+1][j].state == "A")){ live_neighbours++; } }
	
	//Right-lower diagonal
	if(!correct_right_lower_diagonal){ live_neighbours = live_neighbours + 0; }
	else{ if((check_cell[i+1][j+1].state == "A")){ live_neighbours++; } }
	
	return live_neighbours;
}

bool Model::is_underpopulation(unsigned int i, unsigned int j){
	unsigned int n = (this->Model_Grid).GameGrid.size();
	bool correct_i = (i >= 0 && i < n);
	bool correct_j = (j >= 0 && j < n);
	if(!(correct_i && correct_j)){
		throw std::out_of_range("Invalid cell");
	}
	bool is_alive = (this->Model_Grid).GameGrid[i][j].state == "A";
	bool count_check = (count_live_neighbours(i, j) <= 1);
	if(is_alive && count_check){return true;}
	else{return false;}
}
bool Model::is_next_gen(unsigned int i, unsigned int j){
	unsigned int n = (this->Model_Grid).GameGrid.size();
	bool correct_i = (i >= 0 && i < n);
	bool correct_j = (j >= 0 && j < n);
	if(!(correct_i && correct_j)){
		throw std::out_of_range("Invalid cell");
	}
	bool is_alive = (this->Model_Grid).GameGrid[i][j].state == "A";
	bool count_check = (count_live_neighbours(i, j) == 2) || (count_live_neighbours(i, j) == 3);
	if(is_alive && count_check){return true;}
	else{return false;}
}
bool Model::is_overpopulation(unsigned int i, unsigned int j){
	unsigned int n = (this->Model_Grid).GameGrid.size();
	bool correct_i = (i >= 0 && i < n);
	bool correct_j = (j >= 0 && j < n);
	if(!(correct_i && correct_j)){
		throw std::out_of_range("Invalid cell");
	}
	bool is_alive = (this->Model_Grid).GameGrid[i][j].state == "A";
	bool count_check = (count_live_neighbours(i, j) > 3);
	if(is_alive && count_check){return true;}
	else{return false;}
}
bool Model::is_reproduction(unsigned int i, unsigned int j){
	unsigned int n = (this->Model_Grid).GameGrid.size();
	bool correct_i = (i >= 0 && i < n);
	bool correct_j = (j >= 0 && j < n);
	if(!(correct_i && correct_j)){
		throw std::out_of_range("Invalid cell");
	}
	bool is_dead = (this->Model_Grid).GameGrid[i][j].state == "*";
	bool count_check = (count_live_neighbours(i, j) == 3);
	if(is_dead && count_check){return true;}
	else{return false;}
}

Model Model::game_of_life(){
	Grid new_grid((this->Model_Grid).size()+5);
	for(unsigned int i = 0; i < (this->Model_Grid).GameGrid.size(); i++){
		for(unsigned int j = 0; j < (this->Model_Grid).GameGrid[i].size(); j++){
			if(is_underpopulation(i, j)){
				new_grid.GameGrid[i][j].cell_mortem();
			}
			if(is_next_gen(i, j)){
				new_grid.GameGrid[i][j].cell_genesis();
			}
			if(is_overpopulation(i, j)){
				new_grid.GameGrid[i][j].cell_mortem();
			}
			if(is_reproduction(i, j)){
				new_grid.GameGrid[i][j].cell_genesis();
			}
		}
	}
	Model new_game_state(new_grid);
	return new_game_state;
}