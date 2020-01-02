#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "../include/CellT.h"
#include "../include/Grid.h"
#include "../include/Model.h"
#include "../include/View.h"

int main() {
	
	CellT test_ob;
	std::cout << "State at first:" << test_ob.state << std::endl;
	test_ob.cell_genesis();
	std::cout << "State post genesis:" << test_ob.state << std::endl;
	test_ob.cell_mortem();
	std::cout << "State post mortem:" << test_ob.state << std::endl;
	
	Grid test_Grid(5); 
	
	test_Grid.read_pattern("./experiment/simple_cells.txt");
	
	Model test_Model (test_Grid);
	Model new_test_Model = test_Model.game_of_life();
	View  test_view(new_test_Model);
	test_view.Console_Output();
	test_view.Write_Output("./experiment/game_state.txt");
  	return 0;
}