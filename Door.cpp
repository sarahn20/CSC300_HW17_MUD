#include "Door.hpp"

Door::Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB)
{
    this->directionToRoomA = directionToRoomA;
    this->directionToRoomB = directionToRoomB;
    this->roomA = roomA;
    this->roomB = roomB;

    roomA->currentNumberOfDoors++;
    int index = 0;
    while(index < 10) 
    {
        if(roomA->collectionOfDoors[index] == NULL)
        {
            roomA->collectionOfDoors[index] = this;
            break;
        }
        else
        {
            index++;
        }
    }
    roomB->currentNumberOfDoors++;
    int indexB = 0;
    while(indexB < 10) 
    {
        if(roomA->collectionOfDoors[indexB] == NULL)
        {
            roomA->collectionOfDoors[indexB] = this;
            break;
        }
        else
        {
            indexB++;
        }
    }
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
