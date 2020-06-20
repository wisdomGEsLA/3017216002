#ifndef BROWSE1_H
#define BROWSE1_H

#include <QMainWindow>

namespace Ui {
class Browse1;
}

class Browse1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browse1(QWidget *parent = nullptr);
    ~Browse1();
private slots:
         void on_pushButton_clicked();
private:
    Ui::Browse1 *ui;
};

#endif // BROWSE1_H
