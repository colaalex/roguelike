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

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene->setSceneRect(35, 35, 500, 500);

    scene->addItem(player);
    player->setPos(0,0);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, player, &Player::slotGameTimer);
    timer->start(100);

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
