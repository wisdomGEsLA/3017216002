#ifndef BROWSE_H
#define BROWSE_H

#include <QMainWindow>
#include"browse1.h"
#include"browse2.h"
#include"browse3.h"
#include"browse4.h"

namespace Ui {
class Browse;
}

class Browse : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browse(QWidget *parent = nullptr);
    ~Browse();

private slots:
         void on_pushButton_clicked();
         void on_pushButton_2_clicked();
         //void on_pushButton_3_clicked();
         void on_pushButton_4_clicked();
private:
    Ui::Browse *ui;
    Browse1 browse1;
    Browse2 browse2;
    //Browse3 browse3;
    Browse4 browse4;
};

#endif // BROWSE_H
