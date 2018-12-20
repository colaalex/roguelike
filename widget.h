#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QMessageBox>

#include "player.h"
#include "item.h"
#include "food.h"
#include "rangedweapon.h"
#include "bullet.h"
#include "enemy.h"

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
    QTimer *bulletTimer;
    QTimer *enemyTimer;
    QVector <QVector<int> > map;

    QList<Bullet*> bullets; //list of bullets to move them when timer says
    QList<Enemy*> enemies; //list of enemies (behave like turrets)

    QList<QGraphicsItem*> items; //list of all items in game

    int health, ammo; //store hp and ammo of players to be shown on labels

    void drawMap();

    QPair<int, int> absToRel(qreal x, qreal y);

    void addBullet(Bullet *bullet);

private slots:
    void slotDeleteItem(QGraphicsItem *item);
    void slotMoveBullets();
    void slotAddBullet();
    void slotEnemyShoot(QGraphicsItem *item);
    void slotEnemyDies(Enemy *enemy);
    void slotGameOver();
};

#endif // WIDGET_H
