#include "hotelroommanagementsystem.h"
#include "ui_hotelroommanagementsystem.h"

HotelRoomManagementSystem::HotelRoomManagementSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HotelRoomManagementSystem)
{
    ui->setupUi(this);
}

HotelRoomManagementSystem::~HotelRoomManagementSystem()
{
    delete ui;
}

void HotelRoomManagementSystem::on_pushButton_4_clicked()
{
    checkout = new  CheckOut;
    connect(checkout,SIGNAL(sendsignals()),this,SLOT(reshow()));
    checkout->show();
}

void HotelRoomManagementSystem::reshow(){
    this->show();
}

void HotelRoomManagementSystem::on_pushButton_3_clicked()
{
    Statistics *s = new Statistics();
    s->show();
}

void HotelRoomManagementSystem::on_pushButton_clicked()
{
    Register *r = new Register();
    r->show();
}

void HotelRoomManagementSystem::on_pushButton_5_clicked()
{
    Widget *w = new Widget();
    w->show();
}

void HotelRoomManagementSystem::on_pushButton_2_clicked()
{
    Browse *b = new Browse();
    b->show();

}

void HotelRoomManagementSystem::on_pushButton_6_clicked()
{
    room_manage *b = new room_manage();
    b->show();
}
