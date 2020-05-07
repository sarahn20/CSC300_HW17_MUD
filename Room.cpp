#include "Room.hpp"
#include <iostream>
#include "Door.hpp"

using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
    this->maxItemCount = 10;
    this->currentItemCount = 0;
    this->shelf = (Item**)malloc(this->maxItemCount * sizeof(Item*));

}

void Room::displayShelfContents()
{
    for(int i = 0; i < this->currentItemCount; i++)
    {
        cout << this->shelf[i]->getName() << "\n";
    }
}

bool Room::addItem(Item* anItem)
{
    if(this->currentItemCount == this->maxItemCount)
    {
        return false;
    }
    else
    {
        this->shelf[this->currentItemCount] = anItem;
        this->currentItemCount++;
        return true;
    } 
}

Item* Room::removeItem(string anItem)
{
    Item* tempItem = 0;
    for(int i = 0; i < this->currentItemCount; i++)
    {
        if(this->shelf[i]->getName() == anItem)
        {
            tempItem = this->shelf[i];
            while(i < this->currentItemCount-1)
            {
                this->shelf[i] = this->shelf[i+1];
                i++;
            }
            
        }
    }
    if(tempItem != 0)
    {
        this->currentItemCount--;
        
    }
    return tempItem;
}

void Room::addDoor(Door* aDoor)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = aDoor;
    this->currentNumberOfDoors++;
    this->theStudents = new LinkedListOfStudents();
}

void Room::addStudent(Student* aStudent)
{
    if(this->theStudents->indexOf(aStudent) == -1)
    {
        this->theStudents->addFront(aStudent);
        aStudent->setCurrentRoom(this);
    } 
}

void Room::removeStudent(Student* aStudent)
{
    int indexOfStudent = this->theStudents->indexOf(aStudent);
    if(indexOfStudent != -1)
    {
        this->theStudents->removeAtIndex(indexOfStudent);
        aStudent->setCurrentRoom(0); //the student is in limbo
    }
}

void Room::takeDoor(Student* aStudent, string direction)
{
    Door* tempDoor;
    Room* currentRoom = this;
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        if(tempDoor->getDirectionToOtherRoom(currentRoom) == direction)
        {
            Room* theOtherRoom = tempDoor->getTheOtherRoom(currentRoom);
            
            //remove the student from the current room
            this->removeStudent(aStudent);

            //put the student in the new room
            theOtherRoom->addStudent(aStudent);
        }
    }
}

void Room::display()
{
    cout << this->title << "\n";

    //show the potential doors
    cout << "Obvious Exits: ";
    Door* tempDoor = 0;
    
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        cout << tempDoor->getDirectionToOtherRoom(this) << " ";
    }
    cout << "\n Also Here: ";
    Student* tempStudent;

    for(int i = 0; i < this->theStudents->getCount(); i++)
    {
        tempStudent = this->theStudents->getAtIndex(i);
        cout << tempStudent->getName() << " ";
    }
    cout << "\n Items in Room: ";
    this->displayShelfContents();

    cout << "\n";
}
