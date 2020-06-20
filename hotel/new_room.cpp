#include "new_room.h"
#include "ui_new_room.h"
#include "QSqlQuery"
#include <QMessageBox>
#include <qdebug.h>
new_room::new_room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_room)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("select type from room_type");
    while(query.next()){
        ui->comboBox->addItem(query.value(0).toString());
    }
}

new_room::~new_room()
{
    delete ui;
}

void new_room::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql = tr("INSERT INTO room VALUES ('%1',0,%2,0,0,'%3')").arg(ui->comboBox->currentText()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit->text());
    qDebug()<<sql;
    if(query.exec(sql) == false){
        QMessageBox::critical(NULL, "错误", "创建失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else {
        QMessageBox::about(NULL, "成功", "创建成功");
    }

}
