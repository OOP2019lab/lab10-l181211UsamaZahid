#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student;

class Course
{
	friend Student;
private:
	string course_name;
	string course_number;
	Student**students;
	int noofstd;
	
	friend bool addStudent(Student*s1,Course*c1);
	friend void removeStudent(Student*s1,Course*c1);

public:
	Course(string , string);
	string getcoursename();
	int getnoofstd();
	~Course();
	friend ostream& operator<<(ostream& out, const Course*c1);
	friend void addStudent_t2(Student*s1,Course*c1);
};