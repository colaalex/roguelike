#include "player.h"


Player::Player(const QVector<QVector<int> > &map, QObject *parent): QObject(parent), QGraphicsItem() {
    this->map = map;
    relX = 0;
    relY = 0;
    health = 5;
    ammo = 0;
}

Player::Player(int x, int y, const QVector<QVector<int> > &map, QObject *parent) : QObject(parent), QGraphicsItem()
{
    this->map = map;
    //used to spawn player at exact position
    relX = x;
    relY = y;
    health = 5;
    ammo = 0;
}

Player::~Player() {}

int Player::getRelX() const
{
    return relX;
}

int Player::getRelY() const
{
    return relY;
}

void Player::slotGameTimer()
{
    if (GetAsyncKeyState(VK_LEFT))
        if (relX > 0 && map.at(relX-1).at(relY) != 1)
            relX--;
    if (GetAsyncKeyState(VK_RIGHT))
        if (relX < 10 && map.at(relX+1).at(relY) != 1)
            relX++;
    if (GetAsyncKeyState(VK_UP))
        if (relY > 0 && map.at(relX).at(relY-1) != 1)
            relY--;
    if (GetAsyncKeyState(VK_DOWN))
        if (relY < 10 && map.at(relX).at(relY+1) != 1)
            relY++;
    if (GetAsyncKeyState(VK_SPACE))
        if (ammo > 0) {
            ammo--;
            emit signalShoot();
        }

    relToAbs();

    QList<QGraphicsItem*> foundItems = scene()->items(mapToScene(0, 0));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue; //we do nothing with player
        emit signalCheckItem(item);
    }

}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect;
    rect.setRect(0, 0, 50, 50);
    painter->setBrush(Qt::red);
    painter->drawRect(rect);
}

void Player::relToAbs()
{
    //while it's hardcoded let's consider game map is 10x10
    int absX = 50*relX;
    int absY = 50*relY;
    this->setX(absX);
    this->setY(absY);
}

