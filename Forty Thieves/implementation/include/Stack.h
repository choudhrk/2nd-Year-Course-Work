/**
 * \file Stack.h
 * \author Kanakabha Choudhri, MacID: choudhrk
 * \brief Defining stack functions and properties.
 * \date March 20th 2019
 */
 
#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>

/**
 *  \brief Template class for defining various operations of a general stack.
 *  \details Implements a template for a general stack.
 */
template<class T>
class Stack{
	private:
		std::vector<T> S; 
	public:
		/**
		 *  \brief Constructor for a new stack.
		 *  \details Creates a new instance of empty stack.
		 */
		Stack();
		
		/**
		 *  \brief Constructor for a new stack.
		 *  \details Creates a new instance of stack when given an initial vector.
		 *  \param s A vector which stores the various objects of type T.
		 */
		Stack(std::vector<T> s);
		
		/**
		 *  \brief Adds an element to the stack.
		 *  \details Makes a new stack including the given element to add.
		 *  \param element The element to be added.
		 */
		Stack<T> push(T element);
		
		/**
		 *  \brief Removes an element from the stack.
		 *  \details Makes a new stack excluding the top most element.
		 *  \throw out_of_range The stack is empty.
		 */
		Stack<T> pop();
		
		/**
		 *  \brief Returns top element.
		 *  \details Accesses the back of the vector.
		 *  \throw out_of_range The stack is empty.
		 */
		T top();
		
		/**
		 *  \brief Returns size of stack.
		 *  \details Implement size function.
		 */
		unsigned int size();
		
		/**
		 *  \brief Returns the stack.
		 *  \details Returns the vector element.
		 */
		std::vector<T> toSeq();
};
#endif