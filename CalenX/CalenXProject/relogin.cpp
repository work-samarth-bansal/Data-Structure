#include "relogin.h"
#include "ui_relogin.h"
#include "mainpage.h"
Relogin::Relogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Relogin)
{
    ui->setupUi(this);
}

Relogin::~Relogin()
{
    delete ui;
}

void Relogin::on_pushButton_4_clicked()
{
    Mainpage mp;
    mp.setModal(true);
    mp.exec();
}

