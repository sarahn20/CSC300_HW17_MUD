#include <iostream>
#include "Room.hpp"
#include "Map.hpp"
#include "Door.hpp"
#include "Student.hpp"


int main()
{
    Map* cuwCS = new Map("The Computer Science Department");

    Room* hallway1_75 = new Room("Hallway 1.75");
    cuwCS->currRoom = hallway1_75; //1 
    
    //ROOMS 2-15
    Room* hallway1_5 = new Room("Hallway 1.5"); //2
    Room* hallway1 = new Room("Hallway 1"); //3
    Room* hallway2 = new Room("Hallway 2"); //4
    Room* hallway0 = new Room("Hallway 0"); //5
    Room* classroom120 = new Room("Classroom 120"); //6
    Room* esports = new Room("ESports"); //7
    Room* lobby = new Room("Lobby"); //8
    Room* serverRoom = new Room("Server Room"); //9
    Room* locklairsOffice = new Room("Locklair's Office"); //10 
    Room* macLab1 = new Room("Mac Lab 1"); //11 
    Room* macLab2 = new Room("Mac Lab 2"); //12
    Room* classroom118 = new Room("Classroom 118"); //13
    Room* advLab1 = new Room("Advanced Lab 1"); //14
    Room* advLab2 = new Room("Advanced Lab 2"); //15
    
    //MAKE DOORS
    Door* hw1_75TOhw1_5 = new Door(hallway1_75, hallway1_5); //1
    Door* hw1TOhw1_5 = new Door(hallway1, hallway1_5); //2
    Door* hw1TOhw0 = new Door(hallway1, hallway0); //3
    Door* hw0TO120 = new Door(hallway0, classroom120); //4
    Door* hw0TOlobby = new Door(hallway0, lobby); //5
    Door* lobbyTOesports = new Door(lobby, esports); //6
    Door* lobbyTOlocklairsOffice = new Door(lobby, locklairsOffice); //7
    Door* lobbyTOserverRoom = new Door(lobby, serverRoom); //8 
    Door* hw1_5TOhw2 = new Door(hallway1_5, hallway2); //9 
    Door* hw2TO118 = new Door(hallway2, classroom118); //10 
    Door* 118TOmacLab2 = new Door(classroom118, macLab2); //11 
    Door* macLab2TOmacLab1 = new Door(macLab1, macLab2); //12
    Door* macLab1TOhw2 = new Door(macLab1, hallway2); //13 
    Door* hw2TOadvLab1 = new Door(hallway2, advLab1); //14 
    Door* advLab1TOadvLab2 = new Door(advLab1, advLab2); //15
    
    //SET DOORS
    hallway1_75->setWestDoor(hw1_75TOhw1_5); //1
    hallway1_5->setEastDoor(hw1_75TOhw1_5); //2
    hallway1_5->setNorthDoor(hw1_5TOhw2); //3
    hallway1_5->setSouthDoor(hw1TOhw1_5); //4 
    hallway1->setNorthDoor(hw1TOhw1_5); //5 
    hallway1->setSouthDoor(hw1TOhw0); //6
    hallway0->setNorthDoor(hw1TOhw0); //7
    hallway0->setSouthDoor(hw0TO120); //8 
    hallway0->setWestDoor(hw0TOlobby); //9  
    classroom120->setNorthDoor(hw0TO120); //10 
    lobby->setEastDoor(hw0TOlobby); //11 
    lobby->setSouthDoor(lobbyTOesports); //12 
    lobby->setWestDoor(lobbyTOlocklairsOffice); //13 
    lobby->setNorthDoor(lobbyTOserverRoom); //14 
    esports->setNorthDoor(lobbyTOesports); //15 
    locklairsOffice->setEastDoor(lobbyTOlocklairsOffice); //16
    serverRoom->setSouthDoor(lobbyTOserverRoom); //17 
    hallway2->setSouthDoor(hw1_5TOhw2); //18 
    hallway2->setWestDoor(hw2TO118); //19 
    hallway2->setNorthDoor(macLab1TOhw2); //20 
    hallway2->setEastDoor(hw2TOadvLab1); //21 
    classroom118->setEastDoor(hw2TO118); //22 
    classroom118->setNorthDoor(118TOmacLab2); //23
    macLab2->setSouthDoor(118TOmacLab2); //24 
    macLab2->setEastDoor(macLab2TOmacLab1); //25 
    macLab1->setWestDoor(macLab2TOmacLab1); //26 
    macLab1->setSouthDoor(macLab1TOhw2); //27 
    advLab1->setWestDoor(hw2TOadvLab1); //28 
    advLab1->setNorthDoor(advLab1TOadvLab2); //29 
    advLab2->setSouthDoor(advLab1TOadvLab2); //30 

    //Inhabitants
    locklairsOffice->inhabitants->addFront("Dr. Locklair");
    classroom120->inhabitants->addFront("Dr. Litman");

    cuwCS->getCurrRoom->runMud();

    
    return 0;
}
