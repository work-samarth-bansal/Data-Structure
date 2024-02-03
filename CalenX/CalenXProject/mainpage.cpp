#include "mainpage.h"
#include "ui_mainpage.h"

Mainpage::Mainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainpage)
{
    ui->setupUi(this);

}

Mainpage::~Mainpage()
{
    delete ui;
}

void Mainpage::on_pushButton_clicked()
{
    ui->listWidget->addItem("Hello");
}


void Mainpage::on_pushButton_2_clicked()
{
    ui->listWidget->addItem("Hi");
}


void Mainpage::on_pushButton_3_clicked()
{
    ui->listWidget->addItem("Yo");
}

