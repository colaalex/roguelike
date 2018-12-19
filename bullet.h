#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPainter>
#include <QGraphicsEllipseItem>

enum Direction {north, south, west, east};

class Bullet : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Bullet(double x, double y, Direction direction, QObject *parent=nullptr);
    ~Bullet();

    Direction getDirection() {
        return direction;
    }

protected:
    QRectF boundingRect() const {
        return QRectF(0, 0, 10, 10);
    }

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

private:
    double relX, relY;
    Direction direction;
};

#endif // BULLET_H
