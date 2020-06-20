#include "browse2.h"
#include "ui_browse2.h"
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
#include<QPushButton>
Browse2::Browse2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browse2)
{

     ui->setupUi(this);


    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()  << "证件号"<< "姓名"  << "性别" << "年龄"<<"电话");

    ui->tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个
    QSqlQuery query =  QSqlQuery();

    QString a=QString("select* from client");
    query.exec(a);
    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem((query.value(0).toString())));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem((query.value(1).toString())));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem((query.value(2).toString())));
      ui->tableWidget->setItem(i,3,new QTableWidgetItem((query.value(3).toString())));
      ui->tableWidget->setItem(i,4,new QTableWidgetItem((query.value(4).toString())));


      i++;
    }
    ui->tableWidget_2->setColumnCount(5);

    ui->tableWidget_2->setRowCount(50);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()   << "证件号"<< "姓名"  << "性别" << "年龄"<<"电话");
    ui->tableWidget_2->verticalHeader()->setVisible(false); // 隐藏水平header

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中

    ui->tableWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个

}

Browse2::~Browse2()
{
    delete ui;
}

void Browse2::on_pushButton_clicked(){

    QString str=ui->lineEdit_2->text();
    if(ui-> comboBox->currentText()=="证件号")
    {
        QSqlQuery query =  QSqlQuery();

        QString a=QString("select* from client where ID="+str);
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


          i++;
        }

    }
    if(ui-> comboBox->currentText()=="姓名")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from client where name='"+str+"'");
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


          i++;
        }

    }
    if(ui-> comboBox->currentText()=="性别")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from client where gender='"+str+"'");
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


          i++;
        }
     if(ui-> comboBox->currentText()=="年龄")
        {
            QSqlQuery query =  QSqlQuery();
            QString a=QString("select* from client where age="+str);
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


              i++;
            }

        }
    }
    if(ui-> comboBox->currentText()=="联系方式")
    {
        QSqlQuery query =  QSqlQuery();
        QString a=QString("select* from room where telephone="+str);
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

          i++;
        }

    }

}
