#include <iostream>
#include "entity.h"

entity::entity(const string name, const string description, entity* parent) :
	name(name), description(description), parent(parent) 
{
	type = ENTITY;
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
}

entity::entity(const string name, const string description) : entity(name, description, NULL) {
	type: ENTITY;
}

entity::~entity() {
	if (parent != NULL) {
		parent->childEntities.remove(this);
	}
}

