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

namespace Ui {
class SimpleGameWindow;
}


class GameWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit GameWindow(QWidget *parent = 0);
    virtual ~GameWindow();

    void setSize(int w, int h);
    void setTick(int t);

    virtual void addActor(int locX, int locY, int type);

    void setPicture(QImage &img);
    bool takeCity(std::shared_ptr<Manse> city);
    void drawBuses();
    void drawPlayer();
    void drawStops();

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

private:
    Ui::SimpleGameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<OwnActorItem*> actors_;
    OwnActorItem* last_;
    OwnActorItem* playerActor_;
    std::shared_ptr<Manse> city_;

    void gameEnd();
    int playerDirHorizontal_;
    int playerDirVertical_;
    std::vector<std::shared_ptr<Interface::IActor>> nearbyStuff_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 100; //ms
    int score_ = 0;
    int life_ = 0;
};

 //namespace
#endif // GameWindow_HH
