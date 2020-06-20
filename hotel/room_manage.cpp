#include "room_manage.h"
#include "ui_room_manage.h"
#include "edit_room.h"
#include "new_room.h"
#include "new_type.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QModelIndex>
room_manage::room_manage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room_manage)
{
    ui->setupUi(this);

    QSqlQueryModel *model = new QSqlQueryModel();


    QString str2 = tr("select r.room_id,r.type,r.rental,r.area,r.reservation_times from room as r ");
    model->setQuery(str2);


    model->setHeaderData(1,Qt::Horizontal,tr("房间类型"));
    model->setHeaderData(2,Qt::Horizontal,tr("租金"));
    model->setHeaderData(3,Qt::Horizontal,tr("房间面积"));
    model->setHeaderData(4,Qt::Horizontal,tr("预约次数"));
    model->setHeaderData(0,Qt::Horizontal,tr("房间号"));

    ui->tableView->setModel(model);

    QSqlQueryModel *model2 = new QSqlQueryModel();


    QString str3 = tr("select type from room_type");
    model2->setQuery(str3);



    model2->setHeaderData(0,Qt::Horizontal,tr("房型"));

    ui->tableView_2->setModel(model2);

}

room_manage::~room_manage()
{
    delete ui;
}

void room_manage::on_pushButton_2_clicked()
{
    QString check = ui->lineEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel();
    QString str2;
    if( check == NULL){
        str2 = tr("select r.room_id,r.type,r.rental,r.area,r.reservation_times from room as r");
    }
    else {
        str2 = tr("select r.room_id,r.type,r.rental,r.area,r.reservation_times from room as r where r.room_id = '%1'").arg(check);
    }

    model->setQuery(str2);


    model->setHeaderData(1,Qt::Horizontal,tr("房间类型"));
    model->setHeaderData(2,Qt::Horizontal,tr("租金"));
    model->setHeaderData(3,Qt::Horizontal,tr("房间面积"));
    model->setHeaderData(4,Qt::Horizontal,tr("预约次数"));
    model->setHeaderData(0,Qt::Horizontal,tr("房间号"));

    ui->tableView->setModel(model);
}

void room_manage::on_pushButton_4_clicked()
{
    int curRow=ui->tableView->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,0);  //index.row()为算选择的行号。1为所选中行的第一列。。

    QVariant datatemp = modessl->data(indextemp);

    QString room_id=datatemp.toString();

    QSqlQuery query;

    QString a=QString("DELETE FROM room WHERE room_id = '%1'").arg(room_id);
    switch( QMessageBox::warning(NULL, "warning",tr("确定删除这个房间：'%1' 吗").arg(room_id),
                                 QMessageBox::Yes | QMessageBox::Default,
                                 QMessageBox::No | QMessageBox::Escape ))
    {
    case QMessageBox::Yes:
        if(query.exec(a) == false){
            QMessageBox::critical(NULL, "错误", "删除失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        else {
            QMessageBox::about(NULL, "成功", "删除成功");
        }
    case QMessageBox::No:
        return;
    }


}

void room_manage::on_pushButton_3_clicked()
{
    int curRow=ui->tableView->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,0);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp = modessl->data(indextemp);
    QString room_id=datatemp.toString();

    QModelIndex indextemp_1 = modessl->index(curRow,1);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp_1 = modessl->data(indextemp_1);
    QString room_type=datatemp_1.toString();

    QModelIndex indextemp_2 = modessl->index(curRow,3);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp_2 = modessl->data(indextemp_2);
    QString room_area=datatemp_2.toString();

    edit_room *e = new edit_room();
    connect(this,SIGNAL(sendData(QString,QString,QString)),e,SLOT(receiveData(QString,QString,QString)));
    emit sendData(room_type,room_area,room_id);
    e->show();
}

void room_manage::on_pushButton_clicked()
{
    new_room *n = new new_room();
    n->show();
}

void room_manage::on_pushButton_5_clicked()
{
    int curRow=ui->tableView_2->currentIndex().row();//选中行
    QAbstractItemModel *modessl = ui->tableView_2->model();
    QModelIndex indextemp = modessl->index(curRow,0);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QVariant datatemp = modessl->data(indextemp);
    QString room_type=datatemp.toString();
    QSqlQuery query;

    QString a=QString("UPDATE room SET rental = %1 WHERE type = '%2'").arg(ui->lineEdit_2->text()).arg(room_type);
    switch( QMessageBox::warning(NULL, "warning",tr("确定更改这类房间的价格：'%1' 吗").arg(room_type),
                                 QMessageBox::Yes | QMessageBox::Default,
                                 QMessageBox::No | QMessageBox::Escape ))
    {
    case QMessageBox::Yes:
        if(query.exec(a) == false){
            QMessageBox::critical(NULL, "错误", "更改失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        else {
            QMessageBox::about(NULL, "成功", "更改成功");
        }
    case QMessageBox::No:
        return;
    }
}

void room_manage::on_pushButton_6_clicked()
{
    new_type *n = new new_type();
    n->show();
}
