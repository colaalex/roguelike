#include "food.h"

Food::Food(int x, int y) : Item(x, y, type) {}

Food::~Food() {}


void Food::interact(Player *player) {
    player->healthUp(2);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRect rect;
    rect.setRect(0, 0, 50, 50);
    painter->setBrush(Qt::green);
    painter->drawRect(rect);
}
