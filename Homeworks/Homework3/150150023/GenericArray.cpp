#include "GenericArray.h"
#include "Money.h"

//default constructor
template <class Type>
genericArray<Type>::genericArray():size(1),total(0),bonus('x') {

}

//copy constructor
template <class Type>
genericArray<Type>::genericArray(genericArray& in_object)  {
	
	for (int i = 0; i < size; i++) {
		elements[i] = in_object.elements[i];
	}

	total = in_object.total;
	bonus = in_object.bonus;
}
//constructor with arguments
template <class Type>
genericArray<Type>::genericArray(int in_size):size(in_size),total(0),bonus('x') {
	
	if (size <= 0) {
		throw std::string("The size of array cannot be below zero or equal zero!");
	}
	else
		elements = new Type[in_size];

}

//destructor
template <class Type>
genericArray<Type>::~genericArray() {
	delete[] elements;
	//std::cout << "genericArray Destructor invoked!" << std::endl;
}

//sum function
template <class Type>
Type genericArray<Type>::genericArray::sum() {

	for (int i = 0; i < size; i++) {
		total = total + elements[i];
	}

	std::cout << "Your total amount is " << total << std::endl;

	if (total > Type(100.0)) {
		total = total + Type(5.0);
		bonus = '+';
	}
	else if (total < Type(100.0)) {
		total = total - Type(5.0);
		bonus = '-';
	}
	else
		bonus = 'x';


	return total;
}


//print function
template <class Type>
void genericArray<Type>::genericArray::print(std::string in_string)const {


	if (bonus == '+') {
		std::cout << "You have won 5 points bonus, new total is " << total << std::endl;
	}
	else if ( bonus == '-') {
		std::cout << "You have punished 5 points, new total is " << total << std::endl;
	}
	else
		std::cout << "There is no bonus, your total is same " << total << std::endl;


}

