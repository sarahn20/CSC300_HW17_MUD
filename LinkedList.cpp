#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(string studentName)
{
    Student* s = new Student(studentName); //Student n = new Student(studentName); in Java

    //if list is currently empty
    if(!this->head) //tests the pointer count of this->head (boils down to 0 if nothing points here)
                        //Java: this.head == null
    {
        this->head = s;
    }
    else //list has at least 1 thing in it
    {
        s->setNextStudent(this->head);
        this->head = s;
    }
    this->count++;
}

string LinkedList::getFront()
{
    return this->head->getStudentName();
}

string LinkedList::removeFront()
{
    Student* StudentToReturn = this->head;
    this->head = this->head->getNextStudent();
    string val = StudentToReturn->getstudentName();
    delete StudentToReturn;
    this->count--;
    return val;
}

Student* LinkedList::runToEndOfList()
{
    Student* currStudent = this->head;
    while(currStudent->getNextStudent()) //returns true when currStudent has a next Student
    {
        currStudent = currStudent->getNextStudent(); // (*currStudent).getNextStudent()
    }
    return currStudent;
}



void LinkedList::display()
{
    Student* currStudent = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currStudent->getstudentName() << "\n";
        currStudent = currStudent->getNextStudent();
    }
}



Student* LinkedList::runToIndex(int index)
{
    Student* currStudent = this->head;
    for(int i = 0; i < index; i++)
    {
        currStudent = currStudent->getNextStudent();
    }
    return currStudent;
}

}
