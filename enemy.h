#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

#include "bullet.h"


class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Enemy(int hp, Direction direction, QObject *parent=nullptr);
    ~Enemy() {}

    Direction getDirection() {
        return direction;
    }

    void healthDown(int hp) {
        this->hp -= hp;
    }

protected:
    QRectF boundingRect() const {
        return QRectF(0, 0, 50, 50);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void slotGameTimer();

signals:
    void signalAttackPlayer(QGraphicsItem* item);
    void signalEnemyDies(Enemy* enemy);

private:
    int hp; //the same as for player (but it won't have ammo, it's unlimited)
    Direction direction;
};

#endif // ENEMY_H
