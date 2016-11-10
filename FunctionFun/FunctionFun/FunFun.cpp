/*
Program Name:  FunctionFun
Author:  Demetri Van Sickle
Date:  11/09/16
IDE:  Visual Studio 2015
Description:  Take a height (with a value between 3-10) and a width (with a value greater than the height but < 20) and display on the terminal a box and a triangle using the values given.
*/

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//Prototypes
int getInteger(int low, int high);
void printRangeAndAvg(int low, int high);
void printBox(int height, int width);
void printWedge(int height);


void main()
{
	int Height = 0;
	int Width = 0;

	cout << "Please enter a Height that is between 3-10: ";
	Height = getInteger(3, 10);
	cout << "\n";
	cout << "Please enter a Width that is greater than the Height, but less than 20: ";
	Width = getInteger(Height + 1, 20);
	cout << "\n";

	cout << "Thank You" << endl;

	//Find the numbers between the two user given values and display them
	printRangeAndAvg(Height, Width);

	//Draw Square
	printBox(Height, Width);

	//Draw triangle
	printWedge(Height);

}

//==========================================================================
// Function: getInteger
// Description: Get an integer from the user between a specified range
//
// Arguments:
//		low -- lowest allowed interger
//		high -- highest allowed integer
// Return Values:
//		int number -- number between specified range
//==========================================================================
int getInteger(int low, int high)
{
	int number = 0;
	cin >> number;
	cout << "\n";

	while (number < low || number > high)
	{
		if (number < low)
		{
			cout << "Number entered is below (" << low << "). Please try again:";
			cin >> number;
			continue;
		}
		else if (number > high)
		{
			cout << "Number entered is above (" << high << "). Please try again:";
			cin >> number;
			continue;
		}
	}

	return number;
}

//===========================================================================
// Function: printRangeAndAvg
// Description: Print the numbers between two specified values as well as the average
//
// Arguments:
//		low -- first number
//		high -- second number
// Return Value:
//		VOID
//===========================================================================
void printRangeAndAvg(int low, int high)
{
	int NumSum = 0;
	int Average = 0;

	cout << "\nThe integers from " << low << " to " << high << " is:" << endl;
	cout << "\t";

	for (int i = low; i <= high; i++)
	{
		cout << " " << i;

		NumSum = NumSum + i;
	}

	//Display the average of those numbers
	Average = static_cast<float>(NumSum) / (1 + (high - low));
	cout << "\nand the average of those numbers is: " << Average << "\n\n";
}

//=========================================================================
// Function: printBox
// Description: Prints a hollow box of * on the screen of the given height and width
//
// Arguments:
//		height -- height of the box
//		width -- width of the box
// Return Values:
//		VOID
//=========================================================================
void printBox(int height, int width)
{
	for (int i = 0; i <= (width - 1); i++)
	{
		Sleep(100);
		cout << "*";
	}

	cout << "\n";

	for (int i = 0; i <= (height - 3); i++)
	{
		Sleep(100);
		cout << "*" << setw((width - 1)) << right << "*" << endl;
	}

	for (int i = 0; i <= (width - 1); i++)
	{
		Sleep(100);
		cout << "*";
	}

	cout << "\n\n";
}

//==========================================================================
// Function: printWedge
// Description: Prints a wedge of * on the screen of the given height, with two * per row
//
// Arguments:
//		height -- height of the wedge
// Return Values:
//		VOID
//==========================================================================
void printWedge(int height)
{
	int NumOfDots = 1;

	for (int i = 0; i <= (height - 1); i++)
	{
		for (int i = 0; i <= NumOfDots; i++)
		{
			Sleep(50);
			cout << "*";
		}

		NumOfDots += 2;
		cout << "\n";
	}
}