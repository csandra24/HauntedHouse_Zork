#include "item.h"

Item::Item(const string name, const string description, Entity* parent, const itemType iType) : Entity(name, description, parent), iType(iType) {
	type = entityType::ITEM;
}

Item::~Item() {

}
bool Item::changeParent(Entity* newParent) {
	if (parent != NULL) {
		parent->childEntities.remove(this);
	}

	parent = newParent;
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
	return true;

}