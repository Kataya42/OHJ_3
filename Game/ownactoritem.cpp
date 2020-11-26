#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_ , y_));
}


void OwnActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF bounds = boundingRect();


    int r;
    int b;
    int g;

    if (type_ == player){
        r = 255, g = 0, b = 0;
    } else if (type_ == bus){
        r = 0, g = 255, b = 0;
    } else {
         r = 0, g = 0, b = 255;
    }

    QColor color(r%256, g%256, b%256);
    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);

}


QRectF OwnActorItem::boundingRect() const
{

    if (type_ == player){
        return QRectF(0, 0, WIDTHPLAYER, HEIGHTPLAYER);
    } else if (type_ == bus){
        return QRectF(0, 0, WIDTHBUS, HEIGHTBUS);
    } else {
         return QRectF(0, 0, WIDTHSTOP, HEIGHTSTOP);
    }
}

void OwnActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

