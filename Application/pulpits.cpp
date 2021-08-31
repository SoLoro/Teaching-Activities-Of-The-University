#include "pulpits.h"
#include "ui_pulpits.h"

pulpits::pulpits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pulpits)
{
    ui->setupUi(this);
}

pulpits::~pulpits()
{
    delete ui;
}
