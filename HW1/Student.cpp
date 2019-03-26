#include "Student.h"


Student::Student()
{
}

Student::Student(int no, std::string name, int score1, int score2, int score3)
{
	this->m_no = no;
	this->m_name = name;
	this->m_score1 = score1;
	this->m_score2 = score2;
	this->m_score3 = score3;
	this->m_ave = (score1 + score2 + score3) / 3.0f;	
}

int Student::get_no()
{
	return this->m_no;
}

int Student::get_score1()
{
	return this->m_score1;
}

int Student::get_score2()
{
	return this->m_score2;
}

int Student::get_score3()
{
	return this->m_score3;
}

std::string Student::get_name()
{
	return this->m_name;
}

float Student::get_ave()
{
	return this->m_ave;
}
