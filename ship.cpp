//Name: Victor Vu   netID: vhv180000
//Homework #7
//Ship implementation file

#include "Ship.h"
#include <string>
using namespace std;

Ship::Ship()
{
    name = "";
    ID = "";
    credit = 0;
    ship_next = nullptr;
}

Ship::Ship(string name_pass, string ID_pass, int credit_pass)
{
    name = name_pass;
    ID = ID_pass;
    credit = credit_pass;
    ship_next = nullptr;
}