#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QPixmap>

SignUp::SignUp(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    QPixmap pix("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/doctor.jpg");
    int w = ui->label_pic01->width();
    int h = ui->label_pic01->height();
    ui->label_pic01->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

//    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");
//    if(!mydb.open())
//        ui->textEdit->setText("Databse not connected");
//    else{
//        ui->textEdit->setText("Database is connected");
//    }

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_Register_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString first_name,last_name,tp_no,email,password,username;
    first_name=ui->lineEdit_FName->text();
    last_name=ui->lineEdit_LName->text();
    tp_no=ui->lineEdit_tpno->text();
    email=ui->lineEdit_Email->text();
    password=ui->lineEdit_Password->text();
    username=ui->lineEdit_Email->text();


    if(!mydb.open())
       QMessageBox::critical(this,tr("error::"),tr("Database is not connected!"));
    else{
        if((ui->lineEdit_FName->text()!=nullptr)and(ui->lineEdit_LName->text()!=nullptr)and(ui->lineEdit_Email->text()!=nullptr)and(ui->lineEdit_Password->text()!=nullptr)and(ui->lineEdit_CPassword->text()!=nullptr)){
            if((ui->lineEdit_Password->text() == ui->lineEdit_CPassword->text())and(1)){
                QSqlQuery qry;
                qry.prepare("insert into patient (first_name,last_name,email,tp_no,username,password) values('"+first_name+"','"+last_name+"','"+email+"','"+tp_no+"','"+username+"','"+password+"')");

                if(qry.exec()){
                    QMessageBox::information(this,tr("save"),tr("Account created successfully!"));
                    mydb.close();
                }
                else{
                    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
                }
            }
            else{
                QMessageBox::critical(this,tr("Error"),tr("Confirm password is not valid!"));
            }
        }
        else{
            QMessageBox::critical(this,tr("Error"),tr("Please fill the required fields!"));
        }


    }
}


void SignUp::on_go_login_clicked()
{
//    login01 = new Login(this);
//    login01 -> show();
}

