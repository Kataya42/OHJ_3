#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include <QMessageBox>
#include <QPixmap>

static QString RULES = "Move your spaceship using the arrow keys on your keyboard \n"
                       "Hover above busses to suck energy from them \n"
                       "The game ends if your energy reaches 0% \n"
                       "or the F/A-18 hornet catches you. \n"
                       "You gain more points for surviving longer. \n"
                       "By selecting 'two player', it allows the hornet to be \n"
                       "controlled by another player using the WASD keys";

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog {
    Q_OBJECT

public:
    explicit StartDialog(QWidget* parent = nullptr);
    ~StartDialog();

private slots:
    /**
     * @brief on_startButton_clicked emits the
     * status of the checkbox and closes the window
     */
    void on_startButton_clicked();
    /**
     * @brief on_checkBox_clicked updates bool twoPlayer_
     * @param checked, current status of the checkBox
     */
    void on_checkBox_clicked(bool checked);
    /**
     * @brief on_tutorialButton_clicked opens the tutorial dialog window
     */
    void on_tutorialButton_clicked();

private:
    Ui::StartDialog* ui;

    // has the two player option been selected
    bool twoPlayer_ = false;

signals:
    /**
     * @brief sendCheckBox sends the status of the checkBox
     * @param bool isTwoPlayer, status of the checkBox
     */
    void sendCheckBox(bool isTwoPlayer);
};

#endif // STARTDIALOG_HH
