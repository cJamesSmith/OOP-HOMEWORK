/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *  head file for class Lesson
 */


#ifndef __LESSON_H
#define __LESSON_H
#include <iostream>
#include <string>

class Lesson
{
public:
	Lesson(std::string name, int score);
	~Lesson();
	Lesson *p_nextLes;
	std::string get_name();
	int get_score();
	void set_max(int num);
	void set_min(int num);
	int get_min();
	float get_ave();
	int m_totalScore;
	int m_n_numStu;
private:
	std::string m_name;
	int m_score_max;
	int m_score_min;
	float m_ave;
};

#endif
