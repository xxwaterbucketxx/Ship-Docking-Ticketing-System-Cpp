//Name: Victor Vu   netID: vhv180000
//Homework #8
//Ticket header file

#ifndef HOMEWORK__7_TICKET_H
#define HOMEWORK__7_TICKET_H
#include <iostream>
#include "Ship.h"
#include "Dock.h"

using namespace std;

class Ticket{
    
private:
    Ship* Ship_ptr;
    Dock* Dock_ptr;
    int hour_out;
    int minute_out;
    
public:
    //Constructors
    Ticket();
    Ticket(Ship*, Dock*, int, int);
    Ticket(Ticket&);
    
    //Accessors
    Ship* getShip_ptr() {return Ship_ptr;}
    Dock* getDock_ptr() {return Dock_ptr;}
    int getHour_out()   {return hour_out;}
    int getMinute_out() {return minute_out;}
    
    //Mutators
    void setShip_ptr(Ship* s)   {Ship_ptr = s;}
    void setDock_ptr(Dock* d)   {Dock_ptr = d;}
    void setHour_out(int h)     {hour_out = h;}
    void setMinute_out(int m)   {minute_out = m;}

    //Calculate fine function
    int Calc_fine() const;
    
    //Overloaded insertion or << operator
    friend ostream& operator << (ostream&, const Ticket&);
    
};
#endif //HOMEWORK__7_TICKET_H
