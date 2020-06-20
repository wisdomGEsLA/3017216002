#include "register4.h"
#include "register2.h"
#include "register1.h"
#include "ui_register4.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <string.h>
#include <stdlib.h>

Register4::Register4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register4)
{
    ui->setupUi(this);
}

extern QString orderid;

Register4::~Register4()
{
    delete ui;
}

void Register4::on_pushButton_clicked()
{
    this->close();
}

void Register4::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();


    QString str = tr("select r.order_id,r.client_id,r.room_id,r.checkin_time,r.deposit,r.checkout_time,r.room_rates,r.check_in_status from reservation as r where r.order_id in (select MAX(r.order_id) from reservation as r) ");
    qDebug()<<str;
    model->setQuery(str);


    model->setHeaderData(0,Qt::Horizontal,tr("订单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("用户身份证号"));
    model->setHeaderData(2,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(3,Qt::Horizontal,tr("入住时间"));
    model->setHeaderData(4,Qt::Horizontal,tr("租金"));
    model->setHeaderData(5,Qt::Horizontal,tr("退房时间"));
    model->setHeaderData(6,Qt::Horizontal,tr("房间等级"));
    model->setHeaderData(7,Qt::Horizontal,tr("入住人数"));

    ui->tableView->setModel(model);
}
