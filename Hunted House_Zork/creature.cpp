#include <iostream>
#include "room.h"
#include "creature.h"

//Github test
Creature::Creature(const string name, const string description, Room* room) :
	entity(name, description), room(room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}