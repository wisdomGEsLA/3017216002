#include "browse1.h"
#include "ui_browse1.h"
#include<QTableWidget>
#include<QApplication>
#include<QSqlDatabase>
#include<QTextCodec>
#include<QSqlTableModel>
#include<QMainWindow>
#include<QDebug>
#include<QSettings>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDateTime>
#include<QSqlRecord>
#include<QColor>
#include<QComboBox>
Browse1::Browse1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browse1)
{
    ui->setupUi(this);



    ui->tableWidget->setColumnCount(6);

    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()  << "房间类型"<< "租金"  << "房间面积" << "房间状态"<<"预约时间"<< "房间号");

    ui->tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个
    QSqlQuery query =  QSqlQuery();
    QString a=QString("select* from room");
    query.exec(a);
    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
      ui->tableWidget->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
      ui->tableWidget->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
      ui->tableWidget->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

      i++;
    }
    ui->tableWidget_2->setColumnCount(6);

    ui->tableWidget_2->setRowCount(50);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()   << "房间类型"<< "租金"  << "房间面积" << "房间状态"<<"预约时间"<< "房间号");
    ui->tableWidget_2->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个

}

Browse1::~Browse1()
{
    delete ui;
}

void Browse1::on_pushButton_clicked(){

    QString str=ui->lineEdit_2->text();
    if(ui-> comboBox->currentText()=="房间号")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where room_id='"+str+"'");
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";
        query.exec(a);
        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

          i++;
        }

    }
    if(ui-> comboBox->currentText()=="房间类型")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where type='"+str+"'");
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";
        query.exec(a);
        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

          i++;
        }

    }
    if(ui-> comboBox->currentText()=="房间面积")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where area="+str);
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";
        query.exec(a);
        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

          i++;
        }

    }
    if(ui-> comboBox->currentText()=="租金")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where rental="+str);
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";
        query.exec(a);
        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

          i++;
        }

    }
    if(ui-> comboBox->currentText()=="房间状态")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where status='"+str+"'");
        bool success=query.exec(a);
        if(!success)qDebug()<<"!error";
        query.exec(a);
        int i=0;
        while(query.next())
        {
          ui->tableWidget_2->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
          ui->tableWidget_2->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
          ui->tableWidget_2->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
          ui->tableWidget_2->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
          ui->tableWidget_2->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));
          ui->tableWidget_2->setItem(i,5,new QTableWidgetItem((query.value(5).toString())));

          i++;
        }

    }
}
