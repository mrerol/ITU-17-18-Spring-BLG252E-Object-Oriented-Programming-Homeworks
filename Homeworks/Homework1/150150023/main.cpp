#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "CivilRegistry.h"

#define FILENAME "input.txt"

#define ID_SIZE 15
#define NAME_SIZE 20
#define SURNAME_SIZE 20
#define HASAPP_SIZE 15
#define APPDATE_SIZE 20
#define APPSLOT_SIZE 20
#define ENTRYCLOCK_SIZE 15



using namespace std;

int main() {


	bool first_use_flag = true;
	FILE *fptr;
	fptr = fopen(FILENAME, "r+");

	if (!fptr) {
		cerr << "File can not be opened" << endl;
		exit(1);
	}

	char *temp_idno, *temp_name, *temp_surname, *temp_hasapp, *temp_appdate, *temp_appslot, *temp_entryclock;
	int idno = 0;
	CivilRegistry List;
	int citizen_number = 0;
	fseek(fptr, 0, SEEK_SET);
	while (!feof(fptr)) {

		temp_idno = new char[ID_SIZE];
		temp_name = new char[NAME_SIZE];
		temp_surname = new char[SURNAME_SIZE];
		temp_hasapp = new char[HASAPP_SIZE];
		temp_appdate = new char[APPDATE_SIZE];
		temp_appslot = new char[APPSLOT_SIZE];
		temp_entryclock = new char[ENTRYCLOCK_SIZE];

		fscanf(fptr, "%s %s %s %s %s %s %s", temp_idno, temp_name, temp_surname, temp_hasapp, temp_appdate, temp_appslot, temp_entryclock);

		if (first_use_flag) {
			delete[] temp_idno;
			delete[] temp_name;
			delete[] temp_surname;
			delete[] temp_hasapp;
			delete[] temp_appdate;
			delete[] temp_appslot;
			delete[] temp_entryclock;
			first_use_flag = false;
			continue;
		}


		Citizen *temp_Citizen_object = new Citizen(temp_idno, temp_name, temp_surname, temp_hasapp, temp_appdate, temp_appslot, temp_entryclock);
		List.insertCitizen(*temp_Citizen_object);
		citizen_number++;
		//cout << temp_idno << " " << temp_name << " " << temp_surname << " " << temp_hasapp << " " << temp_appdate << " " << temp_appslot << " " << temp_entryclock << endl;

		delete[] temp_idno;
		delete[] temp_name;
		delete[] temp_surname;
		delete[] temp_hasapp;
		delete[] temp_appdate;
		delete[] temp_appslot;
		delete[] temp_entryclock;

	}
	
	List.removeCitizen(citizen_number); // 


	//cout << "end" << endl;
	getchar();
	return EXIT_SUCCESS;
}
