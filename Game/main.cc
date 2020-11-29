#include <QApplication>
#include <creategame.hh>
#include <doxygeninfo.hh>
#include <offlinereader.hh>
#include <gamewindow.hh>
#include <chaser.h>
#include <statistics.hh>
#include <startdialog.hh>

void startGame(std::shared_ptr<GameWindow> playSpace)
{

    QImage kartta;
    kartta.load(":/images/images/omaKartta.png");
    playSpace->setPicture(kartta);
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Q_INIT_RESOURCE(offlinedata); // initializing offline recources
    Q_INIT_RESOURCE(ownGraphics);

    std::shared_ptr<Manse> map = nullptr; // initializing the game city
    map = std::make_shared<Manse>();

    std::shared_ptr<CourseSide::Logic> gamelogic = nullptr; // initializing the game logic
    gamelogic = std::make_shared<CourseSide::Logic>();

    Statistics stats; // initializing the game statistics

    StartDialog* dialogWindow = new StartDialog; // initializing the starting dialogue

    std::shared_ptr<GameWindow> playSpace = nullptr; // initializing the gameWindow
    playSpace = std::make_shared<GameWindow>(dialogWindow, stats, gamelogic, map);


    startGame(playSpace);

    return a.exec();
}

