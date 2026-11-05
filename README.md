# Ship Docking Ticketing System

A C++ console application that simulates a ship docking management system with ticketing and fine calculation. Built as a university homework assignment demonstrating object-oriented programming, linked lists, operator overloading, and file I/O.

## 📋 Overview

This system manages ships waiting to dock at a port facility. Ships are queued in a linked list, assigned to available docks, and issued tickets that track their docking duration and calculate fines for overstaying their allotted time.

## ✨ Features

- **Ship Queue Management**: Custom linked list implementation for FIFO ship queuing
- **Dock Assignment**: Assign ships to docks with check-in time tracking
- **Ticket Generation**: Create tickets linking ships to docks with check-out times
- **Fine Calculation**: Automatic fine computation based on credited vs. actual docking time
- **Binary File Output**: Save tickets to binary files for record keeping
- **Operator Overloading**: Intuitive `+=` (enqueue) and `--` (dequeue) operators

## 🏗️ Class Structure

```
┌─────────────┐     ┌─────────────┐     ┌─────────────┐
│    Ship     │     │    Dock     │     │   Ticket    │
├─────────────┤     ├─────────────┤     ├─────────────┤
│ - name      │     │ - hour_in   │     │ - Ship_ptr  │
│ - ID        │     │ - minute_in │     │ - Dock_ptr  │
│ - credit    │     │ - Ship*     │     │ - hour_out  │
│ - ship_next │     └─────────────┘     │ - minute_out│
├─────────────┤                         ├─────────────┤
│ + getName() │                         │ + Calc_fine()│
│ + getID()   │                         │ + operator<< │
│ + getCredit()│                        └─────────────┘
│ + getShip_next()
│ + setShip_next()
└─────────────┘
        ▲
        │
┌───────┴───────┐
│ Linked_list   │
├───────────────┤
│ - head        │
├───────────────┤
│ + operator+=  │  // Enqueue ship
│ + operator--  │  // Dequeue ship
└───────────────┘
```

## 💰 Fine Calculation Logic

| Overtime Duration | Rate |
|-------------------|------|
| First 60 minutes  | $200/minute |
| Beyond 60 minutes | $500/minute |

**Formula:**
```
time_in = (dock_hour × 60) + dock_minute
time_out = (ticket_hour × 60) + ticket_minute
extra_time = time_out - (time_in + ship_credit)

if extra_time > 60:
    fine = (60 × 200) + (extra_time - 60) × 500
else:
    fine = extra_time × 200
```

## 🚀 Getting Started

### Prerequisites
- C++14 compatible compiler (GCC, Clang, MSVC)
- CMake 3.15+

### Building

```bash
mkdir build && cd build
cmake ..
make
./Ship_Docking_Ticketing_System
```

Or with a single command:
```bash
g++ -std=c++14 main.cpp ship.cpp dock.cpp ticket.cpp linked_list.cpp -o ticketing
./ticketing
```

### Sample Output

```
Ship ID: 12345
Name: MayFlower
Time In: 12 : 0
Time Out: 14 : 0
Credited Minutes: 60
Extra minutes: 60
Fine: 12000
```

## 📁 Project Structure

```
Ship-Docking-Ticketing-System/
├── CMakeLists.txt          # Build configuration
├── main.cpp                # Driver program
├── Ship.h / Ship.cpp       # Ship class
├── Dock.h / Dock.cpp       # Dock class
├── Ticket.h / Ticket.cpp   # Ticket class with fine calculation
├── Linked_list.h / .cpp    # Custom linked list queue
└── README.md               # This file
```

## 🔧 Key Implementation Details

### Linked List Queue (Linked_list)
- **`operator+=`**: Appends ship to end of queue (O(n))
- **`operator--`**: Removes and returns head ship (O(1))
- **Destructor**: Properly deletes all nodes to prevent memory leaks

### Ticket System
- Uses **composition** (pointers to Ship and Dock objects)
- Implements **copy constructor** for ticket duplication
- Overloads **`operator<<`** for formatted output to console/file
- Binary file I/O for persistent ticket storage

### Memory Management
- Ships dynamically allocated with `new`
- Linked list destructor handles cleanup
- Raw pointers used (pre-smart pointer homework assignment)

## 📝 Example Usage

```cpp
// Create queue and ships
Linked_list Queue;
Ship* ship1 = new Ship("MayFlower", "12345", 60);
Ship* ship2 = new Ship("BlackPearl", "54321", 60);

Queue += ship1;  // Enqueue
Queue += ship2;

// Assign first ship to dock
Dock dock1;
dock1.setShip(--Queue);  // Dequeue and assign
dock1.setHour_in(10);
dock1.setMinute_in(30);

// Create ticket
Ticket ticket1;
ticket1.setDock_ptr(&dock1);
ticket1.setShip_ptr(dock1.get_Ship());
ticket1.setHour_out(12);
ticket1.setMinute_out(45);

// Output ticket (calculates fine automatically)
cout << ticket1;

// Save to file
fstream outfile("tickets.dat", ios::out | ios::binary);
outfile << ticket1;
```

## 🎯 Learning Outcomes Demonstrated

- Object-Oriented Design (encapsulation, composition)
- Dynamic Memory Management
- Linked List Implementation
- Operator Overloading
- File I/O (binary and text)
- CMake Build System
- Const Correctness

## 👨‍💻 Author

**Victor Vu**  
University Coursework - Data Structures / C++ Programming

## 📄 License

Educational project - No license specified