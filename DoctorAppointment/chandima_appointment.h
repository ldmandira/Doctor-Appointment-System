#ifndef CHANDIMA_APPOINTMENT_H
#define CHANDIMA_APPOINTMENT_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>

namespace Ui {
class Chandima_appointment;
}

class Chandima_appointment : public QWidget
{
    Q_OBJECT

public:
    explicit Chandima_appointment(QWidget *parent = nullptr);
    ~Chandima_appointment();

private slots:
    void on_tableView_chandima_activated(const QModelIndex &index);

    void on_pushButton_Cappointments_clicked();

private:
    Ui::Chandima_appointment *ui;
};

#endif // CHANDIMA_APPOINTMENT_H
