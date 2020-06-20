#include "browse3.h"
#include "ui_browse3.h"

Browse3::Browse3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browse3)
{
    ui->setupUi(this);
}

Browse3::~Browse3()
{
    delete ui;
}
