#include "workplans.h"
#include "ui_workplans.h"
#include <QMessageBox>


workplans::workplans(QString direction, bool isEditing) :
    ui(new Ui::workplans)
{
    ui->setupUi(this);
    workplans::setWindowTitle("workplans");
    ui->direction_LineEdit->setText(direction);
    Editing = isEditing;
    _prevdirection = direction;
}

workplans::~workplans()
{
    delete ui;
}
