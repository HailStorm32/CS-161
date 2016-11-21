/*
Program Name: Array Fun
Author: Demetri Van Sickle
Date: 11/20/16
IDE: Visual Studio 2015
Description: Gets 10 integers from the user, stores them in an array, and then prints out:
			 the entire array
			 the lowest value in the array
			 the highest value in the array
			 the number of odd numbers in the array
			 the sum of all the values in the array.
			 and all the values that appear in the array more than once
*/

#include <iostream>
using namespace std;

//Prototypes
void getData(int userArray[], int arraySize);
void printData(const int userArray[], int arraySize);
int lowestValue(const int userArray[], int arraySize);
int highestValue(const int userArray[], int arraySize);
int countOdds(const int userArray[], int arraySize);
int sum(const int userArray[], int arraySize);
bool arrayCheck(int numToCheck, int arrayToCheck[], int arraySize);
int getDuplicateValues(const int userArray[], int duplicateValues[], int userArraySize);

//Constants  
const int USER_ARRAY_SIZE = 10;

void main()
{
	int userArray[USER_ARRAY_SIZE] = {};
	int duplicateValues[(USER_ARRAY_SIZE / 2) + 1] = {}; //max amout of duplacates cant be more than half userArray (add 1 just in case the quotient is a fraction)

	cout << "Please enter " << USER_ARRAY_SIZE << " integers (separated by a space): ";
	getData(userArray, USER_ARRAY_SIZE);

	cout << "\nArray Value:";
	printData(userArray, USER_ARRAY_SIZE);

	cout << "\nLowest Value: " << lowestValue(userArray, USER_ARRAY_SIZE) << endl;
	cout << "Highest Value: " << highestValue(userArray, USER_ARRAY_SIZE) << endl;
	cout << "# of odd numbers: " << countOdds(userArray, USER_ARRAY_SIZE) << endl;
	cout << "The sum is: " << sum(userArray, USER_ARRAY_SIZE) << endl;

	getDuplicateValues(userArray, duplicateValues, USER_ARRAY_SIZE);

	cout << "Duplicate Value(s) are:";
	printData(duplicateValues, getDuplicateValues(userArray, duplicateValues, USER_ARRAY_SIZE));
	cout << "\n\n";
}


//=====================================================================================
// Function: getData
// Description: Fills in given array with data entered by the user
//
// Arguments:
//		userArray (O) -- Array that function will write values to
//		arraySize (I) -- Size of array
// Return Values:
//		VOID
//=====================================================================================
void getData(int userArray[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cin >> userArray[i];
	}
}


//=====================================================================================
// Function: printData
// Description: Prints given array values to the screen
//
// Arguments:
//		userArray (I) -- Array of values that function will print
//		arraySize (I) -- Size of array
// Return Values:
//		VOID
//=====================================================================================
void printData(const int userArray[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << " " << userArray[i];
	}
}


//=====================================================================================
// Function: lowestValue
// Description:  Returns the lowest value in the given array
//
// Arguments:
//		userArray (I) -- Array of values that function will find the lowest value
//		arraySize (I) -- Size of array
// Return Values:
//		lowestValue -- lowest value in the given array
//=====================================================================================
int lowestValue(const int userArray[], int arraySize)
{
	int currentLowest = userArray[0];

	for (int i = 1; i < arraySize; i++)
	{
		if (currentLowest > userArray[i])
		{
			currentLowest = userArray[i];
		}
	}

	return currentLowest;
}


//=====================================================================================
// Function: highestValue
// Description: Returns the highest value in the given array
//
// Arguments:
//		userArray (I) -- Array of values that function will find the highest value
//		arraySize (I) -- Size of array
// Return Values:
//		highestValue -- highest value in the given array
//=====================================================================================
int highestValue(const int userArray[], int arraySize)
{
	int currentHighest = userArray[0];

	for (int i = 1; i < arraySize; i++)
	{
		if (currentHighest < userArray[i])
		{
			currentHighest = userArray[i];
		}
	}

	return currentHighest;
}


//=====================================================================================
// Function: countOdds
// Description: Returns the number of odd numbers in the given array
//
// Arguments:
//		userArray (I) -- Array of values that function will count the # of odd #'s
//		arraySize (I) -- Size of array
// Return Values:
//		numOfOdds -- the number of odd numbers there was in the given array
//=====================================================================================
int countOdds(const int userArray[], int arraySize)
{
	int numOfOdds = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if ((userArray[i] % 2) != 0)
		{
			numOfOdds++;
		}
	}

	return numOfOdds;
}

//=====================================================================================
// Function: sum
// Description: Returns the sum of all the values in the given array
//
// Arguments:
//		userArray (I) -- Array of values that function will add
//		arraySize (I) -- Size of array
// Return Values:
//		sum -- the sum of all numbers in the given array
//=====================================================================================
int sum(const int userArray[], int arraySize)
{
	int sum = 0;
	
	for (int i = 0; i < arraySize; i++)
	{
		sum = sum + userArray[i];
	}

	return sum;
}

//=====================================================================================
// Function: arrayCheck
// Description: see if a certain value has already been entered into the given array
//
// Arguments:
//		numToCheck (I) -- the number that will be checked for
//		arrayToCheck (I) -- the array that will be checked
//		arraySize (I) -- size of the array we are checking
// Return Values:
//		True -- value is already in array
//		False -- value is NOT aready in array
//=====================================================================================
bool arrayCheck(int numToCheck, int arrayToCheck[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (numToCheck == arrayToCheck[i])
		{
			return true;
		}
	}

	return false;
}


//=====================================================================================
// Function: getDuplicateValues
// Description: return All the values that appear multiple times in the given array
//
// Arguments:
//		userArray (I) -- Array of values that function will find duplicates in
//		DuplicateValues (O) -- Array that will hold all the duplicate values
//		arraySize (I) -- Size of inital array
//=====================================================================================
int getDuplicateValues(const int userArray[], int duplicateValues[], int userArraySize)
{
	int currentcompareNum = 0;
	int ArrayIndex = 0;
	
	for (int pass = 0; pass < userArraySize; pass++)
	{
		currentcompareNum = userArray[pass];

		for (int i = (pass + 1); i < userArraySize; i++)
		{
			if (currentcompareNum == userArray[i])
			{
				if (!(arrayCheck(currentcompareNum, duplicateValues, ArrayIndex)))
				{
					duplicateValues[ArrayIndex] = currentcompareNum;
					ArrayIndex++;
					break;
				}
				else
				{
					break;
				}
			}
		}
	}

	return (ArrayIndex);
}