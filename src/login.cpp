#include "include/login.h"
#include "ui_login.h"
#include "QSqlDatabase"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

