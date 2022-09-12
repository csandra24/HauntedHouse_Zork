#include <iostream>
#include <string>
#include "world.h"

using namespace std;
using namespace text;

int main() {
	string playerInput;
	World myWorld;
	Actions actions;
	bool end = false;

	while (end == false)
	{
		getline(cin, playerInput);
		printMessage("");

		actions = myWorld.Input(playerInput); 

		if (actions == Actions::END) {
			printMessage("Thank you for playing, if you want to know more or share anything feel free to tell me.\n");
			printMessage("By Sandra Campaña");
			printMessage("Github link to check the full project: https://github.com/csandra24/HauntedHouse_Zork");
			getline(cin, playerInput);
			end = true;
		}
		else if (actions == Actions::QUIT) {
			end = true;
		}
		else if (actions == Actions::NONE) {
			printMessage("Sorry, I don't understand you :("s);

		}

	}

}


