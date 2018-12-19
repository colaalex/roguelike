#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item
{
public:
    explicit Weapon(int x, int y, ItemType type);
    ~Weapon();

    virtual void interact(Player *player) {}

    virtual void attack() {} //depending on whether weapon is melee or ranged

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {}
};

#endif // WEAPON_H
