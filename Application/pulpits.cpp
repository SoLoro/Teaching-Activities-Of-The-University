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


void pulpits::on_pushButton_clicked()
{
    if (Editing)
    {
        QSqlQuery thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT * from function_change_pulpit(:_id ,:_newtitle , :_newtelephone, :_newhead, :_newteachername , :_newworkplandirection , :_neweditiontitle );");
        thisQuery.bindValue(":_id", realID);
        thisQuery.bindValue(":_newtitle", ui->titleEdit->text());
        thisQuery.bindValue(":_newtelephone", ui->telephoneEdit->text());
        thisQuery.bindValue(":_newhead", ui->headEdit->text());
        thisQuery.bindValue(":_newteachername", ui->teacherComboBox->currentText());
        thisQuery.bindValue(":_newworkplandirection", ui->workplanComboBox->currentText());
        thisQuery.bindValue(":_neweditiontitle", ui->editionCombobox->currentText());
        bool checker = thisQuery.exec();
        if (checker)
        {
            QMessageBox::about(this,"Great!", "pulpits changed!");
        }
        if (!checker){
            QMessageBox::about(this,"Error!", "Something went wrong!");}
    }

    if (!Editing)
    {
        QSqlQuery thisQuery = QSqlQuery(myApplicationDB);
        thisQuery.prepare("SELECT * from function_add_pulpit(:_title, :_telephone , :_head , :_teachername, :_workplandirection , :_editiontitle );");
        thisQuery.bindValue(":_title", ui->titleEdit->text());
        thisQuery.bindValue(":_telephone", ui->telephoneEdit->text());
        thisQuery.bindValue(":_head", ui->headEdit->text());
        thisQuery.bindValue(":_teachername", ui->teacherComboBox->currentText());
        thisQuery.bindValue(":_workplandirection", ui->workplanComboBox->currentText());
        thisQuery.bindValue(":_editiontitle", ui->editionCombobox->currentText());
        bool checker = thisQuery.exec();
        if (checker)
        {
            QMessageBox::about(this,"Great!", "?????????? ??????????????!");
        }
        if (!checker)
            QMessageBox::about(this,"Error!", "??????-???? ?????????? ???? ??????!");
    }
}

