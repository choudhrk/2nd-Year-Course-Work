// Implementation here
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../include/Stack.h"
#include "../include/CardTypes.h"

template <class T>
Stack<T>::Stack(){
	std::vector<T> emp_s;
	this->S = emp_s;
}

template <class T>
Stack<T>::Stack(std::vector<T> s){
	this->S = s;
}

template <class T>
Stack<T> Stack<T>::push(T element){
	(this->S).push_back(element);
	Stack<T> new_stack (this->S);
	return new_stack;
}

template <class T>
Stack<T> Stack<T>::pop(){
	if ((this->S).empty() == true){
		throw std::out_of_range("Need an element to pop.");
	}
	else{
		(this->S).pop_back();
		Stack<T> new_stack (this->S);
		return new_stack;
	}
}

template <class T>
T Stack<T>::top(){
	if ((this->S).empty() == true){
		throw std::out_of_range("Need at least one element to choose the top from.");
	}
	else{
	return (this->S)[(this->S).size() - 1];
	}
}

template  <class T>
unsigned int Stack<T>::size(){
        return (this->S).size();
}

template  <class T>
std::vector<T>  Stack<T>::toSeq(){
	return (this->S);
}
// Keep this at bottom
template class Stack<CardT>;