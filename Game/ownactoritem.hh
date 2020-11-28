#ifndef OWNACTORITEM_HH
#define OWNACTORITEM_HH

#include <QGraphicsPixmapItem>
#include <QGraphicsRotation>

const int PLAYERSIZE = 30; // max size for the objects (pxl)
const int BUSSIZE = 15;
const int STOPSIZE = 7;


enum Type {  // types of QgraphicsItems
    PLAYER = 0,
    BUS = 1,
    STOP = 2,
    ENEMY = 3
};

enum Rotation { // rotations for player
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

class OwnActorItem : public QGraphicsPixmapItem {
public:
    /**
     * @brief Constructor
     * @param x coordinate, y coordinate, type of the Item
     */
    OwnActorItem(int x, int y, int type);
    /**
     * @brief setSprite sets the pixmap for the Qgraphics item
     */
    void setSprite();
    /**
     * @brief rotateSprite sets between 4 different pixmap items
     * @param rot, the rotation to be selected
     */
    void rotateSprite(int rot);
    /**
     * @brief boundingRect sets the bounding rectangle
     * @return QRectF, the bounding rectangle to which the pixmaps can be set
     */
    QRectF boundingRect() const;
    /**
     * @brief setCoord sets the coordinates
     * @param x coordinate and y coordinate
     */
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;
};

#endif // OWNACTORITEM_HH
