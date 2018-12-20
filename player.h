#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QVector>

#include "windows.h"
#include "bullet.h"


class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(const QVector<QVector<int> > &map, QObject *parent=nullptr);
    explicit Player(int x, int y, const QVector<QVector<int> > &map, QObject *parent=nullptr);
    ~Player();

    int getRelX() const;
    int getRelY() const;

    void healthUp(int hp) {
        //may be called with items like medkit, food etc.
        health = std::min(10, health + hp);
    }

    void ammoUp(int amount) {
        ammo = std::min(100, ammo + amount);
    }

    int getHealth() {
        return health;
    }

    int getAmmo() {
        return ammo;
    }

    Direction getDirection() {
        return direction;
    }

public slots:
    void slotGameTimer();

signals:
    void signalCheckItem(QGraphicsItem *item);
    void signalShoot();
    void signalGameOver();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int relX, relY; //coordinates in relative scale (position on game map)
    void relToAbs(); //calculates absolute coordinates (position on scene)
    QVector<QVector<int> > map; //copy of map to check collision with wall (and interaction with items)

    int health; //health points from 1 to 10, if helath < 1, player dies
    int ammo; //amount of ammo, if ammo < 1, player can't shoot

    Direction direction;
};

#endif // PLAYER_H
