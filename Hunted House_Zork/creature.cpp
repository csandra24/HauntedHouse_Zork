#include <iostream>
#include "room.h"
#include "creature.h"


Creature::Creature(const string name, const string description, Room* room) :
	Entity(name, description), room(room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}