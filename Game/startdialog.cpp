#include "startdialog.hh"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_pushButton_clicked()
{
    emit sendCheckBox(twoPlayer_);
    close();
}

void StartDialog::on_checkBox_clicked(bool checked)
{
    twoPlayer_ = checked;
}
