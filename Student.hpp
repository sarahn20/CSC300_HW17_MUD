#ifndef Student_hpp
#define Student_hpp
#include <iostream>

using namespace std;

class Student
{
    private:
        string studentName;
        Student* nextStudent;
        
    public:
        Student(string studentName);
        string getStudentName();
        Student* getNextStudent();
        void setNextStudent(Student* s);
};
#endif
