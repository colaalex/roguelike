#ifndef ITEM_H
#define ITEM_H

enum ItemType {food, medkit, boost};

class Item
{
public:
    Item();

protected:
    int relX, relY; //coordinates in relative scale (position on game map)
};

#endif // ITEM_H
