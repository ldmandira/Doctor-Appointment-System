#ifndef AVAILABLESLOTS_H
#define AVAILABLESLOTS_H

#include <QFrame>
#include "appointmentbooking.h"
#include "appointmentcancelation.h"

namespace Ui {
class AvailableSlots;
}

class AvailableSlots : public QFrame
{
    Q_OBJECT

public:
    explicit AvailableSlots(QWidget *parent = nullptr);
    ~AvailableSlots();

private slots:
    void on_pushButton_Appointment_clicked();

    void on_pushButton_Cancelation_clicked();

    void on_pushButton_check_slots_clicked();

    void on_pushButton_Records_clicked();

private:
    Ui::AvailableSlots *ui;
//    AppointmentBooking *appointmentBooking;
//    appointmentcancelation *appointmentCancelation;
};

#endif // AVAILABLESLOTS_H
