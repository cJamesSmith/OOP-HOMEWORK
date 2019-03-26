/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *	Write a CLI program that reads scores and names of 
 *  students, and prints out a summary sheet (in the same 
 *  format with  the last homework "Students I").
 *	The user can input as many students as possible. One 
 *  student can have as many courses as possible. One 
 *  course consists the name of the course and the scores 
 *  the students got. Please note that a student won't 
 *  choose every available course in general.
 */



#include <iostream>
#include <iomanip>
#include "Student.h"
#include <string>
#include "Course.h"
#include <fstream>

int main()
{
	Student *p_headStu = new Student("");
	Student *p_tailStu = p_headStu;
	Course *c = new Course;
	std::string t_name;
	int t_score;
	
	// CAUTION: in file "student.in", you must input each
	// student's score in the following style:
	// name lesson1 score1 lesson2 score2 ... lesson_n score_n !
	// REMENBER: each student must end with "!"
	std::fstream fin("students.in", std::ios::in);
	std::fstream fout("students.out", std::ios::out);
	while (fin >> t_name)
	{
		Student *s = new Student(t_name);
		while (fin >> t_name)
		{
			if (t_name == "!")
			{
				break;
			}
			else
			{
				fin >> t_score;
				s->addLesson(t_name, t_score);
				if (!(c->isIn(t_name, t_score)))
				{
					c->addCourse(t_name, t_score);
				}
			}
		}
		p_tailStu->p_nextStu = s;
		p_tailStu = p_tailStu->p_nextStu;
	}

	// print the title
	fout << std::setw(8) << "Name";
	c->p_tailCou = c->p_headCou->p_nextLes;
	while (c->p_tailCou != NULL)
	{
		fout << std::setw(8) << c->p_tailCou->get_name() << std::right;
		c->p_tailCou = c->p_tailCou->p_nextLes;
	}
	fout << std::setw(8) << "ave" << std::right;
	
	// print the students
	p_tailStu = p_headStu->p_nextStu;
	while (p_tailStu != NULL)
	{
		fout << std::endl;
		fout << std::setw(8) << p_tailStu->get_name() << std::right;
		p_tailStu->p_tailLes = p_tailStu->p_headLes->p_nextLes;
		c->p_tailCou = c->p_headCou->p_nextLes;
		while (c->p_tailCou != NULL)
		{
			if (p_tailStu->p_tailLes == NULL)
			{
				c->p_tailCou = c->p_tailCou->p_nextLes;
				fout << std::setw(8) << "\t";
				continue;
			}
			if (p_tailStu->p_tailLes->get_name() == c->p_tailCou->get_name())
			{
				fout << std::setw(8) << p_tailStu->p_tailLes->get_score() << std::right;
				p_tailStu->p_tailLes = p_tailStu->p_tailLes->p_nextLes;
				c->p_tailCou = c->p_tailCou->p_nextLes;
			}
			else
			{
			    fout << std::setw(8) << "\t";
				c->p_tailCou = c->p_tailCou->p_nextLes;
			}
		}
		fout << std::setw(8) << p_tailStu->get_ave() << std::right;

		p_tailStu = p_tailStu->p_nextStu;
	}
	fout << std::endl;

	// print each course max
	fout << std::setw(8) << "max" << std::right;
	c->p_tailCou = c->p_headCou->p_nextLes;
	while (c->p_tailCou != NULL)
	{
		fout << std::setw(8) << c->p_tailCou->get_score() << std::right;
		c->p_tailCou = c->p_tailCou->p_nextLes;
	}
	fout << std::endl;

	// print each course min
	fout << std::setw(8) << "min" << std::right;
	c->p_tailCou = c->p_headCou->p_nextLes;
	while (c->p_tailCou != NULL)
	{
		fout << std::setw(8) << c->p_tailCou->get_min() << std::right;
		c->p_tailCou = c->p_tailCou->p_nextLes;
	}
	fout << std::endl;

	// print each course ave
	fout << std::setw(8) << "ave" << std::right;
	c->p_tailCou = c->p_headCou->p_nextLes;
	while (c->p_tailCou != NULL)
	{
		fout << std::setw(8) << c->p_tailCou->get_ave() << std::right;
		c->p_tailCou = c->p_tailCou->p_nextLes;
	}
	fout << std::endl;

	// destroy the students' records
	while (p_headStu != NULL)
	{
		p_tailStu = p_headStu->p_nextStu;
		delete p_headStu;
		p_headStu = p_tailStu;
	}
	p_headStu = NULL;
	delete c;
	return 0;
}
