#include "item.h"

Item::Item(int x, int y, ItemType type, QObject *parent) : QObject(parent)
{
    this->type = type;
    relX = x;
    relY = y;
}

Item::~Item() {}
