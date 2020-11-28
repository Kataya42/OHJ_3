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
const int X_OFFSET = 350; //pxl
const int Y_OFFSET = 550;
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
     * @brief addActor adds an actor to the graphics window
     * @param locX, locY coordinates. The type of the actor
     */
    virtual void addActor(int locX, int locY, int type = 0);
    /**
     * @brief setPicture sets background image for game
     * @param img to set as game backgorund
     */
    void setPicture(QImage& img);
    /**
     * @brief takeCity takes a city as the focus interface
     * @param city Manse class city interface
     * @return bool returns true
     */
    bool takeCity(std::shared_ptr<Manse> city);
    /**
     * @brief drawBusses draws the busses onto the interface
     */
    void drawBuses();
    /**
     * @brief drawPlayer draws the player onto the interface
     */
    void drawPlayer();
    /**
     * @brief drawEnemy draws the enemy onto the interface
     */
    void drawEnemy();
    /**
     * @brief drawStops draws the stops onto the interface
     */
    void drawStops();
    /**
     * @brief takeStats takes a Statistcs class to keep track of game statistics
     * @param Statistic class
     */
    void takeStats(Statistics gameStats);
    /**
     * @brief increaseScore increases the score modifier
     */
    void increaseScore();
    /**
     * @brief getLogic takes a Logic class
     * @param Logic class from courseside
     */
    void getLogic(std::shared_ptr<CourseSide::Logic> l);
    /**
     * @brief getDialog gets a dialog window pointer
     * @param dia StartDialog class
     */
    void getDialog(StartDialog* dia);

signals:
    /**
     * @brief gameStarted signal for when the game has started
     */
    void gameStarted();
    /**
     * @brief keyCaught signal for when a key has been pressed
     * @param QkeyEvent for which key was pressed
     */
    void keyCaught(QKeyEvent* e);


private slots:
    /**
     * @brief on_startButton_clicked starts the game when pressed
     */
    void on_startButton_clicked();
    /**
     * @brief updateCoords updates the coordinates of all the actors
     */
    void updateCoords();
    /**
     * @brief advance updates player coordinates and checks if other actors are close
     */
    void advance();
    /**
     * @brief setPlayertwo sets enemyPlayerControlled
     * @param x is enemy player controlled
     */
    void setPlayertwo(bool x);

protected:
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);

private:
    /**
     * @brief gameEnd ends the game and displays the score
     */
    void gameEnd();

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


    int playerDirHorizontal_ = 0; //initial movement direction, 0 = still
    int playerDirVertical_ = 0;
    int enemyDirHorizontal_ = 0;
    int enemyDirVertical_ = 0;

    bool enemyPlayerControlled = false; // is the enemy player controlled
};

#endif // GameWindow_HH
