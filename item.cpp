#include "item.h"

Item::Item(ItemType type, QObject *parent) : QObject(parent)
{
    this->type = type;
}

Item::~Item()
{

}

