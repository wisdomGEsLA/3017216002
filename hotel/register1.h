#ifndef REGISTER1_H
#define REGISTER1_H

#include <QMainWindow>
#include <register2.h>
#include <warning.h>

extern QString orderid;
extern QString clientid;
extern QDate checkintime;
extern QDate checkouttime;
extern QString deposit;
extern QString roomrates;

namespace Ui {
class Register1;
}

class Register1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register1(QWidget *parent = nullptr);
    ~Register1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Register1 *ui;
    Register2* Register2window;
    warning* warningwindow;
};

#endif // REGISTER1_H
