#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QPixmap>


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

//    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

//    if(!mydb.open())
//        QMessageBox::critical(this,tr("error::"),tr("Database is not connected!"));
//    else{
//        //ui->textEdit->setText("Database is connected");
//        QSqlQuery q;
//        QString data = "";
//        q.exec("SELECT * FROM doctor");
//        while(q.next()){
//            data += q.value(0).toString() + " =:=";
//            data += q.value(1).toString() + "\n";
//        }
//        ui->textEdit->setText(data);
//        q.clear();
//        mydb.close();

    QPixmap pix("doctor.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

Login::~Login()
{
    delete ui;
}



void Login::on_pushButton_Login_clicked()
{

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString password,email;
    password=ui->lineEdit_password->text();
    email=ui->lineEdit_username->text();


    if(!mydb.open())
        QMessageBox::critical(this,tr("error::"),tr("Database is not connected!"));
    else{
        if((ui->lineEdit_username->text()!=nullptr)and(ui->lineEdit_password->text()!=nullptr)){
            QSqlQuery qry;
            if(email == "admin1234@gmail.com" && password =="1234") {
                records = new Records(this);
                records->show();
            }
            else if(qry.exec("select * from patient where email='"+email+"' and password='"+password+"'")){
                int count;
                while(qry.next()){
                    count++;
                }
                if(count==1){
                    appointmentBooking = new AppointmentBooking(this);
                    appointmentBooking ->show();
                }
                else{
                    QMessageBox::critical(this,tr("Error"),tr("Login not found"));
                }
            }
            else{
                QMessageBox::critical(this,tr("Error"),tr("Invalid username or password!!"));
            }
        }
        else{
            QMessageBox::critical(this,tr("Error"),tr("Please fill the required fields!"));
        }
}}


void Login::on_go_signup_clicked()
{

//    signup = new SignUp(this);
//    signup ->show();
}








void Login::on_doctor_click_clicked()
{
    doctorLogin = new DoctorLogin(this);
    doctorLogin->show();
}

