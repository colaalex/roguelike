#ifndef WORLD_H
#define WORLD_H

#include <QVector>


class World
{
public:
    World();
    QVector <QVector<int> > getMap() const;
    //for now map is generated in constructor but it should be read from file

private:
    QVector <QVector<int> > map;
    //void readMap(); //to be called from constructor
};

#endif // WORLD_H
