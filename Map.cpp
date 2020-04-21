#include "Map.hpp"

Map::Map(string mapName)
{
    this->mapName = mapName;
    this->currRoom = null;
}

void Map::setCurrRoom(Room* currRoom)
{
    this->currRoom = currRoom;
}

string Map::getCurrRoomName()
{
    return this->currRoom->getRoomName();
}

Room* Map::getCurrRoom()
{
    return this->currRoom;
}

string Map::getMapName()
{
    return this->mapName;
}
