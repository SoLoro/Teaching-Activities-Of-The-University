#include "pulpits.h"
#include "ui_pulpits.h"
#include <QSqlDatabase>
#include <QSql>
#include <QMessageBox>

pulpits::pulpits(int real, bool isEditing) :
    ui(new Ui::pulpits)
{
    ui->setupUi(this);
    pulpits::setWindowTitle("pulpits");
    QSqlDatabase myApplicationDB = QSqlDatabase::database("database");

    teachers = new QSqlQueryModel;
    QSqlQuery get_teachers = QSqlQuery(myApplicationDB);
    get_teachers.prepare("SELECT teacher_name FROM teachers");
    get_teachers.exec();
    teachers->setQuery(get_teachers);
    ui->teacherComboBox->setModel(teachers);

    workplans = new QSqlQueryModel;
    QSqlQuery get_workplans = QSqlQuery(myApplicationDB);
    get_workplans.prepare("SELECT workplan_direction FROM workplans");
    get_workplans.exec();
    workplans->setQuery(get_workplans);
    ui->workplanComboBox->setModel(workplans);

    editions = new QSqlQueryModel;
    QSqlQuery get_editions = QSqlQuery(myApplicationDB);
    get_editions.prepare("SELECT edition_title FROM editions");
    get_editions.exec();
    editions->setQuery(get_editions);
    ui->editionCombobox->setModel(editions);


    Editing = isEditing;
    realID = real;
    QSqlQuery thisQuery = QSqlQuery(myApplicationDB);
}

pulpits::~pulpits()
{
    delete ui;
}
