#include "Shapes.h"

Shape::~Shape()
{

}
/*====== Shape 2D =======*/

void Shape2D::ShowArea() const
{
	// Each of these function is invoked by a Shape2D pointer (this)
	// Polymorphic behavior determines which specific version is called
	// If "this" is a Circle, call Circle::GetName2D() and Circle::Area()
	// If "this" is a Rectangle, call Rectangle:GetName2D(), etc…
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}
bool Shape2D::operator>(const Shape2D& rhs) const
{
	return this->Area() > rhs.Area();
}
bool Shape2D::operator<(const Shape2D& rhs) const
{
	return this->Area() < rhs.Area();
}
bool Shape2D::operator==(const Shape2D& rhs) const
{
	return this->Area() == rhs.Area();
}


/*====== End of Shape 2D =======*/

/*====== Square =======*/

Square::Square(float length_of_side)
{
	_length_of_side = length_of_side;
}
float Square::Area() const
{
	return pow(_length_of_side, 2);
}
string Square::GetName2D() const
{
	return "Square";
}

void Square::Scale(float scaleFactor)
{
	_length_of_side *= scaleFactor;
}

void Square::Display() const
{
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Length of a side: " << _length_of_side << endl;
}

/*====== End of Square =======*/

/*====== Triangle =======*/

Triangle::Triangle(float base, float height)
{
	_base = base;
	_height = height;
}
float Triangle::Area() const
{
	return (_base * _height)/2;
}
string Triangle::GetName2D() const
{
	return "Triangle";
}

void Triangle::Scale(float scaleFactor)
{
	_base *= scaleFactor;
	_height *= scaleFactor;
}

void Triangle::Display() const
{
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Base: " << _base << endl;
	cout << "Height: " << _height << endl;
}

/*====== End of Triangle =======*/

/*====== Circle =======*/

Circle::Circle(float radius)
{
	_radius = radius; 
}
float Circle::Area() const
{
	return PI*pow(_radius, 2);
}
string Circle::GetName2D() const
{
	return "Circle";
}

void Circle::Scale(float scaleFactor)
{
	_radius *= scaleFactor;	
}

void Circle::Display() const
{
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Radius: " << _radius << endl;
}
float Circle::GetRadius() const
{
	return _radius;
}


/*====== End of Circle =======*/


/*====== Shape 3D =======*/

void Shape3D::ShowVolume() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}
bool Shape3D::operator>(const Shape3D& rhs) const
{
	return this->Volume() > rhs.Volume();
}
bool Shape3D::operator<(const Shape3D& rhs) const
{
	return this->Volume() < rhs.Volume();
}
bool Shape3D::operator==(const Shape3D& rhs) const
{
	return this->Volume() == rhs.Volume();
}

/*====== End of Shape 3D =======*/


/*====== TriangularPyramid =======*/

TriangularPyramid::TriangularPyramid(float height, float base_length , float base_height) : Triangle(base_length, base_height)
{
	_height = height;
}
float TriangularPyramid::Volume() const
{
	return (Triangle::Area() * _height)/3;
}
string TriangularPyramid::GetName3D() const
{
	return "TriangularPyramid";
}

void TriangularPyramid::Scale(float scaleFactor)
{
	_height *= scaleFactor;
	Triangle::Scale(scaleFactor);
}

void TriangularPyramid::Display() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	Triangle::Display();
}

/*====== End of TriangularPyramid =======*/

/*====== Cylinder =======*/

Cylinder::Cylinder(float height, float radius) : Circle(radius)
{
	_height = height;
}
float Cylinder::Volume() const
{
	return (Circle::Area() * _height);
}
string Cylinder::GetName3D() const
{
	return "Cylinder";
}

void Cylinder::Scale(float scaleFactor)
{
	_height *= scaleFactor;
	Circle::Scale(scaleFactor);
}

void Cylinder::Display() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	Circle::Display();
}

/*====== End of Cylinder =======*/

/*====== Sphere =======*/

Sphere::Sphere(float radius) : Circle(radius)
{
}
float Sphere::Volume() const
{
	return (Circle::Area() * Circle::GetRadius() * 4)/3;
}
string Sphere::GetName3D() const
{
	return "Sphere";
}

void Sphere::Scale(float scaleFactor)
{	
	Circle::Scale(scaleFactor);
}

void Sphere::Display() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	Circle::Display();
}

/*====== End of Sphere =======*/