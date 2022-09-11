#include <iostream>
#include "entity.h"

Entity::Entity(const string name, const string description, Entity* parent) :
	name(name), description(description), parent(parent) 
{
	type = ENTITY;
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
}

Entity::Entity(const string name, const string description) : Entity(name, description, NULL) {
	type: ENTITY;
}

Entity::~Entity() {
	if (parent != NULL) {
		parent->childEntities.remove(this);
	}
}

