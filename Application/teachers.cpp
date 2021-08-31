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
}

teachers::~teachers()
{
    delete ui;
}
