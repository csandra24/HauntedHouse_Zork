#ifndef __Item__
#define __Item__

#include "room.h"
#include "entity.h"

using namespace std;

enum class itemType { 
	STATIC,
	SILVER_KEY,
	GOLD_KEY,
	megaUltraKey,
	FOOD,
	//WEAPON,
	CONTAINER

};

class Item :
	public Entity
{
public:
	Item(const string name, const string description, Entity* parent, const itemType iType);
	virtual ~Item();
	bool changeParent(Entity* newParent);
	itemType iType;

};




#endif // !1__Item__