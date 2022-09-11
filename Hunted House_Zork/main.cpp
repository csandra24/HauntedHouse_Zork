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

		if (actions == END) {
			printMessage("Piensa un texto pa' el final");
			printMessage("By Sandra Campaña");
			printMessage("SPAM LINK GITHUB");
			getline(cin, playerInput);
			end = true;
		}


		else if (actions == NONE) {
			printMessage("Sorry, I don't understand you :("s);

		}

	}

}


