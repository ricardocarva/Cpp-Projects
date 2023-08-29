#include "Dealership.h"
#include <iostream>
#include "Vehicle.h"
#include "Showroom.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Dealership::Dealership(string name, unsigned int capacity) {
	_name = name;
	_capacity = capacity;
}

void Dealership::AddShowroom(Showroom s) {
	int number_of_showrooms = _showroom.size();
	if (number_of_showrooms == _capacity) {
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else {
		_showroom.push_back(s);
	}
}

float Dealership::GetAveragePrice() {
	int number_of_showrooms = _showroom.size();
	float sum = 0;
	unsigned int number_of_vehicles = 0;
	for (int i = 0; i < number_of_showrooms; i++) {
		number_of_vehicles += _showroom.at(i).GetVehicleList().size();
		sum += _showroom.at(i).GetInventoryValue();
	}
	return sum / number_of_vehicles;
}

void Dealership::ShowInventory() {
	int number_of_showrooms = _showroom.size();
	if (number_of_showrooms == 0) {
		cout << _name << " is empty!" << endl;
		cout << "Average car price: $0.00";
	}
	else {
		for (int i = 0; i < number_of_showrooms; i++) {
			_showroom.at(i).ShowInventory();
			cout << endl;
		}
		cout << "Average car price: $" << setprecision(2) << GetAveragePrice();
	}


}