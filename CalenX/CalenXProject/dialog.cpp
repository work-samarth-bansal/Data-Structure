#include "dialog.h"
#include "ui_dialog.h"
#include "relogin.h"
#include "mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    if(!conn.Connopen()){
        qDebug()<<"Failed Connection";
    }
    else{
        qDebug()<<"Connection Successful";
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    Relogin rl;
    rl.setModal(true);
    rl.exec();
}


void Dialog::on_pushButton_2_clicked()
{
    QString username,name,email,password,confirm;
    QStringList user;
    QStringList emailcol;
    name=ui->Name->text();
    username=ui->username->text();
    email=ui->email->text();
    password=ui->password->text();
    confirm=ui->confirm_password->text();
    if(password==confirm){

        if(!conn.Connopen()){
            qDebug()<<"Failed To Connect";
        }
        conn.Connopen();
        QSqlQuery qry;
        if(qry.exec("select USERNAME from LOGIN ")){
            while(qry.next()){
                user.append(qry.value(0).toString());
            }
        }
        else{
            qDebug() << "Error executing query: " << qry.lastError().text();
        }
        if(user.contains(username)){
            QMessageBox::critical(this,"Incorrect","Username already exists");
        }
        else{
            qry.prepare("insert into Login values(name,username,email,password)");
            if(qry.exec()){
                QMessageBox::information(this,"Saved","Saved");
                conn.Connclose();
            }
            else{
                QMessageBox::information(this,"error","error");
            }
        }
        conn.close();
    }
    else{
        QMessageBox::critical(this,"Incorrect","confirmed password and password are not matching");
    }
}

