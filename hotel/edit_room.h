#ifndef EDIT_ROOM_H
#define EDIT_ROOM_H

#include <QDialog>

namespace Ui {
class edit_room;
}

class edit_room : public QDialog
{
    Q_OBJECT

public:
    explicit edit_room(QWidget *parent = nullptr);
    ~edit_room();
private slots:
    void receiveData(QString type,QString area,QString room_id);
    void on_pushButton_clicked();

private:
    Ui::edit_room *ui;
};

#endif // EDIT_ROOM_H
