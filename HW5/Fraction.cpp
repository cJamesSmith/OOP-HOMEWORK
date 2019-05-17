/*
 * Fraction.cpp
 *
 *  Created on: May 5, 2019
 *      Author: root
 */

#include "Fraction.h"

Fraction::~Fraction()
{
	// TODO Auto-generated destructor stub
}

Fraction::Fraction()
{
	this->den = 0;
	this->num = 0;
	this->den_final = 0;
	this->num_final = 0;
	this->what_is_this();
}

Fraction::Fraction(int a, int b)
{
	this->num = a;
	this->den = b;
	this->den_final = b;
	this->num_final = a;
	this->what_is_this();
}

void Fraction::what_is_this()
{
	if (this->num == 0 && this->den == 0)
	{
		this->type_myself = "NaN";
	}
	else if (this->num == 0 && this->den != 0)
	{
		this->type_myself = "0";
	}
	else if (this->num != 0 && this->den == 0)
	{
		this->type_myself = "inf";
	}
	else
	{
		this->type_myself = "None_0_fraction";
		gcd(this->den, this->num);
	}
}

Fraction::Fraction(const Fraction& another_fraction)
{
	this->den = another_fraction.den;
	this->num = another_fraction.num;
	this->den_final = another_fraction.den_final;
	this->num_final = another_fraction.num_final;
	this->what_is_this();
}

Fraction::Fraction(std::string dec)
{
	int i = dec.length();
	this->den = pow(10, i - dec.find(".") - 1);
	dec.erase(1,1);
	sscanf(dec.c_str(), "%d", &this->num);
	this->num_final = this->num;
	this->den_final = this->den;
}

int Fraction::gcd(int a, int b)
{
	int temp = a;
	while (a % b != 0)
	{
		a = b;
		b = temp % b;
		temp = a;
	}
	this->den_final = this->den / b;
	this->num_final = this->num / b;
	return b;
}

void Fraction::print_double()
{
	double result;
	if (this->type_myself == "NaN")
	{
		std::cout << "NaN" << std::endl;
	}
	else if (this->type_myself == "inf")
	{
		std::cout << "inf" << std::endl;
	}
	else
	{
		result = 1.0 * this->num / this->den;
		std::cout << result << std::endl;
	}
}

void Fraction::print_string()
{
	if (this->type_myself == "NaN")
	{
		std::cout << "NaN" << std::endl;
	}
	else if (this->type_myself == "inf")
	{
		std::cout << "inf" << std::endl;
	}
	else
	{
		std::cout << "original fraction: " << std::endl;
		std::cout << this->num << "/" << this->den << std::endl;
		std::cout << "final fraction: " << std::endl;
		std::cout << this->num_final << "/" << this->den_final << std::endl;
	}
}

const Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
	return Fraction(frac1.num * frac2.num, frac1.den * frac2.den);
}

const Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
	return Fraction(frac1.num * frac2.den, frac1.den * frac2.num);
}

const Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
	return Fraction(frac1.num * frac2.den + frac1.den * frac2.num,
			frac1.den * frac2.den);
}

const Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
	return Fraction(frac1.num * frac2.den - frac1.den * frac2.num,
			frac1.den * frac2.den);
}

std::string operator<(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den < frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::string operator<=(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den <= frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::string operator!=(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den != frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::string operator==(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den == frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::string operator>(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den > frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::string operator>=(const Fraction &frac1, const Fraction &frac2)
{
	if (frac1.type_myself == "NaN" || frac2.type_myself == "NaN")
	{
		return "Nan";
	}
	else if (frac1.type_myself == "inf" || frac2.type_myself == "inf")
	{
		return "inf";
	}
	else
	{
		if (frac1.num * frac2.den >= frac1.den * frac2.num)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}
}

std::ostream & operator<<(std::ostream &os, const Fraction &frac)
{
	if (frac.type_myself == "NaN")
	{
		os << "NaN" << std::endl;
		return os;
	}
	else if (frac.type_myself == "inf")
	{
		os << "inf" << std::endl;
		return os;
	}
	else
	{
		double result = 1.0 * frac.num / frac.den;
		std::cout << result << std::endl;
		return os;
	}
}

