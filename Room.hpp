#ifndef Room_hpp
#define Room_hpp
#include "LinkedList.hpp"
#include "Door.hpp"
#include "Door.cpp"
#include <iostream>

using namespace std;

class Room
{
    private:
        Door* northDoor;
        Door* southDoor;
        Door* eastDoor;
        Door* westDoor;
        string roomName;

    public:
        Room(string roomName);
        void setNorthDoor(Door* givenDoor);
        void setSouthDoor(Door* givenDoor);
        void setEastDoor(Door* givenDoor);
        void setWestDoor(Door* givenDoor);
        string getRoomName();
        LinkedList* inhabitants;
        void runMud();

        
    
};
#endif
