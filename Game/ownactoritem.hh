#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH
#include <graphics/simpleactoritem.hh>


class OwnActorItem : public CourseSide::SimpleActorItem
{
public:
    OwnActorItem(int x, int y, int type);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int x_;
    int y_;
    int type_;

};
#endif // OWNACTORITEM_HH
