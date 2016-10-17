/*
Program Name: Geometry_Fun part2
Author:	Demetri Van Sickle
Date: 10/17/16
IDE: Visual Studio 2015 Enterprise 
Description: Using a positive value it was given, the code will use that value to spit out the area and perimeter of a square and equilateral triangle, and radius, perimeter, and area of a circle. 
*/

#include <iostream>
using namespace std;

const float PI = 3.14159;

void main()
{
	bool flag = true;
	
	int UserInput = 0;

	int SquareLength = 0;
	int SquareArea = 0;
	int SquarePrim = 0;
	
	int TriSide = 0;
	float TriArea = 0;
	int TriPrim = 0;

	float CircleRadius = 0;
	float CirclePrim = 0;
	float CircleArea = 0;

	int NumOfPolySides = 0;
	float PolyArea = 0;
	int PolySide = 0;
	float PolyPrim = 0;

	
	//Get values and check to make sure user entered correct value
	while (flag == true)
	{

		cout << "Please enter a positive whole number: ";

		cin >> UserInput;

		cout << "Please enter a positive whole number for the number of sides of a polygon: ";

		cin >> NumOfPolySides;

		if (UserInput <= 0 || NumOfPolySides <= 0)
		{
			cout << "\nValue entered is negitive or zero." << endl;
		}
		else if (UserInput > 0 && NumOfPolySides > 0)
		{
			flag = false;
		}

	}

	cout.precision(3);

	//Start calulations for the square
	SquareLength = UserInput;
	SquareArea = SquareLength * SquareLength;
	SquarePrim = SquareLength * 4;

	
	//Start calculations for the circle
	CircleRadius = static_cast<float>(UserInput) / 2;
	CircleArea = PI * (CircleRadius * CircleRadius);
	CirclePrim = (2 * PI) * CircleRadius;


	//Start calculations for the triangle
	TriSide = UserInput;
	TriArea = pow(TriSide, 2) * (sqrt(3.0) / 4);
	TriPrim = TriSide * 3;

	//Start calculations for polygon
	PolySide = UserInput;


	//Show calculation values 
	cout << "\nA square with a side length of " << SquareLength << endl;
	cout << "\tHas a perimeter of " << SquarePrim << endl;
	cout << "\tAnd a area of " << SquareArea << endl;

	cout << fixed;
	cout << "\nA circle with a diameter of " << CircleRadius * 2 << endl;
	cout << "\tHas a radius of " << CircleRadius << endl;
	cout << "\tHas a perimeter of " << CirclePrim << endl;
	cout << "\tAnd a area of " << CircleArea << endl;

	cout << "\nA equilateral triangle with a side length of " << TriSide << endl;
	cout << "\tHas a perimeter of " << TriPrim << endl;
	cout << "\tAnd a area of " << TriArea << endl;

	//Allow console to stay open
	cin.get();
	cin.ignore();

}