#include "teachers.h"
#include "ui_teachers.h"

teachers::teachers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teachers)
{
    ui->setupUi(this);
}

teachers::~teachers()
{
    delete ui;
}
