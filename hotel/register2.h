#ifndef REGISTER2_H
#define REGISTER2_H

#include <QMainWindow>
#include <register3.h>

namespace Ui {
class Register2;
}

extern QString roomid;


class Register2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register2(QWidget *parent = nullptr);
    ~Register2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Register2 *ui;
    Register3* register3window;
};

#endif // REGISTER2_H
