#include "thanuki_appointment.h"
#include "ui_thanuki_appointment.h"
#include <QPixmap>
#include <QMessageBox>

thanuki_appointment::thanuki_appointment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thanuki_appointment)
{
    ui->setupUi(this);

    QPixmap pix("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/thanuki.jpeg");
    int w = ui->label_thanuki->width();
    int h = ui->label_thanuki->height();
    ui->label_thanuki->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

thanuki_appointment::~thanuki_appointment()
{
    delete ui;
}

void thanuki_appointment::on_tableView_thanuki_activated(const QModelIndex &index)
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString val=ui->tableView_thanuki->model()->data(index).toString();


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


void thanuki_appointment::on_pushButton_Tappointments_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QSqlQueryModel * modal = new QSqlQueryModel();

    if(!mydb.open())
       QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery* qry=new QSqlQuery(mydb);

        qry->prepare("select * from appointments where doc_name='Dr.Thanuki Idangodage'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_thanuki->setModel(modal);

        mydb.close();

        qDebug()<<(modal->rowCount());

    }
}

