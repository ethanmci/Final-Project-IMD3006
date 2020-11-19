// IMD3006_FinalProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
using namespace std;


int main()
{
	/*while (1) {
		string userTxt;
		cin >> userTxt;
	}*/

	std::string word;
	ifstream wordList("wordlist.txt");
	if (wordList.is_open()) {
		while (getline(wordList, word)) {
			std::cout << word << endl;
		}

		wordList.close();
	}
	else {
		std::cout << "error, file not open" << endl;
	}
	std::cin.get();
	return 0;
	
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
