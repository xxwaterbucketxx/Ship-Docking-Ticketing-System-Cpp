//Name: Victor Vu   netID: vhv180000
//Homework #8
//Dock implementations file

#include "Dock.h"

Dock::Dock()
{
    hour_in = 0;
    minute_in = 0;
    Ship = nullptr;
}
Dock::Dock(int hour, int minute)
{
    hour_in = hour;
    minute_in = minute;
    Ship = nullptr;
}
