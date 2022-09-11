#include "player.h"

using namespace text;

Player::Player(const string name, const string description, Room* room) : Creature(name, description, room)
{
	type = PLAYER;
}

Player::~Player(){}

stateMovement Player::Move(const Directions directions) {

	if (directions == NOWHERE) {
		printMessage("NO SABE DONDE IR UWU");
		return IDLE;
	}

	Room* nextRoom = room->getRoom(directions);
	if (nextRoom != NULL) {
		room = nextRoom;
		if (compareString(room->name, "Name final room (criatura)")) {
			return STOP;
		}

		else {
			return MOVING;
		}
		
	}
	printMessage("You can't go that way.");
	return IDLE;

}


bool Player::Help() {
	printHelp();
	return true;
}

//Actions

bool Player::Pick(Item* item) {
	if (item == NULL) {
		printMessage("Ups, you didn't say what you want to pick.");
		return false;
	}

	bool found = false;
	if (found)
	{
		room->childEntities.remove((Entity*)item);
		childEntities.push_back((Entity*)item);
		printMessage(item->name + "taken."s);
	}
	else {
		printMessage(item->name + " not found in this room."s);
	}
	return found;
}

bool Player::Drop(Item* item) {
	if (item == NULL) {
		printMessage("Ups, you didn't explain what you want to drop.");
		return false;
	}
	bool found = false;
	for (Entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			if (item->iType != STATIC) {
				found = true;
				break;
			}
		}
	}
	if (found) {
		childEntities.remove((Entity*)item);
		room->childEntities.push_back((Entity*)item);
		printMessage(item->name + "dropped."s);
	}
	else {
		printMessage("You don't have that item."s);
	}
	return found;
}

void Player::Inventory() {
	if (childEntities.empty() == false) {
		printMessage("Inventory:");
		for (Entity* iter : childEntities) {
			printMessage("- " + iter->name);
		}
	}
	else {
		printMessage("Your inventory is empty.");
	}
}

bool Player::Open(Item* item) {

	bool found = false;
	if (item == NULL) {
		printMessage("Ups, you didn't mention what you want to open.");
		return false;
	}
	for (Entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			found = true;
			break;
		}
	}
	if (found) {
		if (item->iType == BAG) {
			if (item->childEntities.empty() == false) {
				printMessage("You open the "s + item->name);
				for (Entity* contained : item->childEntities) {
					printMessage(contained->name);
					contained->parent = NULL;
					childEntities.push_back(contained);
				}
				item->childEntities.clear();
			}
			else {
				printMessage("The +" + item->name + "is empty.");
			}
		}
		else {
			printMessage("You could not open that."s);
		}
	}
	else {
		printMessage("That's not in your inventory."s);
	}
	return found;
}

bool Player::Save(Item* item, Item* container) {
	bool itemFound = false;
	bool containerFound = false;
	if ((item == NULL) || (container == NULL)) {
		printMessage("Sorry, I didn't understand you.");
		return false;
	}
	for (Entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			itemFound = true;
		}
		else if (compareString(iter->name, container->name) && container->iType == BAG) {
			containerFound = true;
		}
	}
	if (itemFound && containerFound) {
		item->changeParent(container);
		childEntities.remove(item);
		printMessage("Now "s + item->name + "is inside the "s + container->name + ".");
	}
	else {
		printMessage("You don't have both items."s);
	}
	return false;
}

