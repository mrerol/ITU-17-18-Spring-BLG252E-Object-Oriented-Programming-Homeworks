#include <iostream>
#include <stdio.h> // for getchar();
#include "grayling.h"
#include "grayling1.h"
#include "grayling2.h"
#include "grayling3.h"

void show(Grayling *g);
void reproduce(Grayling *g);
void aging(Grayling *g);

int main() {
	Grayling1 G1_1('f', "G1_1"); //Create a Grayling1 with gender and name attributes
	Grayling1 G1_2(G1_1, 'f', "G1_2_CC"); // Copy Constructor *_CC
	Grayling2 G2_1('m', "G2_1");
	Grayling3 G3_1('f', "G3_1");

	show(&G1_1);
	show(&G1_2);
	show(&G2_1);
	show(&G3_1);
	std::cout << std::endl;

	aging(&G1_2);
	std::cout << std::endl;

	aging(&G1_1);
	aging(&G1_1);
	aging(&G1_1);
	reproduce(&G1_1);
	aging(&G1_1);
	std::cout << std::endl;

	aging(&G2_1);
	aging(&G2_1);
	aging(&G2_1);
	reproduce(&G2_1);
	aging(&G2_1);
	std::cout << std::endl;

	aging(&G3_1);
	aging(&G3_1);
	aging(&G3_1);
	reproduce(&G3_1);
	aging(&G3_1);

	getchar();
	return 0;
}

void show(Grayling *g) {
	g->print();
}
void reproduce(Grayling *g) {
	g->givebirth();
}
void aging(Grayling *g) {
	g->aging();
}