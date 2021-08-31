#include "workplans.h"
#include "ui_workplans.h"

workplans::workplans(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workplans)
{
    ui->setupUi(this);
}

workplans::~workplans()
{
    delete ui;
}
