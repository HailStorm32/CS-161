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
void removeVowels(const char nameWithVowels[], char nameWithOutVowels[]);

//String prototypes
string getNameAndComp();
string removeVowels(string nameWithVowels);

//Main Prototypes
void cStringDemo();
void stringTypeDemo();

//CString Constants
const int MY_NAME_SIZE = 19;
const int MAX_GUESS_SIZE = 30;
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
//		nameWithVowels (I) -- name with the vowels (original name)
//		nameWithOutVowels (O) -- name with out the vowels
// Return Arguments:
//		VOID
//=====================================================================
void removeVowels(const char nameWithVowels[], char nameWithOutVowels[])
{
	char currentCompareChar;
	int index = 0;

	for (int pass = 0; pass < strlen(nameWithVowels); pass++)
	{
		currentCompareChar = nameWithVowels[pass];
		
		for (int i = 0; i < 6; i++)
		{
			if (tolower(currentCompareChar) == VOWELS_C[i])
			{
				break;
			}
			else if (i == 5)
			{
				nameWithOutVowels[index] = currentCompareChar;
				index++;
			}
		}
	}
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
//		nameWithVowels (I) -- name with the vowels (original name)
// Return Values:
//		nameWithOutVowels -- name with out the vowels
//=======================================================================
string removeVowels(string nameWithVowels)
{
	char currentCompareChar;
	string nameWithOutVowels = "";
	int index = 0;

	for (int pass = 0; pass < nameWithVowels.length(); pass++) 
	{
		currentCompareChar = nameWithVowels[pass];

		for (int i = 0; i < 6; i++)
		{
			if (tolower(currentCompareChar) == VOWELS_S[i])
			{
				break;
			}
			else if (i == 5)
			{
				nameWithOutVowels += currentCompareChar;
				index++;
			}
		}
	}
	return nameWithOutVowels;
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
	char userName[MAX_GUESS_SIZE] = "";
	char noVowels[MAX_GUESS_SIZE] = "";
	char nameAndTitle[MY_NAME_SIZE + TITLE_SIZE] = "";

	getNameAndComp(userName, MY_NAME_SIZE);

	cout << "\nYou Entered: " << userName << endl;

	removeVowels(userName, noVowels);
	
	cout << "\nWith no vowels thats: " << noVowels << endl;

	cout << "\nBack in the day that name would have been: ";

	strcpy(nameAndTitle, userName);
	strcat(nameAndTitle, TITLE_C);

	cout << nameAndTitle << endl;
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

	cin.ignore(1); //Clear the buffer

	userName = getNameAndComp();

	cout << "\nYou Entered: " << userName << endl;

	noVowels = removeVowels(userName);

	cout << "\nWith no vowels thats: " << noVowels << endl;

	cout << "\nBack in the day that name would have been: ";

	nameAndTitle = userName + TITLE_S;

	cout << nameAndTitle << endl;
}