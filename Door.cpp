#include "Door.hpp"


Door::Door(Room* room1, Room* room2)
{
    this->room1 = room1;
    this->room2 = room2;
}

string Door::getRoom1Name()
{
    return this->room1->getRoomName();
}

string Door::getRoom2Name()
{
    return this->room2->getRoomName();
}
