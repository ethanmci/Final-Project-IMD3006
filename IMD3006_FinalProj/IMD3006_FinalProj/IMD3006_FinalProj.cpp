// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>  
#include <time.h> 
#include <vector>
#include <algorithm>
#include "GameClassesHeader.h" //includes all game specific classes
using namespace std;

void gameEncounters(Level* level) {
	level->currentEncounter()->getEncounterVis();
}

int main()
{
	ifstream wordList("wordlist.txt");
	string word;
	string wordArray[980];
	unsigned int lineNum = 0;
	int randomGen;
	string playerEntry;
	Player* currentPlayer = new Player();
	string state = "NEW_GAME";
	int difficulty = 1;
	bool alreadyGuessed = false;
	fstream scoreFile;
	ifstream readFile;
	string readLine;
	string playerName;
	string lastWord;
	int score = 0;

	srand(time(NULL));

	randomGen = rand() % 980 + 1;

	while (getline(wordList, word)) {
		wordArray[lineNum] = word;
		lineNum++;
	}
	while (1) {
		if (state == "NEW_GAME") {
			while (state == "NEW_GAME") {
				cout << R"(
  ______  ____  _____          _____ _____ _   _  _____  
 |  ____|/ ____|/ ____|   /\   |  __ \_   _| \ | |/ ____| 
 | |__  | (___ | |       /  \  | |__) || | |  \| | |  __  
 |  __|  \___ \| |      / /\ \ |  ___/ | | | . ` | | |_ | 
 | |____ ____) | |____ / ____ \| |    _| |_| |\  | |__| | 
 |______|_____/_\_____/_/    \_\_|   |_____|_| \_|\_____| 
 |__   __| |  | |  ____|                                  
    | |  | |__| | |__                                     
    | |  |  __  |  __|                                    
    | |  | |  | | |____                                   
   _|_|_ |_|  |_|______| _      ______          _______   
  / ____|   /\   | |    | |    / __ \ \        / / ____|  
 | |  __   /  \  | |    | |   | |  | \ \  /\  / / (___    
 | | |_ | / /\ \ | |    | |   | |  | |\ \/  \/ / \___ \   
 | |__| |/ ____ \| |____| |___| |__| | \  /\  /  ____) |  
  \_____/_/    \_\______|______\____/   \/  \/  |_____/   
)" << endl;
				cout << "type 'start' to start!\ntype 'about' to learn how to play\n";
				cin >> playerEntry;
				transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
				while (1) {
					if (playerEntry == "start") {
						system("cls");
						state = "GAME";
						break;
					}
					else if (playerEntry == "about") {
						system("cls");
						cout << R"(
== HOW TO PLAY ESCAPING THE GALLOWS ==

in ESCAPING THE GALLOWS you descend into an endless dungeon with the goal of making it further 
than all those who have come before you

to defeat ENEMIES you must correctly guess their word one letter at a time, each time you fail to 
guess correctly you will take damage

your health is visualized by a hangman, when the hangman is fully drawn you are dead

in your journey, you will find potions scattered throughout the dungeon from past explorers, 
by acessing your inventory using 'inv' you can make use of these potions and their effects to help you 
overcome whatever challenges you may face!

type 'back' to return to the main screen
)";
						while (1) {
							cin >> playerEntry;
							transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
							if (playerEntry == "back") {
								system("cls");
								break;
							}
							else {
								cout << "invalid entry\n";
							}
						}
						break;
					}
					else {
						cout << "invalid entry" << endl;
						cin >> playerEntry;
					}
				}
				
			}
		}
		//might wanna move these to the top?
		else if (state == "GAME") {
			Level* level = new Level(difficulty, wordArray);
			while (state == "GAME") {
				//cout << level->currentEncounter()->encounterType << "enc type\n";
				if (level->currentEncounter()->encounterType == "ENEMY" && !level->levelComplete) {
					Enemy* currentEnemy = dynamic_cast<EnemyEncounter*>(level->currentEncounter())->enemy;
					lastWord = currentEnemy->selWord; //saving word for potential display on defeat
					string status;
					while (currentPlayer->health > 0) {
						cout << currentPlayer->getVis();
						cout << "Score: " << score << endl;
						currentEnemy->display();
						cout << status;
						if (!currentEnemy->dead) {
							cout << "guess a letter or enter a command: ";
							cin >> playerEntry;
							transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
							//main code starts here
							if (playerEntry.length() == 1 && isalpha(playerEntry[0])) {
								do {
									alreadyGuessed = false;
									for (int t = 0; t < currentEnemy->pastGuesses.size(); t++) {
										if (playerEntry[0] == currentEnemy->pastGuesses[t]) {
											alreadyGuessed = true;
										}
									}
									if (alreadyGuessed) {
										cout << "letter already guessed!\n";
										cin >> playerEntry;
										transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
									}
								} while (alreadyGuessed == true);

								if (currentEnemy->selWord.find(playerEntry[0]) != string::npos) {
									status = "letter is in the word!\n";
								}
								else {
									status = "letter is not in the word!\n";
									currentPlayer->updateHealth(-1); //used to catch variable from going negative
								}

								//checking the player's status
								if (currentPlayer->health <= 0) {
									state = "GAME_OVER";
								}
								else {
									status += "You have " + to_string(currentPlayer->health) + " health left!\n";

								}

								currentEnemy->pastGuesses.push_back(playerEntry[0]);
							}
							else if (playerEntry == "inv") {
								system("cls");
								status = currentPlayer->getInv(currentEnemy);
							}
							else
							{
								status = "invalid entry, must only be 1 letter\n";
							}


						}
						else {
							//assume enemy is dead
							cout << "type 'next' to move to the next encounter\n";
							while (1) {
								cin >> playerEntry;
								transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
								if (playerEntry == "next") {
									if (currentEnemy->pastGuesses.size() == currentEnemy->selWord.size()) {
										score += 25;
									}
									else if (currentEnemy->pastGuesses.size() > currentEnemy->selWord.size()) {
										score += 10;
									}
									else if (currentEnemy->pastGuesses.size() < currentEnemy->selWord.size()) {
										score += 30;
									}
									if (level->levelComplete) {
										difficulty++;
										system("cls");
										break;
									}
									else {
										//level next encounter
										level->nextEncounter();
										system("cls");
										break;
									}
								}
								else if (playerEntry != "next") {
									cout << "invalid input\n";
								}
							}
							break;
						}
						system("cls");
					}
				}
				else if (level->currentEncounter()->encounterType == "ITEM") {
					Item* currentItem = dynamic_cast<ItemEncounter*>(level->currentEncounter())->item;
					//add item collection here!
					currentItem->encounterDisplay();
					cout << "type 'next' to move to the next encounter\n";
					while (1) {
						cin >> playerEntry;
						transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
						if (playerEntry == "next") {
							//level next encounter
							currentPlayer->inventory.push_back(currentItem);
							level->nextEncounter();
							system("cls");
							break;
						}
						else {
							cout << "invalid entry\n";
						}
					}
				}
				else if (level->levelComplete) {
					cout << "the level is cleared!\n next level";
					cin >> playerEntry;
					difficulty++;
					score += 5;
					system("cls");
					break;
				}
			}

		}
		else if (state == "GAME_OVER") {
			system("cls");
			cout << R"(
   _____          __  __ ______    ______      ________ _____  
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
)" << endl << endl;
			cout << "THE WORD WAS: " << lastWord << endl;
			cout << "Write your name to the high scores: " << endl;
			cin >> playerName;
			scoreFile.open("score.txt", fstream::app);
			scoreFile << playerName << ": " << score << "\n";
			scoreFile.close();
			readFile.open("score.txt", fstream::app);
			cout << endl << "HIGHSCORES" << endl;
			while (getline(readFile, readLine))
			{
				cout << readLine << '\n';
			}
			readFile.close();
			cout << endl << "type restart to try again!" << endl;
			while (state == "GAME_OVER") {
				cin >> playerEntry;
				transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
				if (playerEntry == "restart") {
					system("cls");
					difficulty = 1;
					currentPlayer->updateHealth(7);
					score = 0;
					state = "GAME";
					break;
				}
				else {
					cout << "invalid input\n";
				}
			}

		}
	}


}
