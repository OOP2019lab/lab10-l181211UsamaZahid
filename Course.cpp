#include "Course.h"
#include "Student.h"

Course::Course(string cname, string cnum)
{
	course_name = cname;
	course_number = cnum;
	noofstd = 0;
	students = new Student*[4];
	for (int i = 0; i < 4; i++)
	{
		students[i] = nullptr;
	}
}

Course::~Course()
{
	for (int i = 0; i < 4; i++)
		delete students[i];
	delete[]students;
}

bool addStudent(Student*s1,Course*c1)
{
	if (c1[0].noofstd < 4)
	{
		c1[0].students[c1[0].noofstd] = s1;
		c1[0].noofstd++;
		return 1;
	}
	else
	{
		cout << "Max Students reached\n";
		return 0;
	}
}

ostream& operator<<(ostream& out, const Course*c1)
{
	cout << "Course Name: " << c1[0].course_name << endl;
	cout << "Course ID: " << c1[0].course_number << endl;
	cout << "Students:\n";
	for (int i = 0; i < c1[0].noofstd; i++)
		cout << c1[0].students[i][0].getstdname() << endl;
	return out;
}

string Course::getcoursename()
{
	return course_name;
}

int Course::getnoofstd()
{
	return noofstd;
}

void addStudent_t2(Student*s1 , Course*c1)
{
	bool found = 0;
	if (s1[0].getcstaken() < 2 && c1[0].noofstd < 4)
	{
		for (int i = 0; i < c1[0].noofstd; i++)
		{
			if (c1[0].students[i][0].getstdname() == s1[0].getstdname())
			{
				found = 1;
			}
		}
		if (found != 1)
		{
			c1[0].students[c1[0].noofstd] = s1;
			c1[0].noofstd++;
			addCourse_t2(c1, s1);
		}
		
	}
	else if (c1[0].noofstd>4)
		cout << "Course is full\n";
	else
		cout << "Student registry full\n";
}

void removeStudent(Student*s1, Course*c1)
{
	int pos;
	for (int i = 0; i < c1[0].noofstd; i++)
	{
		if (c1[0].students[i][0].getstdname() == s1[0].getstdname())
		{
			pos = i;
		}
	}
	for (int i = pos; i < c1[0].noofstd; i++)
	{
		c1[0].students[i] = nullptr;
		if (i < c1[0].noofstd - 1)
		c1[0].students[i] = c1[0].students[i + 1];
	}
	c1[0].noofstd--;
}