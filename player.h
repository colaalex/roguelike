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

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int relX, relY; //coordinates in relative scale (position on game map)
    void relToAbs(); //calculates absolute coordinates (position on scene)
    QVector<QVector<int> > map; //copy of map to check collision with wall
};

#endif // PLAYER_H
