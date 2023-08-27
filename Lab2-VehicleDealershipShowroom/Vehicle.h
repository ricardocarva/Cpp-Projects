#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
    string _make;
    string _model;
    unsigned int _year;
    float _price;
    unsigned int _mileage;

public:
    // Default constructor, initializes variables to default values    
    Vehicle(string make = "COP3503", string model = "Rust Bucket", unsigned int year = 1900, float price = 0, unsigned int mileage = 0);

    // Print out the vehicle's details in a single line:
    // 1973 Ford Mustang $9500 113000
    void Display();

    // Create and return a string in the form of "YEAR MAKE MODEL"
    // Example: "1970 Ford Mustang"      
    string GetYearMakeModel();

    // Return the price
    float GetPrice();
};