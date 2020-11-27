#include "gamewindow.hh"
#include "ui_simplegamewindow.h"

const int PADDING = 10;


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleGameWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);
    ui->hungerLabel->move(width_+ PADDING, PADDING * 5);
    ui->progressBar->move(width_ + PADDING, PADDING *  7);
    ui->scoreLabel->move(width_+ PADDING, PADDING * 11);
    ui->scoreCount->move(width_ + PADDING, PADDING * 13);

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

    ui->progressBar->setValue(100);
    ui->scoreCount->setPalette(Qt::red);
    ui->progressBar->setPalette(Qt::green);
    //ui->startButton->setEnabled(false);
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

        }
    }

    if (city_->isGameOver()){
        timer->stop();
        scoreTimer->stop();
        gameEnd();
    }

    city_->getPlayer()->updateLocation(playerDirHorizontal_,playerDirVertical_);
    Interface::Location playerLoc = city_->getPlayer()->giveLocation();
    int px = playerLoc.giveX();
    int py = playerLoc.giveY();
    playerActor_->setCoord(px, py);

    if (enemyPlayerControlled)
    {
        city_->getEnemy()->updateLocation(enemyDirHorizontal_,enemyDirVertical_);
        Interface::Location enemyLoc = city_->getEnemy()->giveLocation();
        enemyActor_->setCoord(enemyLoc.giveX(), enemyLoc.giveY());
    } else {
        city_->getEnemy()->chase(city_->getPlayer());
        Interface::Location enemyLoc = city_->getEnemy()->giveLocation();
        enemyActor_->setCoord(enemyLoc.giveX(), enemyLoc.giveY());
    }

    if (city_->getEnemy()->isClose(city_->getPlayer(), 15)) {
        life_ = -1;
        city_->getProg(life_);
    }

}

void GameWindow::advance()
{
    Interface::Location playerLoc = city_->getPlayer()->giveLocation();

    gameStats_.drainPlayerEnergy();
    gameStats_.addScore();

    ui->scoreCount->display(gameStats_.getScore());
    ui->progressBar->setValue(gameStats_.getPlayerEnergy());
    city_->getProg(gameStats_.getPlayerEnergy());

    std::vector<std::shared_ptr<Interface::IActor>> close;
    close = (city_->getNearbyActors(playerLoc));

    if (!(close.empty())){
       gameStats_.addPlayerEnergy();
    }
}
void GameWindow::mousePressEvent(QMouseEvent *event)
{
   setFocus();

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == 16777235) {
        playerDirVertical_ = -1;
        playerDirHorizontal_ = 0;

        //QPixmap a = QPixmap(":/images/images/fightUp.png");
        //playerActor_->setPixmap(a);
        //playerActor_->update();
        //playerActor_->updatePicture(0);

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

    if (enemyPlayerControlled)
    {
        if (event->key() == Qt::Key_W) {
            enemyDirVertical_ = -1;
            enemyDirHorizontal_ = 0;

        } else if (event->key() == Qt::Key_S) {
            enemyDirVertical_ = 1;
            enemyDirHorizontal_ = 0;

        } else if (event->key() == Qt::Key_A) {
            enemyDirHorizontal_ = -1;
            enemyDirVertical_ = 0;

        } else if (event->key() == Qt::Key_D) {
            enemyDirHorizontal_ = 1;
            enemyDirVertical_ = 0;
        }
    }
}

void GameWindow::gameEnd()
{
    QString str;
    str= QString("You got %1 points!")
            .arg(gameStats_.getScore());

    QMessageBox::information(this,
                             tr("Game Over!"),
                             (str));
    this->close();

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

        addActor(x,y,1);
        //std::cout << "x:" << x << " y:" << y << std::endl;
    }


}

void GameWindow::drawPlayer()
{
    OwnActorItem* nact = new OwnActorItem(city_->getPlayer()->giveLocation().giveX(), city_->getPlayer()->giveLocation().giveY(), 0);
    playerActor_ = nact;
    map->addItem(playerActor_);
}

void GameWindow::drawEnemy()
{
    OwnActorItem* nact = new OwnActorItem(city_->getEnemy()->giveLocation().giveX(), city_->getEnemy()->giveLocation().giveY(), 3);
    enemyActor_ = nact;
    map->addItem(enemyActor_);
}


void GameWindow::drawStops()
{
   std::vector<std::shared_ptr<Interface::IStop>> stops = city_->getStops();
   for ( auto i : stops){
       int x = i->getLocation().giveX() + 350 ;
       int y = 500 - i->getLocation().giveY() + 50 ;

       addActor(x,y,2);

       //std::cout << "x:" << x << " y:" << y << std::endl;

   }

}

void GameWindow::takeStats(Statistics gameStats)
{
    gameStats_ = gameStats;
}

void GameWindow::increaseScore()
{
    gameStats_.increaseModifier();
}

void GameWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCoords()));
    emit gameStarted();
    setFocus();
    drawPlayer();
    drawEnemy();
//    playerDirVertical_ = 0;
//    playerDirHorizontal_ = 0;
    scoreTimer = new QTimer(this);
    scoreTimer->start(scoreTick_);
    connect(scoreTimer, SIGNAL(timeout()), this, SLOT(advance()));


//    modTimer = new QTimer(this);
//    modTimer->start(1);
//    connect(modTimer, SIGNAL(timeout()), this, SLOT(increaseScore));


    ui->startButton->setEnabled(false);

}
