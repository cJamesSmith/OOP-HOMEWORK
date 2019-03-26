/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *  .cpp file for class Course
 */


#include "Course.h"

Course::Course()
{
	this->p_headCou = new Lesson("", 0);
	this->p_tailCou = this->p_headCou;
}


Course::~Course()
{
	while (p_headCou != NULL)
	{
		p_tailCou = p_headCou->p_nextLes;
		delete p_headCou;
		p_headCou = p_tailCou;
	}
	p_headCou = NULL;
}

void Course::addCourse(std::string name, int score)
{
	p_tailCou = p_headCou;
	while (p_tailCou->p_nextLes != NULL)
	{
		p_tailCou = p_tailCou->p_nextLes;
	}
	Lesson *l = new Lesson(name, score);
	l->set_max(score);
	l->set_min(score);
	this->p_tailCou->p_nextLes = l;
	p_tailCou = p_tailCou->p_nextLes;
	p_tailCou->m_totalScore += score;
	p_tailCou->m_n_numStu++;
}

bool Course::isIn(std::string name, int score)
{
	p_tailCou = p_headCou->p_nextLes;
	while (p_tailCou != NULL)
	{
		if (p_tailCou->get_name() == name)
		{
			p_tailCou->m_totalScore += score;
			p_tailCou->m_n_numStu++;
			if (p_tailCou->get_min()>score)
			{
				p_tailCou->set_min(score);
			}
			if (p_tailCou->get_score() < score)
			{
				p_tailCou->set_max(score);
			}
			return true;
		}
		p_tailCou = p_tailCou->p_nextLes;
	}
	if (p_tailCou == NULL)
	{
		return false;
	}
	return false;
}
