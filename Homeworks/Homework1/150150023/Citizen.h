#include "Time.h"

using namespace std;

class Citizen {
private:
	char *idNo;
	char *name;
	char *surname;
	bool hasApp;
	Time *appTime;
	char *appSlot;
public:
	Citizen(char *, char *, char *, char *, char *, char *,char *);
	~Citizen();
	Time& getAppTime();
	const bool gethasApp();
	const string getAppSlot();
	const string get_name();
};
