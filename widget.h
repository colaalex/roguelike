#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include "player.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Player *player;
    QTimer *timer;
    QVector <QVector<int> > map;

    void drawMap();
};

#endif // WIDGET_H
