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


void teachers::on_saveButton_clicked()
{
    QSqlQuery myQuery = QSqlQuery(myApplicationDB);
    bool checker = true;
    if (ui->name_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No name !");
    }

    if (ui->discipline_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No discipline!");
    }

    if (ui->position_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No position !");
    }


    if (ui->telephone_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No telephone!");
    }

    if (checker)
    {
        if (!Editing)

        {
            myQuery.prepare("SELECT * FROM function_add_teacher(:_name,:_discipline,:_position,:_telephone);");
            myQuery.bindValue(":_name", ui->name_LineEdit->text());
            myQuery.bindValue(":_discipline", ui->discipline_LineEdit->text());
            myQuery.bindValue(":_position", ui->position_LineEdit->text());
            myQuery.bindValue(":_telephone", ui->telephone_LineEdit->text());
            checker = myQuery.exec();
            if (checker)
            {
                QMessageBox::about(this,"Welcome!", "New teacher!");
                ui->name_LineEdit->setText("");
                ui->discipline_LineEdit->setText("");
                ui->position_LineEdit->setText("");
                ui->telephone_LineEdit->setText("");
            }
            if (!checker){
                QMessageBox::about(this,"Error!", "Something went wrong!");}
        }
        else
        {
            myQuery.prepare("SELECT * FROM function_change_teacher(:_prevname, :_newname, :_newdiscipline, :_newposition,  :_newtelephone);");
            myQuery.bindValue(":_prevname", _prevname);
            myQuery.bindValue(":_newname", ui->name_LineEdit->text());
            myQuery.bindValue(":_newdiscipline", ui->discipline_LineEdit->text());
            myQuery.bindValue(":_newposition", ui->position_LineEdit->text());
            myQuery.bindValue(":_newtelephone", ui->telephone_LineEdit->text());
            checker = myQuery.exec();
            if (checker)
            {
                trayIcon = new QSystemTrayIcon(this);
                trayIcon->setVisible(true);
                trayIcon->showMessage("We will miss them!", "Вы успешно обновили информацию об учителе.");
                ui->name_LineEdit->setText("");
                ui->discipline_LineEdit->setText("");
                ui->position_LineEdit->setText("");
                ui->telephone_LineEdit->setText("");
            }
            if (!checker){
                QMessageBox::about(this,"Error!", "Что-то пошло не так!"+ _prevname);}
        }

    }
}
