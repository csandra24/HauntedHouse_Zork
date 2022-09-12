#ifndef __Player__
#define __Player__

#include <string>
#include <iostream>
#include "creature.h"
#include "globals.h"
#include "room.h"
#include "item.h"

using namespace std;
/*using namespace text;*/

enum class stateMovement {
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
	stateMovement Move(const Directions directions);
	bool Pick(Item* item);
	bool Drop(Item* item);
	bool Open(Item* item);
	bool Help();
	bool Save(Item* item, Item* container);
	bool Look(const Entity* entity);
	void Inventory();

};



#endif // !1__Player__
