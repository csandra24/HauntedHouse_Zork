#ifndef __Player__
#define __Player__

#include <string>
#include <iostream>
#include "creature.h"
#include "globals.h"
#include "room.h"
#include "item.h"

using namespace std;
using namespace text;

enum stateMovement {
	IDLE,
	MOVING,
	STOP
};

class Player :
	public Creature
{
public:
	Player(const string name, const string description, Room *room);
	virtual ~Player();
	stateMovement MOVE(const Directions directions);
	bool Pick(Item* item);
	bool Drop(Item* item);
	bool Open(Item* item);
	bool Look(const entity* entity);
	bool Help();
	bool Save(Item* item);

	void Inventory();

private:

};



#endif // !1__Player__
