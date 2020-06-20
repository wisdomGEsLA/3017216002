#ifndef BROWSE2_H
#define BROWSE2_H

#include <QMainWindow>

namespace Ui {
class Browse2;
}

class Browse2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browse2(QWidget *parent = nullptr);
    ~Browse2();
private slots:
         void on_pushButton_clicked();
private:
    Ui::Browse2 *ui;
};

#endif // BROWSE2_H
