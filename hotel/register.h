#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <register1.h>
#include <register5.h>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();
    //void on_pushButton2_clicked();
    //void on_pushButton3_clicked();//


    void on_pushButton_2_clicked();

private:
    Register1 *Register1window;
    Register5 *Register5window;
    Ui::Register *ui;
};

#endif // REGISTER_H
