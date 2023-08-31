#include "extrafile.h"

using namespace std;

/*====================== Weapons ===================*/
/*========= Constructor =========*/
Ship::Weapon::Weapon(string weapon_name, int power_rating, float power_consumption)
{
	_weapon_name = weapon_name;
	_power_rating = power_rating;
	_power_consumption = power_consumption;
}

/*========= Acessors =========*/


string Ship::Weapon::GetWeaponName() const{

	return _weapon_name;
}
int Ship::Weapon::GetWeaponPowerRating() const
{
	return _power_rating;
}
float Ship::Weapon::GetWeaponPowerConsumption() const
{
	return _power_consumption;
}

/*====================== Ships ===================*/

/*========= Constructor =========*/
Ship::Ship(string ship_name, string ship_class, short length, int shield_capacity, float warp_speed, int weapon_count)
{	
	_ship_name = ship_name;
	_ship_class = ship_class;
	_length = length;
	_shield_capacity = shield_capacity;
	_warp_speed = warp_speed;
	_weapon_count = weapon_count;
}

/*========= Acessors =========*/
string Ship::GetShipName() const
{
	return _ship_name;
	
}
string Ship::GetShipClass() const
{
	return _ship_class;
}
short Ship::GetLenght() const
{
	return _length;
}

int Ship::GetShieldCapacity() const
{
	return _shield_capacity;
}

float Ship::GetWarpSpeed() const
{
	return _warp_speed;
}
vector <Ship::Weapon> Ship::GetWeapons() const
{
	return _weapons;
}

int Ship::GetWeaponPower(int index) const
{
	return _weapons.at(index).GetWeaponPowerRating();

}

int Ship::GetWeaponCount() const
{
	return  _weapon_count;
}
int Ship::GetFirePower() const
{
	int firePower = 0;
	for (int i = 0; i <  _weapon_count; i++) {
		firePower += _weapons.at(i).GetWeaponPowerRating();
	}
	return firePower;
}

/*========= Mutators =========*/
void Ship::AddWeapon(string weapon_name, int power_rating, float power_consumption)
{
	_weapons.push_back(Weapon(weapon_name, power_rating, power_consumption));
}

/*========= Util =========*/
void Ship::ReadDataFromFile(ifstream& inFile,vector<Ship>& input_ship)
{

	//Ship variables
	int ships_count;

	int ship_name_length;
	string ship_name;

	int ship_class_length;
	string ship_class;

	short ship_length;

	int shield_capacity;

	float warp_speed;

	//Weapon variables
	int weapon_count;

	int weapon_name_length;
	string weapon_name;

	int weapon_power_rating;

	float weapon_power_consumption;

	inFile.read((char*)&ships_count, 4);

	for (int i = 0; i < ships_count; i++) 
	{
		// Name
		inFile.read((char*)&ship_name_length, 4);
		char* nameTemp = new char[ship_name_length];
		inFile.read(nameTemp, ship_name_length * sizeof(nameTemp[0]));
		ship_name = nameTemp;
		delete[] nameTemp;

		// Class
		inFile.read((char*)&ship_class_length, 4);
		char* classTemp = new char[ship_class_length];
		inFile.read(classTemp, ship_class_length * sizeof(classTemp[0]));
		ship_class = classTemp;
		delete[] classTemp;

		// Length
		inFile.read((char*)&ship_length, 2);
		// Shield Capacity
		inFile.read((char*)&shield_capacity, 4);
		// Warp Speed
		inFile.read((char*)&warp_speed, 4);
		// Weapon Count
		inFile.read((char*)&weapon_count, 4);
		// Create Ship
		Ship temp = Ship(ship_name, ship_class, ship_length, shield_capacity, warp_speed, weapon_count);

		if (weapon_count > 0) {
			for (int j = 0; j < weapon_count; j++) {
				inFile.read((char*)&weapon_name_length, 4);
				char* weapTemp = new char[weapon_name_length];
				inFile.read(weapTemp, weapon_name_length * sizeof(weapTemp[0]));
				weapon_name = weapTemp;
				delete[] weapTemp;
				inFile.read((char*)&weapon_power_rating, 4);
				inFile.read((char*)&weapon_power_consumption, 4);
				temp.AddWeapon(weapon_name, weapon_power_rating, weapon_power_consumption);
			}
		}
		input_ship.push_back(temp);
	}
}

void Ship::Print() const
{
	cout << "Name: " << _ship_name << endl;
	cout << "Class: " << _ship_class << endl;
	cout << "Length: " << _length << endl;
	cout << "Shield capacity: " << _shield_capacity << endl;
	cout << "Maximum Warp: " << _warp_speed << endl;
	cout << "Armaments:" << endl;

	if ( _weapon_count == 0) {
		cout << "Unarmed" << endl;
	}
	else {
		for (int i = 0; i <  _weapon_count; i++) {
			cout << _weapons.at(i).GetWeaponName() << ", " << _weapons.at(i).GetWeaponPowerRating() << ", " << _weapons.at(i).GetWeaponPowerConsumption() << endl;
		}
		cout << "Total firepower: " << GetFirePower() << endl;
	}
	cout << endl;
}

