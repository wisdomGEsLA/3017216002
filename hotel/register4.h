#ifndef REGISTER4_H
#define REGISTER4_H

#include <QMainWindow>

namespace Ui {
class Register4;
}

class Register4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register4(QWidget *parent = nullptr);
    ~Register4();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Register4 *ui;
};

#endif // REGISTER4_H
