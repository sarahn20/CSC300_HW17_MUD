#include <iostream>
#include "Room.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include "LinkedListOfStudents.hpp"

using namespace std;

int main()
{
   LinkedListOfStudents* ll = new LinkedListOfStudents();
   Student* gonzales = new Student("Mr. Gonzales");
   Student* joe = new Student("Crazy Joe");
   Student* you = new Student("You");
   ll->addFront(gonzales);
   ll->addFront(joe);
   ll->addFront(you);
   Room* hallway1_75 = new Room("Hallway 1.75"); //1
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
   Room* advLab1 = new Room("Advance Lab 1"); //14
   Room* advLab2 = new Room("Advance Lab 2"); //15
   //////
   Door* hw1_75ANDhw1_5 = new Door("east",hallway1_75, "west", hallway1_5); //1
   Door* hw1_5ANDhw1 = new Door("north",hallway1_5,"south", hallway1); //2
   Door* hw1ANDhw0 = new Door("north", hallway1, "south", hallway0); //3
   Door* hw0ANDclassroom120 = new Door("north", hallway0, "south", classroom120); //4
   Door* hw0ANDlobby = new Door("east", hallway0, "west", lobby); //5
   Door* lobbyANDesports = new Door("north", lobby, "south", esports); //6
   Door* lobbyANDlocklairsOffice = new Door("east", lobby, "west", locklairsOffice); //7
   Door* lobbyANdserverRoom = new Door("south", lobby, "north", serverRoom); //8
   Door* hw1_5ANDhw2 = new Door("north", hallway2, "south", hallway1_5); //9
   Door* hw2ANDmacLab1 = new Door("north", macLab1, "south", hallway2); //10
   Door* hw2ANDadvLab1 = new Door("east", advLab1, "west",hallway2); //11
   Door* advLab1ANDadvLab2 = new Door("north", advLab2, "south", advLab1); //12
   Door* macLab1ANDmacLab2 = new Door("west", macLab2, "east", macLab1); //13
   Door* macLab2ANDclassroom118 = new Door("north", macLab2, "south", classroom118); //14
   Door* hw2ANDclassroom118 = new Door("west", classroom118, "east", hallway2); //15
   gonzales->setCurrentRoom(locklairsOffice);
   joe->setCurrentRoom(esports);
   hallway1_75->startGame(you, ll);
   return 0;
}
