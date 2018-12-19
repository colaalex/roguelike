#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include "player.h"
#include "item.h"
#include "food.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Player *player;
    QTimer *timer;
    QVector <QVector<int> > map;

    QList<QGraphicsItem*> items; //list of all items in game

    int health, ammo; //store hp and ammo of players to be shown on labels

    void drawMap();

private slots:
    void slotDeleteItem(QGraphicsItem *item);
};

#endif // WIDGET_H
