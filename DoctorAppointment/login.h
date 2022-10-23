#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "appointmentbooking.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "signup.h"
#include "records.h"
#include "doctorlogin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();

    void on_label_9_linkActivated(const QString &link);

    void on_go_signup_clicked();

    void on_doctor_click_clicked();

private:
    Ui::Login *ui;
    AppointmentBooking *appointmentBooking;
    //SignUp *signup;
    Records *records;
    DoctorLogin *doctorLogin;
};
#endif // LOGIN_H
