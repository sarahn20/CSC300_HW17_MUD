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

void Room::constructMap()
{
    

    Student* player2 = new Student("Mr. Gonzales");
   
    this->ll->addFront(player1);
    this->ll->addFront(player2);
    Room* hallway1_5 = new Room("Hallway 1.5"); //2
    Room* hallway1 = new Room("Hallway 1"); //3
    Room* hallway0 = new Room("Hallway 0"); //4
    Room* classroom120 = new Room("Classroom 120"); //5
    Room* lobby = new Room("Lobby"); //6
    Room* esports = new Room("Esports"); //7
    Room* locklairsOffice = new Room("Locklair's Office"); //8
    Room* serverRoom = new Room("Server Room"); //9
    Room* hallway2 = new Room("Hallway 2"); //10
    Room* classroom118 = new Room("Classroom 118"); //11
    Room* macLab2 = new Room("Mac Lab 2"); //12
    Room* macLab1 = new Room("Mac Lab 1"); //13
    Room* advLab1 = new Room("Advance Lab 2"); //14
    Room* advLab2 = new Room("Advance Lab 1"); //15
    player2->setCurrentRoom(hallway1);
    Door* hw1_75ANDhw1_5 = new Door("East",this, "West", hallway1_5); //1
    Door* hw1_5ANDhw1 = new Door("North",hallway1_5,"South", hallway1); //2
    Door* hw1ANDhw0 = new Door("North", hallway1, "South", hallway0); //3
    Door* hw0ANDclassroom120 = new Door("North", hallway0, "South", classroom 120); //4
    Door* hw0ANDlobby = new Door("East", hallway0, "Wester", lobby); //5
    Door* lobbyANDesports = new Door("North", lobby, "South", esports); //6
    Door* lobbyANDlocklairsOffice = new Door("East", lobby, "West", locklairsOffice); //7
    Door* lobbyANdserverRoom = new Door("South", lobby, "North", serverRoom); //8
    Door* hw1_5ANDhw2 = new Door("North", hallway2, "South", hallway1_5); //9
    Door* hw2ANDmacLab1 = new Door("North", macLab1, "South", hallway2); //10
    Door* hw2ANDadvLab1 = new Door("East", advLab1, "West",hallway2); //11
    Door* advLab1ANDadvLab2 = new Door("North", advLab2, "South", advLab1); //12
    Door* macLab1ANDmacLab2 = new Door("West", macLab2, "East", macLab1); //13
    Door* macLab2ANDclassroom118 = new Door("West", macLab2, "South", classroom118); //14
    Door* hw2ANDclassroom118 = new Door("West", classroom118, "East", hallway2)
    }

string Room::getTitle()
{
    return this->title;
}

void Room::onRoomEnter()
{
    player1->setCurrentRoom(this);
    cout << "You are in room: " << this->title << "\n";
    this->inThisRoom();
    this->collectionOfDoors;
    for(int i = 0; i < 10; i++)
    {
        if(this->collectionOfDoors[i]->getRoomA() == this)
        {
            cout << "The " << this->collectionOfDoors[i]->getDirectionToRoomB() << " leads to " << this->collectionOfDoors[i]->getRoomB()->getTitle() << "\n";
        } 
        else if(this->collectionOfDoors[i]->getRoomB() == this)
        {
            cout << "The " << this->collectionOfDoors[i]->getDirectionToRoomA() << " leads to " << this->collectionOfDoors[i]->getRoomA()->getTitle() << "\n";
        } 
    }
    string direction;
    cout << "Enter the direction you would like to go: ";
    cin >> direction;
    for(int i = 0; i < 10; i++)
    {
        if(this->collectionOfDoors[i]->getRoomA() != this)
        {
            if(this->collectionOfDoors[i]->getDirectionToRoomA() == direction)
            {
                this->collectionOfDoors[i]->getRoomA()->onRoomEnter();
            }
            
        } 
        else if(this->collectionOfDoors[i]->getRoomB() != this)
        {
            if(this->collectionOfDoors[i]->getDirectionToRoomB() == direction)
            {
                this->collectionOfDoors[i]->getRoomB()->onRoomEnter();
            }
            
        } 
    }


}

void Room::inThisRoom()
{
    StudentNode* currNode = ll->getHead();
    cout << "These are the students in the room: ";
    while(int i = 0 < ll->getCount())
    {
        if(currNode->getPayload()->getCurrentRoom() == this)
        {
            cout << currNode->getPayload()->getName() << ", ";
            
        }
        currNode = currNode->getNextNode();
        i++;
        

    }
   




}

