#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#define PI 3.14159f

using namespace std;

class Shape
{

public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;

	// =0 Pure Virtual
	virtual ~Shape() = 0;

};

class Shape2D : virtual public Shape 
{ 
public: 
	virtual float Area() const = 0; 
	void ShowArea() const; 
	virtual string GetName2D() const = 0; 
	bool operator>(const Shape2D& rhs) const; 
	bool operator<(const Shape2D& rhs) const; 
	bool operator==(const Shape2D& rhs) const; 
};

class Square : virtual public Shape2D
{
	float _length_of_side;
public:
	Square(float length_of_side = 0);
	float Area() const;
	string GetName2D() const;
	void Scale(float scaleFactor);
	void Display() const;

};

class Triangle : virtual public Shape2D
{
	float _base;
	float _height;
public:
	Triangle(float base = 0, float height = 0);
	float Area() const;
	string GetName2D() const;
	void Scale(float scaleFactor);
	void Display() const;
};

class Circle : virtual public Shape2D
{
	float _radius;
public:
	Circle(float radius = 0);
	float Area() const;
	string GetName2D() const;
	void Scale(float scaleFactor);
	void Display() const;
	float GetRadius() const;
};


class Shape3D : virtual public Shape
{ 
public: 
	virtual float Volume() const = 0; 
	void ShowVolume() const; 
	virtual string GetName3D() const = 0; 
	bool operator>(const Shape3D & rhs) const; 
	bool operator<(const Shape3D & rhs) const;
	bool operator==(const Shape3D & rhs) const; 
};

class TriangularPyramid : virtual public Shape3D, virtual private Triangle
{
	float _height;
public:
	TriangularPyramid(float height = 0, float base_length = 0, float base_height = 0);
	string GetName3D() const;
	float Volume() const; 
	void Scale(float scaleFactor);
	void Display() const;
};

class Cylinder : virtual public Shape3D, virtual private Circle
{
	float _height;
public:
	Cylinder(float height = 0,  float radius = 0);
	float Volume() const;
	string GetName3D() const;
	void Scale(float scaleFactor);
	void Display() const;
};



class Sphere : virtual public Shape3D, virtual private Circle
{
public:
	Sphere(float radius = 0);
	float Volume() const;
	string GetName3D() const;
	void Scale(float scaleFactor);
	void Display() const;
};