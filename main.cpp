#include <iostream>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include "Item.hpp"
#include <string>
#include <string.h>

using namespace std;

int main()
{
    Student* theStudent = new Student("Mr. Gonzales");
    Room* lobby = new Room("Lobby");
    Room* serverRoom = new Room("Server Room");
    Room* esports = new Room("Esports");
    Room* locklairOffice = new Room("Lockair's Office");

    Door* d1 = new Door("north", serverRoom, "south", lobby);
    Door* d2 = new Door("west", locklairOffice, "east", lobby);
    Door* d3 = new Door("south", esports, "north", lobby);

    string command = "";
    lobby->addStudent(theStudent);

    Item* chainsaw = new Item("chainsaw");
    Item* whisk = new Item("whisk");
    theStudent->addItem(chainsaw);
    theStudent->addItem(whisk);

    while(command != "quit")
    {
        theStudent->getCurrentRoom()->display();
        cout << "Where would you like to go?: ";
        cin >> command; 

        if(command == "backpack")
        {
            theStudent->displayBackpackContents();
        }
        
        if(command == "drop")
        {
            string droppedItem;
           cout << "Your backpack includes: ";
           theStudent->displayBackpackContents(); 
           cout << "\n The room's shelf includes: ";
           theStudent->getCurrentRoom()->displayShelfContents();
           cout << "\n Which item would you like to drop? ";
           cin >> droppedItem;
           theStudent->getCurrentRoom()->addItem(theStudent->removeItem(droppedItem));
           cout << "Your backpack includes: ";
           theStudent->displayBackpackContents(); 
           cout << "The room's shelf includes: ";
           theStudent->getCurrentRoom()->displayShelfContents();
           cout << "\n";
        }

        if(command == "grab")
        {
            string wantedItem;
           cout << "Your backpack includes: ";
           theStudent->displayBackpackContents(); 
           cout << "\n The room's shelf includes: ";
           theStudent->getCurrentRoom()->displayShelfContents();
           cout << "\n Which item would you like to grab? ";
           cin >> wantedItem;
           theStudent->addItem(theStudent->getCurrentRoom()->removeItem(wantedItem));
           cout << "Your backpack includes: ";
           theStudent->displayBackpackContents(); 
           cout << "The room's shelf includes: ";
           theStudent->getCurrentRoom()->displayShelfContents();
           cout << "\n";
        }
        
        else
        {
            theStudent->getCurrentRoom()->takeDoor(theStudent, command);
        } 
    }
    cout << "Goodbye!!!\n";
    return 0;
}
