#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum class entityType
{
	ENTITY,
	CREATURE,
	PLAYER,
	EXIT,
	ROOM,
	ITEM
};

class Entity
{
public:
	entityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> childEntities;

	Entity(const string name, const string description, Entity* parent);
	Entity(const string name, const string description);
	virtual ~Entity();

};


#endif // !1__Entity__
