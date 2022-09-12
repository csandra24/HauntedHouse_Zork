#include "player.h"

using namespace text;

Player::Player(const string name, const string description, Room* room) : Creature(name, description, room)
{
	type = entityType::PLAYER;
}

Player::~Player(){}

stateMovement Player::Move(const Directions directions) {

	if (directions == Directions::NOWHERE) {
		printMessage("NO SABE DONDE IR UWU");
		return stateMovement::IDLE;
	}

	Room* nextRoom = room->getRoom(directions);
	if (nextRoom != NULL) {
		room = nextRoom;
		Look(NULL);
		if (compareString(room->name, "Name final room (criatura)")) {
			return stateMovement::STOP;
		}

		else {
			return stateMovement::MOVING;
		}
		
	}
	printMessage("You can't go that way.");
	return stateMovement::IDLE;

}


bool Player::Help() {
	printHelp();
	return true;
}

//Actions

bool Player::Pick(Item* item) {
	if (item == NULL) {
		printMessage("You didn't say what you want to take.");
		return false;
	}
	bool found = false;
	for (Entity* iter : room->childEntities) {
		if (compareString(iter->name, item->name)) {
			if (item->iType != itemType::STATIC) {
				found = true;
				break;
			}
			else {
				printMessage("You can't take that!");
				return false;
			}
		}
	}
	if (found) {
		room->childEntities.remove((Entity*)item);
		childEntities.push_back((Entity*)item);
		printMessage(item->name + " taken."s);
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
			if (item->iType != itemType::STATIC) {
				found = true;
				break;
			}
		}
	}
	if (found) {
		childEntities.remove((Entity*)item);
		room->childEntities.push_back((Entity*)item);
		printMessage(item->name + " dropped."s);
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
		if (item->iType == itemType::CONTAINER) {
			if (item->childEntities.empty() == false) {
				printMessage("You open the "s + item->name + " and all of its content is added to your inventory.");
				for (Entity* contained : item->childEntities) {
					printMessage(contained->name);
					contained->parent = NULL;
					childEntities.push_back(contained);
				}
				item->childEntities.clear();
			}
			else {
				printMessage("The +" + item->name + " is empty.");
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
		else if (compareString(iter->name, container->name) && container->iType == itemType::CONTAINER) {
			containerFound = true;
		}
	}
	if (itemFound && containerFound) {
		item->changeParent(container);
		childEntities.remove(item);
		printMessage("Now "s + item->name + " is inside the "s + container->name + ".");
	}
	else {
		printMessage("You don't have both items."s);
	}
	return false;
}

bool Player::Look(const Entity* entity) {
	bool found = false;
	if (entity == NULL) {
		printMessage(room->name, room->description);
		if (room->childEntities.empty() == false) {
			printMessage("In this place you can see:");
			for (Entity* object : room->childEntities) {
				string obj = object->name;
				obj[0] = (char)tolower(object->name[0]);
				printMessage("A " + obj);
			}
		}
		return true;
	}
	else if (compareString(entity->name, "player"s)) {
		printMessage(description);
		return true;
	}
	else {
		for (Entity* iter : childEntities) {
			if (compareString(iter->name, entity->name)) {
				found = true;
				break;
			}
		}
		if (!found) {
			for (Entity* iter : room->childEntities) {
				if (compareString(iter->name, entity->name)) {
					found = true;
					break;
				}
			}
		}
	}
	if (found) {
		printMessage(entity->description);
	}
	else {
		printMessage("That's not something you can find in this room nor in your inventory."s);
	}
	return found;
}

bool Player::Craft(CraftItem* craftItem) {
	if (craftItem == NULL) {
		printMessage("Ups, you didn't mention what you want to craft.");
		return false;
	}
	bool found;
	bool crafted = true;
	list<Item*> foundItems;

	for (string itemName : craftItem->recipe) {
		found = false;
		for (Entity* entity : childEntities) {
			if (compareString(entity->name, itemName)) {
				found = true;
				foundItems.push_back((Item*)entity);
				break;
			}
		}
		if (!found) {
			crafted = false;
			printMessage("keep looking, you haven't found everything you need.");
			break;
		}
	}

	if (crafted) {
		for (Item* item : foundItems) {
			childEntities.remove(item);
		}
		childEntities.push_back(craftItem);
		string message = craftItem->name + "crafted."s;
		printMessage(message);
	}
	return crafted;
}

