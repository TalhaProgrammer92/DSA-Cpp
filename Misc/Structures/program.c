#include <stdio.h>
#include <stdlib.h>

// ? Structure
struct Student
{
	int roll, marks; char grade;
};

void print_student(struct Student student)
{
	printf("\nRoll: %d\nMarks: %d\nGrade: %c\n", student.roll, student.marks, student.grade);
}

int main()
{
	struct Student s1, s2; // ! In C++ you do not need to write struct again when create object of a structure

	s1.roll = 19;
	s1.marks = 65;
	s1.grade = 'A';
	// printf("\nRoll: %d\nMarks: %d\nGrade: %c\n", s1.roll, s1.marks, s1.grade);
	print_student(s1);

	s2.roll = 15;
	s2.marks = 41;
	s2.grade = 'B';
	// printf("\nRoll: %d\nMarks: %d\nGrade: %c\n", s2.roll, s2.marks, s2.grade);
	print_student(s2);

	struct Student *s = (struct Student *) malloc(sizeof(struct Student));	// ! In C++, Student s = new Student();

	s->roll = 34;
	s->marks = 75;
	s->grade = 'A';
	// printf("\nRoll: %d\nMarks: %d\nGrade: %c\n", s->roll, s->marks, s->grade);
	print_student(*s);

	return 0;
}