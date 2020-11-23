#include "gamewindow.hh"
#include "ui_simplegamewindow.h"
#include <QDebug>

const int PADDING = 10;


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleGameWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void GameWindow::setTick(int t)
{
    tick_ = t;
}

void GameWindow::addActor(int locX, int locY, int type)
{
    OwnActorItem* nActor = new OwnActorItem(locX, locY, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void GameWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
}

void GameWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}


void GameWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();

}
