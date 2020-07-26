#include "grayling3.h"

// default constructor
Grayling3::Grayling3() {
	mutated_to = "DEAD";
	MPI = 50;
	MP = 0;
	mutate_at = 100;
}

// constructor with paramaters
Grayling3::Grayling3(char gender_in, std::string name_in) :Grayling::Grayling(gender_in, name_in) {
	mutated_to = "DEAD";
	MPI = 50;
	MP = 0;
	mutate_at = 100;
}

// copy constructor
Grayling3::Grayling3(const Grayling3& in_object, char gender_in, std::string name_in) :Grayling(in_object) {
	this->name = name_in;
	this->mutated_to = in_object.mutated_to;
	this->MPI = in_object.MPI;
	this->MP = in_object.MP;
	this->mutate_at = in_object.mutate_at;
}

// destructor
Grayling3::~Grayling3() {
	//std::cout << "Grayling3 destructor invoked" << std::endl;
}

// virtual cosntant print();
void Grayling3::print() const {
	std::cout << "- Grayling 3 -> Age: " << age << " Nname: " << name << " G: " << gender << " MPI: " << MPI << " MP " << MP << " Mutate at: " << mutate_at << std::endl;

}

// virtual  givebirth();
void Grayling3::givebirth()  {
	
	if (this->gender == 'f')
		this->alive = false;
	else
		this->alive = true;

	if (this->alive==false && this->gender == 'f') {
		std::cout << "- Trying to GIVE BIRTH BUT " << this->name << " is not alive and No ability to give birth!" << std::endl;
	}
	else if (this->alive==false  && this->gender=='m') {
		std::cout << "- Trying to GIVE BIRTH BUT " << this->name << " is not alive and No ability to give birth due to gender and mutation!" << std::endl;
	} 
	else 
		std::cout << "- Trying to GIVE BIRTH BUT " << this->name << " No ability to give birth!" << std::endl;

}

// virtual  aging();
void Grayling3::aging() {
	this->age++;
	this->MP = this->MPI + this->MP;

	if (this->alive == false) {
		std::cout << "- Trying to AGING BUT " << this->name << " is not alive" << std::endl;
	} else {
		std::cout << "- AGING: name: " << this->name << " -> Age: " << this->age << " MPI: " << this->MPI << " MP:" << MP << std::endl;
	}

	 if (this->MP >= 100 && this->alive) {
		 this->alive = false;
		std::cout << "- " << this->name << " is dead because of HIGH MUTATION RATE!" << std::endl;
	}
}