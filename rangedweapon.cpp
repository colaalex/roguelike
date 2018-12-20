#include "rangedweapon.h"

RangedWeapon::RangedWeapon(int x, int y) : Weapon(x, y, type) {}
RangedWeapon::~RangedWeapon() {}

void RangedWeapon::interact(Player *player)
{
    player->ammoUp(5);
}

void RangedWeapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect;
    rect.setRect(0, 0, 50, 50);
    painter->setBrush(QImage("rweapon.png"));
    painter->drawRect(rect);
}
