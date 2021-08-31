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

    if (Editing)
    {
        QSqlQuery thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT workplan_tasks from workplans WHERE workplan_direction = :_newdirection");
        thisQuery.bindValue(":_newdirection", _prevdirection);
        thisQuery.exec();
        thisQuery.first();
        ui->tasks_LineEdit->setText(thisQuery.value(0).toString());

        thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT workplan_result from workplanss WHERE workplan_direction = :_newdirection");
        thisQuery.bindValue(":_newdirection", _prevdirection);
        thisQuery.exec();
        thisQuery.first();
        ui->result_LineEdit->setText(thisQuery.value(0).toString());

        thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT workplan_deadlines from workplanss WHERE workplan_direction = :_newdirection");
        thisQuery.bindValue(":_newdirection", _prevdirection);
        thisQuery.exec();
        thisQuery.first();
        ui->deadlines_LineEdit->setText(thisQuery.value(0).toString());

        thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT workplan_main from workplanss WHERE workplan_direction = :_newdirection");
        thisQuery.bindValue(":_newdirection", _prevdirection);
        thisQuery.exec();
        thisQuery.first();
        ui->main_LineEdit->setText(thisQuery.value(0).toString());

    }
}

workplans::~workplans()
{
    delete ui;
}
