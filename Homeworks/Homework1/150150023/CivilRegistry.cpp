#include "CivilRegistry.h"


void CivilRegistry::insertCitizen(Citizen &in_citizen) {


	if ((in_citizen.gethasApp()) && (wApp.empty())) {
		wApp.push_front(in_citizen);
	}
	else if((in_citizen.gethasApp()==false) && (wOutApp.empty())){
		wOutApp.push_front(in_citizen);
	}
	else  {

		if (in_citizen.gethasApp() == true) {//app varken

			list <Citizen>::iterator it = wApp.begin();

			for (; it != wApp.end(); it++) {
				if (in_citizen.getAppTime().get_year() < it->getAppTime().get_year()) {
					break;
				}else if (in_citizen.getAppTime().get_year() == it->getAppTime().get_year() && in_citizen.getAppTime().get_month() < it->getAppTime().get_month()) {
					break;
				}else if (in_citizen.getAppTime().get_year() == it->getAppTime().get_year() && in_citizen.getAppTime().get_month() == it->getAppTime().get_month() && in_citizen.getAppTime().get_day() < it->getAppTime().get_day()) {
					break;
				}else if (in_citizen.getAppTime().get_year() == it->getAppTime().get_year() && in_citizen.getAppTime().get_month() == it->getAppTime().get_month() && in_citizen.getAppTime().get_day() == it->getAppTime().get_day() && in_citizen.getAppSlot().compare(it->getAppSlot())< 0) {
					break;
				}else if (in_citizen.getAppTime().get_year() == it->getAppTime().get_year() && in_citizen.getAppTime().get_month() == it->getAppTime().get_month() && in_citizen.getAppTime().get_day() == it->getAppTime().get_day() && in_citizen.getAppSlot().compare(it->getAppSlot()) == 0 && in_citizen.getAppTime().get_hourandminute().compare(it->getAppTime().get_hourandminute())<0) {
					break;
				}

			}

			wApp.insert(it, in_citizen);
		}
		else if (in_citizen.gethasApp() == false) {       //app yokken
			list <Citizen>::iterator it = wOutApp.begin();

			while (it != wOutApp.end() && in_citizen.getAppTime().operator>(it->getAppTime())) {
				it++;
			}

			wOutApp.insert(it, in_citizen);


		}
	
	}

}
void CivilRegistry::removeCitizen(int number) {

	list <Citizen>::iterator itwApp = wApp.begin();
	list <Citizen>::iterator itwOutApp = wOutApp.begin();
	
	cout << "Citizens with an appointment: " << endl;
	for (; itwApp != wApp.end(); itwApp++) {
		cout << itwApp->get_name() << endl;
	}
	cout <<endl<< "Citizens without an appointment: " << endl;
	for (; itwOutApp != wOutApp.end(); itwOutApp++) {
		cout << itwOutApp->get_name() << endl;
	}
	while(!wApp.empty())
		wApp.pop_front();

	while (!wOutApp.empty())
		wOutApp.pop_front();
		
}
CivilRegistry::~CivilRegistry() {

	wApp.clear();
	wOutApp.clear();
}