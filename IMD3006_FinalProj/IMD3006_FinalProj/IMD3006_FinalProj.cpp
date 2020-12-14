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
	string playerEntry; //should maybe replace player guess?
	char playerGuess;
	Player* currentPlayer = new Player();
	string state = "NEW_GAME";
	int difficulty = 1;
	bool alreadyGuessed = false;
	fstream scoreFile;
	ifstream readFile;
	string readLine;
	string playerName;
	int score = 0;
	/*if (pastGuesses.size() == wordlength)
	score += 25
	else if (round is over and health is not 0)
	score += 10
	if levels completed is a multiple of 5
	score += 5

	also
	line 392 up to 4 letter words
	line 592 up to 5 letter words
	the rest are 6 and longer


		*/

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
					state = "GAME";
					break;
				}
				else  if (playerEntry == "credits") {
					//any librarys that need credit go here?
				}
				else {
					cout << "invalid entry" << endl; //temp fix again :)
				}
			}
		}
		/*else if (state == "SELECT_DIFF") {
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
		}*/
		//might wanna move these to the top?
		else if (state == "GAME") {
			Level* level = new Level(difficulty, wordArray);
			//gameEncounters(level);
			//actual game loop :)
			while (state == "GAME") {
				//cout << level->currentEncounter()->encounterType << "enc type\n";
				if (level->currentEncounter()->encounterType == "ENEMY" && !level->levelComplete) {
					Enemy* currentEnemy = dynamic_cast<EnemyEncounter*>(level->currentEncounter())->enemy;
					string status;
					while (currentPlayer->health > 0) {
						cout << currentPlayer->getVis();
						cout << "Score: " << score << endl;
						currentEnemy->display();

						//main code starts here
						if (!currentEnemy->dead) {
							do {
								cin >> playerGuess;
								alreadyGuessed = false;
								for (int t = 0; t < currentEnemy->pastGuesses.size(); t++) {
									if (playerGuess == currentEnemy->pastGuesses[t]) {
										alreadyGuessed = true;
									}
								}
								if (alreadyGuessed) {
									cout << "letter already guessed!\n";
								}
							} while (alreadyGuessed == true);
							if (!currentEnemy->dead) {
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
								}
								else {
									status += "You have " + to_string(currentPlayer->health) + " health left!\n";
								}
							}

							currentEnemy->pastGuesses.push_back(playerGuess);
						}
						else
						{
							if (currentEnemy->pastGuesses.size() == currentEnemy->selWord.size()) {
								score += 25;
							}
							else if (currentEnemy->pastGuesses.size() > currentEnemy->selWord.size()){
								score += 10;
							}
							cout << "type 'next' to move to the next encounter\n";
							cin >> playerEntry;
							transform(playerEntry.begin(), playerEntry.end(), playerEntry.begin(), tolower);
							if (playerEntry == "next") {
								if (level->levelComplete) {
									difficulty++;
									break;
								}
								else {
									//level next encounter
									level->nextEncounter();
									system("cls");
									break;
								}
							}
						
						}
						system("cls");
					}		
				}
				else if (level->currentEncounter()->encounterType == "ITEM" && !level->levelComplete) {
					//add item collection here!
					cout << "we is items\n";
					cin >> playerEntry;
					level->nextEncounter();
					system("cls");
				} else if (level->levelComplete){
					cout << "the level is cleared!\n next level" << endl;
					cin >> playerEntry;
					difficulty++;
					score += 5;
					system("cls");
					//increase difficulty / level size here!
					break;
				}
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
			while (state == "GAME OVER") {
				cin >> playerEntry;
				if (playerEntry == "restart") {
					system("cls");
					difficulty = 1;
					currentPlayer->updateHealth(7);
					score = 0;
					state = "GAME";
					break;
				}
			} 

		}
	}


}
