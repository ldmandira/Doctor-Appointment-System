#ifndef APPOINTMENTCANCELATION_H
#define APPOINTMENTCANCELATION_H

#include <QFrame>
#include "availableslots.h"
#include "appointmentbooking.h"

namespace Ui {
class appointmentcancelation;
}

class appointmentcancelation : public QFrame
{
    Q_OBJECT

public:
    explicit appointmentcancelation(QWidget *parent = nullptr);
    ~appointmentcancelation();

private slots:
    void on_pushButton_Records_clicked();

    void on_pushButton_AvailableSlots_clicked();

    void on_pushButton_Appointment_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::appointmentcancelation *ui;
    //Records *records;
//    AvailableSlots *availableslots;
//    AppointmentBooking *appointmentbooking;
};

#endif // APPOINTMENTCANCELATION_H
