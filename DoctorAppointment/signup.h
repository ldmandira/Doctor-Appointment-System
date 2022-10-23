#ifndef SIGNUP_H
#define SIGNUP_H

#include <QFrame>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "login.h"
#include <QSqlQueryModel>

namespace Ui {
class SignUp;
}

class SignUp : public QFrame
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_Register_clicked();

    void on_go_login_clicked();

private:
    Ui::SignUp *ui;
   // Login *login01;
};

#endif // SIGNUP_H
