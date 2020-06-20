#include "register1.h"
#include "register2.h"
#include "ui_register1.h"
#include <QStandardItem>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

QString orderid ;
QString clientid ;
QDate checkintime;
QString deposit;
QString roomrates;
QDate checkouttime;

Register1::Register1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register1)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime());
}

Register1::~Register1()
{
    delete ui;
}


int isDigitStr(QString src)
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


void Register1::on_pushButton_2_clicked()
{
    clientid = this->ui->lineEdit_2->text();
    checkintime = this->ui->dateEdit->date();
    checkouttime = this->ui->dateEdit_2->date();


    qDebug()<<checkintime<<checkouttime;

    int resultclient = isDigitStr(clientid);



    QMessageBox *msgbox = new QMessageBox();


    if(clientid.isEmpty())
    {
        msgbox->setText("输入值不能为空"); //设置文本
        msgbox->setStandardButtons(QMessageBox::Yes);//设置对话框有几个按钮
        msgbox->button(QMessageBox::Yes)->setText("确认");
        msgbox->exec();//执行对话框，并获取返回值

    }
    else if (resultclient != 0)
    {
        msgbox->setText("输入值必须为数字");
        msgbox->setStandardButtons(QMessageBox::Yes);//设置对话框有几个按钮
        msgbox->button(QMessageBox::Yes)->setText("确认");
        msgbox->exec();
    }
    else
    {
        Register2window = new Register2();
        Register2window->show();
    }



}

void Register1::on_pushButton_clicked()
{
    this->close();
}
