// HeaderDemonstration.cpp : Defines the entry point for the console application.
// This file holds main and will be used to run the core of our little dungeon crawler.

// header files
#include "stdafx.h"
#include <iostream>
#include "declarations.h" // this is my personal header file that holds 3 functions for this assignment
#include <cstdlib>
#include <ctime>
#include <string>

// uses the standard namespace
using namespace std;

// main
int main()
{
	srand(static_cast<unsigned int>(time(0))); // seeds random number generator
	string playerName; // variable to hold playerName
	int playerLevel; // variable to hold playerLevel
	int levelDifficulty = rand() % 151; // variable to hold level difficulty, initialize at a random number between 1 and 150
	bool victoryCheck; // variable to hold true or false
	int levelNum = 0; // variable to hold the current level of the dungeon you are on, starts at 0

	cout << "Please Choose a Name for your dungeon hero.\n";
	cin >> playerName; //let player pick a name
	cout << "Please Choose a number between 1 and 100. \n";
	cin >> playerLevel; // let player pick their starting player level
	if (playerLevel >= 101) // ensures that the number selected is valid
	{
		playerLevel = validNum(playerLevel); // goes to One.cpp file and runs the validNum function passing playerLevel as the variable and assigns the return value to playerLevel variable
	}
	cout << endl << endl << "Beginning your dungeon crawl!" << endl;

	do // do loop, so it always runs at least once
	{
		cout << "Player Level: " << playerLevel << endl; // show player level
		cout << "Current Floor: " << levelNum << endl; // show current floor
		cout << "Level Difficulty: " << levelDifficulty << endl; // show level difficulty
		victoryCheck = compare(playerLevel, levelDifficulty); // check to see if player beats this floor by going to One.cpp and using the compare function sending playerLevel and levelDifficulty for comparison
		cout << endl; // simple end line for formatting
		if (victoryCheck == true) // if player did win
		{
			cout << "You cleared Floor " << levelNum << endl; // display the level they cleared
			playerLevel = levelUp(playerLevel, 1); // level the player up by 1 by sending playerLevel and 1 into the levelUp function from one.cpp which adds the values together
			levelNum++; // add 1 to level Num
			levelDifficulty = rand() % 151; // get a new random levelDifficulty for the new floor
		}
		else
		{
			cout << "You have died\n\n"; // if victorycheck was not true kill the player
		}
		if (playerLevel == 151) // if playerLevel is equal to 151 force them to leave the dungeon
		{
			cout << "You are more powerful than the dungeon, try farming somewhere harder!\n\n";
			victoryCheck = false; // make victoryCheck false, so we can drop out of the loop
		}
	} while (victoryCheck == true); // while victoryCheck is true keep running the loop

	// print out final stastics
	cout << "Final Statistics:\n";
	cout << "Player Level: " << playerLevel << endl;
	cout << "Cleared Floors: " << levelNum << endl;
	cout << "Thanks for Playing!\n";
	system("pause");
	return 0;
}
