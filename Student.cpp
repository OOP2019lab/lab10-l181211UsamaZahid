#include "Student.h"
#include "Course.h"

Student::Student(string unm, string nm, string rollnum)
{
	username = unm;
	name = nm;
	roll_number = rollnum;
	cstaken = 0;
	courses = new Course*[2];
	for (int i = 0; i < 2; i++)
	{
		courses[i] = nullptr;
	}
}

Student::~Student()
{
	for (int i = 0; i < 2; i++)
		delete courses[i];
	delete[]courses;
}

void Student::addCourse(Course*c1)
{
	if (cstaken < 2)
	{
		bool store = 0;
		store = addStudent(this,c1);
		if (store == 1)
		{
			courses[cstaken] = c1;
			cstaken++;
		}
	}
	else
		cout << "Max Courses taken\n";
}

ostream& operator<<(ostream& out, const Student*s1)
{
	cout << "Roll No: " << s1[0].roll_number << endl;
	cout << "Courses:\n";
	for (int i = 0; i < s1[0].cstaken; i++)
		cout << s1[0].courses[i][0].getcoursename() << endl;
	return out;
}

string Student::getstdname()
{
	return name;
}

int Student::getcstaken()
{
	return cstaken;
}

void addCourse_t2(Course*c1, Student*s1)
{
	bool found = 0;
	if (s1[0].cstaken < 2 && c1[0].getnoofstd() < 4)
	{
		for (int i = 0; i < s1[0].cstaken; i++)
		{
			if (s1[0].courses[i][0].getcoursename() == c1[0].getcoursename())
			{
				found = 1;
			}
		}
		if (found != 1)
		{
			s1[0].courses[s1[0].cstaken] = c1;
			s1[0].cstaken++;
			addStudent_t2(s1, c1);
		}

	}
	else if (c1[0].getnoofstd()>4)
		cout << "Course is full\n";
	else
		cout << "Student registry full\n";
}

void Student::dropCourse(Course*c1)
{
	int found = 0, pos;
	for (int i = 0; i < cstaken; i++)
	{
		if (courses[i][0].getcoursename()==c1[0].course_name)
		{
			pos = i;
			found = 1;
		}
	}
	if (found == 1)
	{
		if (pos == 0)
		{
			courses[pos] = nullptr;
			courses[pos] = courses[pos+1];
			courses[pos+1] = nullptr;
			cstaken--;
			removeStudent(this, c1);
		}
		else
		{
			courses[pos] = nullptr;
			cstaken--;
			removeStudent(this, c1);
		}
	}
	else
		cout << "Course not registered\n";
}