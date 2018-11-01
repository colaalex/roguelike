#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QPair>

#include "windows.h"


class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    explicit Player(int x, int y, QObject *parent=0);
    ~Player();

    int getRelX();
    int getRelY();

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int relX, relY; //coordinates in relative scale (position on game map)
    void relToAbs(); //calculates absolute coordinates (position on scene)
};

#endif // PLAYER_H
