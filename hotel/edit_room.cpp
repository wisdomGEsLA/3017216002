#include "edit_room.h"
#include "ui_edit_room.h"
#include "QSqlQuery"
#include <QMessageBox>
edit_room::edit_room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_room)
{
    ui->setupUi(this);
}

edit_room::~edit_room()
{
    delete ui;
}
void edit_room::receiveData(QString type,QString area,QString room_id){
    ui->label_2->setText(type);
    ui->label_5->setText(area);
    ui->label_7->setText(room_id);
}

void edit_room::on_pushButton_clicked()
{
    QSqlQuery query;
    QString newtype;
    QString newarea;
    if(ui->lineEdit->text()==NULL){
        newtype = ui->label_2->text();
    }
    else {
        newtype = ui->lineEdit->text();
    }
    if(ui->lineEdit_2->text()==NULL){
        newarea = ui->label_5->text();
    }
    else{
        newarea = ui->lineEdit_2->text();
    }
    QString a=QString("UPDATE ROOM SET TYPE = '%1',AREA = %2 WHERE ROOM_ID = '%3'").arg(newtype).arg(newarea).arg(ui->label_7->text());
    switch( QMessageBox::warning(NULL, "warning",tr("确定对以下房间的更改吗：'%1' 吗").arg(ui->label_7->text()),
                                 QMessageBox::Yes | QMessageBox::Default,
                                 QMessageBox::No | QMessageBox::Escape ))
    {
    case QMessageBox::Yes:
        if(query.exec(a) == false){
            QMessageBox::critical(NULL, "错误", "修改失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        else {
            QMessageBox::about(NULL, "成功", "修改成功");
        }
    case QMessageBox::No:
        return;
    }
}
