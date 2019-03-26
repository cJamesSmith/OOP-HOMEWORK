/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date: 2019/3/17 20:28
 *  Version: V1.0
 *  Description:
 *  head file for class Course
 */


#ifndef __COURSE_H
#define __COURSE_H
#include <iostream>
#include <string>
#include "Lesson.h"

class Course
{
public:
	Course();
	~Course();
	Lesson *p_headCou;
	Lesson *p_tailCou;
	void addCourse(std::string name, int score);
	bool isIn(std::string name, int score);
private:
};

#endif
