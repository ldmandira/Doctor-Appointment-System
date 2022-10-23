#include "records.h"
#include "ui_records.h"
#include <QPixmap>
#include <QMessageBox>

Records::Records(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);

    QPixmap pix("D:/3rd year/1st sem/cross platform/qt applictions/appointment_images/firstcare.jpeg");
    int w = ui->label_logo->width();
    int h = ui->label_logo->height();
    ui->label_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Records::~Records()
{
    delete ui;
}

void Records::on_pushButton_Appointment_clicked()
{
    appointmentBooking = new AppointmentBooking(this);
    appointmentBooking ->show();
}


void Records::on_pushButton_Records_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QSqlQueryModel * modal = new QSqlQueryModel();

    if(!mydb.open())
       QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery* qry=new QSqlQuery(mydb);

        qry->prepare("select * from appointments");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        mydb.close();

        qDebug()<<(modal->rowCount());

    }
}


void Records::on_tableView_activated(const QModelIndex &index)
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString val=ui->tableView->model()->data(index).toString();


    if(!mydb.open())
        QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery qry;
        qry.prepare("select * from appointments where appid='"+val+"' or pid='"+val+"' or did='"+val+"' or time_slot='"+val+"'" );
        if(qry.exec()){
            while(qry.next()){

            }
        }

    }
}


void Records::on_pushButton_ReUsers_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QSqlQueryModel * modal = new QSqlQueryModel();

    if(!mydb.open())
       QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery* qry=new QSqlQuery(mydb);

        qry->prepare("select pid,first_name,last_name,email,tp_no,username from patient");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        mydb.close();

        qDebug()<<(modal->rowCount());

    }
}


void Records::on_pushButton_AvailableSlots_clicked()
{
    availableslots = new AvailableSlots(this);
    availableslots ->show();
}


void Records::on_pushButton_Cancelation_clicked()
{
    appcancel = new appointmentcancelation(this);
    appcancel->show();
}

