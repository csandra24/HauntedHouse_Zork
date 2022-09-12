#include <iostream>
#include <string>
#include "world.h"

using namespace text;

World::World() {

	commands = {
		new Command({"pick", "take" }, Actions::PICK, 1),
		new Command({"move", "go" }, Actions::MOVE, 1),
		new Command({"inventory" }, Actions::INVENTORY, 1),
		new Command({"drop" }, Actions::DROP, 1),
		new Command({"save", "put" }, Actions::SAVE, 1),
		new Command({ "help" }, Actions::HELP, 1),
		new Command({"look"}, Actions::LOOK, 1),
		new Command({ "open" }, Actions::OPEN, 1),
		new Command({ "quit", "exit", "end" }, Actions::QUIT, 1),
		new Command({"craft" }, Actions::CRAFT, 1)

	};

	Room* basement  = new Room("Basement\n"s, "It is a dark and damp place, illuminated by a light bulb hanging from the ceiling.\nThere is an old closet and a box with a blurred label, but your not sure what it says.\nTo the east of the basement there is a large metal door,\nwhat will be on the other side, will that cabinet or that box hold any useful object?\n"s);
	Room* basementRoom = new Room("Basement's hall\n"s, "You are plunged into total darkness, unable to recognize anything. You start to hear strange noises.\nIs there something else there? Is that a staircase over there(up)?\n"s);
	Room* hall = new Room("Hall\n"s, "It is a very large and spacious room, decorated like in the 60's, but the windows are all covered, making it\ndifficult to see. You can make out 3 doors in the dark, where do they lead to?\n"s);
	Room* kitchen = new Room("Kitchen\n"s, "At the moment, the most colorful place in the house with blue tiles and floral print textiles.\n There are some cabinets open but others are closed, you can also see what looks like a refrigerator.\n"s);
	Room* bedroom = new Room("Bedroom\n"s, "The room is covered in a nasty green slime, is there anything here?\n"s);
	Room* outdoor = new Room("Outdoor"s, "\n"s);
	//Room* monster = new Room("Nombre lugar"s, "descripción..."s);

	worldEntities.push_back(basement);
	worldEntities.push_back(basementRoom);
	worldEntities.push_back(hall);
	worldEntities.push_back(kitchen);
	worldEntities.push_back(bedroom);
	worldEntities.push_back(outdoor);
	//worldEntities.push_back(monster);

	// exit
	Exit* basementToRoom = new Exit("You succeed in opening the door"s, ""s, basement, basementRoom, Directions::EAST);
	Exit* roomToHall = new Exit("You walk up the stairs and arrive at..."s, ""s, basementRoom, hall, Directions::UP);
	Exit* hallToKitchen = new Exit("Hall to kitchen"s, ""s, hall, kitchen, Directions::EAST);
	/*Exit* kitchenToHall = new Exit("Kitchen to Hall"s, ""s, hall, kitchen, Directions::WEST);*/
	Exit* hallToBedroom = new Exit("Hall to bedroom"s, ""s, hall, bedroom, Directions::WEST);
	Exit* bedroomTOHall = new Exit("Bedroom to hall"s, ""s, hall, bedroom, Directions::EAST);
	Exit* hallToOutdoor = new Exit("Hall to outdoor"s, ""s, hall, outdoor, Directions::NORTH);

	worldEntities.push_back(basementToRoom);
	worldEntities.push_back(roomToHall);
	worldEntities.push_back(hallToKitchen);
	worldEntities.push_back(hallToBedroom);
	worldEntities.push_back(hallToOutdoor);
	/*worldEntities.push_back(kitchenToHall);*/
	worldEntities.push_back(bedroomTOHall);

	//items
	Item* bag = new Item("Bag"s, "This is the backpack you had with you before you were attacked. Is there anything in it?", NULL, itemType::CONTAINER);
	Item* box = new Item("Box"s, "It is a cardboard box of what looks like a fruit store, or not... or of some juegutes... pff, you can't read it is very blurry. "s, NULL, itemType::CONTAINER);
	Item* peach = new Item("Peach"s, "Yellow, orange and juicy fruit."s, box, itemType::FOOD);
	Item* lowerKeyPart = new Item("Lower key part"s, "descripción"s, bag, itemType::SILVER_KEY);
	Item* albumRecipe = new Item("Album recipe"s, "descripción"s, NULL, itemType::CONTAINER);
	Item* trash = new Item("Trash"s, "descripción"s, NULL, itemType::CONTAINER);
	Item* fridge = new Item("Fridge"s, "descripción"s, NULL, itemType::CONTAINER);
	Item* cookies = new Item("Cookies"s, "descripción"s, albumRecipe, itemType::FOOD);
	Item* middleKeyPart = new Item("Middle Key part"s, "descripción"s, trash, itemType::SILVER_KEY);
	/*Item* firecracker = new Item("Firecrackers"s, "descripción"s, fridge, itemType::WEAPON);*/
	Item* upperKeyPart = new Item("Upper key part"s, "descripción"s, NULL, itemType::GOLD_KEY);

	worldEntities.push_back(bag);
	worldEntities.push_back(box);
	worldEntities.push_back(peach);
	worldEntities.push_back(lowerKeyPart);
	worldEntities.push_back(albumRecipe);
	worldEntities.push_back(trash);
	worldEntities.push_back(fridge);
	worldEntities.push_back(cookies);
	worldEntities.push_back(middleKeyPart);
	/*worldEntities.push_back(firecracker);*/
	worldEntities.push_back(upperKeyPart);

	list<string> keyRecipe;
	keyRecipe.push_back(lowerKeyPart->name);
	keyRecipe.push_back(middleKeyPart->name);
	keyRecipe.push_back(upperKeyPart->name);

	CraftItem* megaUltraKey = new CraftItem("Key"s, "Key hooked with adhesive tape able to open anything"s, NULL, itemType::megaUltraKey, keyRecipe);
	
	worldEntities.push_back(megaUltraKey);

	player = new Player("Player"s, "You have woken up in the basement of an old house after being attacked, will you be able to get out?"s, basement);
	/*Creature* slimeMonster = new Creature("Monster's name"s, "Descripción"s, basementRoom);
	Creature* bedMonster = new Creature("Monster's name"s, "Descripción"s, bedroom);*/
	
	worldEntities.push_back(player);
	/*worldEntities.push_back(bedMonster);
	worldEntities.push_back(slimeMonster);*/
	
	basement->addItem(bag);
	basement->addItem(box);
	basement->addItem(albumRecipe);
	basement->addItem(trash);
	basement->addItem(fridge);
	basement->addItem(upperKeyPart);

	printIntro();
	player->Look(NULL);

}

