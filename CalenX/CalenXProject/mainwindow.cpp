#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "mainpage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!Connopen()){
        qDebug()<<"Failed Connection";
    }
    else{
        qDebug()<<"Connection Successful";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog dl;
    dl.setModal(true);
    dl.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString username,password;
    username=ui->username->text();
    password=ui->password->text();
    if(!Connopen()){
        qDebug()<<"Failed to connect";
    }
    Connopen();
    QSqlQuery qry;
    qry.prepare("select * from Login where USERNAME='"+username+"' and password='"+password+"'");
    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count=count+1;
        }
        if(count==1){
            Mainpage mp;
            mp.setModal(true);
            mp.exec();
            Connclose();
        }
        if(count<1){
            QMessageBox::critical(this,"Incorrect","Incorrect Username or Password");
        }
    }
}

