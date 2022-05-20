#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pbGetStarted_clicked();

    void on_pbOk_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
