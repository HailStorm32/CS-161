/*
Program Name: Coordinates
Author: Demetri Van Sickle
Date: 11/15/16
IDE: Visual Studio 2015
Description: Get two coordinates from user and give the quadrant that each set of coordinates is in, compute and print the distance between the points,
			 and compute and print the slope of the line that passes through the points.
*/
/*
/\/\/\/\/\/\/\/\/\/\__pseudocode__/\/\/\/\/\/\/\/\/\/\

 Get two (x & y) points from user and store them in variables
	Store 'x' values in x[1] and x[2]
	Store 'y' values in y[1] and y[2]

for each point
	if(x[i] == 0 && y[i] == 0)
		point is at the origin
	else if(x[i] > 0 && y[i] > 0)
		point is in quad #1
	else if(x[i] < 0 && y[i] > 0)
		point is in quad #2
	else if(x[i] < 0 && y[i] < 0)
		point is in quad #3
	else if(x[i] > 0 && y[i] < 0)
		point is in quad #4

lineDist = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )

slopeRise = y2 - y2
slopeRun = x2 - x1

if(slopeRun = 0)
	return FLT_MAX

*/

#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

//Prototypes
void getCoord(int& x, int& y);
int getQuad(int x, int y);
float getDist(int x1, int x2, int y1, int y2);
float getSlope(int x1, int x2, int y1, int y2);
bool userWantsToContinue();


void main()
{
	int x[3];
	int y[3];

	while (userWantsToContinue())
	{
		getCoord(x[1], y[1]);
		getCoord(x[2], y[2]);

		cout << "\nYour two points are: (" << x[1] << ", " << y[1] << ") ";
		cout << "& (" << x[2] << ", " << y[2] << ")." << endl;

		for (int i = 1; i <=2; i++)
		{
			if (getQuad(x[i], y[i]) == 0)
			{
				cout << "Point: (" << x[i] << ", " << y[i] << ") is at the origin." << endl;
			}
			else
			{
				cout << "Point: (" << x[i] << ", " << y[i] << ") is in quadrant #" << getQuad(x[i], y[i]) << ".\n";
			}
		}

		cout << "The distance between your two points is: " << getDist(x[1], x[2], y[1], y[2]) << endl;

		cout << "The slope of the line that passes through your points is: " << getSlope(x[1], x[2], y[1], y[2]) << endl;
	}

}

//================================================================
// Function: getCoords
// Description: Get two (x, y) coordinates from user
//
// Arguments:
//		x (O) -- x coordinate
//		y (O) -- y coordinate
// Return Values:
//		VOID
//================================================================
void getCoord(int& x, int& y)
{
	static bool firstRun = true;

	if (firstRun == true)
	{
		cout << "\nPlease enter an (x,y) point with a space between 'x' and 'y': ";
		firstRun = false;
	}
	else
	{
		cout << "\nPlease enter another (x,y) point with a space between 'x' and 'y': ";
	}
	cin >> x;
	cin >> y;
}


//================================================================
// Function: getQuad
// Description: Give the quadrant a set of coordinates is in
//
// Arguments:
//		x (I) -- x coordinate
//		y (I) -- y coordinate
// Return Value:
//		0 -- point at the origin (0,0)
//		1 -- point in quadrant #1
//		2 -- point in quadrant #2
//		3 -- point in quadrant #3
//		4 -- point in quadrant #4
//=================================================================
int getQuad(int x, int y)
{
	if (x == 0 && y == 0)
	{
		return 0;
	}
	else if (x > 0 && y > 0)
	{
		return 1;
	}
	else if (x < 0 && y > 0)
	{
		return 2;
	}
	else if (x < 0 && y < 0)
	{
		return 3;
	}
	else if (x > 0 && y < 0)
	{
		return 4;
	}
}


//===========================================================================
// Function: getDist
// Description: Compute the distance between two points
//
// Arguments:
//		x1 (I) -- first x coordinate
//		x2 (I) -- second x coordinate
//		y1 (I) -- first y coordinate
//		y2 (I) -- second y coordinate
// Return Values:
//		pointDist -- distance between the two points
//===========================================================================
float getDist(int x1, int x2, int y1, int y2)
{
	return (sqrt((pow((x2 - static_cast<float>(x1)), 2)) + (pow((y2 - y1), 2))));
}


//===========================================================================
// Function: getSlope
// Description: compute the slope of the line that passes through two points
//
// Arguments:
//		x1 (I) -- first x coordinate
//		x2 (I) -- second x coordinate
//		y1 (I) -- first y coordinate
//		y2 (I) -- second y coordinate
// Return Values:
//		slope -- slope of the line
//===========================================================================
float getSlope(int x1, int x2, int y1, int y2)
{
	if ((x2 - x1) == 0)
	{
		return FLT_MAX;
	}
	else
	{
		return ((y2 - static_cast<float>(y1)) / (x2 - x1));
	}
}


//==========================================================================
// Function: userWantsToContinue
// Description: Ask user if they want to continue and returns the respective bool value
//
// Arguments:
//		VOID
// Return Values:
//		True -- user wants to continue
//		False -- user doesn't want to continue
//==========================================================================
bool userWantsToContinue()
{
	char yesOrNo = 'z';
	static bool firstRun = true;

	if (firstRun == false)
	{
		cout << "\nDo you want to try again? ";
		//cin >> yesOrNo;

		while (!(tolower(yesOrNo) == 'y' || tolower(yesOrNo) == 'n'))
		{
			cout << "\n\tPlease enter 'y' or 'n': ";
			cin >> yesOrNo;
		}

		if (tolower(yesOrNo) == 'y')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		firstRun = false;
		return true;
	}
}