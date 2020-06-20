#ifndef NEW_ROOM_H
#define NEW_ROOM_H

#include <QDialog>

namespace Ui {
class new_room;
}

class new_room : public QDialog
{
    Q_OBJECT

public:
    explicit new_room(QWidget *parent = nullptr);
    ~new_room();

private slots:
    void on_pushButton_clicked();

private:
    Ui::new_room *ui;
};

#endif // NEW_ROOM_H
