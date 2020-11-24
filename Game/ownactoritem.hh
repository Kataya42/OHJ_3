#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH
#include <graphics/simpleactoritem.hh>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>


const int WIDTH1 = 5;
const int HEIGHT2 = 5;

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
