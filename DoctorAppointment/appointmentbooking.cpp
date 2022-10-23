#include "appointmentbooking.h"
#include "ui_appointmentbooking.h"
#include <QMessageBox>
#include <QPixmap>

AppointmentBooking::AppointmentBooking(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AppointmentBooking)
{
    ui->setupUi(this);
    QPixmap pix("D:/3rd year/1st sem/cross platform/qt applictions/appointment_images/firstcare.jpeg");
    int w = ui->label_logo->width();
    int h = ui->label_logo->height();
    ui->label_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->comboBox_Slot->addItem("6.00pm - 6.20pm");
    ui->comboBox_Slot->addItem("6.20pm - 6.40pm");
    ui->comboBox_Slot->addItem("6.40pm - 7.00pm");
    ui->comboBox_Slot->addItem("7.00pm - 7.20pm");
    ui->comboBox_Slot->addItem("7.20pm - 7.40pm");
    ui->comboBox_Slot->addItem("7.40pm - 8.00pm");
    ui->comboBox_Slot->addItem("8.00pm - 8.20pm");
    ui->comboBox_Slot->addItem("8.20pm - 8.40pm");
    ui->comboBox_Slot->addItem("8.40pm - 9.00pm");
    ui->comboBox_Slot->addItem("9.00pm - 9.20pm");
    ui->comboBox_Slot->addItem("9.20pm - 9.40pm");
    ui->comboBox_Slot->addItem("9.40pm - 10.00pm");

    ui->comboBox_DocName->addItem("Dr.Chandima Jeewandara");
    ui->comboBox_DocName->addItem("Dr.Thanuki Idangodage");
    ui->comboBox_DocName->addItem("Dr.Neelika Malavige");
}

AppointmentBooking::~AppointmentBooking()
{
    delete ui;
}

void AppointmentBooking::on_pushButton_Book_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString doc_name,time_slot,Name_of_patient,contact_no;

    doc_name=ui->comboBox_DocName->currentText();
    time_slot=ui->comboBox_Slot->currentText();
    Name_of_patient=ui->lineEdit_Patient->text();
    contact_no=ui->lineEdit_Contact->text();

    if(!mydb.open())
        QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        if((ui->lineEdit_Contact->text()!=nullptr)and(ui->lineEdit_Patient->text()!=nullptr)and(ui->comboBox_DocName->currentText()!=nullptr)and(ui->comboBox_Slot->currentText()!=nullptr)){
            QSqlQuery qry;
            qry.prepare("insert into appointments (doc_name,time_slot,Name_of_patient,contact_no) values('"+doc_name+"','"+time_slot+"','"+Name_of_patient+"','"+contact_no+"')");

            if(qry.exec()){
                QMessageBox::information(this,tr("save"),tr("Appoinment is created successfully!"));
                QSqlQuery qry1;
                QString token;
                qry1.prepare("select appid from appointments where doc_name='"+doc_name+"' and time_slot='"+time_slot+"'");
                if(qry1.exec()){
                    while(qry1.next()){
                        token = "Token no: "+qry1.value(0).toString();
                    }
                    ui->token_no->setText(token);
                }
                mydb.close();
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


void AppointmentBooking::on_pushButton_Cancel_clicked()
{

}



void AppointmentBooking::on_pushButton_Cancelation_clicked()
{
//    AppointmentCancelation01 = new appointmentcancelation(this);
//    AppointmentCancelation01->show();
}


void AppointmentBooking::on_pushButton_AvailableSlots_clicked()
{
//    availableslots01 = new AvailableSlots(this);
//    availableslots01 ->show();
}

