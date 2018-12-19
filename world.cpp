#include "world.h"

World::World()
{
    //yep, again hardcode, map is 11x11
    for (int i = 0; i < 11; i++) {
        map.append(QVector<int>());
        for (int j = 0; j < 11; j++) map[i].append(0); //0 - simple path
    }
    //add a few wall blocks to check interaction
    for (int i = 0; i < 7; i++) map[i][5] = 1; //1 - wall
}

QVector<QVector<int> > World::getMap() const
{
    return map;
}
