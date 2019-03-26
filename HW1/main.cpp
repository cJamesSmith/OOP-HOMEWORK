/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date:2019.2.25 10:49:50
 *  Version:V 1.0
 *  Description: Write a program that asks you 10 records of students....
 *  Complier: g++-7
 */

// 10 students
#define NUM_STUDENT 10

#include <iostream>
#include "Student.h"

int main()
{
	// temp variables
	int no;
	int score1;
	int score2;
	int score3;
	std::string name;

	// variables of statistic results
	float ave_score1 = 0;
	float ave_score2 = 0;
	float ave_score3 = 0;
	int max_score1 = 0;
	int max_score2 = 0;
	int max_score3 = 0;
	int min_score1 = 10;
	int min_score2 = 10;
	int min_score3 = 10;
	
	// an array which saves 10 students' infomation
	Student sp[NUM_STUDENT];

	// input 10 students info
	std::cout << "Please input 10 students' infomation" << std::endl;
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		std::cin >> no >> name >> score1 >> score2 >> score3;
		sp[i] = Student(no, name, score1, score2, score3);
		
		if (max_score1 < score1)
		{
			max_score1 = score1;
		}
		if (max_score2 < score2)
		{
			max_score2 = score2;
		}
		if (max_score3 < score3)
		{
			max_score3 = score3;
		}
		if (min_score1 > score1)
		{
			min_score1 = score1;
		}
		if (min_score2 > score2)
		{
			min_score2 = score2;
		}
		if (min_score3 > score3)
		{
			min_score3 = score3;
		}
		
		ave_score1 += score1;
		ave_score2 += score2;
		ave_score3 += score3;
	}
	
	ave_score1 /= NUM_STUDENT;
	ave_score2 /= NUM_STUDENT;
	ave_score3 /= NUM_STUDENT;

	// print the results
	std::cout <<
	       	"no\tname\tscore1\tscore2\tscore3\taverage" <<
	       	std::endl;
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		std::cout << sp[i].get_no() << "\t" << 
			sp[i].get_name() << "\t" <<
			sp[i].get_score1() << "\t" <<
		       	sp[i].get_score2() << "\t" <<
			sp[i].get_score3() << "\t" <<
		       	sp[i].get_ave() << std::endl;
	}
	
	std::cout << "\t" << "average" << "\t" << ave_score1 <<
	       	"\t" << ave_score2 << "\t" << ave_score3 <<
	       	"\t" << std::endl;
	       	
	std::cout << "\t" << "min" << "\t" << min_score1 <<
	       	"\t" << min_score2 << "\t" << min_score3 <<
	       	"\t" << std::endl;
	       	
	std::cout << "\t" << "max" << "\t" << max_score1 <<
	       	"\t" << max_score2 << "\t" << max_score3 <<
	       	"\t" << std::endl;
	       	
	return 0;
}
