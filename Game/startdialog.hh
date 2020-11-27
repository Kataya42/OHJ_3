#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>

namespace Ui {
class startDialog;
}

class startDialog : public QDialog
{
    Q_OBJECT

public:
    explicit startDialog(QWidget *parent = nullptr);
    ~startDialog();

private:
    Ui::startDialog *ui;
};

#endif // STARTDIALOG_HH
