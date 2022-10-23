#include "availableslots.h"
#include "ui_availableslots.h"
#include <QMessageBox>
#include <string>

AvailableSlots::AvailableSlots(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AvailableSlots)
{
    ui->setupUi(this);
    ui->comboBox_doctor->addItem("Dr.Chandima Jeewandara");
    ui->comboBox_doctor->addItem("Dr.Neelika Malavige");
    ui->comboBox_doctor->addItem("Dr.Thanuki Idangodage");
}

AvailableSlots::~AvailableSlots()
{
    delete ui;
}

void AvailableSlots::on_pushButton_Appointment_clicked()
{
//   appointmentBooking = new AppointmentBooking(this);
//   appointmentBooking ->show();

}


void AvailableSlots::on_pushButton_Cancelation_clicked()
{
//    appointmentCancelation = new appointmentcancelation(this);
//    appointmentCancelation ->show();
}


void AvailableSlots::on_pushButton_check_slots_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString doc_name;

    doc_name=ui->comboBox_doctor->currentText();

    int i = 1;
    while(i<=12){
        QString lblname = "t_slot"+QString::number(i);

        QLabel * ptr = this->findChild<QLabel*>(lblname);
        if(ptr)
               {
                    ptr->setStyleSheet("QLabel { background-color:rgba(0, 255, 0, 125); }");
               }
        i = i+1;
        }



           if(!mydb.open())
               QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
           else{
               if(ui->comboBox_doctor->currentText()!=nullptr){
                   QSqlQuery qry;
                   qry.prepare("select time_slot from appointments where doc_name='"+ui->comboBox_doctor->currentText()+"'");

                   if(qry.exec()){
                       while(qry.next()){

                           if(qry.value(0).toString() == "6.00pm - 6.20pm"){
                               QString lblname = "t_slot1";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {

                                   ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "6.20pm - 6.40pm"){
                               QString lblname = "t_slot2";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "6.40pm - 7.00pm"){
                               QString lblname = "t_slot3";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "7.00pm - 7.20pm"){
                               QString lblname = "t_slot4";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "7.20pm - 7.40pm"){
                               QString lblname = "t_slot5";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "7.40pm - 8.00pm"){
                               QString lblname = "t_slot6";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "8.00pm - 8.20pm"){
                               QString lblname = "t_slot7";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "8.20pm - 8.40pm"){
                               QString lblname = "t_slot8";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel {background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "8.40pm - 9.00pm"){
                               QString lblname = "t_slot9";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel {background-color:rgba(255,0,0,200); }");

                               }
                           }
                           else if(qry.value(0).toString() == "9.00pm - 9.20pm"){
                               QString lblname = "t_slot10";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200);; }");

                               }
                           }
                           else if(qry.value(0).toString() == "9.20pm - 9.40pm"){
                               QString lblname = "t_slot11";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200);; }");

                               }
                           }
                           else if(qry.value(0).toString() == "10.40pm - 10.00pm"){
                               QString lblname = "t_slot12";
                               QLabel * ptr = this->findChild<QLabel*>(lblname);
                               if(ptr)
                               {
                                       ptr->setStyleSheet("QLabel { background-color:rgba(255,0,0,200); }");

                               }
                           }





                       }
                   }
                   else{
                       QMessageBox::critical(this,tr("error::"),qry.lastError().text());
                   }
               }
               else{
                   QMessageBox::critical(this,tr("Error"),tr("Please fill the required fields!"));
               }


          }
       }


void AvailableSlots::on_pushButton_Records_clicked()
{

}

