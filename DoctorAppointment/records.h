#ifndef RECORDS_H
#define RECORDS_H

#include <QFrame>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include "appointmentbooking.h"
#include "availableslots.h"
#include "appointmentcancelation.h"

namespace Ui {
class Records;
}

class Records : public QFrame
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();

private slots:
    void on_pushButton_Appointment_clicked();

    void on_pushButton_Records_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_ReUsers_clicked();

    void on_pushButton_AvailableSlots_clicked();

    void on_pushButton_Cancelation_clicked();

private:
    Ui::Records *ui;
    AppointmentBooking *appointmentBooking;
    AvailableSlots *availableslots;
    appointmentcancelation *appcancel;
};

#endif // RECORDS_H
