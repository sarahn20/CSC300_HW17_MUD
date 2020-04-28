#ifndef Room_hpp
#define Room_hpp

#include <string>

class Door; // allows us to reference door when door refereneces Room.
class Student;
class LinkedListOfStudents;

using namespace std;

class Room
{
    private:
        string title;
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
        
    
    public:
        Room(string title);
        void addDoor(Door* d);
        string getTitle();
        void startGame(Student* player, LinkedListOfStudents* ls);
};
#endif
