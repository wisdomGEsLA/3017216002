#ifndef REGISTER3_H
#define REGISTER3_H

#include <QMainWindow>
#include <register4.h>


namespace Ui {
class Register3;
}

class Register3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register3(QWidget *parent = nullptr);
    ~Register3();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Register3 *ui;
    Register4 * Register4window;
};

#endif // REGISTER3_H
