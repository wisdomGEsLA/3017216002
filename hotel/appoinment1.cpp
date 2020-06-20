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
#include <QMessageBox>
#include <QAbstractItemModel>
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
//    app_intime = QDateTime::fromString(in_time, "yyyy-MM-dd hh:mm:ss");
//    app_outtime = QDateTime::fromString(out_time, "yyyy-MM-dd hh:mm:ss");
    qDebug()<<"in_time is"<< in_time;
    qDebug()<<"out_time is"<< out_time;
    qDebug()<< out_time;
    QSqlQueryModel *model = new QSqlQueryModel();

    QString sql = tr("select m.type,m.rental,m.area,m.status,m.reservation_times,m.room_id  from room as m "
                     "where m.status = 0 or (m.status != 0 "
                     "and m.room_id = (select r1.room_id from reservation as r1 where ('%1'<= r1.checkin_time or '%2' >= r1.checkout_time) "
                     "and r1.room_id not in (select r2.room_id from reservation as r2 where ('%3'<=r2.checkout_time and '%4' >= r2.checkin_time )"
                     "or ('%5' >= r2.checkin_time and '%6' <= r2.checkout_time)"
                     "or ('%7' <= r2.checkin_time and '%8' >= r2.checkout_time))))").arg(out_time).arg(in_time).arg(in_time).arg(in_time).arg(out_time).arg(out_time).arg（in_time）.arg(out_time);
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
    int curRow=ui->show_table->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->show_table->model();
    QModelIndex indextemp = modessl->index(curRow,5);
    QVariant datatemp = modessl->data(indextemp);
    app_roomid=datatemp.toString();

    //app_roomid = this->ui->lineEdit->text();
    if(app_roomid == NULL ){
        QMessageBox::warning(this,"error","未选择房间!!");
        return;
    }
    QSqlQuery query,query1;
    QString sql1 = tr("UPDATE room SET status='%1' and reservation_times = reservation_times +'%2' WHERE room_id='%3' and status != 1").arg('2').arg('1').arg(app_roomid);
    QSqlQuery query2;
    QString sql2 = tr("UPDATE room SET reservation_times = reservation_times +'%1' WHERE room_id='%2' and status = 1").arg('1').arg(app_roomid);
    query2.exec(sql2);
    QString sql = tr("INSERT INTO reservation(client_id,room_id,checkin_time,deposit,checkout_time,room_rates,check_in_status)VALUES('%1','%2','%3',0,'%4',0,'%5') ").arg(id).arg(app_roomid).arg(in_time).arg(out_time).arg("2");
    qDebug()<<sql;
    bool one = query.exec(sql);//执行sql语句
    query1.exec(sql1);
    if (one)
        qDebug()<<"ok";
    appo2 = new  appointment2;
    this->hide();
    appo2->show();
}
