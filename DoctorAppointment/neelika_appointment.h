#ifndef NEELIKA_APPOINTMENT_H
#define NEELIKA_APPOINTMENT_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>

namespace Ui {
class neelika_appointment;
}

class neelika_appointment : public QWidget
{
    Q_OBJECT

public:
    explicit neelika_appointment(QWidget *parent = nullptr);
    ~neelika_appointment();

private slots:
    void on_pushButton_Nappointments_clicked();

    void on_tableView_neelika_activated(const QModelIndex &index);

private:
    Ui::neelika_appointment *ui;
};

#endif // NEELIKA_APPOINTMENT_H
