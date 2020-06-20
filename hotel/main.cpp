#include "hotelroommanagementsystem.h"
#include <QApplication>
#include <QSqlDatabase>
#include<QMessageBox>
#include <QSqlQuery>
void connect_mysql()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("127.0.0.1");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
        db.setDatabaseName("data");      //连接数据库名，与设置一致
        db.setUserName("cy");          //数据库用户名，与设置一致
        db.setPassword("a784166247");    //数据库密码，与设置一致
        db.open();
        if(!db.open())
        {

            QMessageBox::critical(0, QObject::tr("无法打开数据库"),"无法创建数据库连接！ ", QMessageBox::Cancel);
            return ;
        }
        else
        {
             //qDebug()<<"连接成功"<<"connect to mysql OK";
        }
        QSqlQuery query(db);
        query.exec("select * from student");
        while(query.next()){
            //qDebug()<<query.value("name").toString();
        }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HotelRoomManagementSystem w;
    connect_mysql();
    w.show();

    return a.exec();
}
