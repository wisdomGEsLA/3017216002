#ifndef BROWSE4_H
#define BROWSE4_H

#include <QMainWindow>
#include<QSqlQuery>
namespace Ui {
class Browse4;
}

class Browse4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browse4(QWidget *parent = nullptr);
    ~Browse4();
private slots:
         void on_pushButton_clicked();
private:
    Ui::Browse4 *ui;

};

#endif // BROWSE4_H
