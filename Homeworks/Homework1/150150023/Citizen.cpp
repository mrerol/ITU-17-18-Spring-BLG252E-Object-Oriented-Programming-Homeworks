#include "Citizen.h"
#include <string>

#define ID_SIZE 15
#define NAME_SIZE 20
#define SURNAME_SIZE 20
#define HASAPP_SIZE 15
#define APPDATE_SIZE 20
#define APPSLOT_SIZE 20
#define ENTRYCLOCK_SIZE 15

Citizen::Citizen(char *in_idno, char *in_name, char *in_surname, char *in_hasApp, char *in_appdate, char *in_appSlot,char *in_entryclock) {
	idNo = new char[ID_SIZE];
	name = new char[NAME_SIZE];
	surname = new char[SURNAME_SIZE];
	appSlot = new char[APPSLOT_SIZE];

	if (strcmp(in_hasApp, "FALSE")==0) {
		hasApp = false;
	}
	else {
		hasApp = true;
	}

	strncpy(idNo,in_idno,ID_SIZE);
	strncpy(name, in_name, NAME_SIZE);
	strncpy(surname, in_surname, SURNAME_SIZE);
	strncpy(appSlot, in_appSlot, APPSLOT_SIZE);

	int i, size_of_hh = 0;
	for (i = 0;; i++) {
		if (*(in_entryclock + i)=='.')
			break;

		size_of_hh++;
	}
	//stoi fonsiyonun c++11 sürümünde vardýr ve burada kullanýlmýþtýr
	string temp_hour_string(in_entryclock); 
	int temp_hour = stoi(temp_hour_string.substr(0, size_of_hh),nullptr,16); // hour
	int temp_minute = stoi(temp_hour_string.substr(size_of_hh + 1, 2), nullptr, 16); // minute


	string temp_day_string(in_appdate);
	//substr string objesini parçalamak için kullanýlmýþtýr.
	int temp_day = stoi(temp_day_string.substr(0, 2), nullptr, 16); // day
	int temp_month = stoi(temp_day_string.substr(3, 2), nullptr, 16); //month
	int temp_year = stoi(temp_day_string.substr(6, 2), nullptr, 16); //year

	appTime=new Time(temp_day, temp_month, temp_year, temp_hour, temp_minute);

}
Time& Citizen::getAppTime() {
	
	return *appTime; //civilRegistry içinde kullanýlmak için Time objesini döndürüyor

}
const bool Citizen::gethasApp() {
	return hasApp;
}
const string Citizen::getAppSlot() {
	return string(appSlot);
}
const string Citizen::get_name() {
	return string(name);
}
Citizen::~Citizen() {

	delete[] idNo;
	delete[] name;
	delete[] surname;
	delete[] appSlot;
	delete appTime;
}