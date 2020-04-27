#include "Door.hpp"

Door::Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB)
{
    this->directionToRoomA = directionToRoomA;
    this->directionToRoomB = directionToRoomB;
    this->roomA = roomA;
    this->roomB = roomB;

    roomA->addDoor(this);
    roomB->addDoor(this);
}

Room* Door::getRoomA()
{
    return this->roomA;
}

Room* Door::getRoomB()
{
    return this->roomB;
}

string Door::getDirectionToRoomA()
{
    return this->directionToRoomA;
}

string Door::getDirectionToRoomB()
{
    return this->directionToRoomB;
}
