#ifndef _Money_h_
#define _Money_h_

#include <stdio.h>
#include <iostream>

class Money {
private:
	int lira;
	int kurus;
public:
	Money(); // default constructor
	Money(Money&); //copy constructor
	Money(int,int); // constructor with parameters
	Money(double); // constructor for comparison
	~Money(); //destructor

	int getLira()const;
	int getKurus()const;

	void setLira(int);
	void setKurus(int);

	Money& operator=(Money const &);
	Money operator+(Money const &);
	Money operator-(Money const &);
	bool operator<(Money const&);
	bool operator>(Money const&);
	bool operator==(Money const&);

	friend std::ostream& operator<<(std::ostream&, const Money& );

};

#endif
