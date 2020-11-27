#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type)
    : x_(x)
    , y_(y)
    , type_(type)
{
    setPos(mapToParent(x_, y_));
}

void OwnActorItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

    QRectF bounds = boundingRect();

    if (type_ == PLAYER) {
        painter->drawPixmap(bounds, QPixmap(":/images/images/oofo.png"), bounds);
    }
    else if (type_ == BUS) {
        painter->drawPixmap(bounds, QPixmap(":/images/images/bus.png"), bounds);
    }
    else if (type_ == STOP) {
        painter->drawPixmap(bounds, QPixmap(":/images/images/stop.png"), bounds);
    }
    else {
        painter->drawPixmap(bounds, QPixmap(":/images/images/fightUp.png"), bounds);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF OwnActorItem::boundingRect() const
{

    if (type_ == PLAYER) {
        return QRectF(0, 0, WIDTHPLAYER, HEIGHTPLAYER);
    }
    else if (type_ == BUS) {
        return QRectF(0, 0, WIDTHBUS, HEIGHTBUS);
    }
    else if (type_ == STOP) {
        return QRectF(0, 0, WIDTHSTOP, HEIGHTSTOP);
    }
    else {
        return QRectF(0, 0, WIDTHPLAYER, HEIGHTPLAYER);
    }
}

void OwnActorItem::setCoord(int x, int y)
{
    setX(x);
    setY(y);
}
