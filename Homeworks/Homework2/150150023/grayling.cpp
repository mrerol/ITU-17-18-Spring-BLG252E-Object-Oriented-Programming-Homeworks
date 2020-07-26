#include "grayling.h"

// default constructor
Grayling::Grayling() {
	age = 0;
	name = "";
	gender = 'X';
	alive = false;
	mutant = false;
}

// constructor with paramaters
Grayling::Grayling(char gender_in, std::string name_in) {
	age = 0;
	name = name_in;
	gender = gender_in;
	alive = true;
	mutant = false;
}
// copy constructor
Grayling::Grayling(const Grayling& in_object) {
	this->age = in_object.age;
	this->name = in_object.name;
	this->gender = in_object.gender;
	this->alive = in_object.alive;
	this->mutant = in_object.mutant;
}

// destructor
Grayling::~Grayling() {
	//std::cout << "Grayling destructor invoked" << std::endl;
}

// virtual constant print();
void Grayling::print() const {
	std::cout << "- Grayling -> Age: " << age << " Nname: " << name << " G: " << gender << std::endl;
}

// virtual givebirth();
void Grayling::givebirth(){
	if (this->alive==false && this->gender == 'f') {
		std::cout << "- Trying to GIVE BIRTH BUT" <<this->name<<" is not alive"<< std::endl;
	}
	else if (this->gender == 'm' && this->alive ) {
		std::cout << "- Trying to GIVE BIRTH BUT" << this->name << " No ability to give birth due to gender!" << std::endl;
	}
	else if(this->alive == false && this->gender == 'm'){
		std::cout << "- Trying to GIVE BIRTH BUT" << this->name << " is not alive and No ability to give birth due to gender!" << std::endl;

	}else
		std::cout << "- Grayling gave birth to 2 offsprings!" << std::endl;
}

// virtual aging();
void Grayling::aging(){
	this->age++;
	std::cout << "- Grayling -> Age: " << this->age << " Nname: " << this->name << " G: " << this->gender << std::endl;
}

