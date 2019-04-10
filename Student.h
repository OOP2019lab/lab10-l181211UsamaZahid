#pragma once
#include <iostream>
#include <string>
using namespace std;

class Course;

class Student
{
	friend Course;
private:
	string username;
	string name;
	string roll_number;
	Course**courses;
	int cstaken;

public:
	Student(string, string,string);
	~Student();
	string getstdname();
	int getcstaken();
	void addCourse(Course*c1);
	void dropCourse(Course*c1);
	friend void addCourse_t2(Course*c1, Student*s1);
	friend ostream& operator<<(ostream& out, const Student*s1);
};