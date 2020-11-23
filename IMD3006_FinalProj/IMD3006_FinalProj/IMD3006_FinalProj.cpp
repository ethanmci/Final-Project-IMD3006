// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

#include <stdlib.h>  
#include <time.h> 
#include <vector>
using namespace std;


int main()
{
	/*while (1) {
		string userTxt;
		cin >> userTxt;
	}*/

	ifstream wordList("wordlist.txt");
	string word;
	string wordArray[980];
	unsigned int lineNum = 0;
	int randomGen;
	char playerGuess;
	Player* currentPlayer = new Player();

	srand(time(NULL));

	randomGen = rand() % 980 + 1;

	while (getline(wordList, word)) {
		wordArray[lineNum] = word;
		//cout << wordArray[lineNum] << endl;
		lineNum++;





		//cout << word << endl;
	}
	/*
	cout << "word: ";
	for (size_t x = 0, length = wordArray[randomGen].length(); x != length; ++x)
	{
		cout << "_ ";
	}
	*/


	vector<char> playerGuesses;
	while (1) {
		cout << endl << wordArray[randomGen] << endl; //debugging output
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
			cout << "letter is in the word!" << endl;
		}
		else {
			cout << "letter is not in the word!" << endl;
			currentPlayer->health--;
		}

		//checking the player's status
		if (currentPlayer->health <= 0) {
			cout << "You have died\n";
		}
		else {
			//hangman output here?
			cout << "You have " << currentPlayer->health << " health left!\n";
		}

		playerGuesses.push_back(playerGuess);
		//system("cls");
	}


}
