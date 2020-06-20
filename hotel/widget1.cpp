#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime());
}

Widget::~Widget()
{
    delete ui;
}

QString name,id,number,in_time,out_time;

void Widget::on_pushButton_2_clicked() //下一步，显示可用房屋信息
{
    name = this->ui->lineEdit->text();
    id = this->ui->lineEdit_2->text();
    number = this->ui->lineEdit_3->text();
    in_time = ui->dateEdit->date().toString("yyyy-MM-dd");
    out_time = ui->dateEdit_2->date().toString("yyyy-MM-dd");
    appo1 = new  appoinment1;

    this->hide();
    connect(appo1,SIGNAL(sendsignals()),this,SLOT(reshow()));
    appo1->show();

}
void Widget::reshow(){

    this->show();

}
void Widget::on_pushButton_clicked()
{

}
