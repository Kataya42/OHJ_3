#include "ownactoritem.hh"

OwnActorItem::OwnActorItem() : CourseSide::SimpleActorItem(int x, int y, int type)
{
    setPos(mapToParent(x_ % 100, y_ % 100));
}


void OwnActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    QColor color(type_%256, type_%256, type_%256);
    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}
