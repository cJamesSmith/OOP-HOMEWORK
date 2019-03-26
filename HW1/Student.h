#pragma once
#include <string>
#include <iostream>


class Student
{
public:
	Student();

	// initiate the members of class "Student"
	Student(int no, std::string name, int score1, int score2, int score3);

	int get_no();
	int get_score1();
	int get_score2();
	int get_score3();
	std::string get_name();
	float get_ave();
	
private:
	std::string m_name;
	int m_no;
	int m_score1;
	int m_score2;
	int m_score3;
	float m_ave;
};

