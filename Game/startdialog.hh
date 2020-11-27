#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog {
    Q_OBJECT

public:
    explicit StartDialog(QWidget* parent = nullptr);
    ~StartDialog();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked(bool checked);

private:
    Ui::StartDialog* ui;
    bool twoPlayer_ = false;

signals:
    void sendCheckBox(bool a);
};

#endif // STARTDIALOG_HH
