#ifndef ROOM_MANAGE_H
#define ROOM_MANAGE_H

#include <QDialog>

namespace Ui {
class room_manage;
}

class room_manage : public QDialog
{
    Q_OBJECT

public:
    explicit room_manage(QWidget *parent = nullptr);
    ~room_manage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::room_manage *ui;
signals:
    void sendData(QString,QString,QString);
};

#endif // ROOM_MANAGE_H
