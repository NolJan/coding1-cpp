#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int health = 100;																// Global variables to track health and the totalTreasure gathered
int totalTreasure;																// Admittedly unsure of what value is meant to be used, so I just did 100 for health

void Story() {																	// Function purely for opening exposition
	cout << "\tYou are but a humble cricket. One day after playing your nightly lament on your leg cello " <<
	"and shutting in for the night, a rasping knock on the door to your burrow interrupts your preparing of supper.\n";
	cout << "Upon making your way to the door to open it, a comely grasshopper, adorned from antennae to rear abdomen in leaf plate armor stands before you.\n"
		<< "'You're needed by your fellow critters of the wood. I would accompany you, but I have other duties I must attend to. I do come with provisions and supplies from our lords, ' and he pulls a large sack up from the ground betwixt his long legs. "
		<< "it's dark brown, made of the finest flea leather, and fastened to the side with twine is a sharpened blade, about the length of your extended arm."
		<< " ' I know it's a lot to ask, but if you are willing, the package in this bag needs to be delivered to the neighboring wood. Do you accept?'\n";
}

bool AskYesNo(string question) {												// Function for asking the user Yes/No questions
	string input;																// String for the input
	cout << question << "(Yes/No)?: ";											// Ask user if yes or no
	cin >> input;																// Apply user input to input variable
	//cout << "\n";
	if (input == "Yes" || input == "yes" || input == "y" || input == "Y") {		// If statement that checks user input, has or statements to accomodate for various ways user can say yes
		return true;															// If they said yes, return true
	}
	if (input == "No" || input == "no" || input == "n" || input == "N") {		// Same as yes if, but for no
		return false;															// If they said no, return false
	}	
	else {																		
		cout << "Speak up sonny, I don't know what you said!\n";				// If the user inputs something that's not y/n, snarky deaf man statement, then recurse the yes/no statement
		if (AskYesNo("")) {
			return true;
		}
		else {
			return false;
		}
	}
}

int RollDie(int sides = 6) {													// Function to roll number, default to D6
	return (rand() % sides) + 1;												// Gets random number, remainder + 1 of the dice sides, functions as a dice
}

void Ending() {																	// Function that plays when you die, tells a little story, tells player their treasure
	cout << "Despite your best efforts, you have succumbed to your wounds. No one in either wood can blame you, and you will surely be celebrated for your efforts.\n"
		<< " Unfortunately, celebration cannot bring you back, and you die, bleeding out on the road before the next traveling trader can save you."
		<< " Lucky for them though, while rushing your body to the nearest town, " << totalTreasure << " gold coins fall out of your bag while the cart jangles, and they use this to fund the opening of their store!";
}

void Adventure() {																// Main adventure function
	cout << "After making your way towards the neighboring wood, there comes an eight legged freak, charging towards you.";
	int treasure = RollDie(100);
	int playerBlock = RollDie(20);
	int spiderHit = RollDie(20);												// Generate treasure from 1-100 randomly, as well as d20 attack and AC roll for the spider and player respectively
	if (playerBlock > spiderHit) {												// If AC higher than attack, flavor text, get gold, move on
		cout << "You deftly dodge and redirect the spiders slashes and stabs, stabbing it during your acrobratic twirling, and the spider falls over, legs curled up in a ball.\n"
			<< "From within the mouth you see a slight glint, shining from between the fangs of the creature. You pull out a slimy pile of treasure, and after counting, you add " << treasure << " gold pieces into your pouch\n";
		totalTreasure = totalTreasure + treasure;								// Add treasure to total
	}
	if (playerBlock < spiderHit) {												// If player AC lower than attack, take damage, flavor text
		cout << "Despite your best efforts, the spider's many legs make their way past your blocks and dodges, lodging a sharp appendage into your torso, and you take " << spiderHit << " damange, reducing your "
			<< "wellbeing to a " << health - spiderHit << " amount, if you had to quantify it. You scurry away, bleeding, but alive.";
		health = health - spiderHit;											// Modify health according to spider attack
	}
	if (playerBlock == spiderHit){												// In the rare chance the AC and attack rolls are the same, funny text, nothing happens
		cout << "You and the spider are evenly matched, and after hours of perfectly blocked blows from each side, you awkwardly stare at eachother for a few minutes, out of breath, and share a silent agreement, walking seperate ways.\n";
	}
	if (health > 0){																// Alert player to status, quick if in the off chance of player dying
		cout << "Checking your bearings, you find you are in possession of " << totalTreasure << " gold, and if you had to put a number to it, " << health << " health.";

	}
}

int main() {
	srand(NULL);																// Seed random numbers
	Story();
	if (!AskYesNo("Do you accept his request?"))								// If you say no, funny text, end program
	{
		cout << "You close your door in his face, and honestly? Fair.\n";
		return 0;
	}
	while (health > 0) {														// While loop for adventuring, goes as long as the player has health
		if (AskYesNo("Do you continue down the road?\n")) {						// Prompt for continuation
			Adventure();														// Call adventure function
		}
		else {
			if (health > 75) {													// Upon quitting, check for 3 seperate health brackets, give appropraite flavor text message accordingly
				cout << "After taking a few light blows, having " << health << " health left, you decide it's time to call it quits, fuck the neighboring wood after all. Besides, on your adventure you collected " << totalTreasure
					<< " bits of gold after all, so it was a worthwhile journey.";
				break;
			}
			if (health > 20 && health < 75) {						
				cout << "After taking many heavy blows, you think this quest is better suited for the next guy, and head home. Your pockets jingle with the sound of "
					<< totalTreasure << " gold coins as you limp home with " << health << " health remaining.";
				break;
			}
			if (health < 20) {
				cout << "After a particularly fowl fight with a foe, you pass out in the middle of the road, with approximately "
					<< totalTreasure << " coins spilling out of your pockets, along with a lot of blood. Although you are still alive with " << health << " health, who knows how long it is until you awaken.";
				break;
			}
		}
	}
	if (health <= 0) {															// If dead, run ending function
		Ending();
	}
}