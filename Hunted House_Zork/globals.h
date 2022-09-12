#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>
#include <array>
#include <list>

using namespace std;

//Directions' variable

enum Directions {
	NOWHERE = 0,
	NORTH = 1,
	SOUTH = -1,
	EAST = 2,
	WEST = -2,
	UP = 3,
	DOWN = -3,
};

extern array <Directions, 6> directionString; 

enum Actions {
	PICK,
	DROP,
	MOVE,
	OPEN,
	LOOK,
	END,
	INVENTORY,
	HELP,
	SAVE,
	QUIT,
	NONE
};

class Command
{
public:
	Command(const list<string> names, const Actions actions, const int numberOfArguments);
	virtual ~Command();
	int CountWords(const string& input);
	bool IsCommand(const string& input);
	string GetArguments(const string& input);
	list<string> names;
	Actions actions;
	int numberOfArguments;

};

namespace text { 
	void printMessage(string message);
	void printMessage(string message, string message2);
	void printHelp();
	void printIntro();
	bool compareString(string first, string second);
	bool compareString(string first, const Directions directions);

}



#endif // !1__Globals__


