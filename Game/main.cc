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


int main(int argc, char *argv[])
{
    std::shared_ptr<Manse> map = nullptr;
    map = std::make_shared<Manse>();
    QApplication a(argc, argv);

    std::shared_ptr<GameWindow> w = nullptr;
    w = std::make_shared<GameWindow>();

    QImage kartta;
    Q_INIT_RESOURCE(offlinedata);
    kartta.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

    w->setPicture(kartta);
    w->addActor(50, 15,300);

    map->addWindow(w);


    CourseSide::Logic gamelogic;
    gamelogic.fileConfig();
    gamelogic.setTime(12,10);
    gamelogic.takeCity(map);
    gamelogic.finalizeGameStart();

    w->show();

    map->draw();




    return a.exec();
}
