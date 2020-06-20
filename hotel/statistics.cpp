#include "statistics.h"
#include <QtCharts>
#include "ui_statistics.h"
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>

#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <ui_statistics.h>

#include <QSqlQuery>
#include <QSqlDatabase>
static QButtonGroup* check =  new QButtonGroup();

using namespace QtCharts;

Statistics::Statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime());


    check->addButton(ui->radioButton,1);
    check->addButton(ui->radioButton_2,2);
    ui->radioButton->setChecked(true);
    check->setExclusive(true);


}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_pushButton_2_clicked()
{
    qDebug()<<QString::number(check->checkedId());
    switch (check->checkedId()) {
        case 1:{
             QDate start = ui->dateEdit->date();
             QDate end = ui->dateEdit_2->date();
             QString start_str = start.toString("yyyy-MM-dd");
             QString end_str = end.toString("yyyy-MM-dd");
             if(ui->comboBox->currentText() == "收入") {

                      QString sql_str = tr("select DATE_FORMAT(checkout_time,'%Y-%m') as time, sum(room_rates) from reservation where (check_in_status = 0 or check_in_status = 1) and checkout_time between '%1' and '%2' group by time order by time asc").arg(start_str).arg(end_str);
                      QSqlQuery query ;
                      qDebug()<<sql_str;
                      qDebug()<< query.exec(sql_str);


                      // 将图表绑定到视图
                      QChart *chart = new QChart();  //创建QChart实例,为图表框架,相当图画笔
                      //QChartView *chartview = new QChartView(chart);//用于显示曲线,相当于画布
                      QBarSet *set0 = new QBarSet("收入");
                      QStringList categories;
                      QBarSeries *series = new QBarSeries();
                      int max1 = 0;
                      while(query.next()){
                          // 参数 x 为循环自增变量 i，参数 y 为正弦函数Y值
                          categories << query.value(0).toString();
                          qDebug()<<query.value(0).toString();
                          *set0<<query.value(1).toInt();
                          if(max1 < query.value(1).toInt())
                              max1 = query.value(1).toInt();
                      }

                      QBarCategoryAxis *axisX = new QBarCategoryAxis();
                      axisX->setCategories(categories);
                      QStringList test = axisX->categories();
                      for (int i = 0; i < test.size(); ++i)
                          qDebug() << test.at(i).toLocal8Bit().constData() << "?";
                      series->append(set0);
                      chart->addSeries(series);
                      chart->addAxis(axisX, Qt::AlignBottom);
                      series->attachAxis(axisX);
                      QValueAxis *axisY = new QValueAxis();
                      axisY->setRange(0,max1 *1.2);
                      chart->addAxis(axisY, Qt::AlignLeft);
                      series->attachAxis(axisY);
                      // 将系列添加到图表
                      // 基于已添加到图表的 series 来创建默认的坐标轴

                      chart->setTitle("收入统计");
                      chart->setAnimationOptions(QChart::SeriesAnimations);

                      chart->legend()->setVisible(true);
                      chart->legend()->setAlignment(Qt::AlignBottom);
                      ui->widget->setChart(chart);
             }

             else if (ui->comboBox->currentText() == "房型使用统计") {
                     // 将图表绑定到视图
                     QChart *chart = new QChart();  //创建QChart实例,为图表框架,相当图画笔
                     //QChartView *chartview = new QChartView(chart);//用于显示曲线,相当于画布

                     QStringList types;
                     QStringList categories;
                     QBarSeries *series = new QBarSeries();
                     QSqlQuery query;
                     QString sql_room_type = tr("select  type from room_type");
                     query.exec(sql_room_type);
                     while(query.next()){
                         // 参数 x 为循环自增变量 i，参数 y 为正弦函数Y值
                         types << query.value(0).toString();
                         qDebug()<<query.value(0).toString();
                     }
                     QBarSet **set;
                     set = new QBarSet*[types.size()];
                     for(int i = 0;i<types.size();++i){
                         set[i] = new QBarSet(types.at(i));

                     }
                     QString sql_str = tr("select DATE_FORMAT(checkout_time,'%Y-%m') as time, R.type,count(*) from reservation RE,room R where R.room_id = RE.room_id and( checkout_time between '%1' and '%2') group by time,R.type order by time asc,type desc").arg(start_str).arg(end_str);
                     query.exec(sql_str);
                     QString currentdate;
                     int max1= 0;
                     int found=0;
                     while(query.next()){
                         if(query.value(0).toString()!=currentdate){
                             currentdate = query.value(0).toString();
                             if(found != 0){
                                 for(int i = found;i<types.size();++i){
                                     *set[i] << 0;
                                 }
                             }

                             found=0;
                         }

                         for(int i = found;i<types.size();++i){
                             if(types[i] == query.value(1).toString()){
                                 qDebug()<<query.value(1).toString()<<query.value(2).toString() << set[i]->label() << i;
                                 *set[i] << query.value(2).toInt();
                                 if(query.value(2).toInt()>max1){
                                     max1 = query.value(2).toInt();
                                 }
                                 found = i+1;
                                 break;
                              }
                             else {
                                 *set[i] << 0;
                             }
                         }
                         categories << query.value(0).toString();

                     }
                     QBarCategoryAxis *axisX = new QBarCategoryAxis();
                     axisX->setCategories(categories);
                     //for(int i = 0;i<types.size();++i){

                     //}
                     qDebug()<<set[1]->count();
                     qDebug()<<set[2]->count();
                     qDebug()<<set[3]->count();

                     for(int i = 0;i<types.size();++i){
                         series->append(set[i]);

                     }
                    // series->append(set[4]);
                     chart->addSeries(series);
                     chart->addAxis(axisX, Qt::AlignBottom);
                     series->attachAxis(axisX);

                     QValueAxis *axisY = new QValueAxis();
                     axisY->setRange(0,max1 *2);
                     chart->addAxis(axisY, Qt::AlignLeft);
                     series->attachAxis(axisY);
                     chart->setTitle("房型统计");
                     chart->setAnimationOptions(QChart::SeriesAnimations);

                     chart->legend()->setVisible(true);
                     chart->legend()->setAlignment(Qt::AlignBottom);
                     ui->widget->setChart(chart);
             }
        break;}
        case 2:{
        QDate start = ui->dateEdit->date();
        QDate end = ui->dateEdit_2->date();
        QString start_str = start.toString("yyyy-MM-dd");
        QString end_str = end.toString("yyyy-MM-dd");
        if(ui->comboBox->currentText() == "收入") {

                 QString sql_str = tr("select DATE_FORMAT(checkout_time,'%Y-%m-%d') as time, sum(room_rates) from reservation where (check_in_status = 0 or check_in_status = 1) and checkout_time between '%1' and '%2' group by time order by time asc").arg(start_str).arg(end_str);
                 QSqlQuery query ;
                 qDebug()<<sql_str;
                 qDebug()<< query.exec(sql_str);


                 // 将图表绑定到视图
                 QChart *chart = new QChart();  //创建QChart实例,为图表框架,相当图画笔
                 //QChartView *chartview = new QChartView(chart);//用于显示曲线,相当于画布
                 QBarSet *set0 = new QBarSet("收入");
                 QStringList categories;
                 QBarSeries *series = new QBarSeries();
                 int max1 = 0;
                 while(query.next()){
                     // 参数 x 为循环自增变量 i，参数 y 为正弦函数Y值
                     categories << query.value(0).toString();
                     qDebug()<<query.value(0).toString();
                     *set0<<query.value(1).toInt();
                     if(max1 < query.value(1).toInt())
                         max1 = query.value(1).toInt();
                 }

                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
                 axisX->setCategories(categories);
                 QStringList test = axisX->categories();
                 for (int i = 0; i < test.size(); ++i)
                     qDebug() << test.at(i).toLocal8Bit().constData() << "?";
                 series->append(set0);
                 chart->addSeries(series);
                 chart->addAxis(axisX, Qt::AlignBottom);
                 series->attachAxis(axisX);
                 QValueAxis *axisY = new QValueAxis();
                 axisY->setRange(0,max1 *1.2);
                 chart->addAxis(axisY, Qt::AlignLeft);
                 series->attachAxis(axisY);
                 // 将系列添加到图表
                 // 基于已添加到图表的 series 来创建默认的坐标轴

                 chart->setTitle("收入统计");
                 chart->setAnimationOptions(QChart::SeriesAnimations);

                 chart->legend()->setVisible(true);
                 chart->legend()->setAlignment(Qt::AlignBottom);
                 ui->widget->setChart(chart);
        }

        else if (ui->comboBox->currentText() == "房型使用统计") {
                // 将图表绑定到视图
                QChart *chart = new QChart();  //创建QChart实例,为图表框架,相当图画笔
                //QChartView *chartview = new QChartView(chart);//用于显示曲线,相当于画布

                QStringList types;
                QStringList categories;
                QBarSeries *series = new QBarSeries();
                QSqlQuery query ;
                QString sql_room_type = tr("select  type from room_type");
                query.exec(sql_room_type);
                while(query.next()){
                    // 参数 x 为循环自增变量 i，参数 y 为正弦函数Y值
                    types << query.value(0).toString();
                }
                QBarSet **set;
                set = new QBarSet*[types.size()];
                for(int i = 0;i<types.size();++i){
                    set[i] = new QBarSet(types.at(i));

                }
                QString sql_str = tr("select DATE_FORMAT(checkout_time,'%Y-%m-%d') as time, R.type,count(*) from reservation RE,room R where R.room_id = RE.room_id and( checkout_time between '%1' and '%2') group by time,R.type order by time asc,type desc").arg(start_str).arg(end_str);
                query.exec(sql_str);
                QString currentdate;
                int max1= 0;
                int found=0;
                while(query.next()){
                    if(query.value(0).toString()!=currentdate){
                        currentdate = query.value(0).toString();
                        if(found != 0){
                            for(int i = found;i<types.size();++i){
                                *set[i] << 0;
                            }
                        }

                        found=0;
                    }

                    for(int i = found;i<types.size();++i){
                        if(types[i] == query.value(1).toString()){
                            qDebug()<<query.value(1).toString()<<query.value(2).toString() << set[i]->label() << i;
                            *set[i] << query.value(2).toInt();
                            if(query.value(2).toInt()>max1){
                                max1 = query.value(2).toInt();
                            }
                            found = i+1;
                            break;
                         }
                        else {
                            *set[i] << 0;
                        }
                    }
                    categories << query.value(0).toString();

                }
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                axisX->setCategories(categories);
                //for(int i = 0;i<types.size();++i){

                //}
                qDebug()<<set[1]->count();
                qDebug()<<set[2]->count();
                qDebug()<<set[3]->count();

                for(int i = 0;i<types.size();++i){
                    series->append(set[i]);

                }
               // series->append(set[4]);
                chart->addSeries(series);
                chart->addAxis(axisX, Qt::AlignBottom);
                series->attachAxis(axisX);

                QValueAxis *axisY = new QValueAxis();
                axisY->setRange(0,max1 *2);
                chart->addAxis(axisY, Qt::AlignLeft);
                series->attachAxis(axisY);
                chart->setTitle("房型统计");
                chart->setAnimationOptions(QChart::SeriesAnimations);

                chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);
                ui->widget->setChart(chart);
        }
   break;
    }
    }

}

