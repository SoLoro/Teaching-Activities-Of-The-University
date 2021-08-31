#include "teachers.h"
#include "ui_teachers.h"

#include <QSqlQuery>
#include <QMessageBox>

teachers::teachers(QString name, bool isEditing) :
    ui(new Ui::teachers)
{
    ui->setupUi(this);
    teachers::setWindowTitle("teachers");
    ui->name_LineEdit->setText(name);
    _prevname = name;
    Editing = isEditing;
    QSqlDatabase myApplicationDB = QSqlDatabase::database("database");

    if (Editing)
    {
        QSqlQuery thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT teachers_discipline from teachers WHERE teacher_name = :_newname");
        thisQuery.bindValue(":_newname", _prevname);
        thisQuery.exec();
        thisQuery.first();
        ui->discipline_LineEdit->setText(thisQuery.value(0).toString());

        thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT teachers_position from teachers WHERE teacher_name = :_newname");
        thisQuery.bindValue(":_newname", _prevname);
        thisQuery.exec();
        thisQuery.first();
        ui->position_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT teachers_telephone from teachers WHERE teacher_name = :_newname");
        thisQuery.bindValue(":_newname", _prevname);
        thisQuery.exec();
        thisQuery.first();
        ui->telephone_LineEdit->setText(thisQuery.value(0).toString());
    }
}

teachers::~teachers()
{
    delete ui;
}
