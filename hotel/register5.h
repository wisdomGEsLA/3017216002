#ifndef REGISTER5_H
#define REGISTER5_H

#include <QMainWindow>
#include <register3.h>

extern QString clientid;
extern QString orderid;

namespace Ui {
class Register5;
}

class Register5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register5(QWidget *parent = nullptr);
    ~Register5();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Register5 *ui;
    Register3* register3window;
};

#endif // REGISTER5_H
