/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *  .cpp file for class Student
 */

#include "Student.h"

std::string Student::get_name()
{
	return this->m_name;
}

Student::Student(std::string name)
{
	this->m_name = name;
	this->p_nextStu = NULL;
	this->p_headLes = new Lesson("", 0);
	this->p_tailLes = p_headLes;
	this->m_ave_score = 0;
	this->m_totalScore = 0;
	this->m_n_les = 0;
}

Student::~Student()
{
	while (p_headLes != NULL)
	{
		p_tailLes = p_headLes->p_nextLes;
		delete p_headLes;
		p_headLes = p_tailLes;
	}
	p_headLes = NULL;
}

void Student::addLesson(std::string name, int score)
{
	Lesson *l = new Lesson(name, score);
	this->m_n_les++;
	this->m_totalScore += score;
	p_tailLes->p_nextLes = l;
	p_tailLes = p_tailLes->p_nextLes;
	this->m_ave_score = 1.0f * this->m_totalScore / this->m_n_les;
}

void Student::printLes()
{
	p_tailLes = p_headLes->p_nextLes;
	while (p_tailLes != NULL)
	{
		std::cout << "Lesson:" << p_tailLes->get_name() << " score:" << p_tailLes->get_score() << std::endl;
		p_tailLes = p_tailLes->p_nextLes;
	}
}

float Student::get_ave()
{
	return this->m_ave_score;
}

bool Student::isIn(std::string name)
{
	p_tailLes = p_headLes;
	while (p_tailLes != NULL)
	{
		if (p_tailLes->get_name() == name)
		{
			return true;
		}
		p_tailLes = p_tailLes->p_nextLes;
	}
	if (p_tailLes == NULL)
	{
		return false;
	}
	return false;
}
