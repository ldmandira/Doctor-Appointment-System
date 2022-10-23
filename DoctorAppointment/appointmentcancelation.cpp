#include "appointmentcancelation.h"
#include "ui_appointmentcancelation.h"
#include <QPixmap>
#include <QMessageBox>

appointmentcancelation::appointmentcancelation(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::appointmentcancelation)
{
    ui->setupUi(this);
    QPixmap pix("D:/3rd year/1st sem/cross platform/qt applictions/appointment_images/firstcare.jpeg");
    int w = ui->label_logo->width();
    int h = ui->label_logo->height();
    ui->label_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->comboBox_time->addItem("6.00pm - 6.20pm");
    ui->comboBox_time->addItem("6.20pm - 6.40pm");
    ui->comboBox_time->addItem("6.40pm - 7.00pm");
    ui->comboBox_time->addItem("7.00pm - 7.20pm");
    ui->comboBox_time->addItem("7.20pm - 7.40pm");
    ui->comboBox_time->addItem("7.40pm - 8.00pm");
    ui->comboBox_time->addItem("8.00pm - 8.20pm");
    ui->comboBox_time->addItem("8.20pm - 8.40pm");
    ui->comboBox_time->addItem("8.40pm - 9.00pm");
    ui->comboBox_time->addItem("9.00pm - 9.20pm");
    ui->comboBox_time->addItem("9.20pm - 9.40pm");
    ui->comboBox_time->addItem("9.40pm - 10.00pm");

    ui->comboBox_dname->addItem("Dr.Chandima Jeewandara");
    ui->comboBox_dname->addItem("Dr.Thanuki Idangodage");
    ui->comboBox_dname->addItem("Dr.Neelika Malavige");
}

appointmentcancelation::~appointmentcancelation()
{
    delete ui;
}

void appointmentcancelation::on_pushButton_Records_clicked()
{
//    records = new Records(this);
//    records->show();
}


void appointmentcancelation::on_pushButton_AvailableSlots_clicked()
{
//    availableslots = new AvailableSlots(this);
//    availableslots->show();
}


void appointmentcancelation::on_pushButton_Appointment_clicked()
{
//    appointmentbooking = new AppointmentBooking(this);
//    appointmentbooking->show();
}


void appointmentcancelation::on_pushButton_Cancel_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString time_slot,doc_name,token_no;
    time_slot=ui->comboBox_time->currentText();
    doc_name=ui->comboBox_dname->currentText();
    token_no=ui->lineEdit->text();


    if(!mydb.open())
        QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        if((ui->comboBox_dname->currentText()!=nullptr)and(ui->comboBox_time->currentText()!=nullptr)){
            QSqlQuery qry;
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this,"Warning","Please confirm the data deletion!",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes){
                if(qry.exec("delete from appointments where time_slot='"+time_slot+"' and doc_name='"+doc_name+"'")){
                        QMessageBox::information(this,tr("Success"),tr("Appointment deleted successfully!"));
                    }
                else{
                    QMessageBox::critical(this,tr("Error"),tr("Error deleting the appointment!"));
                }

            }
            else{
                QMessageBox::critical(this,tr("Error"),tr("Please fill the required fields!"));
            }

}
}}

