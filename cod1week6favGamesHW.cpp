#include <iostream>
#include <string>
using namespace std;

int main() {

	int gameCount = 0;										// Counter for the amount of games currently in the array
	const int MAX_SIZE = 20;								// Max size of the array, I could've just done 20, but good form or something, idk
	string favGames[MAX_SIZE];								// The string thats the favGames list, size of 20 (MAX_SIZE)
	string input;											// You wouldn't believe what this does
	cout << "Howdy, welcome to the program that will allow you make and manipulate a list of your favorite games!\n";
	do {
		cout << " Please Input One of the Following\nAdd\tRemove\tEdit\tShow\tQuit\n";
		cin >> input;
			break;
	} while (true);
}


/*
	Be Pseudo Code Fr, for FavGames Assignment

	Setup Stuff
		int gameCount = 0;
	start loop
	0. Greeting
		some text
		explain input options
		prompt for input
	1. Add
		ask the player "what game they want to add"
		get input from player
		add input(game) to array and increment
			gameCount
		(optional) tell player what name they've added
	2. Edit
		ask player "what game do you want to edit"
		get input from player
		loop through array to index [gameCount]						//honestly should just make a "search" function (upon further thought, idk if i can do that with my current knowledge set)
			check each element for if it matches the edit query
				loop, if input == array[index]
			if match found
				ask player "what would you like to edit it to"
				get input
				replace element at index gameCount with input
			if none found
				tell player that no match is found
				(optional) prompt player for if they would like to see the list
					get input
					show list (see 4)
	3. Remove
		ask player "what game would you like to remove"
		get input from player
		loop through array to index [gameCount]						//again, make a search function for this reason, it repeats twice
		if match found
			(optional) ask player if they are sure they want to delete
				if yes, do it, if no, reset to input promot
			delete it
		if match not found
			tell player that no match is found
				optionally, again as in 2, ask player if they would like to see a list to check for what they want
	4. Show
		loop through array using for loop, just output the list
	5. Quit
		yeah, quit, break, whatever
	*/