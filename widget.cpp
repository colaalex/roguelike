#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);

    scene = new QGraphicsScene();
    player = new Player();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(35, 35, 500, 500); //

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
