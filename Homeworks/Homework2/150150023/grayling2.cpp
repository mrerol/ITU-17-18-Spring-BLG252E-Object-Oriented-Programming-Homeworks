#include "grayling2.h"

// default constructor
Grayling2::Grayling2() {
	mutated_to = "Grayling3";
	MPI = 40;
	MP = 0;
	mutate_at = 80;
}

// constructor with paramaters
Grayling2::Grayling2(char gender_in, std::string name_in) :Grayling::Grayling(gender_in, name_in) {
	mutated_to = "Grayling3";
	MPI = 40;
	MP = 0;
	mutate_at = 80;
}

// copy constructor
Grayling2::Grayling2(const Grayling2& in_object, char gender_in, std::string name_in) :Grayling(in_object) {
	this->name = name_in;
	this->mutated_to = in_object.mutated_to;
	this->MPI = in_object.MPI;
	this->MP = in_object.MP;
	this->mutate_at = in_object.mutate_at;
}

// destructor
Grayling2::~Grayling2() {
	//std::cout << "Grayling2 destructor invoked" << std::endl;
}

// virtual constatn print();
void Grayling2::print() const {
	std::cout << "- Grayling 2 -> Age: " << age << " Nname: " << name << " G: " << gender << " MPI: " << MPI << " MP " << MP << " Mutate at: " << mutate_at << std::endl;

}

// virtual  givebirth();
void Grayling2::givebirth() {
	if (this->alive == false && this->gender == 'f') {
		std::cout << "- Trying to GIVE BIRTH BUT" << this->name << " is not alive" << std::endl;
	}
	else if (this->gender == 'm' && this->alive) {
		std::cout << "- Trying to GIVE BIRTH BUT" << this->name << " No ability to give birth due to gender!" << std::endl;
	}
	else if (this->alive == false && this->gender == 'm') {
		std::cout << "- Trying to GIVE BIRTH BUT" << this->name << " is not alive and No ability to give birth due to gender!" << std::endl;

	}
	else
		std::cout << "- Grayling gave birth to 1 offsprings!" << std::endl;
}

// virtual  aging();
void Grayling2::aging() {
	this->age++;
	this->MP = this->MPI + this->MP;

	if (this->alive == false) {
		std::cout << "- Trying to AGING BUT " << this->name << " is not alive" << std::endl;
	}
	else if (this->mutant == true) {

		std::cout << "- AGING: name: " << this->name << " -> " << this->mutated_to << " Age: " << this->age << " MPI: " << this->MPI << " MP:" << MP << std::endl;
	}
	else {
		std::cout << "- AGING: name: " << this->name << " -> Age: " << this->age << " MPI: " << this->MPI << " MP:" << MP << std::endl;
	}

	if (this->MP == 80) {
		this->alive = true;
		this->mutant = true;
		this->MP = 0;
		this->MPI = 50;
		std::cout << "- Mutated TO: " << this->mutated_to << std::endl;
	}
	else if (this->age == 3 && this->alive) {
		this->alive = false;
		std::cout << "- " << this->name << " is dead because of AGING!" << std::endl;
	}

}