#ifndef __Craftitem__
#define __Craftitem__

#include "item.h"

class CraftItem :
	public Item 
{
public:
	list<string> recipe;
	CraftItem(const string name, const string description, Entity* parent, const itemType iType, const list<string> recipe);
	virtual ~CraftItem();
};

#endif