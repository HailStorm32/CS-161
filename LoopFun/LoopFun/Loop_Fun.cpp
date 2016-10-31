/*
Program Name:  Loop_Fun
Author:  Demetri Van Sickle
Date:  10/27/16
IDE:  Visual Studio 2015
Description:  Take a height (with a value between 3-10) and a width (with a value greater than the height but < 20) and display on the terminal a box and a triangle using the values given.
*/
/*
				////////////////---pseudocode---///////////////////////

/////////--PART_1--/////////

Get a height (with a value between 3-10) and a width (with a value greater than the height but < 20) and put them in two variables Height  &  Width
While ((Height < 3 || Height > 10) || Height >= Width || (Width <= Height || Width > 20) )
	If(Height < 3 || Height > 10)
		Tell user why value is wrong, and get Height value again
		Check loop condition
	If(Height >= Width)
		Tell user why value is wrong, and get Height value again
		Check loop condition
	If(Width <= Height || Width > 20)
		Tell user why value is wrong, and get Width value again
		Check loop condition
End while
*/

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;


void main()
{
	int Height = 0;
	int Width = 0;
	int NumSum = 0;
	int NumOfDots = 1;

	float Average = 0;

	cout << "Please enter a Height that is between 3-10: ";
	cin >> Height;
	cout << "\n";
	cout << "Please enter a Width that is greater than the Height, but less than 20: ";
	cin >> Width;
	cout << "\n";

	//Make sure the user has entered correct values and prompt for another value if needed
	while ((Height < 3 || Height > 10) || Height >= Width || (Width <= Height || Width > 20))
	{
		if (Height < 3 || Height > 10)
		{
			cout << "Given Height is out of range!" << endl;
			cout << "Please enter a Height that is between 3-10: ";
			cin >> Height;
			cout << "\n";
			continue;
		}

		if (Height >= Width)
		{
			cout << "Height can't be greater than OR equal to the width!" << endl;
			cout << "Please enter a Width that is greater than the Height(" << Height << "), but less than 20: ";
			cin >> Width;
			cout << "\n";
			continue;
		}

		if (Width <= Height || Width > 20)
		{
			cout << "Given Width is out of range!" << endl;
			cout << "Please enter a Width that is greater than the Height(" << Height << "), but less than 20: ";
			cin >> Width;
			cout << "\n";
			continue;
		}
	}

	cout << "Thank You" << endl;

	//Find the numbers between the two user given values and display them
	cout << "\nThe integers from " << Height << " to " << Width << " is:" << endl;
	cout << "\t";

	for (int i = Height; i <= Width; i++)
	{
		cout << " " << i;

		NumSum = NumSum + i;
	}

	//Display the average of those numbers
	Average = static_cast<float>(NumSum) / (1 + (Width - Height));
	cout << "\nand the average of those numbers is: " << Average << "\n\n";

	//Draw Square
	for (int i = 0; i <= (Width - 1); i++)
	{
		Sleep(100);
		cout << "*";
	}
	
	cout << "\n";

	for (int i = 0; i <= (Height - 3); i++)
	{
		Sleep(100);
		cout << "*" <<  setw((Width - 1)) << right << "*" << endl;
	}

	for (int i = 0; i <= (Width - 1); i++)
	{
		Sleep(100);
		cout << "*";
	}

	cout << "\n\n";

	//Draw triangle
	cout << "*" << endl;
	for (int i = 0; i <= (Height - 1); i++)
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