#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_ , y_));
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
    setX( x );
    setY( y );
}

