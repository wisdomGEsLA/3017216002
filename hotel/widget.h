#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "appoinment1.h"

extern QString name,id,number,in_time,out_time;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void reshow();

private:
    Ui::Widget *ui;
    appoinment1 *appo1;
};

#endif // WIDGET_H
