#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "weapon.h"
#include "item.h"
#include "player.h"


class RangedWeapon : public Weapon
{
public:
    explicit RangedWeapon(int x, int y);
    ~RangedWeapon();

    void interact(Player *player);

    void attack() {} //it will generate bullet object

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    static const ItemType type = rangedWeapon;
};

#endif // RANGEDWEAPON_H
