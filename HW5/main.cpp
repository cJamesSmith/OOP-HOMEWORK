/*
 * main.cpp
 *
 *  Created on: May 5, 2019
 *      Author: root
 */

#include "Fraction.h"
int main(int argc, char **argv)
{
	Fraction frac1;
	Fraction frac2 = Fraction("1.5");
	frac1 = frac2;
	frac1 = frac1 * frac2;
	frac1.print_double();
	frac2.print_string();
	std::cout << (frac1 < frac2) << std::endl;
	return 0;
}
