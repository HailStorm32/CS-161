/*
Program Name: String Demo
Author: Demetri Van Sickle
Date: 11/29/16
IDE: Visual Studio 2015
Description: Have the user guess your name, and then take the name they enterd and remove the vowels
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//CString prototypes
void getNameAndComp(char userName[], int size);
void removeVowels(const char nameWithV[], char nameWithOutV[]);
void printCString(const char cString[], int size);

//String prototypes
string getNameAndComp();
string removeVowels(string nameWithV);
void printString(string string);

//Main Prototypes
void cStringDemo();
void stringTypeDemo();

//CString Constants
const int MY_NAME_SIZE = 19;
const int MAX_GUSESS_SIZE = 30;
const int TITLE_SIZE = 18;
const char MY_NAME_CSTR[MY_NAME_SIZE] = "Demetri Van Sickle";
const char VOWELS_C[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };
const char TITLE_C[TITLE_SIZE] = " the Barbarian";

//String Constants
const string MY_NAME_STR = "Demetri Van Sickle";
const string VOWELS_S = "aeiouy";
const string TITLE_S = " the Barbarian";

void main()
{
	cout << "****************** CString Demo **************************\n\n" << endl;
	cStringDemo();

	cout << "****************** String Demo **************************\n\n" << endl;
	stringTypeDemo();
}

//\\\\\\\\\\\\\\\\\\\\\\\\\CSTRING FUNCTIONS///////////////////////////

//====================================================================
// Function: getName
// Description: Get a name from the user and put it in given variable
//				Then compare to see if it equals my name
//
// Arguments: 
//		userName (O) -- cString that will hold the name that the user enterd
//		size (I) -- size of the CString array
// Return Values:
//		VOID
//=====================================================================
void getNameAndComp(char userName[], int size)
{
	cout << "Please guess my name (First & Last):";

	cin.get(userName, MY_NAME_SIZE);

	if (!(strcmp(userName, MY_NAME_CSTR)))
	{
		cout << "\nYou guessed it!" << endl;
	}
	else
	{
		cout << "\nNice try, but incorrect" << endl;
	}
}

//=====================================================================
// Function: removeVowels
// Description: Remove vowels from given CString
// 
// Arguments:
//		nameWithV (I) -- name with the vowels (original name)
//		nameWithOutV (O) -- name with out the vowels
// Return Arguments:
//		VOID
//=====================================================================
void removeVowels(const char nameWithV[], char nameWithOutV[])
{
	char currentCompareChar;
	int index = 0;

	for (int pass = 0; pass < MAX_GUSESS_SIZE; pass++)
	{
		currentCompareChar = nameWithV[pass];
		
		for (int i = 0; i < 6; i++)
		{
			if (tolower(currentCompareChar) == VOWELS_C[i])
			{
				break;
			}
			else if (i == 5)
			{
				nameWithOutV[index] = currentCompareChar;
				index++;
			}
		}
	}
}

//=====================================================================
// Function: printCString
// Description: Function that will print the a given cString
// 
// Arguments:
//		userName (I) -- cString to be printed
//		size (I) -- size of given cString
// Return Arguments:
//		VOID
//=====================================================================
void printCString(const char cString[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << cString[i];
	}
	cout << "\n";
}


//\\\\\\\\\\\\\\\\\\\\\\\STRING FUNCTIONS///////////////////////////////

//======================================================================
// Function: getNameAndComp
// Description: Get a name from the user and put it in given variable
//				Then compare to see if it equals my name
// Arguments:
//		VOID
// Return Values:
//		userName -- name the that user entered
//=======================================================================
string getNameAndComp()
{
	string userName;
	
	cout << "Please guess my name (First & Last):";

	getline(cin, userName);

	if (userName == MY_NAME_STR)
	{
		cout << "\nYou guessed it!" << endl;
	}
	else
	{
		cout << "\nNice try, but incorrect" << endl;
	}

	return userName;
}

//=======================================================================
// Function: removeVowels
// Description: Remove vowels from given String
// 
// Arguments:
//		nameWithV (I) -- name with the vowels (original name)
// Return Values:
//		nameWithOutV -- name with out the vowels
//=======================================================================
string removeVowels(string nameWithV)
{
	char currentCompareChar;
	string nameWithOutV = "";
	int index = 0;

	for (int pass = 0; pass < nameWithV.length(); pass++) //
	{
		currentCompareChar = nameWithV[pass];

		for (int i = 0; i < 5; i++)
		{
			if (tolower(currentCompareChar) == VOWELS_S[i])
			{
				break;
			}
			else if (i == 5)
			{
				nameWithOutV[index] += currentCompareChar;
				index++;
			}
		}
	}

	return nameWithOutV;
}

//========================================================================
// Function: printString
// Description: Function that will print given String
//
// Arguments:
//		string -- string that will be printed
// Return Value:
//		VOID
//========================================================================
void printString(string string)  
{
	cout << string << endl;  //I know this function is pointless, but it makes both types of functions (cStringDemo & stringTypeDemo) more symmetric
}


//\\\\\\\\\\\\\\\\\\\\\\\\\MAIN FUNCTIONS///////////////////////////////////

//========================================================================
// Function: cStringDemo
// Description:  Function that will run all the code for the CString version
//
// Arguments:
//		VOID
// Return Values:
//		VOID
//=========================================================================
void cStringDemo()
{
	char userName[MAX_GUSESS_SIZE] = "";
	char noVowels[MAX_GUSESS_SIZE] = "";
	char nameAndTitle[MY_NAME_SIZE + TITLE_SIZE] = "";

	getNameAndComp(userName, MY_NAME_SIZE);

	cout << "\nYou Entered: ";
	printCString(userName, MAX_GUSESS_SIZE);

	removeVowels(userName, noVowels);
	
	cout << "\nWith no vowels thats: ";
	printCString(noVowels, MY_NAME_SIZE);

	cout << "\nBack in the day that name would have been: ";

	strcpy(nameAndTitle, userName);
	strcat(nameAndTitle, TITLE_C);

	printCString(nameAndTitle, TITLE_SIZE + MY_NAME_SIZE);
}

//========================================================================
// Function: stringTypeDemo
// Description:  Function that will run all the code for the String version
//
// Arguments:
//		VOID
// Return Values:
//		VOID
//=========================================================================
void stringTypeDemo()
{
	string userName = "";
	string noVowels = "";
	string nameAndTitle = "";

	userName = getNameAndComp();

	cout << "\nYou Entered: ";
	printString(userName);

	noVowels = removeVowels(userName);

	cout << "\nWith no vowels thats: " << noVowels << endl;

	cout << "\nBack in the day that name would have been: ";

	nameAndTitle = userName + TITLE_S;

	printString(userName);
}