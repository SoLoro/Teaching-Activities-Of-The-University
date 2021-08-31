#include "editions.h"
#include "ui_editions.h"

editions::editions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editions)
{
    ui->setupUi(this);
}

editions::~editions()
{
    delete ui;
}
