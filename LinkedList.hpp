#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Student.hpp"

class LinkedList 
{
private:
    Student* head;
    int count;
    Student* runToEndOfList();
    Student* runToIndex(int index);
    
public:
    LinkedList();
    void addFront(string studentName);
    string getFront();
    string removeFront();
    void display();
#endif /* LinkedList_hpp */
