#include "globals.h"

using namespace text;

array<Directions, 6> directionString = { NORTH,SOUTH,EAST,WEST,UP,DOWN };

namespace  text {
	void printMessage(string message) {
		message[0] = (char)toupper(message[0]);
		cout << message << '\n';
	}

	void printMessage(string message, string message2) {
		message[0] = (char)toupper(message[0]);
		message2[0] = (char)toupper(message2[0]);
		cout << message << '\n' << message2 << '\n';
	}

	void printHelp() {
		cout << "1 word commands\n";
		cout << "Inventory - List of player's inventory\n";
		cout << "End/Quit - End the game\n\n";
		cout << "2 word commands\n";
		cout << "Move/Go (direction) - Player movement towards that direction\nPick/Take/Get (item) - Add item to player's inventory\n";
		cout << "Drop (item) - Remove item from player's inventory and leave it on the floor\n";
		cout << "Open (container) - Open any container and put its content in player's inventory\n\n";
		cout << "4 word commands\n";
		cout << "Save/Put (item) in (container) - Removes an object from the player's inventory and adds it to a container, such as a bag.\n";
	}

	void printIntro() {
		cout << "You are about to enter the haunted house. Pensar textito\n";
		cout << "Pensar textito\n";
		cout << "Pensar textito\n";
		cout << "If you need help just type HELP\n\n";
	}

	bool compareString(string first, string second) {
		bool equals = true;
		if (first.size() != second.size()) {
			equals = false;
		}
		else {
			for (unsigned int i = 0; i < first.size(); i++) {
				if (tolower(first[i]) != tolower(second[i])) {
					equals = false;
					break;
				}
			}
		}
		return equals;
	}

	bool compareString(string first, const Directions directions) {
		bool equals = true;
		string second = "";
		switch (directions) {
		case NORTH:
			second = "north";
			break;
		case SOUTH:
			second = "south";
			break;
		case EAST:
			second = "east";
			break;
		case WEST:
			second = "west";
			break;
		case UP:
			second = "up";
			break;
		case DOWN:
			second = "down";
			break;
		}
		if (first.size() != second.size()) {
			equals = false;
		}
		else {
			for (unsigned int i = 0; i < first.size(); i++) {
				if (tolower(first[i]) != tolower(second[i])) {
					equals = false;
					break;
				}
			}
		}
		return equals;
	}
}

//command

Command::Command(const list<string> names, const Actions actions, const int numberOfArguments) :
	names(names), actions(actions), numberOfArguments(numberOfArguments) {

}

Command::~Command(){
}

int Command::CountWords(const string& input) {
	int numberOfWords = 1;
	int i = 0;
	char letter;
	bool lastIsSpace = false;
	while (i < input.size()) {
		letter = input[i];

		if (isspace(letter) && !lastIsSpace) {
			lastIsSpace = true;
			numberOfWords++;
		}
		else {
			lastIsSpace = false;
		}
		i++;
	}

	return numberOfWords;

}

bool Command::IsCommand(const string& input) {
	bool found = false;
	for (string iter : names) {
		if (compareString(input.substr(0, iter.size()), iter)) {
			found = true;
			break;
		}
	}
	return found;
}

string Command::GetArguments(const string& input) {

	int inputWordsCount = CountWords(input);

	string arguments = input;

	for (string iter : names) {
		if (inputWordsCount == 1) {
			arguments = ""s;
			break;
		}
		if (inputWordsCount == 2) {
			if (compareString(input.substr(0, iter.size() + 1), (iter + " "))) {
				arguments.erase(0, iter.size() + 1);
				break;
			}
		}
		if (inputWordsCount == 4) {
			if (compareString(input.substr(0, iter.size() + 1), (iter + " "))) {
				arguments.erase(0, iter.size() + 1);
				break;
			}
		}
	}

	return arguments;
}

//fin command

