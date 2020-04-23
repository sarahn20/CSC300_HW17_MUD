#include <iostream>
#include "Room.hpp"

using namespace std;

int main()
{
    
    Room* hallway1_75 = new Room("Hallway 1.75"); //1
    hallway1_75->constructMap();
    hallway1_75->onRoomEnter();
    return 0;
}
