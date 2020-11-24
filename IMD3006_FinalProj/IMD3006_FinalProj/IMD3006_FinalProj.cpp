// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "enemy.h"


#include <stdlib.h>  
#include <time.h> 
#include <vector>
using namespace std;


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

	srand(time(NULL));

	randomGen = rand() % 980 + 1;

	while (getline(wordList, word)) {
		wordArray[lineNum] = word;
		lineNum++;
		//cout << word << endl;
	}

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
	//gheto solution LOL, fix this later 
	cout << "type 'start' to start!\n";
	while (1) {
		cin >> playerEntry;
		if (playerEntry == "start") {
			break;
		}
		else {
			cout << "invalid entry"; //temp fix again :)
		}
	}
	//might wanna move these to the top ?
	vector<char> playerGuesses;
	string status;
	while (1) {
		cout << currentPlayer->getVis();
		//cout << endl << wordArray[randomGen] << endl; //debugging output
		cout << "word: ";
		for (size_t x = 0, length = wordArray[randomGen].length(); x != length; ++x)
		{
			bool isGuessed = false;
			for (int j = 0; j < playerGuesses.size(); j++) {
				if (wordArray[randomGen][x] == playerGuesses[j]) {
					cout << wordArray[randomGen][x] << " ";
					isGuessed = true;
				}
			}

			if (!isGuessed)
				cout << "_ ";
		}
		cout << endl;

		cin >> playerGuess;
		if (wordArray[randomGen].find(playerGuess) != string::npos) {
			status = "letter is in the word!\n";
		}
		else {
			status = "letter is not in the word!\n";
			currentPlayer->updateHealth(-1); //used to catch variable from going negative
		}

		//checking the player's status
		if (currentPlayer->health <= 0) {
			status += "You have died\n";
		}
		else {
			//hangman output here?
			status += "You have " + to_string(currentPlayer->health) + " health left!\n";
		}

		playerGuesses.push_back(playerGuess);
		system("cls");
	}


}
