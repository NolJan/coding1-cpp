// Nolyn Janssen, Coding 1, Week 6 of Spring 25, Feb 25th 2025
// Loops and Lists
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Making an array
	// Array is an ordered list of a single type of variable
		
	// Creat an Array of integers with a [size] of 10
	
	const int MAX_SIZE = 10;			// Constant variable for max size, cannot be changed, ALL_CAPS format for constants

	int element = 0;					// Tracks where array location is

	int scores[MAX_SIZE];				// THis arrary has 10 slots for integer values to be held

	// Add a value to the first element for the array
	scores[0] = 9001;

	// Display the value to confirm that it works
	cout << "The highest score in scores is " << scores[0] << ".\n";
}