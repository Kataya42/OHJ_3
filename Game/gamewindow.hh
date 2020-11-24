#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "interfaces/iactor.hh"
#include "interfaces/icity.hh"
#include "ownactoritem.hh"
#include "manse.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

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

    virtual void addActor(int locX, int locY, int type = 0);

    void setPicture(QImage &img);
    bool takeCity(std::shared_ptr<Manse> city);
    void drawBuses();
    void drawStops();

    void setTestLocation(Interface::Location loc);
signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();
    void updateCoords();

private:
    Ui::SimpleGameWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<OwnActorItem*> actors_;
    OwnActorItem* last_;
    std::shared_ptr<Manse> city_;
    Interface::Location loca_;

    std::vector<std::shared_ptr<Interface::IActor>> nearbyStuff_;

    int width_ = 1095; //pxls
    int height_ = 592;
    int tick_ = 100; //ms
};

 //namespace
#endif // GameWindow_HH
