#ifndef BROWSE3_H
#define BROWSE3_H

#include <QMainWindow>

namespace Ui {
class Browse3;
}

class Browse3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browse3(QWidget *parent = nullptr);
    ~Browse3();

private:
    Ui::Browse3 *ui;
};

#endif // BROWSE3_H
