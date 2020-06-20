#include "new_type.h"
#include "ui_new_type.h"
#include "QSqlQuery"
#include <QMessageBox>
new_type::new_type(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_type)
{
    ui->setupUi(this);
}

new_type::~new_type()
{
    delete ui;
}

void new_type::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==NULL || ui->lineEdit_2->text()== NULL){
        QMessageBox::critical(NULL, "错误", "输入不能为空", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else {
        QSqlQuery query;
        QString sql = tr("INSERT INTO room_type VALUES ('%1',%2,%3)").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text());

            if(query.exec(sql) == false){
                QMessageBox::critical(NULL, "错误", "创建失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else {
                QMessageBox::about(NULL, "成功", "创建成功");
            }
    }
}
