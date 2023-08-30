#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Lego
{
	//Number	Theme	Name	Minifigs	Pieces	USPrice

	int _number;
	string _theme;
	string _name;	
	int _minifig;
	int _pieces_count;
	double _price;


public:
	/*============= Constructor ==================*/
	Lego(int number = -1, string theme = "Theme", string name = "Name", int minifig = -1, int pieces_count = -1, double price = 0.0f);
	/*================== Accessors ==================*/
	int GetNumber() const;
	string GetTheme() const;
	string GetName() const;
	int GetMinifigs() const;
	int GetPieces() const;
	double GetPrice() const;
	void PrintLego() const;
	void Deserialize(istringstream& inFile);
	void PrintLegoShort() const;

};


