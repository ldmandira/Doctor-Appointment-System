#ifndef THANUKI_APPOINTMENT_H
#define THANUKI_APPOINTMENT_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>

namespace Ui {
class thanuki_appointment;
}

class thanuki_appointment : public QWidget
{
    Q_OBJECT

public:
    explicit thanuki_appointment(QWidget *parent = nullptr);
    ~thanuki_appointment();

private slots:
    void on_tableView_thanuki_activated(const QModelIndex &index);

    void on_pushButton_Tappointments_clicked();

private:
    Ui::thanuki_appointment *ui;
};

#endif // THANUKI_APPOINTMENT_H
