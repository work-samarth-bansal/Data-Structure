#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
#include<QMessageBox>
namespace Ui {
class Mainpage;
}

class Mainpage : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase db;
    void Connclose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool Connopen(){
        QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/VISHNU/calenx.db");
        if(db.open()){
            qDebug()<<"Connected";
            return true;
        }
        else{
            qDebug()<<"Not Connected";
            return false;
        }
    }

public:
    explicit Mainpage(QWidget *parent = nullptr);
    ~Mainpage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Mainpage *ui;
};

#endif // MAINPAGE_H
