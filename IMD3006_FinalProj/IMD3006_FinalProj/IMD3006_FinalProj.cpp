// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>  
#include <time.h> 
#include <vector>

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
	string playerEntry; //should maybe replace player guess?
	char playerGuess;
	Player* currentPlayer = new Player();
	string state = "NEW_GAME";
	int difficulty = 0;
	bool alreadyGuessed = false;

	srand(time(NULL));

	randomGen = rand() % 980 + 1;

	while (getline(wordList, word)) {
		wordArray[lineNum] = word;
		lineNum++;
		//cout << word << endl;
	}
	//gheto solution LOL, fix this later 
	while (1) {
		if (state == "NEW_GAME") {
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
			cout << "type 'start' to start!\n";
			while (state == "NEW_GAME") {
				cin >> playerEntry;
				if (playerEntry == "start") {
					system("cls");
					state = "SELECT_DIFF";
					break;
				}
				else  if (playerEntry == "credits") {
					//any librarys that need credit go here?
				}
				else {
					cout << "invalid entry"; //temp fix again :)
				}
			}
		}
		else if (state == "SELECT_DIFF") {
			cout << "select difficulty:\n 1 = easy, 2 = normal, 3 = hard\n";
			while (state == "SELECT_DIFF") {
				cin >> difficulty;
				if (difficulty > 0 && difficulty < 4) {
					system("cls");
					state = "GAME";
					break;
				}
				else {
					cout << "invalid difficulty!\n";
				}
			}
		}
		//might wanna move these to the top?
		else if (state == "GAME") {
			Level* level = new Level(difficulty, wordArray);
			gameEncounters(level);
			if (level->currentEncounter()->encounterType == "ENEMY") {
				Enemy* currentEnemy = dynamic_cast<EnemyEncounter*>(level->currentEncounter())->enemy;
				string status;
				while (currentPlayer->health > 0) {
					cout << currentPlayer->getVis();
					cout << "Guesses[";
					for (int g = 0; g < currentEnemy->pastGuesses.size(); g++) {
						cout << currentEnemy->pastGuesses[g] << ", ";
					}
					cout << "]";
					cout << endl << currentEnemy->selWord << endl; //debugging output
					currentEnemy->update();
					cout << currentEnemy->getVis();
					if (currentEnemy->pastGuesses.size() == 0)
						cout << "a " << currentEnemy->getEnemyType() << " approaches!\n";
					cout << "word: ";
					for (int x = 0; x < currentEnemy->selWord.length(); ++x)
					{
						bool isGuessed = false;
						for (int j = 0; j < currentEnemy->pastGuesses.size(); j++) {
							if (currentEnemy->selWord[x] == currentEnemy->pastGuesses[j]) {
								cout << currentEnemy->selWord[x] << " ";
								isGuessed = true;
							}
						}

						if (!isGuessed)
							cout << "_ ";
					}
					cout << endl;

					do {
						cin >> playerGuess;
						alreadyGuessed = false;
						for (int t = 0; t < currentEnemy->pastGuesses.size(); t++) {
							if (playerGuess == currentEnemy->pastGuesses[t]) {
								alreadyGuessed = true;
							}
						}
					} while (alreadyGuessed == true);
					if (currentEnemy->selWord.find(playerGuess) != string::npos) {
						status = "letter is in the word!\n";
					}
					else {
						status = "letter is not in the word!\n";
						currentPlayer->updateHealth(-1); //used to catch variable from going negative
					}

					//checking the player's status
					if (currentPlayer->health <= 0) {
						state = "GAME OVER";
						//status += "You have died\n";
					}
					else {
						//hangman output here?
						status += "You have " + to_string(currentPlayer->health) + " health left!\n";
					}

					currentEnemy->pastGuesses.push_back(playerGuess);
					system("cls");
				}		
			}
			else if (level->currentEncounter()->encounterType == "ITEM") {
			
			}
		}
		else if (state == "GAME OVER") {
			system("cls");
			cout << R"(
   _____          __  __ ______    ______      ________ _____  
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
)" << endl << endl;
			cout << "type restart to try again!" << endl;
			while (state == "GAME OVER") {
				cin >> playerEntry;
				if (playerEntry == "restart") {
					system("cls");
					difficulty = 0;
					currentPlayer->updateHealth(7);
					state = "SELECT_DIFF";
					break;
				}
			} 

		}
	}


}
