#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type)
    : x_(x)
    , y_(y)
    , type_(type)
{
    setPos(mapToParent(x_, y_));
}

void OwnActorItem::setSprite()
{
    if (type_ == PLAYER) {
        this->setPixmap(QPixmap(":/images/images/oofo.png"));
    }
    else if (type_ == BUS) {
        this->setPixmap(QPixmap(":/images/images/bus.png"));
    }
    else if (type_ == STOP) {
     this->setPixmap(QPixmap(":/images/images/stop.png"));
    }
    else if (type_ == ENEMY){
       this->setPixmap(QPixmap(":/images/images/fightUp.png"));
    }
    update();
}

void OwnActorItem::rotateSprite(int rot)
{
    if (rot == UP) {
        this->setPixmap(QPixmap(":/images/images/fightUp.png"));
    }
    else if (rot == DOWN) {
        this->setPixmap(QPixmap(":/images/images/fightDown.png"));
    }
    else if (rot == LEFT) {
        this->setPixmap(QPixmap(":/images/images/fightLeft.png"));
    }
    else if (rot == RIGHT){
        this->setPixmap(QPixmap(":/images/images/fightRight.png"));
    }
    update();

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
