#include "appoinment1.h"
#include "ui_appoinment1.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <QTableView>
appoinment1::appoinment1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::appoinment1)
{
    ui->setupUi(this);
    show_information();
}
extern QString name,id,number,in_time,out_time;
QString app_roomid;
QDateTime app_intime;
QDateTime app_outtime ;
appoinment1::~appoinment1()
{
    delete ui;
}

void appoinment1::on_pushButton_clicked()//上一步按钮
{
    emit sendsignals();
    this->hide();
}

void appoinment1::show_information()
{
    app_intime = QDateTime::fromString(in_time, "yyyy-MM-dd hh:mm:ss");
    app_outtime = QDateTime::fromString(out_time, "yyyy-MM-dd hh:mm:ss");
    qDebug()<<"in_time is"<< in_time;
    qDebug()<<"out_time is"<< out_time;
    qDebug()<< out_time;
    QSqlQueryModel *model = new QSqlQueryModel();

    QString sql = tr("select m.type,m.rental,m.area,m.status,m.reservation_times,m.room_id  from room as m,reservation as r where m.status = '%1' or (m.status = '%2' and r.room_id = m.room_id and '%3' <= r.checkin_time ) ").arg('0').arg('2').arg(out_time);
    model->setQuery(sql);

    model->setHeaderData(5,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(0,Qt::Horizontal,"房间类型");
    model->setHeaderData(2,Qt::Horizontal,tr("面积"));
    model->setHeaderData(1,Qt::Horizontal,tr("租金"));
    model->setHeaderData(3,Qt::Horizontal,tr("房间状态"));
    model->setHeaderData(4,Qt::Horizontal,tr("预约次数"));
    ui->show_table->setModel(model);

}

void appoinment1::on_pushButton_2_clicked()
{
    app_roomid = this->ui->lineEdit->text();

    QSqlQuery query,query1;
    QString sql1 = tr("UPDATE room SET status='%1' WHERE room_id='%2'").arg('2').arg(app_roomid);
    QString sql = tr("INSERT INTO reservation(client_id,room_id,checkin_time,checkout_time,check_in_status)VALUES('%1','%2','%3','%4','%5') ").arg(id).arg(app_roomid).arg(in_time).arg(out_time).arg("2");
    bool one = query.exec(sql);//执行sql语句
    query1.exec(sql1);
    if (one)
        qDebug()<<"ok";
    appo2 = new  appointment2;
    this->hide();
    appo2->show();
}
