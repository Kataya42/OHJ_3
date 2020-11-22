#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QTimer>
#include <interfaces/icity.hh>
#include "manse.h"
#include "gamewindow.hh"

class GameMaster : public QObject
{
    Q_OBJECT
public:
    explicit GameMaster(QObject *parent = nullptr);
    void getcity(std::shared_ptr<Manse> city);
    void getWindow(std::shared_ptr<GameWindow> window);
    void runbusses();
signals:

private slots:
    void updateDraw();

private:
    std::shared_ptr<Manse> city_;
    std::shared_ptr<GameWindow> window_;
    QTimer timer_;
};

#endif // GAMEMASTER_H
