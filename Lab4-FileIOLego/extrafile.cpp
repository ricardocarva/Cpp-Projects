#include "extrafile.h"
#include <string>
#include <vector>

/*============= Constructor ==================*/

Lego::Lego(int number, string theme, string name, int minifig, int pieces_count, double price)
{
	_number = number;
	_theme = theme;
	_name = name;
	_minifig = minifig;
	_pieces_count = pieces_count;
	_price = price;
}
/*================== Accessors ==================*/


int Lego::GetNumber() const { return _number; }
string Lego::GetTheme() const { return _theme; }
string Lego::GetName() const { return _name; }
int Lego::GetMinifigs() const { return _minifig; }
int Lego::GetPieces() const { return _pieces_count; }
double Lego::GetPrice() const { return _price; }
void Lego::PrintLego() const {

	cout << "Name: " << _name << endl;
	cout << "Number: " << _number << endl;
	cout << "Theme: " << _theme << endl;
	cout << "Price: $" << _price << endl;
	cout << "Minifigures: " << _minifig << endl;
	cout << "Piece count: " << _pieces_count << endl;
}

void Lego::PrintLegoShort() const {

	cout << _number << " " << _name << " $" << _price << endl; 
}
void Lego::Deserialize(istringstream& inFile)
{ 
	string token;
	getline(inFile, token, ',');
	int temp_number = stoi(token);
	_number = temp_number;

	getline(inFile, token, ',');
	_theme =  token;

	getline(inFile, token, ',');
	_name = token;

	getline(inFile, token, ',');
	int temp_minifig = stoi(token);
	_minifig = temp_minifig;

	getline(inFile, token, ',');
	int temp_pieces = stoi(token);

	_pieces_count = temp_pieces;

	getline(inFile, token);
	double temp_price = stod(token);
	_price = temp_price;

}
