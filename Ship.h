//Name: Victor Vu   netID: vhv180000
//Homework #8
//Ship header file

#ifndef HOMEWORK__7_SHIP_H
#define HOMEWORK__7_SHIP_H
#include <string>

using namespace std;

class Ship{

private:
    string name;
    string ID;
    int credit;
    Ship* ship_next;
    
public:
    //Constructors
    Ship();
    Ship(string, string, int);
    
    //Accessors
    string getName()    {return name;}
    string getID()  {return ID;}
    int getCredit() {return credit;}
    Ship* getShip_next() {return ship_next;}
    
    //Mutators
    void setName(string n)  {name = n;}
    void setID(string i)    {ID = i;}
    void setCredit(int c)   {credit = c;}
    void setShip_next(Ship* p)   {ship_next = p;}
    
};

#endif //HOMEWORK__7_SHIP_H
