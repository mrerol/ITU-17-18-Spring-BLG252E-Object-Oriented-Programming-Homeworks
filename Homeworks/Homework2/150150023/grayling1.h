#include "grayling.h"

class Grayling1 :public Grayling {

private:

	std::string mutated_to; //name of Grayling form that the current fish mutated to
	double MPI; //mutation probability increasing (MPI) rate per year (30%, 40% or 50% according to variations / forms)
	double MP;//mutation probability (MP) that current fish have (0 at the creation)
	double mutate_at; // the mutation probability that the current fish mutate at

public:
	Grayling1(); // default constructor
	Grayling1(char, std::string); // constructor with paramaters
	Grayling1(const Grayling1&, char, std::string); // copy constructor
	~Grayling1(); // destructor
	void print() const; // virtual constant print();
	void givebirth(); // virtual  givebirth();
	void aging(); // virtual  aging();

};
