#include "Citizen.h"

using namespace std;

class CivilRegistry {
private:
	list <Citizen> wApp;
	list <Citizen> wOutApp;

public:
	CivilRegistry() {};
	~CivilRegistry();
	void insertCitizen( Citizen &);
	void removeCitizen(int);
};
