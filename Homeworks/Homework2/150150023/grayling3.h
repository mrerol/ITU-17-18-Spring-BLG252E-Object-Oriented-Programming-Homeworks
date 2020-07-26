#include "grayling.h"

class Grayling3 :public Grayling {

private:
	std::string mutated_to; //name of Grayling form that the current fish mutated to
	double MPI; //mutation probability increasing (MPI) rate per year (30%, 40% or 50% according to variations / forms)
	double MP;//mutation probability (MP) that current fish have (0 at the creation)
	double mutate_at; // the mutation probability that the current fish mutate at

public:
	Grayling3(); // default constructor
	Grayling3(char, std::string); // constructor with paramaters
	Grayling3(const Grayling3&, char, std::string);  // copy constructor	
	~Grayling3(); // destructor
	void print() const; // virtual constant print();
	void givebirth(); // virtual  givebirth();
	void aging();  // virtual  aging();
};