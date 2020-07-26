#include "Time.h"

using namespace std;

Time::Time(int in_day, int in_month, int in_year, int in_hour, int in_minute):day(in_day), month(in_month), year(in_year), hour(in_hour), minute(in_minute) {

}
const bool Time::operator<(Time &in_object) { 

	if (this->year < in_object.year)
		return true;
	else if (this->year == in_object.year && this->month < in_object.month)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day < in_object.day)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day == in_object.day && this->hour < in_object.hour)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day == in_object.day && this->hour == in_object.hour && this->minute < in_object.minute)
		return true;
	else return false;
}
const bool Time::operator>(Time &in_object) {

	if (this->year > in_object.year)
		return true;
	else if (this->year == in_object.year && this->month > in_object.month)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day > in_object.day)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day == in_object.day && this->hour > in_object.hour)
		return true;
	else if (this->year == in_object.year && this->month == in_object.month && this->day == in_object.day && this->hour == in_object.hour && this->minute > in_object.minute)
		return true;
	else return false;
}
const bool Time::operator==(Time &in_object) {

	if (this->year == in_object.year && this->month == in_object.month && this->day == in_object.day && this->hour == in_object.hour && this->minute == in_object.minute)
		return true;
	else
		return false;
}

const string Time::getTime() {

	string temp; // string objesi kullanılarak istenilen formatta tarih hazırlanmıştır

	temp += to_string(hour);
	temp += ".";
	temp += to_string(minute);
	temp += " ";
	temp += to_string(day);
	temp += "/";
	temp += to_string(month);
	temp += "/";
	temp += to_string(year);

	return temp;
}
const int Time::get_year() {
	return year;
}
const int Time::get_month() {
	return month;
}
const int Time::get_day() {
	return day;
}
const string Time::get_hourandminute() {
	return to_string(hour) + to_string(minute);
}