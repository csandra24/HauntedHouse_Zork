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

/*bool Player::Look(const entity* entity) {

}*/

void Player::Inventory() {
	if (childEntities.empty() == false)  {
		printMessage("Bag:");
			for (entity* iter : childEntities) {
				printMessage("- " + iter->name);
			}
	}
}

bool Player::Help() {
	printHelp();
	return true;
}