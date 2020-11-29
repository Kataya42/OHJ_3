#include "ownactoritem.hh"
#include "errors/gameerror.hh"

OwnActorItem::OwnActorItem(int x, int y, int type)
    : x_(x)
    , y_(y)
    , type_(type)
{
    setPos(mapToParent(x_, y_));
    if (type_ > 3 or type_ < 0) {
        type_ = BUS;
        throw Interface::GameError("Invalid type!");
    }
}

void OwnActorItem::setSprite()
{
    // depending on the type, set the corresponding pixmap
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

    // depending on the rotation, set the corresponding pixmap
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

    // depending on the type, sets the corresponding bounding rectangle
    if (type_ == PLAYER) {
        return QRectF(0, 0, PLAYERSIZE, PLAYERSIZE);
    }
    else if (type_ == BUS) {
        return QRectF(0, 0, BUSSIZE, BUSSIZE);
    }
    else if (type_ == STOP) {
        return QRectF(0, 0, STOPSIZE, STOPSIZE);
    }
    else  {
        return QRectF(0, 0, PLAYERSIZE, PLAYERSIZE);
    }
}

void OwnActorItem::setCoord(int x, int y)
{
    setX(x);
    setY(y);
}
