#include "Student.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
    this->maxItemCount = 10;
    this->currentItemCount = 0;
    this->backpack = (Item**)malloc(this->maxItemCount * sizeof(Item*));
}

void Student::displayBackpackContents()
{
    if(this->currentItemCount > 0)
    {
        for(int i = 0; i < this->currentItemCount; i++)
        {
            cout << this->backpack[i]->getName() << "\n";
        }
    }
    else
    {
        cout << "nothing \n";
    }
}

bool Student::addItem(Item* anItem)
{
    if(this->currentItemCount == this->maxItemCount)
    {
        return false;
    }
    else
    {
        this->backpack[this->currentItemCount] = anItem;
        this->currentItemCount++;
        return true;
    } 
}

Item* Student::removeItem(string anItem)
{
    Item* tempItem = 0;
    for(int i = 0; i < this->currentItemCount; i++)
    {
        if(this->backpack[i]->getName() == anItem)
        {
            tempItem = this->backpack[i];
            while(i < this->currentItemCount-1)
            {
                this->backpack[i] = this->backpack[i+1];
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

string Student::getName()
{
    return this->name;
}

void Student::setCurrentRoom(Room* aRoom)
{
    this->currentRoom = aRoom;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}
