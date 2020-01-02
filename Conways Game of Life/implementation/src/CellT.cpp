#include <iostream>
#include <string>
#include "CellT.h"
		
CellT::CellT(){
	this->state = "";
}
void CellT::cell_genesis(){
	this->state = "A";
}
void CellT::cell_mortem(){
	this->state = "*";
}