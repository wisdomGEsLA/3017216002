#include "register3.h"
#include "ui_register3.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <string.h>
#include <stdlib.h>
#include "register5.h"
#include <QMessageBox>


Register3::Register3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register3)
{
    ui->setupUi(this);
}

Register3::~Register3()
{
    delete ui;
}


extern QString clientid;

int isnum(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return -1;
    }
    else
    { //纯数字
        return 0;
    }
}

void Register3::on_pushButton_4_clicked()
{
    QString ID = clientid;
    QString name = this->ui->lineEdit->text();
    QString gender = this->ui->comboBox->currentText();
    QString age = this->ui->lineEdit_3->text();
    QString telephone = this->ui->lineEdit_5->text();

    int resultage = isnum(age);
    int resulttelephone = isnum(telephone);
    qDebug()<<resultage<<'ccccc'<<resulttelephone;
    qDebug()<<gender;

    if(resultage != 0||resulttelephone != 0)
        {
        QMessageBox *msgbox = new QMessageBox();
        msgbox->setText("年龄与电话必须为数字");
        msgbox->setStandardButtons(QMessageBox::Yes);
        msgbox->button(QMessageBox::Yes)->setText("确认");
        msgbox->exec();
        }

    else {
        QSqlQuery query;

        QString str = tr("insert into client(ID,name,gender,age,telephone) values('%1','%2','%3',%4,'%5')").arg(ID).arg(name).arg(gender).arg(age).arg(telephone);
        qDebug()<<str;
        query.exec(str);

    }





}

void Register3::on_pushButton_clicked()
{
    this->close();
}

void Register3::on_pushButton_3_clicked()
{
    Register4window = new Register4();
    Register4window->show();
}
