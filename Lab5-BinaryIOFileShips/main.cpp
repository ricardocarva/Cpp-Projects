#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "extrafile.h"

using namespace std;

void load_data_placeholder(int option, vector<Ship>& output);
void load_data(string filePath, vector<Ship>& output);

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

   /* Load files here */

	vector <Ship> ships_vector;
	load_data_placeholder(option, ships_vector);

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	
	cin >> option;
	
	/* Work your magic here */
	if (option == 1)
	{
		// Print All
		for (unsigned int i = 0; i < ships_vector.size(); i++)
		{
			ships_vector.at(i).Print();
		}
	}
	else if (option == 2)
	{
		// Starship with the strongest weapon
		int index_strongest = 0;
		int highest_power = 0;
		int temp_power = 0;

		for (unsigned int i = 0; i < ships_vector.size(); i++)
		{
			if (ships_vector.at(i).GetWeaponCount() > 0)
			{
				for (int j = 0; j < ships_vector.at(i).GetWeaponCount(); j++)
				{
					temp_power = ships_vector.at(i).GetWeaponPower(j);
					if (temp_power > highest_power)
					{
						highest_power = temp_power;
						index_strongest = i;
					}
				}				
			}
		}
		ships_vector.at(index_strongest).Print();
	}

	else if (option == 3)
	{
		// Strongest starship overall
		int index_strongest_overall = 0;
		int highest_fire_power = INT_MIN;
		int temp_fire_power = INT_MIN;

		for (unsigned int i = 0; i < ships_vector.size(); i++)
		{
			if (ships_vector.at(i).GetWeaponCount() > 0)
			{				
				temp_fire_power = ships_vector.at(i).GetFirePower();
				if (temp_fire_power > highest_fire_power)
				{
					highest_fire_power = temp_fire_power;
					index_strongest_overall = i;
				}
			}
		}
		ships_vector.at(index_strongest_overall).Print();
	}
	else if (option == 4)
	{
		// Weakest ship (ignoring unarmed)
		int index_weakest_overall = 0;
		int weakest_fire_power = INT_MAX;
		int temp_fire_power = INT_MAX;

		for (unsigned int i = 0; i < ships_vector.size(); i++)
		{
			if (ships_vector.at(i).GetWeaponCount() > 0)
			{
				temp_fire_power = ships_vector.at(i).GetFirePower();
				if (temp_fire_power < weakest_fire_power)
				{
					weakest_fire_power = temp_fire_power;
					index_weakest_overall = i;
				}
			}
		}
		ships_vector.at(index_weakest_overall).Print();
	}
	else if (option == 5)
	{
		// Unarmed ships
		for (unsigned int i = 0; i < ships_vector.size(); i++)
		{
			if (ships_vector.at(i).GetWeaponCount() == 0)
			{
				ships_vector.at(i).Print();
			}
		}
	}
	else {
		cout << "Invalid selection!" << endl;
	}
	
   return 0;
}

void load_data_placeholder(int option, vector<Ship>& output)
{
	if (option == 1)
	{
		load_data("friendlyships.shp", output);
	}
	else if (option == 2)
	{
		load_data("enemyships.shp", output);
	}
	else if (option == 3)
	{
		load_data("friendlyships.shp", output);
		load_data("enemyships.shp", output);

	}
	else {
		cout << "Invalid entry!" << endl;
	}
}

void load_data(string filePath, vector<Ship>& output)
{
	ifstream inFile(filePath, ios_base::binary);
	if (inFile.is_open())
	{
		Ship newShip;
		newShip.ReadDataFromFile(inFile, output);
		inFile.close();
	}
	else
	{
		cout << "Error! File " << filePath << " could not be opened!" << endl;
	}

}
