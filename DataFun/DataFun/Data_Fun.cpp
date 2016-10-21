/*
Program Name:  Data Fun
Author:  Demetri Van Sickle
Date:  10/19/16
IDE:  Visual Studio 2015 Enterprise
Description:  Take a persons favorite number (integer, and floating point) and letter. It will then display fun facts regaring those inputs
*/
/*
				////////////////---pseudocode---///////////////////////


//////--Part_1--//////

Get integer from user and put it in variable called UserInt
If UserInt < 0 print out that its negative
	else, print that it is positive
If UserInt > 1000, print that its greater than 1000
	else if UserInt is > 100 print that its greater than 100
	else if UserInt is > 10 print that its greater than 10
If UserInt % 2 != a value >= 1, print that its even
	else, print that its odd
If UserInt == to 2, 10, 18, 36, 54 or 86,
	else if UserInt = 2, print ithe nobel gas it corresponds to
	else if UserInt = 10, print ithe nobel gas it corresponds to
	else if UserInt = 18, print ithe nobel gas it corresponds to
	else if UserInt = 36, print ithe nobel gas it corresponds to
	else if UserInt = 54, print ithe nobel gas it corresponds to
	else if UserInt = 86, print ithe nobel gas it corresponds to
	else if UserInt != 2, 10, 18, 36, 54 or 86, print that its not a nobel gas number


//////--Part_2--//////

Get favorite char from user and put it in variable called UserLetter
If UserLetter < 61, print that its a uppercase letter
	else, print that its lowercase
If UserLetter == A or a, print that its a vowel
	else if UserLetter == E or e, print that its a vowel
	else if UserLetter == I or i, print that its a vowel
	else if UserLetter == O or o, print that its a vowel
	else if UserLetter == U or u, print that its a vowel
	else if UserLetter == Y or y, print that its a vowel
	else, print that its not a vowel
Convert UserLetter to int and print it
If UserLetter % 10 == 0, print its ascii value with the 'th' prefix
	else if UserLetter % 10 == 1, print its ascii value with the 'st' prefix
	else if UserLetter % 10 == 2, print its ascii value with the 'nd' prefix
	else if UserLetter % 10 == 3, print its ascii value with the 'rd' prefix
	else if UserLetter % 10 == 4-9, print its ascii value with the 'th' prefix


//////--Part_3--//////

Get favorite floating point number from user and put in a variable called UserFloat
Break UserFloat into its decimal and int values and dislay them
If the decimal value of UserFloat != 0, print that it couldn't be an int
*/

#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <stdio.h>

using namespace std;

const char LettersUpper[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
const char LettersLower[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

void main()
{
	int UserInt = 0;
	int UserCharVal = 0;
	float DecimalNum = 0;
	float WholeNum = 0;
	float UserFloat = 0;
	char UserChar;
	bool IsLetter = false;
	string NumSuffix;

	while (true)
	{
		/////////////////////Begin Part 1////////////////////
		cout << "\n\n\nPlease enter your favorite integer number: ";
		cin >> UserInt;
		cout << "\n\t" << UserInt << " ";

		//Check if number is positive
		if (UserInt < 0)
		{
			cout << "is a negative number," << endl;
		}
		else
		{
			cout << "is a positive number," << endl;
		}

		//Check to see if the number greater than 1000, 100, or 10
		if (UserInt > 1000)
		{
			cout << "\tis GREATER than 1000," << endl;
		}
		else if (UserInt > 100)
		{
			cout << "\tis GREATER than 100," << endl;
		}
		else if (UserInt > 10)
		{
			cout << "\tis GREATER than 10," << endl;
		}


		//Check to see if the number is even
		if ((UserInt % 2) != 0)
		{
			cout << "\tis ODD," << endl;
		}
		else
		{
			cout << "\tis EVEN," << endl;
		}

		//See if the number is an atomic number
		switch (UserInt)
		{
		case 2:
			cout << "\tis the atomic number of helium," << endl;
			break;
		case 10:
			cout << "\tis the atomic number of neon," << endl;
			break;
		case 18:
			cout << "\tis the atomic number of argon," << endl;
			break;
		case 36:
			cout << "\tis the atomic number of krypton," << endl;
			break;
		case 54:
			cout << "\tis the atomic number of xenon," << endl;
			break;
		case 86:
			cout << "\tis the atomic number of radon," << endl;
			break;
		default:
			cout << "\tis not an atomic number," << endl;
			break;
		}


		/////////////////////Begin Part 2////////////////////
		cout << "\n\nPlease enter your favorite character: ";
		cin >> UserChar;

		///See if UserChar a letter or not
		if (UserChar >= 65 && UserChar <= 90)
		{
			cout << "\t" << UserChar << " is an uppercase letter," << endl;
			IsLetter = true;
		}
		else if (UserChar >= 97 && UserChar <= 122)
		{
			cout << "\t" << UserChar << " is a lowercase letter," << endl;
			IsLetter = true;
		}
		else;

		//Only run if we have a letter
		if (IsLetter)
		{
			//see if its a vowel
			switch (UserChar)
			{
			case 'A':
			case 'a':
				cout << "\tis a vowel,";
				break;
			case 'E':
			case 'e':
				cout << "\tis a vowel,";
				break;
			case 'I':
			case 'i':
				cout << "\tis a vowel,";
				break;
			case 'O':
			case 'o':
				cout << "\tis a vowel,";
				break;
			case 'U':
			case 'u':
				cout << "\tis a vowel,";
				break;
			case 'Y':
			case 'y':
				cout << "\tis (sometimes) a vowel,";
				break;
			default:
				cout << "\tis not a vowel,";
				break;
			}

			//Print the letter's posittion in the alphabet 
			for (int i = 0; i <= 30; i++)
			{
				if (LettersUpper[i] == UserChar || LettersLower[i] == UserChar)
				{
					//get number suffix
					if (((i + 1) % 10) == 1)
					{
						NumSuffix = "st";
					}
					else if (((i + 1) % 10) == 2)
					{
						NumSuffix = "nd";
					}
					else if (((i + 1) % 10) == 3)
					{
						NumSuffix = "rd";
					}
					else if (((i + 1) % 10) == 4 || ((i + 1) % 10) == 5 || ((i + 1) % 10) == 6 || ((i + 1) % 10) == 7 || ((i + 1) % 10) == 8 || ((i + 1) % 10) == 9)
					{
						NumSuffix = "th";
					}

					cout << "\n\tis the " << i + 1 << NumSuffix << " letter in the alphabet," << endl;
					break;
				}
				else;
			}

		}

		else
		{
			cout << "\tIs not a letter," << endl;
		}

		UserCharVal = UserChar;

		cout << "\tThe ASCII value for " << UserChar << " is " << UserCharVal << endl;


		/////////////////////Begin Part 3////////////////////
		cout << "\n\nPlease enter your favorite floating point number: ";
		cin >> UserFloat;

		//Split User float into two parts and display it
		DecimalNum = modf(UserFloat, &WholeNum);

		if (DecimalNum != 0)
		{
			cout << "\n\t" << UserFloat << " can't be stored as an int without losing data," << endl;
		}
		else
		{
			cout << "\n\t" << UserFloat << " can be stored as an int with no data loss," << endl;
		}

		cout << "\tThe portion to the left of the decimal point is: " << WholeNum << "\n\tand the portion to the right is: " << DecimalNum << endl;
	}


	//Allow console to stay open
	cin.get();
	cin.ignore();

}
