#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH
#include <graphics/simplemainwindow.hh>

#include <QMainWindow>

class GameWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void draw();

signals:

};

#endif // GAMEWINDOW_HH
