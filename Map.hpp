#ifndef Map_hpp
#define Map_hpp
#include "Room.hpp"

class Map
{
    private:
        Room* currRoom;
        string mapName;
    
    public:
        Map(string mapName);
        void setCurrRoom(Room* currRoom);
        string getCurrRoomName();
        Room* getCurrRoom();
        string getMapName();
        
};
#endif
