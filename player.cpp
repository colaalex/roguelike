#include "player.h"

Player::Player(QObject *parent) : QObject(parent), QGraphicsItem() {
    relX = 0;
    relY = 0;
}

Player::Player(int x, int y, QObject *parent) : QObject(parent), QGraphicsItem()
{
    //used to spawn player at exact position
    relX = x;
    relY = y;
}

Player::~Player() {}

int Player::getRelX()
{
    return relX;
}

int Player::getRelY()
{
    return relY;
}

void Player::slotGameTimer()
{
    if (GetAsyncKeyState(VK_LEFT)) relX--;
    if (GetAsyncKeyState(VK_RIGHT)) relX++;
    if (GetAsyncKeyState(VK_UP)) relY--;
    if (GetAsyncKeyState(VK_DOWN)) relY++;

    if (relX < 0) relX = 0;
    if (relX > 10) relX = 10;
    if (relY < 0) relY = 0;
    if (relY > 10) relY = 10;

    relToAbs();

//    if (this->x() - 10 < -250) this->setX(-240);
//    if (this->x() + 10 > 250) this->setX(240);
//    if (this->y() - 10 < -250) this->setY(-240);
//    if (this->y() + 10 > 250) this->setY(240);
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

