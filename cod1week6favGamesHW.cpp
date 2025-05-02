#include <iostream>
#include <string>
using namespace std;

int main() {

	int gameCount = 0;										// Counter for the amount of games currently in the array
	const int MAX_SIZE = 20;								// Max size of the array, I could've just done 20, but good form or something, idk
	string favGames[MAX_SIZE];								// The string thats the favGames list, size of 20 (MAX_SIZE)
	string input;											// You wouldn't believe what this does
	cout << "Howdy, welcome to the program that will allow you make and manipulate a list of your favorite games!\n";		// Intro to explain purpose
	do {
		cout << " Please Input One of the Following\nAdd\tRemove\tEdit\tShow\tQuit\n";										// List Command Options
		cin >> input;																										// Take initial input
		if (input == "Add" || input == "add") {																								// Check if Add was prompted
			cout << "Please name the game you would like to add!\n";														// Get game from user
			cin >> favGames[gameCount];																						// Take user input, assign it to the most recent index
			gameCount++;																									// Update the counter of games, functions as a fix for the human vs computer number formatting, 
			cout << "The game in slot " << gameCount <<  " is now " << favGames[gameCount-1] << ".\n";						// Inform the user of the game added and where in the list
 		}
		if (input == "Edit" || input == "edit") {																			// Check for Edit command input
			cout << "What game would you like to edit?\n";																	// Prompt for game to edit
			cin >> input;																									
			for (int i = 0; i <= gameCount; i++) {																				
				if (input == favGames[i]) {																					// Loop as many times as the inputted games count is, checking if the promptet edit is in the list currently
					cout << "What would you like to edit " << favGames[i] << " to?\n";										// If match found, prompt for the replacement
					cin >> favGames[i];
					cout << "The game in slot " << i + 1 << " is now " << favGames[i] << "\n";
					break;																									// Inform user of edit success, break to prevent false negative cout
				}	
				if (i == gameCount) {																						// Might be a better way to do this, but this allows me to only do this at the end
					cout << "That game is not found in the list, would you like to view the current list?\n";				// If there isn't a match, prompts user to see if they would 
					cin >> input;																							// Asks for user if they want to see the list
					if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {									// Just different yes input formats
						for (int i = 0; i <= gameCount; i++) {
							cout << i + 1 << ". " << favGames[i] << "\n";													// Loop that listall entries
						}
					}
					break;
				}
			}
		}
		if (input == "Remove" || input == "remove") {																		// Check for if the input is remove
			cout << "What game would you like to remove?\n";																// Ask for input, assign it to the input holder
			cin >> input;
			for (int i = 0; i < gameCount; i++) {																			// Same loop and break as the Edit branch, just delete it instead
				if (input == favGames[i]) {																						
					favGames[i] = "";
					cout << input << " has been removed from slot" << i + 1 << "\n";
					break;
				}
				if (i == gameCount) {
					cout << "That game is not found in the list, would you like to view the current list?\n";
					cin >> input;
					if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {
						for (int i = 0; i < gameCount; i++) {
							cout << i + 1 << ". " << favGames[i] << "\n";
						}
					}
					break;
				}
			}
		}
		if (input == "Show" || input == "show") {																			// Check if input is show
			for (int i = 0; i < gameCount; i++) {																			// Loop to output list formatted numerically
				cout << i + 1 << ". " << favGames[i] << "\n";
			}
		}
		if (input == "Quit" || input == "quit") {																			// Check for input being "Quit"
			return 0;																										
		}
	} while (true);
}