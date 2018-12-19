#include "bullet.h"


Bullet::Bullet(double x, double y, Direction direction, QObject *parent) : QObject (parent)
{
    relX = x;
    relY = y;
    this->direction = direction;
}

Bullet::~Bullet() {}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect;
    rect.setRect(0, 0, 10, 10);
    painter->setBrush(Qt::black);
    painter->drawRect(rect);
}
