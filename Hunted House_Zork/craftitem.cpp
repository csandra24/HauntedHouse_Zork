#include "craftitem.h"

CraftItem::CraftItem(const string name, const string description, Entity* parent, const itemType iType, const list<string> recipe) : Item(name, description, parent, iType), recipe(recipe)
{
}


CraftItem::~CraftItem()
{
}