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
		printf_s("");

		actions = myWorld.Input(playerInput); 

		if (actions == END) {
			printMessage("Piensa un texto pa' el final");
			printMessage("By Sandra Campa�a");
			printMessage("SPAM LINK GITHUB");
			getline(cin, playerInput);
			end = true;
		}


		else if (actions == NONE) {
			printf_s("Sorry, I don't understand you :(");

		}

	}

}


