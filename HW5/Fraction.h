/*
 * Fraction.h
 *
 *  Created on: May 5, 2019
 *      Author: Xianwei C.
 *      3170104952
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

class Fraction
{
public:
	virtual ~Fraction();
	Fraction(); // default ctor
	Fraction(std::string dec); // ctor transfroms decimal to fraction
	Fraction(int a, int b); // ctor takes two integers as parameters
	Fraction(const Fraction &another_fraction); // copy ctor
	friend const Fraction operator*(const Fraction &frac1, const Fraction &frac2); // overload arithmetical operators '*'
	friend const Fraction operator/(const Fraction &frac1, const Fraction &frac2); // overload arithmetical operators '/'
	friend const Fraction operator+(const Fraction &frac1, const Fraction &frac2); // overload arithmetical operators '+'
	friend const Fraction operator-(const Fraction &frac1, const Fraction &frac2); // overload arithmetical operators '-'
	friend std::string operator<(const Fraction &frac1, const Fraction &frac2); // overload relational operators '<'
	friend std::string operator<=(const Fraction &frac1, const Fraction &frac2); // overload relational operators '<='
	friend std::string operator!=(const Fraction &frac1, const Fraction &frac2); // overload relational operators '!='
	friend std::string operator==(const Fraction &frac1, const Fraction &frac2); // overload relational operators '=='
	friend std::string operator>(const Fraction &frac1, const Fraction &frac2); // overload relational operators '>'
	friend std::string operator>=(const Fraction &frac1, const Fraction &frac2); // overload relational operators '>='
	friend std::ostream & operator<<(std::ostream &os, const Fraction &frac); // overload ostream
	friend std::istream & operator>>(std::istream &is, Fraction &frac) // overload istream, somehow
	{
		std::string expr;
		std::string num, den;
		is >> num >> expr >> den;
		sscanf(num.c_str(), "%d", &frac.num);
		sscanf(den.c_str(), "%d", &frac.den);
		frac.what_is_this();
		return is;
	}
	void what_is_this(); // check if the fraction is alike "0/0"(NaN); "a/0"(inf); or a real number
	void print_double(); // translate the fraction to a double number
	void print_string(); // translate the fraction to a string
	int gcd(int a, int b); // simplify the fraction

private:
	int num; // numerator
	int den; // denominator
	int num_final;
	int den_final;
	std::string type_myself;
};

#endif /* FRACTION_H_ */
