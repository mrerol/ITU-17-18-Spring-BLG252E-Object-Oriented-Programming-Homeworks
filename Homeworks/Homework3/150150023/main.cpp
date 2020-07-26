#include "Money.h"
#include "GenericArray.h"
#include "GenericArray.cpp"

int main()
{
	genericArray<int>m1(5);
	genericArray<double>m2(5);
	genericArray<Money>m3(5);

	
	try{
		//genericArray<Money>m4(0);
		//genericArray<Money>m4(-1);
		Money d(-1, 89);
		//Money z(1, -1);
		//Money x(1, 100);
	}
	catch(std::string in_string){
		std::cout << in_string << std::endl;
	}
	/*
	try {
	Money a(0,0);
	Money b(0, 0);
	Money c(0, 0);
	Money k(0, 0);
	Money m(0, 0);
	Money bonus(0, 0);

	m3.elements[0] = a;
	m3.elements[1] = b;
	m3.elements[2] = c;
	m3.elements[3] = k;
	m3.elements[4] = m;

	std::cout << "Money object:" << std::endl;
	m3.total = m3.sum();
	m3.print("Money");
	std::cout << std::endl;

	}
	catch (std::string in_string) {
		std::cout << in_string << std::endl;
	}
	*/

	/*
	Money a(10, 5);
	Money b(10, 5);
	Money c(2,2);
	Money k(1,1);
	Money m(10, 20);
	Money bonus(5, 0);
	*/
	
	Money a(10,5);
	Money b(10,5);
	Money c(43,7);
	Money k(50,6);
	Money m(10,20);
	Money bonus(5,0);
	
	m3.elements[0] = a;
	m3.elements[1] = b;
	m3.elements[2] = c;
	m3.elements[3] = k;
	m3.elements[4] = m;
	
	/*
	m2.elements[0] = 0;
	m2.elements[1] = 0;
	m2.elements[2] = 0;
	m2.elements[3] = 0;
	m2.elements[4] = 4;
	*/

	m2.elements[0] = 12.5;
	m2.elements[1] = 11.6;
	m2.elements[2] = 13.9;
	m2.elements[3] = 23.7;
	m2.elements[4] = 130.7;
	

	/*
	m1.elements[0] = 0;
	m1.elements[1] = 0;
	m1.elements[2] = 0;
	m1.elements[3] = 0;
	m1.elements[4] = 0;
	*/
	
	m1.elements[0] = 1;
	m1.elements[1] = 2;
	m1.elements[2] = 5;
	m1.elements[3] = 9;
	m1.elements[4] = 90;
	
	
	std::cout << "Money object:" << std::endl;
	m3.total = m3.sum();
	m3.print("Money");
	std::cout << std::endl;
	
	std::cout << "double array:" << std::endl;
	m2.total = m2.sum();
	m2.print("double");
	std::cout << std::endl;

	std::cout << "int array:" << std::endl;
	m1.total = m1.sum();
	m1.print("int");
	std::cout << std::endl;




	getchar();
	return 0;
}