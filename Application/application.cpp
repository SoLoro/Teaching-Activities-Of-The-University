#include "application.h"
#include "ui_application.h"

application::application(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);
}

application::~application()
{
    delete ui;
}
