#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>
#include <QGraphicsScene>
#include <actors/nysse.hh>
#include <manse.h>
#include <actors/passenger.hh>
#include <actors/stop.hh>
#include <core/location.hh>
#include <core/logic.hh>
#include <errors/gameerror.hh>
#include <errors/initerror.hh>
#include <graphics/simpleactoritem.hh>
#include <graphics/simplemainwindow.hh>
#include <interfaces/iactor.hh>
#include <interfaces/icity.hh>
#include <interfaces/ipassenger.hh>
#include <interfaces/istatistics.hh>
#include <interfaces/istop.hh>
#include <interfaces/ivehicle.hh>
#include <creategame.hh>
#include <doxygeninfo.hh>
#include <offlinereader.hh>
#include <gamewindow.hh>
#include <gamemaster.h>



int main(int argc, char *argv[])
{
    std::shared_ptr<Manse> map = nullptr;
    map = std::make_shared<Manse>();
    QApplication a(argc, argv);

    std::shared_ptr<GameWindow> w = nullptr;
    w = std::make_shared<GameWindow>();

    QImage kartta;
    Q_INIT_RESOURCE(offlinedata);
    Q_INIT_RESOURCE(ownGraphics);
    kartta.load(":/images/images/omaKartta.png");
    //kartta.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    w->setPicture(kartta);

    w->takeCity(map);

    CourseSide::Logic gamelogic;
    gamelogic.fileConfig();
    gamelogic.setTime(12,10);
    gamelogic.takeCity(map);
    // Gamemaster testing class for game functions
    std::shared_ptr<Player> pelaaja = nullptr;
    pelaaja = std::make_shared<Player>();
    Interface::Location start;
    start.setXY(480, 316);
    pelaaja->move(start);
    map->addPlayer(pelaaja);
    w->show();
    gamelogic.finalizeGameStart();
    w->drawBuses();
    w->drawStops();

    return a.exec();
}
