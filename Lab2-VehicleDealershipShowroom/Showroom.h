#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"
using namespace std;

class Showroom {

    string _name;
    vector <Vehicle> _vehicles;
    unsigned int _capacity;

public:
    Showroom(string name = "Unnamed Showroom" , unsigned int capacity = 0);

    // Accessor
    vector <Vehicle> GetVehicleList();

    // Behaviors
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};
