// Nolyn Janssen, Coding 1, Week 6 of Spring 25, Feb 25th 2025
// Loops and Lists
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Making an array
	// Array is an ordered list of a single type of variable
		
	// Creat an Array of integers with a [size] of 10
	
	const int MAX_SIZE = 10;							// Constant variable for max size, cannot be changed, ALL_CAPS format for constants

	int element = 0;									// Tracks where array location is

	int scores[MAX_SIZE];								// This arrary has 10 slots for integer values to be held


	scores[0] = 9001;									// Add a value to the first element for the array

	// Display the value to confirm that it works
	cout << "The highest score in scores is " << scores[0] << ".\n";

	// Add 3 more scores (and seven years ago) using element++ to keep track of the spot in the array you are at

	element = 1;										// Points to second element in the array
	scores[element++] = 682;							// The element++ (postfix increment operator adds 1 after the line is ran
														// (so this is running as "scores[1] = 682;" and then it adds one to the index
	scores[element++] = 602;
	scores[element++] = 412;

	cout << "The second score is " << scores[1] << ".\n";

	// (Pseudocode/plain english)
	// Use a while loop to output all the scores
	// End loop when loop counter is equal to element

	int counter = 0;									// Tracks number of loops ran by loop
	while (counter < element) {							// Loop, end condition is when it has cycled for as many elements that are in the array

														// Silly text formatting, just outputs the scores
		cout << "The " << counter + 1 << "(st,nd,rd,th) score is " << scores[counter] << ".\n";	
		counter++;										// Increments counter by one
	}

	// Make an array of strings named bestFriends
	// Use a while loop to ask user to add names, or quit
	// At the end, use a for loop to display all the names

	string bestFriends[20];								// String Array to hold the names of best friends, arbitrarily chose 20 as the size
	int friendCount = 0;								// Counter for array loop, named differently because 'counter' is used already
		
	string input;
	cout << "We're making a list of your best friends. Who would you like to add?\nType 'quit' at any time to quit.\n";
	do {												// Add fail cases first, then functionality
		getline(cin, input);							// Get user input, assign it to "input"
		if (input == "quit") {							// Fail Con. #1, if the user quits
			cout << "Thanks for adding your friends list!";
			break;
		}
		if (friendCount >= 19) {						// Fail Con. #2, if the user exceeds the bestFriends array size
			cout << "You whore (nothing wrong with that)! You shouldn't have that many friends.";
			break;
		}

		bestFriends[friendCount++] = input; // Assign the user input to the applicable address of the bestFriends array

	} while (true);

	// You already know this, but hey, fun typing
	// A for loop runs "FOR a certain time period"
	// for loops include a counter, a test, and an incremental action, all on the same line
	//
	// Like this:
	// for(setup; test; actions; {code}
	
	cout << "We will now list your friends (in no particular order)! \n\n";	// Just some setup text

	for (int i = 0; i < friendCount; i++) {				// For loop, just checks to make sure it loops for the number of items added to the bestFriends array
														// Outputs friends in order of array, also outputs the order of the friends added
		cout << "Your " << i + 1 << "(st,nd,rd,th) listed friend is: \t" << bestFriends[i] <<".\n";	
	}
}