#include "enemy.h"

Enemy::Enemy(int hp, Direction direction, QObject *parent) :QObject (parent)
{
    this->hp = hp;
    this->direction = direction;
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect;
    rect.setRect(0, 0, 50, 50);
    painter->setBrush(Qt::yellow);
    painter->drawRect(rect);
}

void Enemy::slotGameTimer()
{
    QPolygonF polygon;
    polygon << mapToScene(0, 0) << mapToScene(0, -300) << mapToScene(0, 300) << mapToScene(300, 0) << mapToScene(-300, 0);

    QList<QGraphicsItem*> items = scene()->items(polygon);

    foreach(QGraphicsItem* item, items) {
        if (item == this)
            continue;
        emit signalAttackPlayer(item);
    }
}
