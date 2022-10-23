#ifndef DOCTORLOGIN_H
#define DOCTORLOGIN_H

#include <QWidget>
#include <chandima_appointment.h>
#include <thanuki_appointment.h>
#include <neelika_appointment.h>
namespace Ui {
class DoctorLogin;
}

class DoctorLogin : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorLogin(QWidget *parent = nullptr);
    ~DoctorLogin();

private slots:
    void on_pushButton_DoctorLogin_clicked();

private:
    Ui::DoctorLogin *ui;
    Chandima_appointment *chandima_Appointment;
    thanuki_appointment *thanuki_Appointment;
    neelika_appointment *neelika_Appointment;
};

#endif // DOCTORLOGIN_H
