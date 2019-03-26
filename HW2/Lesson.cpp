/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *  .cpp file for class Lesson
 */

#include "Lesson.h"

Lesson::Lesson(std::string name, int score)
{
	this->m_name = name;
	this->m_score_max = score;
	this->p_nextLes = NULL;
	this->m_ave = 0;
	this->m_n_numStu = 0;
	this->m_totalScore = 0;
}

Lesson::~Lesson()
{
}

std::string Lesson::get_name()
{
	return this->m_name;
}

int Lesson::get_score()
{
	return this->m_score_max;
}

void Lesson::set_max(int num)
{
	this->m_score_max = num;
}

void Lesson::set_min(int num)
{
	this->m_score_min = num;
}

int Lesson::get_min()
{
	return this->m_score_min;
}

float Lesson::get_ave()
{
	this->m_ave = 1.0f * this->m_totalScore / this->m_n_numStu;
	return this->m_ave;
}
