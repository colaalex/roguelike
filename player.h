#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QList>
#include <QVector>

#include "windows.h"


class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(const QVector<QVector<int> > &map, QObject *parent = 0);
    explicit Player(int x, int y, const QVector<QVector<int> > &map, QObject *parent=0);
    ~Player();

    int getRelX() const;
    int getRelY() const;

    void healthUp(int hp) {
        //may be called with items like boost, food etc.
        health = std::min(10, health + hp);
    }

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int relX, relY; //coordinates in relative scale (position on game map)
    void relToAbs(); //calculates absolute coordinates (position on scene)
    QVector<QVector<int> > map; //copy of map to check collision with wall

    int health; //health points from 1 to 10, if helath < 1, player dies
};

#endif // PLAYER_H
