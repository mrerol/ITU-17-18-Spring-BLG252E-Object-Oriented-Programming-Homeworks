#include <iostream>
#include "Money.h"

//default constructor
Money::Money():lira(0),kurus(0) {

}

//copy constructor
Money::Money(Money& in_object) {
	lira = in_object.getLira();
	kurus = in_object.getKurus();
}

// constructor with parameters
Money::Money(int in_lira, int in_kurus) {

	if (in_lira < 0 || in_kurus < 0) {
		throw std::string("The amount of money cannot be below zero!");
	}
	else if (in_kurus >= 100) {
		throw std::string("The amount of kurus cannot be above of one hundred!");
	}
	else {
		lira = in_lira;
		kurus = in_kurus;
	}
}

// constructor for comaprison - this takes money like 5.20 not 5.2 always needed 2 floating step
Money::Money(double in_money) {

	if (in_money < 0 ) {
		throw std::string("The amount of money cannot be below zero!");
	}
	else if ((in_money - (int)in_money)  >= 100) {
		throw std::string("The amount of kurus cannot be above of one hundred!");
	}
	else {
		lira = (int)in_money;
		kurus = (in_money - (int)in_money)*100; // taking floating part
	}
}

//destructor
Money::~Money() {
	//std::cout << "Money Destructor invoked!" << std::endl;
}

int Money::getLira()const{
	return lira;
}
int Money::getKurus()const{
	return kurus;
}

//setter function for lira
void Money::setLira(int in_lira) {
	lira = in_lira;
}

//setter function for kurus
void Money::setKurus(int in_kurus) {
	kurus = in_kurus;
}

//operator= overloading
Money& Money::operator=(Money const &in_object) {

	this->setLira(in_object.getLira());
	this->setKurus(in_object.getKurus());

	return *this;
}

//operator+ overloading
Money Money::operator+(Money const &in_object) {

	Money temp_object;

	temp_object.setLira(lira + in_object.getLira());
	temp_object.setKurus(kurus + in_object.getKurus());

	if(temp_object.getKurus() >= 100) {
		temp_object.setKurus(temp_object.getKurus()-100);
		temp_object.setLira(temp_object.getLira()+1);

	}
	
	return temp_object;
}

//operator- overloading
Money Money::operator-(Money const &in_object) {

	Money temp_object;

	temp_object.setLira(lira - in_object.getLira());
	temp_object.setKurus(kurus - in_object.getKurus());

	if (temp_object.getLira() < 0) {
		throw std::string("The amount of money cannot be below zero!");
	}
	else if (temp_object.getKurus() < 0) {
		temp_object.setKurus(temp_object.getKurus() + 100);
		temp_object.setLira(temp_object.getLira() - 1);
	}


	return temp_object;
}

//operator< overloading
bool Money::operator<(Money const &in_object) {
	if (this->getLira() < in_object.getLira()) {
		return true;
	}
	else if ((this->getLira() == in_object.getLira()) && (this->getKurus() < in_object.getKurus())) {
		return true;
	}
	else
		return false;
}

//operator> overloading
bool Money::operator>(Money const &in_object) {
	if (this->getLira() > in_object.getLira()) {
		return true;
	}
	else if ((this->getLira() == in_object.getLira()) && (this->getKurus() > in_object.getKurus())) {
		return true;
	}
	else
		return false;
}

//operator== overloading
bool Money::operator==(Money const &in_object) {

	if ((this->getLira() == in_object.getLira()) && (this->getKurus() == in_object.getKurus())) {
		return true;
	}
	else
		return false;
}

//operator<< overloading
std::ostream& operator<<(std::ostream& os, const Money& in_object)
{
	os << in_object.lira << " lira, " << in_object.kurus << " kurus";
	return os;
}