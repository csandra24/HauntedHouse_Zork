#ifndef __World__
#define __World__

#include "globals.h"
#include "entity.h"
#include "creature.h"
#include "player.h"
#include "exit.h"
#include "room.h"
#include "item.h"
#include "craftitem.h"

using namespace std;

class World {
public:
	World();
	virtual ~World();
	Actions Input(const string& input);
	Command * getCommand(const string& input);

private:
	Player* player;
	list<Command*> commands;
	list<Entity*> worldEntities;
};



#endif // !1__World__
