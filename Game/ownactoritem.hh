#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH

#include <QGraphicsPixmapItem>
#include <QGraphicsRotation>

const int WIDTHPLAYER = 30;
const int HEIGHTPLAYER = 30;

const int WIDTHBUS = 15;
const int HEIGHTBUS = 15;

const int WIDTHSTOP = 7;
const int HEIGHTSTOP = 7;

enum Type {
    PLAYER = 0,
    BUS = 1,
    STOP = 2,
    ENEMY = 3
};

enum Rotation {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3

};

class OwnActorItem : public QGraphicsPixmapItem {
public:
    OwnActorItem(int x, int y, int type);
    void setSprite();
    void rotateSprite(int rot);
    QRectF boundingRect() const;
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;
};

#endif // OWNACTORITEM_HH
