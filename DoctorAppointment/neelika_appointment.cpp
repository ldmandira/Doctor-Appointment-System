#include "neelika_appointment.h"
#include "ui_neelika_appointment.h"
#include <QPixmap>
#include <QMessageBox>

neelika_appointment::neelika_appointment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::neelika_appointment)
{
    ui->setupUi(this);

    QPixmap pix("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/neelika.png");
    int w = ui->label_neelika->width();
    int h = ui->label_neelika->height();
    ui->label_neelika->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

neelika_appointment::~neelika_appointment()
{
    delete ui;
}

void neelika_appointment::on_pushButton_Nappointments_clicked()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QSqlQueryModel * modal = new QSqlQueryModel();

    if(!mydb.open())
       QMessageBox::critical(this,tr("Error"),tr("Database not connected!"));
    else{
        QSqlQuery* qry=new QSqlQuery(mydb);

        qry->prepare("select * from appointments where doc_name='Dr.Neelika Malavige'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_neelika->setModel(modal);

        mydb.close();

        qDebug()<<(modal->rowCount());

    }
}


void neelika_appointment::on_tableView_neelika_activated(const QModelIndex &index)
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/3rd year/1st sem/cross platform C++/qt applictions/DoctorAppointment/FirstCare.db");

    QString val=ui->tableView_neelika->model()->data(index).toString();


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

