#include "register2.h"
#include "register1.h"
#include "register3.h"
#include "ui_register2.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <string.h>
#include <stdlib.h>
#include <QTableView>

Register2::Register2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register2)
{
    ui->setupUi(this);

}

Register2::~Register2()
{
    delete ui;
}

extern QString orderid;
extern QString clientid;
extern QDate checkintime;
extern QDate checkouttime;
extern QString deposit;
extern QString roomrates;

QString roomid;

void Register2::on_pushButton_clicked()
{
    this->close();
}

void Register2::on_pushButton_2_clicked()
{
    int curRow=ui->tableView->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,4);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp = modessl->data(indextemp);
    QString roomid=datatemp.toString();
    qDebug()<<roomid;


    QSqlQuery query;


    QString checkintime_str = checkintime.toString("yyyy-MM-dd");
    QString checkouttime_str = checkouttime.toString("yyyy-MM-dd");


    QString str = tr("insert into reservation(client_id,room_id,checkin_time,deposit,checkout_time,check_in_status) values('%1','%2','%3',%4,0,'1')").arg(clientid).arg(roomid).arg(checkintime_str).arg(deposit).arg(checkouttime_str);
    qDebug()<<str;
    int kk = query.exec(str);

    QString str1 = tr("update room set status = '1' where room_id = '%1'").arg(roomid);
    query.exec(str1);

    qDebug()<<str1;


    register3window = new Register3();
    register3window->show();

}

void Register2::on_pushButton_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();


    QString str2 = tr("select r.type,r.rental,r.area,r.reservation_times,r.room_id from room as r where r.status = '0' ");
    model->setQuery(str2);


    model->setHeaderData(0,Qt::Horizontal,tr("房间类型"));
    model->setHeaderData(1,Qt::Horizontal,tr("押金"));
    model->setHeaderData(2,Qt::Horizontal,tr("房间面积"));
    model->setHeaderData(3,Qt::Horizontal,tr("预约次数"));
    model->setHeaderData(4,Qt::Horizontal,tr("房间号"));

    ui->tableView->setModel(model);


}
