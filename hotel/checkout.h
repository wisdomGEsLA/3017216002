#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QMainWindow>

extern QString roomid,rent,out_time;

namespace Ui {
class CheckOut;
}

class CheckOut : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckOut(QWidget *parent = nullptr);
    ~CheckOut();
    static QString room_id,rent,out_time;
    static QDateTime outtime ;

signals:
    void sendsignals();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void show_information();

private:
    Ui::CheckOut *ui;
};

#endif // CHECKOUT_H
