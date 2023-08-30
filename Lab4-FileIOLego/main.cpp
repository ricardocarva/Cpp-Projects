#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <float.h> 
#include <climits>
#include "extrafile.h"
using namespace std;

void load_data_placeholder(int option, vector<Lego>& output);

void load_data(string filePath, vector<Lego>& output);


int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	
	/*======= Load data from file(s) =======*/
	vector <Lego> lego_vector;
	load_data_placeholder(option, lego_vector);

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << lego_vector.size() << endl;
	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	if (choice == 1)
	{
		int index_most_expensive = 0;
		double most_expensive_set = 0.00;
		
		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			if (lego_vector.at(i).GetPrice() > most_expensive_set)
			{
				most_expensive_set = lego_vector.at(i).GetPrice();
				index_most_expensive = i;
			}
		}
		cout << "The most expensive set is: " << endl;
		lego_vector.at(index_most_expensive).PrintLego();
	}
	if (choice == 2)
	{
		int index_largest_piece_count = 0;
		int largest_piece_count = 0;

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			if (lego_vector.at(i).GetPieces() > largest_piece_count)
			{
				largest_piece_count = lego_vector.at(i).GetPieces();
				index_largest_piece_count = i;
			}
		}
		cout << "The set with the highest parts count: " << endl;
		lego_vector.at(index_largest_piece_count).PrintLego();
	}
	if (choice == 3)
	{
		vector<Lego> lego_matches;
		string search_match;
		getline(cin, search_match);

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			if (lego_vector.at(i).GetName().find(search_match) != string::npos)
			{
				lego_matches.push_back(lego_vector.at(i));
			}
		}
		if (lego_matches.size() == 0)
		{
			cout << "No sets found matching that search term" << endl;
		}
		else
		{
			cout << "Sets matching \"" << search_match << "\":" << endl;
			for (unsigned int i = 0; i < lego_matches.size(); i++)
			{
				lego_matches.at(i).PrintLegoShort();
			}
		} 
	}
	if (choice == 4)
	{
		vector<Lego> lego_matches;
		string search_match;
		getline(cin, search_match);

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			if (lego_vector.at(i).GetTheme().find(search_match) != string::npos)
			{
				lego_matches.push_back(lego_vector.at(i));
			}
		}
		if (lego_matches.size() == 0)
		{
			cout << "No sets found matching that search term" <<  endl;
		}
		else
		{
			cout << "Sets matching \"" << search_match << "\":" << endl;
			for (unsigned int i = 0; i < lego_matches.size(); i++)
			{
				lego_matches.at(i).PrintLegoShort();
			}
		}
	}
	if (choice == 5)
	{
		int total_pieces = 0;

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			total_pieces += lego_vector.at(i).GetPieces();
		
		}
		if (total_pieces == 0)
		{
			cout << "Average Pieces is " << total_pieces << endl;
		}
		else
		{
			cout << "Average part count for " << lego_vector.size() << " sets: " << total_pieces / lego_vector.size() << endl;
			
		}
	}

	if (choice == 6)
	{
		int index_maximum_price = 0;
		double maximum_price = DBL_MIN;

		int index_minimum_price = 0;
		double minimum_price = DBL_MAX;

		double total = 0;

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{

			if (lego_vector.at(i).GetPrice() > maximum_price)
			{
				maximum_price = lego_vector.at(i).GetPrice();
				index_maximum_price = i;
			}
			else if (lego_vector.at(i).GetPrice() < minimum_price)
			{
				minimum_price = lego_vector.at(i).GetPrice();
				index_minimum_price = i;
			}
			total += lego_vector.at(i).GetPrice();
		}
		if (lego_vector.size() > 0)
			cout << "Average price for " << lego_vector.size() << " sets: $" << total / lego_vector.size() << endl;
		else 
			cout << "Average price for " << lego_vector.size() << " sets: $" << total / 1 << endl;
		cout << endl;
		cout << "Least expensive set: " << endl;
		lego_vector.at(index_minimum_price).PrintLego();
		cout << endl;
		cout << "Most expensive set: " << endl;
		lego_vector.at(index_maximum_price).PrintLego();		
	}
	if (choice == 7)
	{
		int index_most_minifig = 0;
		int most_minifig_set = INT_MIN;
		int total_minifigs = 0;

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			if (lego_vector.at(i).GetMinifigs() > most_minifig_set)
			{
				most_minifig_set = lego_vector.at(i).GetMinifigs();
				index_most_minifig = i;
			}
			total_minifigs += lego_vector.at(i).GetMinifigs();
		}
		if (lego_vector.size() > 0)
			cout << "Average number of minifigures: " << total_minifigs / lego_vector.size() << endl;
		else
			cout << "Average number of minifigures: " << total_minifigs / 1 << endl;
		cout << "Set with the most minifigures: " << endl;
		lego_vector.at(index_most_minifig).PrintLego();
	}
	if (choice == 8)
	{
		double total_price = 0.00;
		int total_pieces = 0;
		int total_minifigs = 0;

		for (unsigned int i = 0; i < lego_vector.size(); i++)
		{
			total_price += lego_vector.at(i).GetPrice();
			total_pieces += lego_vector.at(i).GetPieces();
			total_minifigs += lego_vector.at(i).GetMinifigs();
		}
		cout << "If you bought one of everything..." << endl;
		cout << "It would cost: $" << total_price << endl;
		cout << "You would have " << total_pieces << " pieces in your collection" << endl;
		cout << "You would have an army of " << total_minifigs << " minifigures!" << endl;

	}

	return 0;
}

void load_data_placeholder(int option, vector<Lego>& output)
{
	if (option == 1)
	{
		load_data("lego1.csv", output);
	}
	else if (option == 2)
	{
		load_data("lego2.csv", output);
	}
	else if (option == 3)
	{
		load_data("lego3.csv", output);
	}
	else if (option == 4)
	{
		load_data("lego1.csv", output);
		load_data("lego2.csv", output);
		load_data("lego3.csv", output);

	}
	else {
		cout << "Invalid entry!" << endl;
	}
}

void load_data(string filePath, vector<Lego>& output)
{
	ifstream csv(filePath);
	if (csv.is_open())
	{
		string lineFromFile;
		getline(csv, lineFromFile);

		while (getline(csv, lineFromFile))
		{
			istringstream stream(lineFromFile);
			Lego newLego;
			newLego.Deserialize(stream);
			output.push_back(newLego);			
		}
	}
	else
	{
		cout << "Error! File " << filePath << " could not be opened!" << endl;
	}
}
