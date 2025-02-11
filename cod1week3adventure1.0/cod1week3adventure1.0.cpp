using namespace std;
#include <iostream>					
#include <string>
#include <cstdlib>
#include <ctime>
																// if the is a "?" before a comment, it was the instructions for the assignment
int main() {

// ?welcome the player
	srand(time(NULL));											// seeding, I admittedly don't fully understand this part, but whatevs
	char pAnswer = 'y';											// setup for player input on intro questions
	string playerName = "null";									// playerName, initialized with placeholder text, wasn't in the instructions, but I liked the idea of having a custom name
	int pHealth = 10;											// player health
	char cont = 'y';											// variable for if the player wants to continue, I wanted this named "continue" but thats a thing so cont it is
	int turn = 0;												// turn counter
	int pBlock = (rand() % 4) + 1;								// player block value/stat, is randomized 1-4
	int pAttack = (rand() % 4) + 1;								// player attack value/stat, is randomized 1-4
	int pBlockDefault = pBlock;									// variable to be able to reset block in case of stat modifiers
	int battlesWon = 0;											// counter for the number of battles won (duh)
	string pInput = "nullbutinput";
	cout << "\tHello!\n -Please enter your name-\n\t";			// request playerName from player
	getline(cin, playerName);									// assign playerName
	cout << "\n\n I see..." << playerName << ", what a nice name!\n Would you like to go an adventure " << playerName << "?\n";
	cin >> pAnswer;
	if (pAnswer == 'y') {
		cout << "\nAre you sure? Be warned, once you enter the gauntlet, you or your enemy must perish...so I ask again, do you wish to depart on an adventure?\n";
		cin >> pAnswer;
		if (pAnswer == 'y') {
			// I don't know why I've decided to do a creative writing assignment right now, this might the clunkiest tutorial ever made, but why not, yknow
			cout << "\nVery well! I see you are an individual of great courage. Even so, I insist on giving you some guidance, lest you perish before taking your second step down your path.";
			cout << "\nYou shall find an endless number of inscrutuble creatures, who are so simple minded and vile, the only purpose they serve is to take you to the fiery depths they emerged from themselves.";
			cout << "\nLuckily, I am able to provide you some semblence of aid. After each fight, there will be a brief moment I'll be able to commune with you. During this time, if you wish, I shall return you here, to the beginning.";
			cout << "\nThese fiendish foes of yours, will either rush at you in a blind rage, or hide behind their defences in cowardice. Unfortunately, there is no tell which will come over the other.";
			cout << "\nLuckily, I have gifts. The Sword of Flame and Fury, and the Saving Shield of the Stars. If you wish to attack during your battles, simply express the desire to do so, and you will valiantly slash at your foes.";
			cout << "\nSimilarly, if you wish to fall back and defend in a moment of tactical wisdom, you may also express the desire, and it will be done. This back and forth 'tween you and the demons shall determine the victor.";
			cout << "\nI wish you luck " << playerName << ", and I shall speak with shortly.";

			cout << "\n\n\n In battle, type 'attack' to make a slash at your enemy, or 'block' for a 50% bonus to your defences.";
	
			while (cont == 'y'){												// man i'm only like 60% sure of what I'm doing
				turn = 0;
				cout << "\nA new creature stands before you.";						
				int creatureAttack = (rand() % 3) + 1;							// determine creatures attack power, randomized 1-3
				int creatureAction = 1;											// this will be the creatures move each turn, it will be set randomly, a 1 is a block, a 2 is an attack
				while (pHealth > 0 && turn < 4)									// loop checking the two fail conditions each turn
				{
		
					pBlock = pBlockDefault;										// probably not optimal, but resets the block to the proper value in case the player decides to block
					creatureAction = (rand() % 2) + 1;							// determines creatures action this turn
					cout << "\nWhat shall you do?\n";							//!!!This keeps saying this twice, and I don't know why!!!
					getline(cin, pInput);										// player inputs actions
					if (pInput == "attack") {									// condition for if player attacks
						if (creatureAction == 2)								// checks for creatures action, if it blocked, oh no, if it didn't, player kills it
						{
							cout << "The creature was slain!";
							battlesWon++;
							break;
						}
						if (creatureAction == 1) {
							cout << "The creature blocked.";
						}		
					}
					if (pInput == "block")										// if player blocked, it checks to see if the creature was attacking and if so, did it hit regardless
					{
						pBlock = pBlock * 1.5;
						if (creatureAction == 2) {
							cout << "The creature attacked, and it...";
							if (creatureAttack >= pBlock) {
								cout << "hit! Ouch! You lost " << creatureAttack << " health!";
								pHealth = pHealth - creatureAttack;
							}
							else {
								cout << "missed! Hooray!";
							}
						}
						if (creatureAction == 1) {
							cout << "The creature cowers in fear as you stand in prepartion of a blow...way to waste a turn.";
						}
					}				
					turn++;													// adds turn
				}// end of encounter loop
				if (pHealth <= 0) {											// check if loop exited due to death
					cout << "\nOwie, you died.";
					break;
				}
				else if (turn >= 4) {										// check if loop exited due to time
					cout << "\nThe battle waned for too long, reinforcements arrived of the enemy arrived, and you were overwhelmed. You died.";
					break;
				}
				cout << "\nContinue?";										// if loop exited due to victory, asks if the player wants to continue
				cin >> cont;												// takes player input to see if gameplay loop should continue
			}// end of play loop
		}
		if (pAnswer == 'n') {							
			cout << "\nI see...there is no shame in knowing ones one limits, depart from this place then!";
			cout << "\n\n\n\n\.";											// I don't like the command window game ending with the exit instructions of vstudio, so this adds space			
			return 0;
		}
	}
	if (pAnswer == 'n') {
		cout << "Bah! Coward, leave this place at once!\n *The wizard points his staff at you, and your vision goes black*";
	}
	cout << "\nThe game is over. You won " << battlesWon << " battles, good job!";				// text to tell player their score
cout << "\n\n\n\n\.";																			// I don't like the command window game ending with the exit instructions of vstudio, so this adds space			
}// end of main