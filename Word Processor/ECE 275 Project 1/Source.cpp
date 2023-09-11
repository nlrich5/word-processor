#include <iostream>
#include <string>
using namespace std;

void PrintMenu() {
	cout << "MENU" << endl;
	cout << "c - Number of non-whitespace characters" << endl;
	cout << "w - Number of words" << endl;
	cout << "f - Find text" << endl;
	cout << "r - Replace all !'s" << endl;
	cout << "s - Shorten spaces" << endl;
	cout << "q - Quit" << endl;
}

int GetNumOfNonWSCharacters(const string string) {
	int count = 0;
	int i = 0;
	
	while (string[i] != '\0') {
		if (string[i] != ' ') {
			count++;
		}
		i++;
	}

	return count;
}

int GetNumOfWords(const string string) {
	int numWords = 0;
	int i = 0;

	while (string[i + 1] != '\0') {
		if (isalpha(string[i])) {
			if (!(isalpha(string[i + 1])) && (string[i + 1] != '\'')) {
				numWords++;
			}
		}
		i++;
	}
	if (isalpha(string[i])) {
		numWords++;
	}

	return numWords;
}

int FindText(string search, string userString) {
	int instances = 0;
	int searchLength = search.size();
	int i = 0;
	string tempString;

	while (userString[i + searchLength - 1] != '\0') {
		tempString = userString.substr(i, searchLength);
		if (search == tempString) {
			instances++;
		}
		i++;
	}

	return instances;
}

void ReplaceExclamation(string &string) {
	int i = 0;

	while (string[i] != '\0') {
		if (string[i] == '!') {
			string[i] = '.';
		}
		i++;
	}

	return;
}

void ShortenSpace(string &string) {

	int i = 0;

	while (string[i + 1] != '\0') {
		if (string[i] == ' ') {
			if (string[i + 1] == ' ') {
				string.erase(i, 1);
				i--;
			}
		}
		i++;
	}

	return;
}

string ExecuteMenu(char userInput, string userString) {
	string findTextSearch;
	
	while (userInput != 'q') {
		switch (userInput) {
			case 'c':
				cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userString) << endl;
				break;
			case 'w':
				cout << "Number of words: " << GetNumOfWords(userString) << endl;
				break;
			case 'f':
				cout << "Enter a word or phrase to be found:" << endl;
				cin >> findTextSearch;
				cout << "\"" << findTextSearch << "\" instances: " << FindText(findTextSearch, userString) << endl;
				break;
			case 'r':
				ReplaceExclamation(userString);
				cout << "Edited text: " << userString << endl;
				break;
			case 's':
				ShortenSpace(userString);
				cout << "Edited text: " << userString << endl;
				break;
			default:
				cout << "Invalid input. Please enter a valid option." << endl;
				break;
		}

		cout << endl;
		PrintMenu();
		cin >> userInput;
	}

	return userString;
}

int main() {

	string input;
	char menuInput;

	cout << "Enter a sample text:" << endl;
	getline(cin, input);

	cout << endl << "You entered: " << input << endl;

	PrintMenu();

	cin >> menuInput;
	ExecuteMenu(menuInput, input);

	return 0;
}