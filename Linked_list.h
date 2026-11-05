//Name: Victor Vu   netID: vhv180000
//Homework #8
//Linked list header file

#ifndef HOMEWORK__7_LINKED_LIST_H
#define HOMEWORK__7_LINKED_LIST_H
#include "Ship.h"

class Linked_list{
    
private: 
    Ship* head;
    
public:
    //Constructors
    Linked_list();
    Linked_list(Ship*);
    
    //Destructor 
    ~Linked_list();
    
    //Accessors
    Ship* getHead_ptr() {return head;}
    
    //Mutators
    void setHead_ptr(Ship* h)   {head = h;}
    
    //Overloaded operators
    Linked_list & operator += (Ship*);
    Ship* operator --();
    
};

#endif //HOMEWORK__7_LINKED_LIST_H
