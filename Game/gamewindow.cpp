#include "gamewindow.hh"
#include "ui_simplegamewindow.h"

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleGameWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(WIDTH, HEIGHT);
    ui->centralwidget->setFixedSize(WIDTH + ui->startButton->width() + PADDING, HEIGHT + PADDING);

    ui->startButton->move(WIDTH + PADDING, PADDING);
    ui->hungerLabel->move(WIDTH + PADDING, PADDING * 5);
    ui->progressBar->move(WIDTH + PADDING, PADDING * 7);
    ui->scoreLabel->move(WIDTH + PADDING, PADDING * 11);
    ui->scoreCount->move(WIDTH + PADDING, PADDING * 13);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0, 0, WIDTH, HEIGHT);

    resize(minimumSizeHint());

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCoords()));

    scoreTimer = new QTimer(this);
    connect(scoreTimer, SIGNAL(timeout()), this, SLOT(advance()));

    modTimer = new QTimer(this);
    connect(modTimer, SIGNAL(timeout()), this, SLOT(increaseScore));

    ui->progressBar->setValue(100);
    ui->scoreCount->setPalette(Qt::red);
    ui->progressBar->setPalette(Qt::green);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::addActor(int locX, int locY, int type)
{
    OwnActorItem* nActor = new OwnActorItem(locX, locY, type);
    nActor->setSprite();
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void GameWindow::updateCoords()
{
    std::vector<std::shared_ptr<Interface::IActor>> buses = city_->getActors();
    int counter = 0;
    for (auto i : buses) {
        if (counter < actors_.size()) {
            int nx = i->giveLocation().giveX() + X_OFFSET;
            int ny = Y_OFFSET1 - i->giveLocation().giveY() + Y_OFFSET2;
            actors_.at(counter)->setCoord(nx, ny);
            actors_.at(counter)->update();
            counter++;
        }
    }

    if (city_->isGameOver()) {
        timer->stop();
        scoreTimer->stop();
        gameEnd();
    }

    city_->getPlayer()->updateLocation(playerDirHorizontal_, playerDirVertical_);
    Interface::Location playerLoc = city_->getPlayer()->giveLocation();
    int px = playerLoc.giveX();
    int py = playerLoc.giveY();
    playerActor_->setCoord(px, py);

    if (enemyPlayerControlled) {
        city_->getEnemy()->updateLocation(enemyDirHorizontal_, enemyDirVertical_);
        Interface::Location enemyLoc = city_->getEnemy()->giveLocation();
        enemyActor_->setCoord(enemyLoc.giveX(), enemyLoc.giveY());
    }
    else {
        city_->getEnemy()->chase(city_->getPlayer());
        Interface::Location enemyLoc = city_->getEnemy()->giveLocation();
        enemyActor_->setCoord(enemyLoc.giveX(), enemyLoc.giveY());

        int direction = city_->getEnemy()->getDirection(city_->getPlayer());
        enemyActor_->rotateSprite(direction);
    }

    if (city_->getEnemy()->isClose(city_->getPlayer(), DANGER_RADIUS)) {
        city_->getProg(-1);
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

    std::vector<std::shared_ptr<Interface::IActor> > close;
    close = (city_->getNearbyActors(playerLoc));

    if (!(close.empty())) {
        gameStats_.addPlayerEnergy();
    }
}

void GameWindow::mousePressEvent(QMouseEvent* event)
{
    setFocus();
    Q_UNUSED(event);
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up) {
        playerDirVertical_ = -1;
        playerDirHorizontal_ = 0;
    }
    else if (event->key() == Qt::Key_Down) {
        playerDirVertical_ = 1;
        playerDirHorizontal_ = 0;
    }
    else if (event->key() == Qt::Key_Left) {
        playerDirHorizontal_ = -1;
        playerDirVertical_ = 0;
    }
    else if (event->key() == Qt::Key_Right) {
        playerDirHorizontal_ = 1;
        playerDirVertical_ = 0;
    }

    if (enemyPlayerControlled) {
        if (event->key() == Qt::Key_W) {
            enemyDirVertical_ = -1;
            enemyDirHorizontal_ = 0;
            enemyActor_->rotateSprite(UP);
        }
        else if (event->key() == Qt::Key_S) {
            enemyDirVertical_ = 1;
            enemyDirHorizontal_ = 0;
            enemyActor_->rotateSprite(DOWN);
        }
        else if (event->key() == Qt::Key_A) {
            enemyDirHorizontal_ = -1;
            enemyDirVertical_ = 0;
            enemyActor_->rotateSprite(LEFT);
        }
        else if (event->key() == Qt::Key_D) {
            enemyDirHorizontal_ = 1;
            enemyDirVertical_ = 0;
            enemyActor_->rotateSprite(RIGHT);
        }
    }
}

void GameWindow::gameEnd()
{
    QString str;
    str = QString("You got %1 points!")
              .arg(gameStats_.getScore());

    QMessageBox::information(this,
        tr("Game Over!"),
        (str));
    this->close();
}
void GameWindow::setPicture(QImage& img)
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

    std::vector<std::shared_ptr<Interface::IActor>> buses = city_->getActors();
    for ( auto i : buses){
        int x = i->giveLocation().giveX() + 350;
        int y = Y_OFFSET1 - i->giveLocation().giveY() + Y_OFFSET2;

        addActor(x, y, BUS);
    }
}

void GameWindow::drawPlayer()
{
    OwnActorItem* nact = new OwnActorItem(city_->getPlayer()->giveLocation().giveX(), city_->getPlayer()->giveLocation().giveY(), PLAYER);
    nact->setSprite();
    playerActor_ = nact;
    map->addItem(playerActor_);
}

void GameWindow::drawEnemy()
{
    OwnActorItem* nact = new OwnActorItem(city_->getEnemy()->giveLocation().giveX(), city_->getEnemy()->giveLocation().giveY(), ENEMY);
    nact->setSprite();
    enemyActor_ = nact;
    map->addItem(enemyActor_);
}

void GameWindow::drawStops()
{
    std::vector<std::shared_ptr<Interface::IStop> > stops = city_->getStops();
    for (auto i : stops) {
        int x = i->getLocation().giveX() + X_OFFSET;
        int y = Y_OFFSET1 - i->getLocation().giveY() + Y_OFFSET2;

        addActor(x, y, STOP);
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

void GameWindow::getLogic(std::shared_ptr<CourseSide::Logic> l)
{
    gamelogic_ = l;
}
void GameWindow::setPlayertwo(bool x)
{
    enemyPlayerControlled = x;
    this->show();
}

void GameWindow::getDialog(StartDialog* dia)
{
    dialog_ = dia;
    connect(dialog_, SIGNAL(sendCheckBox(bool)), this, SLOT(setPlayertwo(bool)));
}

void GameWindow::on_startButton_clicked()
{

    emit gameStarted();

    setFocus();
    drawPlayer();
    drawEnemy();

    timer->start(TICK);
    scoreTimer->start(TICK * DIFFICULTY);
    modTimer->start(1);

    ui->startButton->setEnabled(false);
    gamelogic_->finalizeGameStart();
    drawBuses();
    drawStops();
}
