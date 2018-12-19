#ifndef FOOD_H
#define FOOD_H

#include "item.h"


class Food : public Item
{
public:
    explicit Food(int x, int y);
    ~Food();

    void interact(Player *player);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    static const ItemType type = food;
};

#endif // FOOD_H
