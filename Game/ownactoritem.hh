#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH
#include <graphics/simpleactoritem.hh>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>


const int WIDTHPLAYER = 30;
const int HEIGHTPLAYER = 30;

const int WIDTHBUS = 15;
const int HEIGHTBUS = 15;

const int WIDTHSTOP = 7;
const int HEIGHTSTOP = 7;

enum Type
{
    player = 0,
    bus = 1,
    stop = 2,
    enemy = 3
};

enum Direction
{
    up = 0,
    right = 1,
    down = 2
};

class OwnActorItem : public QGraphicsPixmapItem
{
public:

    OwnActorItem(int x, int y, int type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setCoord(int x, int y);
    void updatePicture(int dir);

private:
    int x_;
    int y_;
    int type_;


};


#endif // OWNACTORITEM_HH
