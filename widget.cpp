#include "widget.h"
#include "ui_widget.h"
#include "world.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);

    scene = new QGraphicsScene();
    map = World().getMap();
    drawMap();
    player = new Player(map);

    auto food = new Food(3, 3); //add food to map, hardocoded
    items.append(food);

    auto weapon = new RangedWeapon(4, 4);
    items.append(weapon);

    auto enemy = new Enemy(5, Direction::east); //hardcoded enemy with 5 hp
    enemies.append(enemy);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->hpLabel->setText(QString("Health: %1").arg(player->getHealth()));
    ui->ammoLabel->setText(QString("Ammo: %1").arg(player->getAmmo()));


    scene->addItem(player);
    player->setPos(0,0);

    scene->addItem(food);
    food->setPos(300, 300);

    scene->addItem(weapon);
    weapon->setPos(400, 400);

    scene->addItem(enemy);
    enemy->setPos(150, 400);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, player, &Player::slotGameTimer);
    timer->start(100);

    bulletTimer = new QTimer();
    connect(bulletTimer, &QTimer::timeout, this, &Widget::slotMoveBullets);
    bulletTimer->start(100);

    enemyTimer = new QTimer();
    connect(enemyTimer, &QTimer::timeout, enemy, &Enemy::slotGameTimer);
    enemyTimer->start(1000); //every second it'll check for player in visible zone and try to shoot player

    connect(player, &Player::signalCheckItem, this, &Widget::slotDeleteItem);
    connect(player, &Player::signalShoot, this, &Widget::slotAddBullet);
    connect(enemy, &Enemy::signalAttackPlayer, this, &Widget::slotEnemyShoot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::drawMap()
{
    for (int i = 0; i < map.size(); i++)
        for (int j = 0; j < map.at(i).size(); j++) {
            switch (map.at(i).at(j)) {
            case 0: //simple path
                scene->addRect(50*i, 50*j, 50, 50, QPen(Qt::black));
                break;
            case 1: //wall
                scene->addRect(50*i, 50*j, 50, 50, QPen(Qt::black), QBrush(Qt::black));
                break;
            default:
                break;
            }
        }
}

QPair<int, int> Widget::absToRel(qreal x, qreal y)
{
    int i, j;
    i = int(x / 50);
    j = int(y / 50);
    return qMakePair(i, j);
}

void Widget::addBullet(Bullet *bullet)
{
    bullets.append(bullet);
    scene->addItem(bullet);
    bullet->setPos(bullet->x(), bullet->y());
    ui->ammoLabel->setText(QString("Ammo: %1").arg(player->getAmmo()));
}

void Widget::slotDeleteItem(QGraphicsItem *item)
{
    foreach(QGraphicsItem *it, items) {
        if (it == item) {
            if (static_cast<Item*>(it)->getType() == food)
                static_cast<Food*>(it)->interact(player);
            else if (static_cast<Item*>(it)->getType() == rangedWeapon)
                static_cast<RangedWeapon*>(it)->interact(player);
            scene->removeItem(it);
            items.removeOne(item);
            delete it;
            ui->hpLabel->setText(QString("Health: %1").arg(player->getHealth()));
            ui->ammoLabel->setText(QString("Ammo: %1").arg(player->getAmmo()));
        }
    }
}

void Widget::slotMoveBullets()
{
    foreach(Bullet *bullet, bullets) {
        if (bullet->getDirection() == Direction::east){
            bullet->setX(bullet->x() + 100); //just for test
        }
        else if (bullet->getDirection() == Direction::north) {
            bullet->setY(bullet->y() - 100);
        }
        else if (bullet->getDirection() == Direction::south) {
            bullet->setY(bullet->y() + 100);
        }
        else {
            bullet->setX(bullet->x() - 100);
        }

        if (bullet->x() > 550 || bullet->x() < 0 || bullet->y() > 550 || bullet->y() < 0) {
            scene->removeItem(bullet);
            bullets.removeOne(bullet);
            delete bullet;
        } else {
            QPair<int, int> absCor = absToRel(bullet->x(), bullet->y());
            if (map.at(absCor.first).at(absCor.second) == 1) {
                //if it collides with wall (tile)
                scene->removeItem(bullet);
                bullets.removeOne(bullet);
                delete bullet;
            } else
                bullet->setPos(bullet->x(), bullet->y());
        }
            //TODO add reaction
    }
}

void Widget::slotAddBullet()
{
    auto bullet = new Bullet(player->x()+25, player->y()+25, player->getDirection());
    addBullet(bullet);
    //+25 in each coordiante is used to spawn bullet in the middle of tile
}

void Widget::slotEnemyShoot(QGraphicsItem *item)
{
    if (item == player) {
        auto enemy = static_cast<Enemy*>(QObject::sender());
        auto bullet = new Bullet(enemy->x() + 25, enemy->y() + 25, enemy->getDirection());
        addBullet(bullet);
    }
}
