#include "include/login.h"
#include "ui_login.h"
#include "QSqlDatabase"
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    //this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    QFile fout("test.db");
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    QSqlQuery qry;

    if(fout.exists())
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        if(db.open())
        {
            qry.prepare("CREATE TABLE \"Users\" (\"username\"	TEXT NOT NULL UNIQUE, \"email\"	TEXT, \"password\"	TEXT, PRIMARY KEY(\"username\"));");
            if(!qry.exec())
                QMessageBox::warning(this,"Error","Something went wrong!");

            qry.prepare("CREATE TABLE \"Keepass\" (\
                        \"Serial\"	INTEGER NOT NULL UNIQUE,\
                        \"username\"	TEXT,\
                        \"password\"	TEXT,\
                        \"site\"	TEXT,\
                        \"Description\"	TEXT,\
                        PRIMARY KEY(\"Serial\" AUTOINCREMENT)\
                    )");
             if(!qry.exec())
                QMessageBox::warning(this,"Error","Something went wrong!");
        }

    }
    fout.close();
    db.commit();
    db.close();
}

Login::~Login()
{
    delete ui;
}


void Login::on_pbGetStarted_clicked()
{
   exit(0);
}


void Login::on_pbOk_clicked()
{
    // check if all fields are well filled
    if(ui->uname->text().isEmpty() ||
            ui->pwd->text().isEmpty() ||
            ui->email->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please fill in the fields to continue!");
        return;
    }

    // check if passwords match
    if(!(ui->pwd->text() == ui->confpwd->text()))
    {
        QMessageBox::information(this,"Error","Passwords don't match!");
        return;
    }

    // append the details

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    QSqlQuery qry;
    db.open();

    if(!db.isOpen())
    {
        QMessageBox::warning(this,"Setup Error","Couldn't establish connection to database!");
        return;
    }

    qry.prepare("INSERT INTO Users (username, email, password) VALUES (:uname, :email, :pwd)");
    qry.bindValue(":uname", ui->uname->text());
    qry.bindValue(":email", ui->email->text());
    qry.bindValue(":pwd", ui->pwd->text());

    if(qry.exec())
    {
        QMessageBox::information(this,"Success!","Your registration was sucessful");
        db.commit();
        db.close();
        ui->stackedWidget->setCurrentIndex(1);
        return;
    }
    else
    {
        QMessageBox::warning(this,"Error","Something went wrong while trying to register you!");
    }

}
