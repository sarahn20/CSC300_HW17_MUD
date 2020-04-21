#ifndef Door_hpp
#define Door_hpp
#include "Room.hpp"

using namespace std;

class Door
{
    private:
        Room* room1;
        Room* room2;
    
    
    public:
        Door(Room* room1, Room* room2);
        string getRoom1Name();
        string getRoom2Name();
    
};
#endif
