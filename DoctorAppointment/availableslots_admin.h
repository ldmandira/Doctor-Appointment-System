#ifndef AVAILABLESLOTS_ADMIN_H
#define AVAILABLESLOTS_ADMIN_H

#include <QWidget>

namespace Ui {
class availableslots_admin;
}

class availableslots_admin : public QWidget
{
    Q_OBJECT

public:
    explicit availableslots_admin(QWidget *parent = nullptr);
    ~availableslots_admin();

private:
    Ui::availableslots_admin *ui;
};

#endif // AVAILABLESLOTS_ADMIN_H
