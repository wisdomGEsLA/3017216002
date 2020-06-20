#include "browse4.h"
#include "ui_browse4.h"
#include<QTableWidget>
#include<QApplication>
#include<QSqlDatabase>
#include<QTextCodec>
#include<QSqlTableModel>
#include<QMainWindow>
#include<QDebug>
#include<QSettings>
#include<QMessageBox>

#include<QSqlQueryModel>
#include<QDateTime>
#include<QSqlRecord>
#include<QColor>
#include<QComboBox>
#include<QPushButton>
Browse4::Browse4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browse4)
{
    ui->setupUi(this);



    ui->tableWidget->setColumnCount(8);

    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()  << "预约订单号"<< "顾客id"  << "房间id" << "入住时间"<<"押金"<< "离开时间"<<"room_rates"<<"登记状态");

    ui->tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个

    QString a=QString("select* from reservation");
    QSqlQuery query =  QSqlQuery();
    bool success=query.exec(a);
    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
      ui->tableWidget->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
      ui->tableWidget->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
      ui->tableWidget->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
      ui->tableWidget->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
      ui->tableWidget->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));

      i++;
    }
    ui->tableWidget_2->setColumnCount(8);

    ui->tableWidget_2->setRowCount(50);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()   << "房间类型"<< "租金"  << "房间面积" << "房间状态"<<"预约时间"<< "房间号");
    ui->tableWidget_2->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个

}

Browse4::~Browse4()
{
    delete ui;
}

void Browse4::on_pushButton_clicked(){


    QString str=ui->lineEdit->text();
    if(ui-> comboBox->currentText()=="预约订单号")
    {

        QString a=QString("select* from reservation where order_id="+str);
        QSqlQuery query =  QSqlQuery();
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";

        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
          ui->tableWidget_2->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
          ui->tableWidget_2->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));
          i++;
        }

    }
    if(ui-> comboBox->currentText()=="顾客号")
    {

        QString a=QString("select* from reservation where client_id"+str);
        QSqlQuery query = QSqlQuery();
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";

        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
          ui->tableWidget_2->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
          ui->tableWidget_2->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));
          i++;
        }

    }
    if(ui-> comboBox->currentText()=="房间号")
    {

        QString a=QString("select* from reservation where roomid="+str);
        QSqlQuery query =  QSqlQuery();
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";

        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
          ui->tableWidget_2->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
          ui->tableWidget_2->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));
          i++;
        }

    }
    if(ui-> comboBox->currentText()=="预记入住时间")
    {

        QString a=QString("select* from reservaiton where checkin_time='"+str+'"');
        QSqlQuery query = QSqlQuery();
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";

        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
          ui->tableWidget_2->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
          ui->tableWidget_2->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));
          i++;
        }

    }
    if(ui-> comboBox->currentText()=="预计退房时间")
    {

        QString a=QString("select* from room where checkout_time='"+str+"'");
        QSqlQuery query =  QSqlQuery();
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";

        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));
          ui->tableWidget_2->setItem(i,6,new QTableWidgetItem((query.value(6).toString())));
          ui->tableWidget_2->setItem(i,7,new QTableWidgetItem((query.value(7).toString())));
          i++;
        }

    }
}
