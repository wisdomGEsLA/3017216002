#include "appointment2.h"
#include "ui_appointment2.h"
#include <QStandardItem>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
appointment2::appointment2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::appointment2)
{
    ui->setupUi(this);
    show_information();
}
extern QString name,id,number,in_time,out_time,app_roomid;
appointment2::~appointment2()
{
    delete ui;
}
void appointment2::show_information()
{
    QSqlQueryModel *model = new QSqlQueryModel();
     qDebug()<<id;
     QString sql = tr("select * from reservation where room_id = '%1' and client_id = '%2' and check_in_status = '%3' ").arg(app_roomid).arg(id).arg('2');
    model->setQuery(sql);
    qDebug()<<sql;
    model->setHeaderData(0,Qt::Horizontal,tr("预约订单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("身份证号"));
    model->setHeaderData(2,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(3,Qt::Horizontal,tr("预计入住时间"));
    model->setHeaderData(4,Qt::Horizontal,tr("订金"));
    model->setHeaderData(5,Qt::Horizontal,tr("预计退房时间"));
    model->setHeaderData(6,Qt::Horizontal,tr("租金"));
    model->setHeaderData(7,Qt::Horizontal,tr("入住情况"));
    ui->tableView->setModel(model);
}

void appointment2::on_pushButton_clicked()
{
    this->close();

}
