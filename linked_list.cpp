//Name: Victor Vu   netID: vhv180000
//Homework #8
//Linked list implementations file

#include <iostream>
#include "Linked_list.h"
#include "Ship.h"

using namespace std;

//Default Constructor
Linked_list::Linked_list() 
{
    head = nullptr;
}

//Overloaded Constructor
Linked_list::Linked_list(Ship * first) 
{
    head = first;
}

//Destructor 
Linked_list::~Linked_list() 
{
    Ship* ptr = head;
    
    while (head != nullptr)
    {
        head = ptr -> getShip_next();
        delete ptr;
        
        ptr = head;
    }
    
    cout << "The deconstructor has been ran";
}

//Overloaded += operator 
Linked_list& Linked_list::operator+=(Ship* ship)
{
    Ship* ptr = head;
    
    if (head == nullptr)
    {
        head = ship;
    } 
    else
    {
        while((ptr != nullptr) && (ptr -> getShip_next() != nullptr))
            ptr = ptr -> getShip_next();

        ptr -> setShip_next(ship);
    }
    
    return *this;
}

//Overloaded -- operator
Ship* Linked_list::operator--() 
{
    Ship* ptr = head;
    
    head = ptr -> getShip_next();
    
    ptr -> setShip_next(nullptr);
    
    return ptr;
}