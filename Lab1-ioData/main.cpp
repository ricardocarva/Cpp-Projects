#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{

	/* Type code here. */
	string title_data = "";

	cout << "Enter a title for the data:" << endl;
	/*
	*	getline(istream&, string&)
	*		This function allows you to get input for strings, including spaces. It reads characters up to a newline character (for user input, this would be when the "enter" key is pressed).
	*		The first parameter is typically cin, with the second parameter a string you want to read, like this:
	*			string input;
	*			getline(cin, input);
	*/
	getline(cin, title_data);
	cout << "You entered: " << title_data << endl;

	string header_one = "";
	string header_two = "";

	cout << "Enter the column 1 header:" << endl;
	getline(cin, header_one);
	cout << "You entered: " << header_one << endl;

	cout << "Enter the column 2 header:" << endl;
	getline(cin, header_two);
	cout << "You entered: " << header_two << endl;

	vector <string> data_point_string;
	vector <int> data_point_int;

	string temp_string = "";

	while (true) {

		cout << "Enter a data point (-1 to stop input):" << endl;
		getline(cin, temp_string);

		unsigned int found_stopper_flag == temp_string.find("-1");
		//find(item) returns index of first item occurrence, else returns string::npos (a constant defined in the string library). 

		if (found_stopper_flag != std::string::npos) {
			break;
		}

		int countCommas = 0;
		//Count number of commas
		for (long unsigned int i = 0; i < temp_string.length(); i++)
		{
			if (temp_string[i] == ',')
			{
				countCommas++;
			}
		}

		if (countCommas == 0)
		{
			cout << "Error: No comma in string." << endl;
		}

		else if (countCommas > 1)
		{
			cout << "Error: Too many commas in input." << endl;

		}
		//Only 1 comma
		else
		{
			unsigned int commaLocation = temp_string.find_first_of(',');
			/*
			*	try/catch
			*		Not functions, but keywords, these are used to handle exceptions. 
			*		Sometimes operations can fail to generate the correct results, while other times they may fail to generate ANY result. 
			*		This could be due to incorrect input, going out of bounds of an array, and a variety of other cases. For more information, look at section 15.1 Exception basics.
			*/
			try {
				/* 
				*	int stoi(string&)
				*		This function takes a string, converts it to an integer and returns that integer. 
				*		For example, the string "-24" returns an integer with the value of -24. 
				*		If it is unable to convert (i.e. the string contains "Batman"), an exception of type invalid_argument is thrown, which you will need to catch if you want your program to continue.
				*/
				int temp_integer = stoi(temp_string.substr(commaLocation + 1));

				data_point_string.push_back(temp_string.substr(0, commaLocation));
				data_point_int.push_back(temp_integer);

				cout << "Data string: " << temp_string.substr(0, commaLocation) << endl;
				cout << "Data integer: " << temp_integer << endl;
			}
			catch (invalid_argument& excpt) {
				cout << "Error: Comma not followed by an integer." << endl;
			}

		}
	};

	cout << endl;

	/*
	*	setw(int)
	*		This looks like a function, but is really a stream manipulator. It allows you to specify how many characters the next output should be. 
	*		This is useful when trying to line things up different outputs. (For more information look at section 12.1 Output formatting)
	*/
	cout << setw(33) << right << title_data << endl;
	cout << setw(20) << left << header_one << "|" << setw(23) << right << header_two << endl;
	cout << "--------------------------------------------" << endl;

	for (unsigned int i = 0; i < data_point_string.size(); i++) {
		cout << setw(20) << left << data_point_string[i] << "|";
		cout << setw(23) << right << data_point_int[i] << endl;
	}

	cout << endl;
	for (unsigned int i = 0; i < data_point_string.size(); i++) {

		cout << setw(20) << right << data_point_string[i] << " ";

		for (unsigned int j = 0; j < data_point_int[i]; j++) {

			cout << "*";

		}
		cout << endl;
	}
	return 0;
}