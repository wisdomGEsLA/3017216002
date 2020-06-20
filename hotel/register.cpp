#include "register.h"
#include "ui_register.h"
#include "register1.h"
#include "register5.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
   Register1window = new Register1(this);
   Register1window->show();
}





void Register::on_pushButton_2_clicked()
{
    Register5window = new Register5(this);
    Register5window->show();
}
