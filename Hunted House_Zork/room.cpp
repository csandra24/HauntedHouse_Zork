#include "room.h"
#include "exit.h"

using namespace text;

Room::Room(const string name, const string description) : Entity(name, description) {
	type = ROOM;
	childExits = {};
}

Room::~Room() 
{
}

bool Room::addExit(Exit* exit) {
	childExits.push_back(exit);
	return true;
}

bool Room::addItem(Item* item) {
	childEntities.push_back((Entity*)item);
	return true;
}

Room* Room::getRoom(const Directions directions) {
	Room* result = NULL;

	for (Exit* iter : childExits) {
		if (iter->origin == this && directions == iter->directions) {
			result = iter->destination;
			break;
		}
		else if (iter->destination == this && -directions == iter->directions) {
			result = iter->origin;
			break;
		}
	}

	return result;
}