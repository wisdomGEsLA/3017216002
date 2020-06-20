#ifndef NEW_TYPE_H
#define NEW_TYPE_H

#include <QDialog>

namespace Ui {
class new_type;
}

class new_type : public QDialog
{
    Q_OBJECT

public:
    explicit new_type(QWidget *parent = nullptr);
    ~new_type();

private slots:
    void on_pushButton_clicked();

private:
    Ui::new_type *ui;
};

#endif // NEW_TYPE_H
