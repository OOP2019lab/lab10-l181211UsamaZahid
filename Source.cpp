#include "Student.h"
#include "Course.h"

int main()
{
	Student*s1 = new Student("S1", "Anum", "11-1351");
	Student*s2 = new Student("S2", "Sara", "12-6462");
	Student*s3 = new Student("S3", "Sana", "11-4531");
	Student*s4 = new Student("S4", "Zara", "12-4342");
	Student*s5 = new Student("S5", "Hira", "11-5940");

	Course*c1 = new Course("OOP", "CS102");
	Course*c2 = new Course("PF", "CS101");
	Course*c3 = new Course("AI", "CS365");

	s1[0].addCourse(c1);
	s1[0].addCourse(c2);
	s1[0].addCourse(c3);
	s2[0].addCourse(c2);
	s3[0].addCourse(c2);
	s4[0].addCourse(c2);
	s5[0].addCourse(c2);
	cout << s1 << endl;
	cout << c2 << endl;
	cout << c1 << endl;

	cout << c1 << endl;
	cout << s5 << endl;
	addCourse_t2(c1, s5);
	addStudent_t2(s5, c3);
	addCourse_t2(c1, s5);
	cout << s5 << endl;
	cout << c1 << endl;
	cout << c3 << endl;
	s5->dropCourse(c1);
	cout << c1 << endl;
	cout << s5 << endl;
	s4->dropCourse(c3);
	system("pause");
}