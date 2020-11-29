#include <QApplication>
#include <creategame.hh>
#include <doxygeninfo.hh>
#include <offlinereader.hh>
#include <gamewindow.hh>
#include <chaser.h>
#include <statistics.hh>
#include <startdialog.hh>

void startGame(std::shared_ptr<Manse> map,
    std::shared_ptr<CourseSide::Logic> gamelogic,
    Statistics stats,
    std::shared_ptr<GameWindow> playSpace,
    StartDialog* dialogWindow)
{
    playSpace->getDialog(dialogWindow);
    dialogWindow->show();

    QImage kartta;
    kartta.load(":/images/images/omaKartta.png");

    playSpace->setPicture(kartta);
    playSpace->takeCity(map);
    playSpace->takeStats(stats);

    gamelogic->fileConfig();
    gamelogic->setTime(12, 10);
    gamelogic->takeCity(map);
    playSpace->getLogic(gamelogic);

    map->addPlayer();
    map->addEnemy();
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

    std::shared_ptr<GameWindow> playSpace = nullptr; // initializing the gameWindow
    playSpace = std::make_shared<GameWindow>();

    StartDialog* dialogWindow = new StartDialog; // initializing the starting dialogue

    startGame(map, gamelogic, stats, playSpace, dialogWindow);

    return a.exec();
}