World::~World() {
	for (list<Entity*>::reverse_iterator rit = worldEntities.rbegin(); rit != worldEntities.rend(); ++rit) {
		delete* rit;
	}
	worldEntities.clear();

	for (Command* cm : commands) {
		delete cm;
	}
	commands.clear();
}

Actions World::Input(const string& input)
{
	Command* command;
	string args;
	stateMovement statemovement;
	bool found = false;

	if (input.size() == 0) {
		return Actions::NONE;
	}

	command = getCommand(input);

	if (command == NULL) {
		return Actions::NONE;
	}

	args = command->GetArguments(input);

	switch (command->actions) {
	case Actions::LOOK:
		if (args.empty()) {
			player->Look(NULL);
		}
		else {
			for (Entity* element : worldEntities) {
				if (compareString(args, element->name) && element->parent == NULL && element->type != entityType::EXIT) {
					player->Look(element);
					found = true;
					break;
				}
			}
			if (!found) {
				printMessage("This item does not exists.");
			}
		}
		break;
	case Actions::MOVE:
		if (args.empty()) {
			statemovement = player->Move(Directions::NOWHERE);
		}
		else {
			for (Directions directions : directionString) {
				if (compareString(args, directions)) {
					statemovement = player->Move(directions);
					found = true;
					break;
				}
			}
			if (!found) {
				printMessage("I didn't not understand where you want to go.");
				statemovement = stateMovement::IDLE;
			}
		}
		if (statemovement == stateMovement::STOP) {
			bool megaUltraKey = false;

			for (Entity* item : player->childEntities) {
				if (compareString(item->name, "Key")) {
					megaUltraKey = true;
				}
			}
			if (megaUltraKey == true) {
				printMessage("You get out of the house, you are free! You breathe again the clean air of the street and see clearly the blue sky.\n\n");
			}
			else {
				printMessage("You didn't manage to open the door, do you really think you got out?\n\n");
			}
			command->actions = Actions::END;
		}
		break;
	case Actions::PICK:
		if (args.empty()) {
			player->Pick(NULL);
		}
		else {
			for (Entity* element : worldEntities) {
				if (compareString(args, element->name) && element->parent == NULL && (element->type == entityType::ITEM)) {
					if (Item* item = dynamic_cast<Item*>(element)) {
						player->Pick(item);
						found = true;
						break;
					}
					else {
						printMessage("That's not an item you can take.");
					}
				}
			}
			if (!found) {
				printMessage("This item does not exists.");
			}
		}
		break;
	case Actions::DROP:
		if (args.empty()) {
			player->Drop(NULL);
		}
		else {
			for (Entity* element : player->childEntities) {
				if (compareString(args, element->name) && (element->type == entityType::ITEM)) {
					if (Item* item = dynamic_cast<Item*>(element)) {
						player->Drop(item);
						found = true;
						break;
					}
					else {
						printMessage("That's not an item you can drop.");
					}
				}
			}
			if (!found) {
				printMessage("This item doesn't exists.");
			}
		}
		break;
	case Actions::INVENTORY:
		player->Inventory();
		break;

		case Actions::OPEN:
			if (args.empty()) {
				player->Open(NULL);
			}
			else {
				for (Entity* element : worldEntities) {
					if (compareString(args, element->name) && element->parent == NULL && (element->type == entityType::ITEM)) {
						if (Item* item = dynamic_cast<Item*>(element)) {
							player->Open(item);
							found = true;
							break;
						}
						else {
							printMessage("You can't open that.");
						}
					}
				}
				if (!found) {
					printMessage("This item doesn't exists.");
				}
			}
			break;
		case Actions::SAVE:
			if (args.empty()) {
				player->Save(NULL, NULL);
			}
			else {
				Item* first = NULL;
				Item* second = NULL;
				for (Entity* element : worldEntities) {
					if (compareString(args.substr(0, element->name.size()), element->name) && element->parent == NULL && (element->type == entityType::ITEM)) {
						if (Item* item = dynamic_cast<Item*>(element)) {
							first = item;
							break;
						}
					}
				}
				if (first == NULL) {
					printMessage("You don't have that first item");
					break;
			}
			//Ignoring first item
			args.erase(0, first->name.size());
			//Ignoring " in "
			args.erase(0, 4);
			for (Entity* element : worldEntities) {
				if (compareString(args.substr(0, element->name.size()), element->name) && element->parent == NULL && (element->type == entityType::ITEM)) {
					if (Item* item = dynamic_cast<Item*>(element)) {
						second = item;
						break;
					}
				}
			}
			if (first != NULL && second != NULL) {
				player->Save(first, second);
			}
			else {
				printMessage("You don't have that container.");
			}
		}
		break;
		case Actions::CRAFT:
			if (args.empty()) {
				player->Craft(NULL);
			}
			else {
				for (Entity* element : worldEntities) {
					if (compareString(args, element->name) && (element->type == entityType::ITEM)) {
						if (CraftItem* item = dynamic_cast<CraftItem*>(element)) {
							player->Craft(item);
							found = true;
							break;
						}
						else {
							printMessage("This item can't be craft.");
						}
					}
				}
				if (!found) {
					printMessage("This item doesn't exists.");
				}
			}
			break;
	case Actions::HELP:
		player->Help();
		break;
	case Actions::QUIT:
		break;
	default:
		return Actions::NONE;
	}
	return command->actions;
}

Command* World::getCommand(const string& input) {
	Command* cmd = NULL;
	for (Command* command : commands) {
		if (command->IsCommand(input)) {
			cmd = command;
			break;
		}
	}
	return cmd;
}