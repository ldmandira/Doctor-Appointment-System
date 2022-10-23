#include "doctorlogin.h"
#include "ui_doctorlogin.h"
#include "thanuki_appointment.h"
#include "neelika_appointment.h"
#include "chandima_appointment.h"
#include <QMessageBox>
#include <QPixmap>


DoctorLogin::DoctorLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorLogin)
{
    ui->setupUi(this);
    QPixmap pix("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/doctor.jpg");
    int w = ui->label_pic02->width();
    int h = ui->label_pic02->height();
    ui->label_pic02->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

DoctorLogin::~DoctorLogin()
{
    delete ui;
}

void DoctorLogin::on_pushButton_DoctorLogin_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString password,email;
    password=ui->lineEdit_dctpassword->text();
    email=ui->lineEdit_dctusername->text();


    if(!mydb.open())
        QMessageBox::critical(this,tr("error::"),tr("Database is not connected!"));
    else{
        if((ui->lineEdit_dctusername->text()!=nullptr)and(ui->lineEdit_dctpassword->text()!=nullptr)){
            QSqlQuery qry;
            if(email == "chandimajeewandara10@gmail.com" && password =="abc@1234") {
                chandima_Appointment = new Chandima_appointment(this);
                chandima_Appointment ->show();

            }
            else if(email == "thanukiidangodage@gmail.com" && password =="def@4567") {
                thanuki_Appointment = new thanuki_appointment(this);
                thanuki_Appointment ->show();

            }
            else if(email == "neelikamalavige26@gmail.com" && password =="ghi@7890") {
                neelika_Appointment = new neelika_appointment(this);
                neelika_Appointment ->show();

            }
    }
 }

}
