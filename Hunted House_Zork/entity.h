#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum entityType
{
	ENTITY,
	CREATURE,
	PLAYER,
	EXIT,
	ROOM,
	ITEM
};

class entity
{
public:
	entityType type;
	string name;
	string description;
	entity* parent;
	list<entity*> childEntities;

	entity(const string name, const string description, entity* parent);
	entity(const string name, const string description);
	virtual ~entity();

};


#endif // !1__Entity__
