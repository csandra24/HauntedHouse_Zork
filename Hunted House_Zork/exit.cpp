#include "exit.h"
#include "room.h"

Exit::Exit(const string name, const string description, Room* origin, Room* destination, const Directions directions) :
	Entity(name, description), directions(directions), origin(origin), destination(destination) 
{
	type = EXIT;
	origin->addExit(this);
	destination->addExit(this);
}

Exit::~Exit() {

}
