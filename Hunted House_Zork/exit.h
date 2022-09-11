#ifndef __Exit__
#define __Exit__

#include <string>
#include "globals.h"
#include "entity.h"

using namespace std;

class Room;

class Exit :
	public Entity
{
public:
	Room* origin;
	Room* destination;
	Directions directions;

	Exit(const string name, const string description, Room* origin, Room* destination, const Directions directions);
	virtual ~Exit();
};



#endif // !1__Exit__
