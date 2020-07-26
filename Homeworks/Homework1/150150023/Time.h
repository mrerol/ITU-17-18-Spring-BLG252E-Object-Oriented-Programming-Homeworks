#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <list>
#include <iostream>
#include <string>
#include <iterator>


using namespace std;

class Time {
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	Time(int, int, int, int ,int);
	~Time() {};
	const string getTime();
	const bool operator<(Time &);
	const bool operator>(Time &);
	const bool operator==(Time &);
	const int get_year();
	const int get_month();
	const int get_day();
	const string get_hourandminute();
};