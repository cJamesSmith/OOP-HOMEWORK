#ifndef __STUDENT_H
#define __STUDENT_H
#include <iostream>
#include <string.h>
#include "Lesson.h"

class Student
{
public:
	Student(std::string name);
	std::string get_name();
	~Student();
	Student *p_nextStu;
	Lesson *p_headLes;
	void addLesson(std::string name, int score);
	void printLes();
	Lesson *p_tailLes;
	float get_ave();
	bool isIn(std::string name);
private:
	std::string m_name;
	float m_ave_score;
	int m_n_les;
	int m_totalScore;
};

#endif
