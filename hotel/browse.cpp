#include "browse.h"
#include "ui_browse.h"
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
Browse::Browse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browse)
{
    ui->setupUi(this);
}

Browse::~Browse()
{
    delete ui;
}

void Browse::on_pushButton_clicked()
{
    browse1.show();
}void Browse::on_pushButton_2_clicked()
{
    browse2.show();
}void Browse::on_pushButton_3_clicked()
{
    browse3.show();
}void Browse::on_pushButton_4_clicked()
{
    browse4.show();
}
