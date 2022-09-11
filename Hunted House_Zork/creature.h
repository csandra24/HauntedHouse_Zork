#ifndef __Creature__
#define __Creature__

#include "entity.h"


using namespace std;

class Room;

class Creature :
	public Entity
{
public:
	Creature(const string name, const string description, Room* room);
	virtual ~Creature();
	Room* room;
};


#endif // !1__Creature__
