#include "chandima_appointment.h"
#include "ui_chandima_appointment.h"
#include <QPixmap>
#include <QMessageBox>

Chandima_appointment::Chandima_appointment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chandima_appointment)
{
    ui->setupUi(this);

    QPixmap pix("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/chandima.jpg");
    int w = ui->label_chandima->width();
    int h = ui->label_chandima->height();
    ui->label_chandima->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Chandima_appointment::~Chandima_appointment()
{
    delete ui;
}

void Chandima_appointment::on_tableView_chandima_activated(const QModelIndex &index)
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString val=ui->tableView_chandima->model()->data(index).toString();


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


void Chandima_appointment::on_pushButton_Cappointments_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QSqlQueryModel * modal = new QSqlQueryModel();

    if(!mydb.open())
       QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery* qry=new QSqlQuery(mydb);

        qry->prepare("select * from appointments where doc_name='Dr.Chandima Jeewandara'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_chandima->setModel(modal);

        mydb.close();

        qDebug()<<(modal->rowCount());

    }
}

