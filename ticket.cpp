//Name: Victor Vu   netID: vhv180000
//Homework #8
//Ticket implementations file

#include "Ticket.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
Ticket::Ticket()
{
    Ship_ptr = nullptr;
    Dock_ptr = nullptr;
    hour_out = 0;
    minute_out = 0;
}

//Overloaded Constructor
Ticket::Ticket(Ship* ptr_s, Dock* ptr_d, int hour, int minute)
{
    Ship_ptr = ptr_s;
    Dock_ptr = ptr_d;
    hour_out = hour;
    minute_out = minute;
}

//Copy Constructor 
Ticket::Ticket(Ticket& obj)
{
    Ship_ptr = obj.Ship_ptr;
    Dock_ptr = obj.Dock_ptr;
    hour_out = obj.hour_out;
    minute_out = obj.minute_out;
}

//Calculate fine function
int Ticket::Calc_fine() const {
    int time_in, 
        time_out, 
        time_over, 
        charge = 0;
    
    time_in = (((Dock_ptr -> getHour_in()) * 60) + (Dock_ptr -> getMinute_in()));
    
    time_out = (((hour_out * 60) + minute_out));
    
    time_over = time_out - (time_in + (Ship_ptr -> getCredit()));
    
    if (time_over > 60)
        charge = (60 * 200) + (500 * (time_over - 60));
    else 
        charge = time_over * 200;
    
    return charge;
}

//Overloaded insertion or << operator 
ostream& operator << (ostream& stream, const Ticket& obj)
{
    int extra_time, 
        time_in, 
        time_out;

    time_in = (((obj.Dock_ptr -> getHour_in()) * 60) + (obj.Dock_ptr -> getMinute_in()));

    time_out = (((obj.hour_out * 60) + obj.minute_out));

    extra_time = time_out - (time_in + (obj.Ship_ptr -> getCredit()));
    
    stream << "Ship ID: " << obj.Ship_ptr -> getID() << endl;
    stream << "Name: " << obj.Ship_ptr -> getName() << endl;
    stream << "Time In: " << setfill('0') << setw(2) << obj.Dock_ptr -> getHour_in() << ":" << setfill('0') << setw(2) << obj.Dock_ptr -> getMinute_in() << endl;
    stream << "Time Out: " << setfill('0') << setw(2) << obj.hour_out << ":" << setfill('0') << setw(2) << obj.minute_out << endl;
    stream << "Credited Minutes: " << obj.Ship_ptr -> getCredit() << endl;
    stream << "Extra minutes: " << extra_time << endl;
    stream << "Fine: " << obj.Calc_fine() << endl;
    stream << endl;
    
    return stream;
}