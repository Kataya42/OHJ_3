#include <QApplication>
#include <creategame.hh>
#include <doxygeninfo.hh>
#include <offlinereader.hh>
#include <gamewindow.hh>
#include <chaser.h>
#include <statistics.hh>
#include <startdialog.hh>

int main(int argc, char* argv[])
{
    std::shared_ptr<Manse> map = nullptr;
    map = std::make_shared<Manse>();
    QApplication a(argc, argv);

    std::shared_ptr<GameWindow> playSpace = nullptr;
    playSpace = std::make_shared<GameWindow>();

    StartDialog* dialogWindow = new StartDialog;
    playSpace->getDialog(dialogWindow);
    dialogWindow->show();

    QImage kartta;
    Q_INIT_RESOURCE(offlinedata);
    Q_INIT_RESOURCE(ownGraphics);
    kartta.load(":/images/images/omaKartta.png");

    Statistics stats;

    playSpace->setPicture(kartta);
    playSpace->takeCity(map);
    playSpace->takeStats(stats);

    std::shared_ptr<CourseSide::Logic> gamelogic = nullptr;
    gamelogic = std::make_shared<CourseSide::Logic>();

    gamelogic->fileConfig();
    gamelogic->setTime(12, 10);
    gamelogic->takeCity(map);
    playSpace->getLogic(gamelogic);

    std::shared_ptr<Player> pelaaja = nullptr;
    pelaaja = std::make_shared<Player>();
    Interface::Location start;
    start.setXY(480, 316);
    pelaaja->move(start);
    map->addPlayer(pelaaja);

    std::shared_ptr<Chaser> enemy = nullptr;
    enemy = std::make_shared<Chaser>();
    Interface::Location enemyStart;
    enemyStart.setXY(500, 500);
    enemy->move(enemyStart);
    map->addEnemy(enemy);

    return a.exec();
}
