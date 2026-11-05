//Name: Victor Vu   netID: vhv180000
//Homework #8
//Dock header file

#ifndef HOMEWORK__7_DOCK_H
#define HOMEWORK__7_DOCK_H
#include "Ship.h"

class Dock{
    
private:
    int hour_in;
    int minute_in;
    Ship* Ship;
    
public:
    //Constructors
    Dock();
    Dock(int, int);
    
    //Accessors
    int getHour_in()    {return hour_in;}
    int getMinute_in()  {return minute_in;}
    class Ship* get_Ship()    {return Ship;}
    
    //Mutators
    void setHour_in(int h)  {hour_in = h;}
    void setMinute_in(int m)    {minute_in = m;}
    void setShip(class Ship* p)  {Ship = p;}
};

#endif //HOMEWORK__7_DOCK_H
