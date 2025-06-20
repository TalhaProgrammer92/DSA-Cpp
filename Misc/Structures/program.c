#include <stdio.h>
#include <stdlib.h>

// ? Structure
struct Student
{
	int roll, marks; char grade;
};

int main()
{
	struct Student s1, s2; // ! In C++ you do not need to write struct again when create object of a structure

	s1.roll = 19;
	s1.marks = 65;
	s1.grade = 'A';

	s2.roll = 15;
	s2.marks = 41;
	s2.grade = 'B';

	struct Student *s = (struct Student *) malloc(sizeof(struct Student));	// ! In C++, Student s = new Student();

	s->roll = 34;
	s->marks = 75;
	s->grade = 'A';

	return 0;
}