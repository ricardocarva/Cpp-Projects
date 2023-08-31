#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

///*========= Util Class =========*/


class Ship
{
public:
	struct Weapon
	{
		string _weapon_name;
		int _power_rating;
		float _power_consumption;
		/*========= Constructor =========*/
		Weapon(string weapon_name = "Unarmed", int power_rating = 0, float power_consumption = 0.0f);
		/*========= Acessors =========*/
		string GetWeaponName() const;
		int GetWeaponPowerRating() const;
		float GetWeaponPowerConsumption() const;
	};

	/*========= Constructor =========*/
	Ship(string ship_name = "Unammed", string ship_class = "Default", short length = 0, int shield_capacity = 0, float warp_speed = 0.0f, int weapon_count = 0);

	/*========= Acessors =========*/
	string GetShipName() const;
	string GetShipClass() const;
	short GetLenght() const;
	int GetShieldCapacity() const;
	float GetWarpSpeed() const;
	vector <Weapon> GetWeapons() const;
	int GetWeaponPower(int index) const;
	int GetWeaponCount() const;
	int GetFirePower() const;
		
	/*========= Mutators =========*/
	void AddWeapon(string weapon_name, int power_rating, float power_consumption);

	/*========= Util =========*/
	void ReadDataFromFile(ifstream& inFile,vector<Ship>& input_ship);
	void Print() const;

private:
	string _ship_name;
	string _ship_class;
	short _length;
	int _shield_capacity;
	float _warp_speed;
	int _weapon_count;
	vector <Weapon> _weapons;
};


