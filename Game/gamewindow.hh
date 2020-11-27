#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>

#include "ownactoritem.hh"
#include "manse.h"
#include <core/logic.hh>
#include <statistics.hh>
#include <startdialog.hh>

const int WIDTH = 1095; //pxl
const int HEIGHT = 592;
const int TICK = 100; //ms
const int DIFFICULTY = 3; // multiplier for score gain over time
const int PADDING = 10;
const int X_OFFSET = 350;
const int Y_OFFSET1 = 550;
const int Y_OFFSET2 = 0;
const int DANGER_RADIUS  = 15; // how close enemy needs to be to player


namespace Ui {
class SimpleGameWindow;
}

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = 0);
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
    /**
     * @brief
     * @pre
     * @post
     */
    virtual void addActor(int locX, int locY, int type = 0);
    /**
     * @brief setPicture sets background image for game
     * @param img to set as game backgorund
     */
    void setPicture(QImage& img);
    /**
     * @brief
     * @pre
     * @post
     */
    bool takeCity(std::shared_ptr<Manse> city);

    void drawBuses();

    void drawPlayer();

    void drawEnemy();

    void drawStops();

    void takeStats(Statistics gameStats);

    void increaseScore();

    void getLogic(std::shared_ptr<CourseSide::Logic> l);

    void getDialog(StartDialog* dia);

signals:
    void gameStarted();
    void keyCaught(QKeyEvent* e);
    void move(int dir);

private slots:
    void on_startButton_clicked();
    void updateCoords();
    void advance();
    void setPlayertwo(bool x);

protected:
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);

private:
    Ui::SimpleGameWindow* ui;
    QGraphicsScene* map;
    QTimer* timer;
    QTimer* scoreTimer;
    QTimer* modTimer;
    QVector<OwnActorItem*> actors_;
    OwnActorItem* last_;
    OwnActorItem* playerActor_;
    OwnActorItem* enemyActor_;
    std::shared_ptr<Manse> city_;
    StartDialog* dialog_;
    Statistics gameStats_;
    std::shared_ptr<CourseSide::Logic> gamelogic_;
    std::vector<std::shared_ptr<Interface::IActor> > nearbyStuff_;
    void gameEnd();
    int playerDirHorizontal_ = 0;
    int playerDirVertical_ = 0;
    int enemyDirHorizontal_;
    int enemyDirVertical_;
    bool enemyPlayerControlled = false;
};

#endif // GameWindow_HH
