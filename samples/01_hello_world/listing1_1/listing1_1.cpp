#include "listing1_1.h"
#include "ui_listing1_1.h"

listing1_1::listing1_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::listing1_1)
{
    ui->setupUi(this);
}

listing1_1::~listing1_1()
{
    delete ui;
}
