#ifndef __Room__
#define __Room__

#include "globals.h"
#include "entity.h"

using namespace std;

class Exit;
class Item;

class Room :
	public Entity
{
public:
	list<Exit*> childExits;
	Room(const string name, const string description);
	virtual ~Room();
	bool addExit(Exit* exit);
	bool addItem(Item* item);
	Room* getRoom(const Directions directions);

};


#endif // !1__Room__