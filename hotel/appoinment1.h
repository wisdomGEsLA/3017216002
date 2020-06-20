#ifndef APPOINMENT1_H
#define APPOINMENT1_H

#include <QWidget>
#include <appointment2.h>
extern QString app_roomid;
extern QDateTime app_intime;
extern QDateTime app_outtime ;
namespace Ui {
class appoinment1;
}

class appoinment1 : public QWidget
{
    Q_OBJECT

public:
    explicit appoinment1(QWidget *parent = nullptr);
    ~appoinment1();


signals:
    void sendsignals();

private slots:
    void on_pushButton_clicked();
    void show_information();

    void on_pushButton_2_clicked();

private:
    Ui::appoinment1 *ui;
    appointment2 *appo2;
};

#endif // APPOINMENT1_H
