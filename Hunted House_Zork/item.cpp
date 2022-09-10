#include "item.h"

Item::Item(const string name, const string description, entity* parent, const itemType iType) : entity(name, description, parent), iType(iType) {
	type = ITEM;
}

Item::~Item() {

}
bool Item::changeParent(entity* newParent) {
	if (parent != NULL) {
		parent->childEntities.remove(this);
	}

	parent = newParent;
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
	return true;

}