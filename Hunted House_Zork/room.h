#ifndef __Room__
#define __Room__

#include "globals.h"
#include "entity.h"

using namespace std;

class Room :
	public entity
{
public:
	Room(const string name, const string description);
	virtual ~Room();
	bool addExit(Exit* exit);
	bool addItem(Item* item);
	Room* getRoom(const Directions directions);

};


#endif // !1__Room__