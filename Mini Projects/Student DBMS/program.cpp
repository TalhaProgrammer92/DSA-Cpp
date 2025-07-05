#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ? Book - Manage various books for different classes/standards
class Book
{
    // * Attributes
    string title, sub_title;
    int marks;

public:
    // * Constructors
    Book() {}
    Book(string title, string sub_title, int marks) : title(title), sub_title(sub_title), marks(marks) {}

    // * Getters
    string get_title() { return title; }
    string get_subtitle() { return sub_title; }
    int get_marks() { return marks; }
};

// ? Student - Manage students of different standards
class Student
{
    // * Attributes
    string name;                        // ! Name of the student
    int roll;                           // ! Roll number of the student
    int standard;                       // ! Standard (Class) of the student
    char section;                       // ! Section of the class of the student
    unordered_map<Book, int> books_set; // ! Books' set and marks gained

public:
    // * Constructor
    Student() {}
    Student(string name, int roll, int standard, char section, vector<Book> &books)
    {
        // ! Assigning values
        this->name = name;
        this->roll = roll;
        this->standard = standard;
        this->section = section;

        // ! Assigning book set
        for (Book book : books)
            this->books_set[book] = 0;
    }
};

int main()
{
}
