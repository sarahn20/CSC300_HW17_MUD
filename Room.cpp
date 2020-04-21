#include "Room.hpp"
#include <iostream>

Room::Room(string roomName)
{
    this->roomName = roomName;
    this->northDoor = NULL;
    this->southDoor= NULL;
    this->eastDoor = NULL;
    this->westDoor = NULL;
}

void Room::setNorthDoor(Door* givenDoor)
{
    this->northDoor = givenDoor;
}

void Room::setSouthDoor(Door* givenDoor)
{
    this->southDoor = givenDoor;
}

void Room::setEastDoor(Door* givenDoor)
{
    this->eastDoor = givenDoor;
}

void Room::setWestDoor(Door* givenDoor)
{
    this->westDoor = givenDoor;
}

string Room::getRoomName()
{
    return this->roomName;
}

void Room::runMud()
{
    this->inhabitants->addFront("Sarah");
    cout << "You are in room: " << this->getRoomName() << "\n";
    cout << "Room inhabitants include: " << this->inhabitants->display() << "\n";
    if(this->northDoor)
    {
        if(this != this->northDoor->room1)
        {
            cout << "The North Door leads to: " << this->northDoor->room1->getRoomName();
        }
        else if(this != this->northDoor->room2)
        {
           cout << "The North Door leads to: " << this->northDoor->room1->getRoomName(); 
        }
        
    }
    if(this->southDoor)
    {
        if(this != this->southDoor->room1)
        {
            cout << "The South Door leads to: " << this->southDoor->room1->getRoomName();
        }
        else if(this != this->southDoor->room2)
        {
           cout << "The South Door leads to: " << this->southDoor->room1->getRoomName(); 
        }
        
    }
    if(this->eastDoor)
    {
        if(this != this->eastDoor->room1)
        {
            cout << "The East Door leads to: " << this->eastDoor->room1->getRoomName();
        }
        else if(this != this->eastDoor->room2)
        {
           cout << "The East Door leads to: " << this->eastDoor->room1->getRoomName(); 
        }
        
    }
    if(this->westDoor)
    {
        if(this != this->westDoor->room1)
        {
            cout << "The West Door leads to: " << this->westDoor->room1->getRoomName();
        }
        else if(this != this->westDoor->room2)
        {
           cout << "The West Door leads to: " << this->westDoor->room1->getRoomName(); 
        }
    }
    cout << "Which door would you like to go through?";
    string goalDoor;
    cin >> goalDoor;
    this->inhabitants->removeFront();
    if(goalDoor == "north door")
    {
        if(this != this->northDoor->room1)
        {
            cuwCS->setCurrRoom(this->northDoor->room1);
            this->runMud();
            
        }
        else if(this != this->northDoor->room2)
        {
           cuwCS->setCurrRoom(this->northDoor->room2);
           this->runMud(); 
        }

    }
    else if(goalDoor == "south door")
    {
        if(this != this->southDoor->room1)
        {
            cuwCS->setCurrRoom(this->southDoor->room1);
            this->runMud();
            
        }
        else if(this != this->southDoor->room2)
        {
           cuwCS->setCurrRoom(this->southDoor->room2);
           this->runMud(); 
        }

    }
    else if(goalDoor == "east door")
    {
        if(this != this->eastDoor->room1)
        {
            cuwCS->setCurrRoom(this->eastDoor->room1);
            this->runMud();
            
        }
        else if(this != this->eastDoor->room2)
        {
           cuwCS->setCurrRoom(this->eastDoor->room2);
           this->runMud(); 
        }

    }
    else if(goalDoor == "west door")
    {
        if(this != this->westDoor->room1)
        {
            cuwCS->setCurrRoom(this->westDoor->room1);
            this->runMud();
            
        }
        else if(this != this->westDoor->room2)
        {
           cuwCS->setCurrRoom(this->westDoor->room2);
           this->runMud(); 
        }

    }
}
