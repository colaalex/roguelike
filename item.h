#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsItem>

#include "player.h"

enum ItemType {food, medkit, weapon};

class Item : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
     Item(ItemType type, QObject *parent=nullptr);
    ~Item();

    ItemType getType() {
        return type;
    }

    virtual void interact(Player *player) {} //add health or ammo, depends on type

protected:
    QRectF boundingRect() const {
        return QRectF(0, 0, 50, 50);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {}

    int relX, relY; //coordinates in relative scale (position on game map)

    ItemType type;
};

#endif // ITEM_H
