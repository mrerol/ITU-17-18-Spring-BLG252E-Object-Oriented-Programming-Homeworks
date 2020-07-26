#include "grayling1.h"

// default constructor
Grayling1::Grayling1() {
	mutated_to = "Grayling2";
	MPI = 30;
	MP = 0;
	mutate_at = 60;
}

// constructor with paramaters
Grayling1::Grayling1(char gender_in, std::string name_in):Grayling::Grayling(gender_in, name_in) {
	mutated_to = "Grayling2";
	MPI = 30;
	MP = 0;
	mutate_at = 60;
}

// copy constructor
Grayling1::Grayling1(const Grayling1& in_object, char gender_in, std::string name_in):Grayling(in_object){
	this->name = name_in;
	this->mutated_to = in_object.mutated_to;
	this->MPI = in_object.MPI;
	this->MP = in_object.MP;
	this->mutate_at = in_object.mutate_at;
}

// destructor
Grayling1::~Grayling1() {
	//std::cout << "Grayling1 destructor invoked" << std::endl;
}

// virtual constant print();
void Grayling1::print() const {
	std::cout << "- Grayling 1 -> Age: " << age << " Nname: " << name << " G: " << gender <<" MPI: "<<MPI<<" MP "<<MP<<" Mutate at: "<<mutate_at<<std::endl;
}

// virtual givebirth();
void Grayling1::givebirth() {
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
		std::cout << "- Grayling gave birth to 2 offsprings!" << std::endl;
}

// virtual aging();
void Grayling1::aging() {
	
	this->age++;
	this->MP = this->MPI + this->MP;

	if (this->alive == false) {
		std::cout << "- Trying to AGING BUT " << this->name << " is not alive" << std::endl;
	}
	else if(this->mutant==true){

		std::cout<<"- AGING: name: "<<this->name<<" -> "<<this->mutated_to<<" Age: " << this->age << " MPI: " << this->MPI << " MP:" << MP << std::endl;
	}
	else {
		std::cout << "- AGING: name: " << this->name << " -> Age: " << this->age << " MPI: " << this->MPI << " MP:" << MP << std::endl;
	}

	if (this->MP == 60) {
		this->alive = true;
		this->mutant = true;
		this->MP = 0;
		this->MPI = 40;
		std::cout << "- Mutated TO: " << this->mutated_to << std::endl;
	}
	else if ( this->age==4) {
		this->alive = false;
		std::cout << "- " << this->name << " is dead because of AGING!" << std::endl;
	}
	

}