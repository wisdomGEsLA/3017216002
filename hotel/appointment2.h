#ifndef APPOINTMENT2_H
#define APPOINTMENT2_H

#include <QWidget>

namespace Ui {
class appointment2;
}

class appointment2 : public QWidget
{
    Q_OBJECT



public:
    explicit appointment2(QWidget *parent = nullptr);
    ~appointment2();

private slots:
    void on_pushButton_clicked();
    void show_information();
private:
    Ui::appointment2 *ui;
};

#endif // APPOINTMENT2_H
