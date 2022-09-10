#include "player.h"

/*Player::Player(const string name, const string description, room* room)
{
	type = PLAYER;
}*/

Player::Player(const string name, const string description, Room* room) : Creature(name, description, room)
{
	type = PLAYER;
}

Player::~Player(){}

stateMovement Player::MOVE(const Directions directions) {

	if (directions == NOWHERE) {
		printMessage("NO SABE DONDE IR UWU");
		return IDLE;
	}

	Room* nextRoom = room->getRoom(directions);
	if (nextRoom != NULL) {
		room = nextRoom;
		Look(NULL);
		if (compareString(room->name, "Name final room")) {
			return STOP;
		}

		else {
			return MOVING;
		}
		
	}
	printMessage("");
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
		room->childEntities.remove((entity*)item);
		childEntities.push_back((entity*)item);
		printMessage(item->name + "taken."s);
	}
	else {
		printMessage(item->name + " not found in this room."s);
	}
	return found;
}

bool Player::Drop(Item* item) {
	if (item == NULL) {
		printMessage("Ups, you didn't say what you want to drop.");
		return false;
	}
	bool found = false;
	for (entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			if (item->iType != STATIC) {
				found = true;
				break;
			}
		}
	}
	if (found) {
		childEntities.remove((entity*)item);
		room->childEntities.push_back((entity*)item);
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
		for (entity* iter : childEntities) {
			printMessage("-" + iter->name);
		}
	}
	else {
		printMessage("Your inventory is empty");
	}
}