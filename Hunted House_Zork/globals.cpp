#include "globals.h"

using namespace text;

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
		cout << "2 word commands\n";
		cout << "Move (direction) - Player movement towards that direction\nGet/Pick/Take (item) - Add item to player's inventory\n";
		cout << "Drop (item) - Remove item from player's inventory and leave it on the floor\n";
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

