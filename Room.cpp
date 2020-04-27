#include "Room.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include "LinkedListOfStudents.hpp"
#include <iostream>

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
    this->collectionOfDoors[10];
    
}

void Room::addDoor(Door* d)
{
    for(int i = 0; i < 10; i++)
    {
        if(this->collectionOfDoors[i] == 0)
        {
            this->collectionOfDoors[i] = d;
            this->currentNumberOfDoors++;
            break;
        }
    }
}

string Room::getTitle()
{
    return this->title;
}

void Room::startGame(Student* player, LinkedListOfStudents* ls)
{
    player->setCurrentRoom(this);
    cout << "YOU ARE IN: " << this->getTitle() << "\n";
    cout << "Students in " << this->getTitle() << " include: ";
    StudentNode* currNode = ls->getHead();
    for(int i = 0; i < ls->getCount(); i++)
    {
        if(currNode->getPayload()->getCurrentRoom() == this)
        {
            if(currNode != ls->getHead())
            {
                cout << ", ";
            }
            cout << currNode->getPayload()->getName();
            
        }
        currNode = currNode->getNextNode();
    }
    cout << "\n";
    for(int i = 0; i < 10; i++) // displays all possible rooms to go to
    {
        if(this->collectionOfDoors[i] != 0)
        {
            if(this->collectionOfDoors[i]->getRoomA() == this)
            {
                cout << this->collectionOfDoors[i]->getRoomB()->getTitle() << " is through the " << this->collectionOfDoors[i]->getDirectionToRoomB() << " door" << "\n";
            }
            else if(this->collectionOfDoors[i]->getRoomB() == this)
            {
                cout << this->collectionOfDoors[i]->getRoomA()->getTitle() << " is through the " << this->collectionOfDoors[i]->getDirectionToRoomA() << " door" << "\n";
            }

        }
    }
    string userInput = "";
    cout << "Enter the direction where you would like to go next: ";
    cin >> userInput;
    cout << "\n";
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++) //sends user to their seleted room
        {
            if(this->collectionOfDoors[i] != 0)
            {
                if(this->collectionOfDoors[i]->getRoomA() == this)
                {
                    if(userInput == this->collectionOfDoors[i]->getDirectionToRoomB())
                    {
                        this->collectionOfDoors[i]->getRoomB()->startGame(player, ls);
                    }
                
                }
                else if(this->collectionOfDoors[i]->getRoomB() == this)
                {
                    if(userInput == this->collectionOfDoors[i]->getDirectionToRoomA())
                    {
                        this->collectionOfDoors[i]->getRoomA()->startGame(player, ls);
                    }
                    
                }

            }
            
        }
    }
    cout << "*There's no door in that direction! Try again.*" << "\n";
    this->startGame(player,ls);
}
