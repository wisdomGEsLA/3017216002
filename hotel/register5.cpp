#include "register5.h"
#include "ui_register5.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <string.h>
#include <stdlib.h>
#include "register3.h"

extern QString clientid;
extern QString orderid;

Register5::Register5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register5)
{
    ui->setupUi(this);
}




Register5::~Register5()
{
    delete ui;
}

void Register5::on_pushButton_3_clicked()
{
    clientid = this->ui->lineEdit->text();
    QSqlQuery query,query1;
    QSqlQueryModel *model = new QSqlQueryModel();


    QString str = tr("select r.order_id,r.client_id,r.room_id,r.checkin_time,r.deposit,r.checkout_time,r.room_rates,r.check_in_status from reservation as r where r.client_id = %1 ").arg(clientid);
    qDebug()<<str;
    model->setQuery(str);

    QString str1 = tr("select r.order_id from reservation as r where r.client_id = '%1'").arg(clientid);
    qDebug()<<str1;
    query1.exec(str1);
    query1.next();
    orderid = query1.value(0).toString();




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

void Register5::on_pushButton_clicked()
{
    this->close();
}

void Register5::on_pushButton_2_clicked()
{
    QSqlQuery query;

    int curRow=ui->tableView->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,2);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp = modessl->data(indextemp);
    QString roomid=datatemp.toString();
    qDebug()<<roomid;

    QString str1 = tr("update room set status = '1' where room_id = '%1'").arg(roomid);
    query.exec(str1);
    QString str2 = tr("update reservation set check_in_status = '1' where room_id = '%1'").arg(roomid);
    query.exec(str2);



    register3window = new Register3();
    register3window->show();
}
