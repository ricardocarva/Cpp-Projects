#include "Showroom.h"
#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"
using namespace std;

Showroom::Showroom(string name, unsigned int capacity) {
	_name = name;
	_capacity = capacity;
}

vector <Vehicle> Showroom::GetVehicleList() {
	return _vehicles;
}

void Showroom::AddVehicle(Vehicle v) {
	unsigned int number_of_vehicles = _vehicles.size();
	if (number_of_vehicles == _capacity) {
		cout << "Showroom is full! Cannot add " << v.Vehicle::GetYearMakeModel() << endl;
	}
	else {
		_vehicles.push_back(v);
	}
}

void Showroom::ShowInventory() {
	unsigned int number_of_vehicles = _vehicles.size();
	if (number_of_vehicles == 0) {
		cout << _name << " is empty!" << endl;
	}
	else {
		cout << "Vehicles in " << _name << endl;

	}


	for (int i = 0; i < number_of_vehicles; i++)
	{
		_vehicles.at(i).Display();
	}
}

float Showroom::GetInventoryValue() {
	int number_of_vehicles = _vehicles.size();
	float sum = 0;
	for (int i = 0; i < number_of_vehicles; i++)
	{
		sum += _vehicles.at(i).GetPrice();
	}
	return sum;
}