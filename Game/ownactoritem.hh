#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH

#include <graphics/simpleactoritem.hh>
#include <QGraphicsPixmapItem>

const int WIDTHPLAYER = 30;
const int HEIGHTPLAYER = 30;

const int WIDTHBUS = 15;
const int HEIGHTBUS = 15;

const int WIDTHSTOP = 7;
const int HEIGHTSTOP = 7;

enum Type {
    PLAYER = 0,
    BUS = 1,
    STOP = 2,
    ENEMY = 3
};

class OwnActorItem : public QGraphicsPixmapItem {
public:
    OwnActorItem(int x, int y, int type);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;
};

#endif // OWNACTORITEM_HH
