// Nolyn Janssen
// (There's a decent chance I dont need all that, but hey, I'm just copying the lecture)
// All about functions

// First task - create an array with three names
// use a loop to display all of the names.
#include <iostream>										// Dumb library inclusion, I'll remember how to do all this without pasting it one day
#include <string>
using namespace std;


// Put global variables at the top, so it predates all functions and they can use them
int currentShirtSizeElement = 0;						// Keeps track of shirt size array
string professor = "Brian";								// This shit is global, can be fine sometimes, most of the time you shouldn't use them
														// Whenever possible, don't use them, locals are safer, avoids bugs.

														// Function gotta be declared before it can be used, but it CAN be defined later, makes it cleaner, sometimes it duplicates stuff though, can be clunky if done weirdly
void sayHello() {										// Void function, returns nothing, the parantheses do things late
	cout << "Hello!\n";
}

void sayGoodbye() {										// Void function, yeah, same as hello but different
	cout << "Goodbye, you fool!\n";
}

// Adding two numbers with (parameters)
// Parameters go inside the paranthesis 
// They are the INPUTS for our function
// Optionally we can add default values for our input parameters
// We are creating two variables in the input parameter (parenthesis) 
void add(int number1 = 2, int number2 = 0) {					// Void function, doesn't need to return anything as all functionality is just printed to console
	// cout << "The sum of number1 and number2 is: ";
	cout << "The sum of " << number1 << " and " << number2 << " is: ";
	cout << number1 + number2 << endl;					// Adds two input numbers
}

// Overload the add function
// This one adds two floast
// Don't forget to call this function in main()
void add(float firstNum, float secondNum) {
	cout << firstNum << " plus " << secondNum << " equals ";
	cout << firstNum + secondNum << endl;
}

// "Break your brain brain" before the break (totally not doing this post lecture)
// Overload add() to accept two strings
// Using concatentation!

void add(string firstThing, string secondThing) {
	cout << firstThing << " added to (?) " << secondThing << " is: ";
	cout << firstThing + secondThing << endl;
}

// Return types - the output of the function
bool askYN(string question = "y/n?") {
	// In a dowhile loop
		// Ask the user the question
		// Get input from player
		// If Y, return true
		// If N Return False
		// Else, loop again
	do {
		cout << question << " (y/n) " << endl;
		string input;
		getline(cin, input);

		if (input == "y") {			// If y, return true
			return true;			// This quits the function
		}
		else if (input == "n") {	// If n, return false
			return false;			// Quits function, but with false
		}
		else {						// Else, loop again (Armed and dangerous again, again, again)
			cout << "Please type 'y' or 'n'.\n";
		}

	} while (true);
}

// Show array elements function
// Doesn't return anything
// Accepts one parameter as a pointer (shhh you don't about those yet(I kind of do))
// Call with   show(names, 3);   
void show(string* array, int arraySize) {
	cout << "Here are the contents of your array: \n";
	for (int i = 0; i < arraySize; i++) {
		cout << array[i] << endl;
	}
}

// Create a function that accepts a pointer to an array of strings
// Let it add another element as long as there are spaces in the array.

// 1. Put a while loop in the function, keep adding until player says done
	//or if user reaches max limit in array
void addShirtSize(string* array) {
	string input;
	while (true) {
		if (currentShirtSizeElement > 9) {				// As Mr Brain said, probably would be better to have a MaxArray variable, but this checks to make sure it doesn't exceed the limit of the array
			cout << "That's the max amount of shirt sizes we can support. :(\n";
			break;										// Breaks if it does
		}
		cout << "Please add a shirt size to the array, or type 'Done' to stop. \n";
		getline(cin, input);							// Asks for input

		if (input == "Done") {							// Checks for if user said done, if they did break
			break;
		}
		// Increments the global counter
		array[currentShirtSizeElement++] = input;		// If not, add to array

	}
	

	
}

int main() {											// Main code body, void because I felt like it														
	// SETUP
	string shirtSizes[10];								// Creating the array of shirtSizes
	// int currentSize = 0;
	addShirtSize(shirtSizes);							// Add shirt sizes
	show(shirtSizes, currentShirtSizeElement);			// Show shirtSizes

	string playerName = "brain";						// Local variable, only exists in main (good
														// ^ Compared to the i in a for loop, it is local to the loop, cant be used outside of it

	sayHello();											// Just calling the function, will print "Hello!"
	add(23, 12);										// Call add function, uses two predefined int numbers
	add();												// Able to call without defining them, as the function has default values
	add(23);											// ^ Similarly, since the 2nd (and all of them) have default, we dont need to input all values
	add(22.2f, 23.5f);									// Apparently you can differentiate between a double and float variable by adding an f to the end of it to make it a float
	add("Word", "Other");
	if (askYN("Do you like pizza?")) {					// If that just calls the bool function, inherently a true/false since its a bool
		cout << "Let's get some pizza for lunch!\n";	// If question is yes
	}
	else {
		cout << "I would not care to know you.\n";		// If it's not yet
	}
	string input;										// String variable to hold input
	string names[3];									// String array to hold names
	cout << "Please input three names to be stored\n";	// User prompt to put in names, apparently I didn't need to input names, just output, but I did anyways
	for (int i = 0; i < 3; i++) {						// For loop that goes 3 times
		cin >> input;									// Take input, assign to input variable
		names[i] = input;								// Assign input value to current array element
	}
	show(names, 3);
//	for (int i = 0; i < 3; i++) {						// Another 3x for loop
//		cout << i + 1 << ". " << names[i] << "\n";		// Output array elements, using the iterative i to access ascending values
//	}													// Could also do a "while (counter < 3) {cout << names [counter++];} and some other stuff, you get it
	sayGoodbye();										// Call the function, cmon, you know what it does lmao
}