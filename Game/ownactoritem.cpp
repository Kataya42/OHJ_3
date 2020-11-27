#include "ownactoritem.hh"

OwnActorItem::OwnActorItem(int x, int y, int type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_ , y_));
}

void OwnActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF bounds = boundingRect();


//    int r;
//    int b;
//    int g;

    if (type_ == player){
       // painter->drawPixmap(bounds,QPixmap(":/images/images/fightUp.png"),bounds);
       // painter->drawPixmap(bounds,QPixmap(":/images/images/fightDown.png"),bounds);
       // painter->drawPixmap(bounds,QPixmap(":/images/images/fightLeft.png"),bounds);
        painter->drawPixmap(bounds,QPixmap(":/images/images/oofo.png"),bounds);
    } else if (type_ == bus){
        painter->drawPixmap(bounds,QPixmap(":/images/images/bus.png"),bounds);
    } else if (type_ == stop){
         painter->drawPixmap(bounds,QPixmap(":/images/images/stop.png"),bounds);
    } else {
        painter->drawPixmap(bounds,QPixmap(":/images/images/fightUp.png"),bounds);
    }


     //  painter->drawPixmap(bounds,QPixmap(":/images/ufo.png"),bounds);
      Q_UNUSED(option);
      Q_UNUSED(widget);

//    QColor color(r%256, g%256, b%256);
//    QBrush brush(color);
//    painter->setBrush(brush);
//    painter->drawEllipse(bounds);

}


QRectF OwnActorItem::boundingRect() const
{

    if (type_ == player){
        return QRectF(0, 0, WIDTHPLAYER, HEIGHTPLAYER);
    } else if (type_ == bus){
        return QRectF(0, 0, WIDTHBUS, HEIGHTBUS);
    } else if (type_ == stop){
         return QRectF(0, 0, WIDTHSTOP, HEIGHTSTOP);
    } else {
        return QRectF(0,0,WIDTHPLAYER,HEIGHTPLAYER);
    }
}

void OwnActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

void OwnActorItem::updatePicture( int dir)
{



    //scene->addPixmap(pix);

    if (dir ==0){
      //  paint->drawPixmap(":/images/images/oofo.png")):
    } else if (dir == 1){
         setPixmap(QPixmap(":/images/images/fightRight.png"));
    } else if (dir == 2){
         setPixmap(QPixmap(":/images/images/fightRight.png"));
    } else {
         setPixmap(QPixmap(":/images/images/fightRight.png"));
    }

}

