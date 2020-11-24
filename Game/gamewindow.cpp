#include "gamewindow.hh"
#include "ui_simplegamewindow.h"
#include <QDebug>
#include <QKeyEvent>

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
    playerDirVertical_ = 0;
    playerDirHorizontal_ = 0;
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

void GameWindow::updateCoords()
{
    std::vector<std::shared_ptr<Interface::IActor>> buses = city_->getBuses();
    int counter = 0;
    for ( auto i : buses){
        if (counter < actors_.size()){
            int nx = i->giveLocation().giveX() + 350;
            int ny = 500 - i->giveLocation().giveY() + 50;
            actors_.at(counter)->setCoord(nx, ny);
            counter++;

            //std::cout << nx << " "  << ny << std::endl;




            std::vector<std::shared_ptr<Interface::IActor>> close;
            close = (city_->getNearbyActors(loca_));


        }
    }

    city_->getPlayer()->updateLocation(playerDirHorizontal_,playerDirVertical_);
    int px = city_->getPlayer()->giveLocation().giveX();
    int py = city_->getPlayer()->giveLocation().giveY();
    playerActor_->setCoord(px, py);

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == 16777235) {
        playerDirVertical_ = -1;
        playerDirHorizontal_ = 0;

    } else if (event->key() == 16777237) {
        playerDirVertical_ = 1;
        playerDirHorizontal_ = 0;

    } else if (event->key() == 16777234) {
        playerDirHorizontal_ = -1;
        playerDirVertical_ = 0;

    } else if (event->key() == 16777236) {
        playerDirHorizontal_ = 1;
        playerDirVertical_ = 0;
    }



    //std::cout << "updated bus positions";

}

void GameWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

bool GameWindow::takeCity(std::shared_ptr<Manse> city)
{
    city_ = city;
    return true;
}

void GameWindow::drawBuses()
{
    std::vector<std::shared_ptr<Interface::IActor>> buses = city_->getBuses();
    for ( auto i : buses){
        int x = i->giveLocation().giveX() + 350;

        int y = 500 - i->giveLocation().giveY() + 50;

        addActor(x,y);
        std::cout << "x:" << x << " y:" << y << std::endl;
    }

    //LocationTestBus

    loca_ = Interface::Location();
    loca_.setXY(480,316);
    addActor(480,316,100);

}


void GameWindow::drawPlayer()
{
    OwnActorItem* nact = new OwnActorItem(city_->getPlayer()->giveLocation().giveX(), city_->getPlayer()->giveLocation().giveY(), 100);
    playerActor_ = nact;
    map->addItem(playerActor_);
}


void GameWindow::drawStops()
{
   std::vector<std::shared_ptr<Interface::IStop>> stops = city_->getStops();
   for ( auto i : stops){
       int x = i->getLocation().giveX() + 350 ;
       int y = 500 - i->getLocation().giveY() + 50 ;

      // addActor(x,y);
       std::cout << "x:" << x << " y:" << y << std::endl;
   }
}


void GameWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCoords()));
    emit gameStarted();
    grabKeyboard();
    drawPlayer();
    playerDirVertical_ = 1;
    playerDirHorizontal_ = 1;
}

void GameWindow::setTestLocation(Interface::Location loc)
{
    loca_ = loc;
}
