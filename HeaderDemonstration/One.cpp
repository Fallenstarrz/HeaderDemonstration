// This is a new .cpp file that will hold all of our functions, so we can reuse them as needed without making the main function crazy long, which expodites the speed of the function, and keeps it organized.

// header files
#include <stdafx.h>
#include "iostream"
#include <string>

// use standard namespace
using namespace std;

// LevelUp function, this will be used in main inside the HeaderDemonstration.cpp file
int levelUp(int x, int y) // take 2 numbers as parameters
{
	return x + y; // add the parameters together
}
// compare function, this will be used in main inside the HeaderDemonstration.cpp file
bool compare(int x, int y) // take 2 numbers as parameters
{ 
	if (x > y) // compare the 2 parameters, if x is larger then return true
	{
		return true; // returns true
	}
	else // compare the 2 parameters, if x is not larger return false
	{
		return false; // return false
	}
}
// validNum function, this will be used in main inside the HeaderDemonstration.cpp file
int validNum(int num) // take 1 number as parameter
{
	while (num >= 101) // check if num is greater than 101, if it is then go into the loop
	{
		cout << "Invalid Number.\nPlease select a number between 1 and 100."; // let user know they need to choose between 1 and 100
		cin >> num; // let user pick a new number, so we have a way to leave the loop
	}
	return num; // return the newly selected number by the user.
}