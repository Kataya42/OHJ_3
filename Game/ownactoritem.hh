#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH
#include <graphics/simpleactoritem.hh>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>


const int WIDTHPLAYER = 15;
const int HEIGHTPLAYER = 15;

const int WIDTHBUS = 10;
const int HEIGHTBUS = 10;

const int WIDTHSTOP = 5;
const int HEIGHTSTOP = 5;

enum Type
{
    player = 0,
    bus = 1,
    stop = 2
};


class OwnActorItem : public QGraphicsItem
{
public:
    OwnActorItem(int x, int y, int type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;

};


#endif // OWNACTORITEM_HH
