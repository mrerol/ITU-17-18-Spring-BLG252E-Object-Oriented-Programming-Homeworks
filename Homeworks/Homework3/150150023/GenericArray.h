#ifndef _GenericArray_h_
#define _GenericArray_h_

#include <string>

template <class Type>
class genericArray {
private:
	const int size;
	char bonus;
public:
	Type *elements;
	Type total;

	genericArray(); // default constructor
	genericArray(int); //constructor with arguments
	genericArray(genericArray &); //copy constructor
	~genericArray(); //destructor

	void print(std::string)const;
	Type sum();

};


#endif
