#include "checkout.h"
#include "ui_checkout.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <QTableView>

QString CheckOut::room_id;
QString CheckOut::out_time;
QString CheckOut::rent;
QDateTime CheckOut::outtime;

CheckOut::CheckOut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckOut)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    show_information();
}

CheckOut::~CheckOut()
{
    delete ui;
}

void CheckOut::on_pushButton_clicked()
{
    emit sendsignals();
    this->hide();
}

void CheckOut::on_pushButton_2_clicked()
{
    room_id = this->ui->lineEdit->text();
    out_time = this->ui->dateEdit->date().toString("yyyy-MM-dd");


    QSqlQuery query;
    QString sql = tr("UPDATE reservation SET checkout_time='%1',check_in_status = 0 WHERE room_id='%2'").arg(out_time).arg(room_id);
    bool ok = query.exec(sql);
    if (ok)
        qDebug()<<"ok";
}

void CheckOut::show_information()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString sql = tr("select * from reservation where check_in_status = 1");
    model->setQuery(sql);
    model->setHeaderData(0,Qt::Horizontal,tr("订单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("证件号"));
    model->setHeaderData(2,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(3,Qt::Horizontal,tr("入住时间"));
    model->setHeaderData(4,Qt::Horizontal,tr("押金"));
    model->setHeaderData(5,Qt::Horizontal,tr("退房时间"));
    model->setHeaderData(6,Qt::Horizontal,tr("房费"));
    model->setHeaderData(7,Qt::Horizontal,tr("订单状态"));
    ui->tableView->setModel(model);
}
