#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Showroom.h"
#include <string>
#include <vector>
using namespace std;

class Dealership
{
	string _name;
	unsigned int _capacity;
	vector <Showroom> _showroom;

public:
	//Constructors
	Dealership(string name = "Generic Dealership", unsigned int capacity = 0);

	// Behaviors 
	void AddShowroom(Showroom s); 
	float GetAveragePrice(); 
	void ShowInventory();

};

