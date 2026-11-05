//Name: Victor Vu   netID: vhv180000
//Homework #8
//Main driver file

#include <fstream>
#include <iostream>
#include "Ship.h"
#include "Dock.h"
#include "Ticket.h"
#include "Linked_list.h"
#include <string>

using namespace std;

int main() 
{
    
    //Create linked list object
    Linked_list Queue;
    
    //Dynamically create 3 Ships
    Ship* Ship1 = new Ship ("MayFlower", "12345", 60);
    Ship* Ship2 = new Ship ("BlackPearl", "54321", 60);
    Ship* Ship3 = new Ship ("Titanic", "98765", 60);

    //Add the three ships to thee Linked 
    // list with the overloaded += operator
    Queue += Ship1;
    Queue += Ship2;
    Queue += Ship3;
    
    //Create a Dock Object
    Dock Dock1;
    
    //Remove the Ship from the Linked list using the --operator
    //Connect the Dock to the Ship that was removed
    Dock1.setShip(--Queue);
    
    //Update the Dock time in to 12 hours, 0 minutes
    Dock1.setHour_in(12);
    Dock1.setMinute_in(0);
    
    //Create a Ticket object
    Ticket Ticket1;
    
    //Connect the Ticket to the Ship and Dock
    Ticket1.setDock_ptr(&Dock1);
    Ticket1.setShip_ptr(Dock1.get_Ship());
    
    //Disconnect the Ship from the Dock
    Dock1.setShip(nullptr);

    //Update the Ticket Object to 14 hours, 0 minutes
    Ticket1.setHour_out(14);
    Ticket1.setMinute_out(0);
    
    
    fstream outfile ("Tickets.txt", ios::out | ios::binary);

    //Display the Ticket Object using the overloaded << operator below
    
    //Display to file
    outfile << Ticket1;
    //Display to console 
    cout << Ticket1;
    
    outfile.close();
    
    return 0;
}
