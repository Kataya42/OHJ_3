#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH
#include <graphics/simplemainwindow.hh>
#include <graphics/simpleactoritem.hh>
#include <interfaces/istop.hh>
#include <QMainWindow>

class GameWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);


signals:

};

#endif // GAMEWINDOW_HH
