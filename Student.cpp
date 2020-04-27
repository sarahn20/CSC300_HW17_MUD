#include "Student.hpp"

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
}

void Student::setCurrentRoom(Room* rand) 
{
    this->currentRoom = rand;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}

string Student::getName()
{
    return this->name;
}
