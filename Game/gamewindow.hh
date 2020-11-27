#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "interfaces/icity.hh"
#include "ownactoritem.hh"
#include "manse.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QTimer>
#include <QWidget>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <string>
#include <QString>
#include <core/logic.hh>
#include <QDebug>
#include <QKeyEvent>
#include <statistics.hh>
#include <QPainter>

namespace Ui {
class SimpleGameWindow;
}


class GameWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit GameWindow(QWidget *parent = 0);
    virtual ~GameWindow();
    /**
     * @brief setSize sets size of game window
     * @param w width
     * @param h height
     */
    void setSize(int w, int h);
    /**
     * @brief setTick sets game tickrate
     * @param t tickrate in milliseconds
     */
    void setTick(int t);

    virtual void addActor(int locX, int locY, int type = 0);
    /**
     * @brief setPicture sets background image for game
     * @param img to set as game backgorund
     */
    void setPicture(QImage &img);
    bool takeCity(std::shared_ptr<Manse> city);
    /**
     * @brief drawBuses adds buses to scene
     * @pre map contains buses
     * @post buses are added to scene
     */
    void drawBuses();
    /**
     * @brief drawPlayer adds player to scene
     * @pre map contains player
     * @post player added to scene
     */
    void drawPlayer();
    /**
     * @brief drawEnemy adds enemy to scene
     * @pre map contains enemy
     * @post enemy added to scene
     */
    void drawEnemy();
    /**
     * @brief drawStops adds stops to scene
     * @pre map contains stops
     * @post stops are added to scene
     */
    void drawStops();
    void takeStats(Statistics gameStats);
    void increaseScore();
    void getLogic(std::shared_ptr<CourseSide::Logic> l);


signals:
    void gameStarted();
    void keyCaught(QKeyEvent *e);
    void move(int dir);

private slots:
    void on_startButton_clicked();
    void updateCoords();
    void advance();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    Ui::SimpleGameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QTimer *scoreTimer;
    QTimer *modTimer;
    QVector<OwnActorItem*> actors_;
    OwnActorItem* last_;
    OwnActorItem* playerActor_;
    OwnActorItem* enemyActor_;
    std::shared_ptr<Manse> city_;

    Statistics gameStats_;
    std::shared_ptr<CourseSide::Logic> gamelogic_;


    void gameEnd();
    int playerDirHorizontal_;
    int playerDirVertical_;
    int enemyDirHorizontal_;
    int enemyDirVertical_;
    std::vector<std::shared_ptr<Interface::IActor>> nearbyStuff_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 100; //ms
    int scoreTick_ = 300;
    int score_ = 0;
    int life_ = 0;
    bool enemyPlayerControlled = false;
};

 //namespace
#endif // GameWindow_HH
