#include "listing1_2.h"
#include "./ui_listing1_2.h"

listing1_2::listing1_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listing1_2)
{
    ui->setupUi(this);
}

listing1_2::~listing1_2()
{
    delete ui;
}

