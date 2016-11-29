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
void printCString(const char cString, int size);

//String prototypes
string getNameAndComp();
string removeVowels(string nameWithV);
void printString(string string);

//Main Prototypes
void cStringDemo();
void stringTypeDemo();

const int ARRAY_SIZE = 18;
const char MY_NAME[ARRAY_SIZE] = "Demetri VanSickle";
const string MY_NAME = "Demetri VanSickle";

void main()
{
	//char noVowels[ARRAY_SIZE] = "";
	string noVowels = "";



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

	cin.get(userName, ARRAY_SIZE);

	if (strcmp(userName, MY_NAME))
	{
		cout << "\nYou guessed it!" << endl;
	}
	else
	{
		cout << "Nice try, but incorrect" << endl;
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
void printCString(const char cString, int size)
{

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
	char userName[ARRAY_SIZE] = "";
	char noVowels[ARRAY_SIZE] = "";

	getNameAndComp()
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

}