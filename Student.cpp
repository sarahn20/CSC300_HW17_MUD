#include "Student.hpp"

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
}

void Student::setCurrentRoom(Room* r)
{
    this->currentRoom = r;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}

string Student::getName()
{
    return this->name;
}
