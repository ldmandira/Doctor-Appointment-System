#ifndef APPOINTMENTBOOKING_H
#define APPOINTMENTBOOKING_H

#include <QFrame>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "availableslots.h"
#include "appointmentcancelation.h"

namespace Ui {class AppointmentBooking;}

class AppointmentBooking : public QFrame
{
    Q_OBJECT

public:
    explicit AppointmentBooking(QWidget *parent = nullptr);
    ~AppointmentBooking();

private slots:
    void on_pushButton_Book_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Cancelation_clicked();

    void on_pushButton_AvailableSlots_clicked();

private:
    Ui::AppointmentBooking *ui;
    //AvailableSlots *availableslots01;
   // appointmentcancelation *AppointmentCancelation01;



};

#endif // APPOINTMENTBOOKING_H
