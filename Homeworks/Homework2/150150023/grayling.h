#ifndef GRAYLING_H
#define GRAYLING_H

#include <string>
#include <iostream> 

class Grayling {

protected:
	short age; //age years
	std::string name; //name
	char gender; // gender (giving birth or not)
	bool alive; // indicate whether alive (or not)
	bool mutant; // indicate whether mutant (or not)

public:
	Grayling(); // default constructor
	Grayling(char , std::string ); // constructor with paramaters 
	Grayling(const Grayling&); // copy constructor
	~Grayling(); // destructor
	virtual void print() const; // virtual constant print();
	virtual void givebirth(); // virtual  givebirth();
	virtual void aging(); // virtual  aging();
};



#endif