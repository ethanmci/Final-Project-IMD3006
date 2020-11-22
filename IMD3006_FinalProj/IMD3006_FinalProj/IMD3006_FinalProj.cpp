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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
