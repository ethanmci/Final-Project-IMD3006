// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

#include <stdlib.h>  
#include <time.h> 
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

	srand(time(NULL));

	randomGen = rand() % 980 + 1;

	while (getline(wordList, word)) {
		wordArray[lineNum] = word;
		//cout << wordArray[lineNum] << endl;
		lineNum++;





		//cout << word << endl;
	}
	cout << "word: ";
	for (size_t x = 0, length = wordArray[randomGen].length(); x != length; ++x)
	{
		cout << "_ ";
	}

	cout << endl << wordArray[randomGen] << endl;

	do {
		cin >> playerGuess;
		if (wordArray[randomGen].find(playerGuess) != std::string::npos) {
			cout << "letter is in the word!" << endl;
		}
		else {
			cout << "letter is not in the word!" << endl;
		}
	} while (true);

}
