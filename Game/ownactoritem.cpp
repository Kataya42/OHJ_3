#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type) : CourseSide::SimpleActorItem(x,y,type)
{
    setPos(mapToParent(x_ % 100 , y_ % 100));
}

void OwnActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    QColor color(type_%256, type_%256, type_%256);
    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}


QRectF OwnActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH1, HEIGHT2);
}


void OwnActorItem::setCoord(int x, int y)
{
    setX( x % 100 );
    setY( y % 100 );
}

