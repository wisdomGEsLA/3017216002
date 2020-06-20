#ifndef HOTELROOMMANAGEMENTSYSTEM_H
#define HOTELROOMMANAGEMENTSYSTEM_H

#include <QMainWindow>
#include "checkout.h"
#include "statistics.h"
#include "register.h"
#include "widget.h"
#include "browse.h"
#include "room_manage.h"
namespace Ui {
class HotelRoomManagementSystem;
}

class HotelRoomManagementSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit HotelRoomManagementSystem(QWidget *parent = nullptr);
    ~HotelRoomManagementSystem();

private slots:
    void on_pushButton_4_clicked();
    void reshow();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::HotelRoomManagementSystem *ui;
    CheckOut *checkout;
};

#endif // HOTELROOMMANAGEMENTSYSTEM_H
