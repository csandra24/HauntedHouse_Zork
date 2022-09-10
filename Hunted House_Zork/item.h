#ifndef __Item__
#define __Item__

#include "room.h"
#include "entity.h"

using namespace std;

enum itemType {
	STATIC,
	SILVER_KEY,
	GOLD_KEY,
	FOOD,
	WEAPON,
	BAG

};

class Item :
	public entity
{
public:
	Item(const string name, const string description, entity* parent, const itemType iType);
	virtual ~Item();
	bool changeParent(entity* newParent);
	itemType iType;

};




#endif // !1__Item__