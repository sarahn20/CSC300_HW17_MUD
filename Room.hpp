#ifndef Room_hpp
#define Room_hpp
#include "LinkedListOfStudents.hpp"

#include <string>

class Door; // allows us to reference door when door refereneces Room.
class Student;

using namespace std;

class Room
{
    private:
        string title;
        
    
    public:
        Room(string title);
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
        void playGame();
        void constructMap();
        LinkedListOfStudents* ll;
        string getTitle();
        void onRoomEnter();
        void inThisRoom();
        Student* player1 = new Student("Sarah");

};
#endif
