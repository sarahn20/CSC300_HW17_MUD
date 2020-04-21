#include "Student.hpp"

Student::Student(string studentName)
{
    this->studentName = studentName;
}

string Student::getStudentName()
{
    return this->studentName;
}

Student* Student::getNextStudent()
{
    return this->nextStudent;
}

void Student::setNextStudent(Student* s)
{
    this->nextStudent = s;
}
