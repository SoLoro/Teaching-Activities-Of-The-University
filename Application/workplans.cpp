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


void workplans::on_saveButton_clicked()
{
    bool checker = true;

    if (ui->direction_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No direction !");
    }
    if (ui->tasks_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No tasks !");
    }
    if (ui->result_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No result!");
    }
    if (ui->deadlines_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No deadlines !");
    }
    if (ui->main_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No main !");
    }

    QSqlDatabase myApplicationDB = QSqlDatabase::database("database");

    if (checker == true)
    {
        QSqlQuery myQuery = QSqlQuery(myApplicationDB);
        if (!Editing)
        {
            myQuery.prepare("SELECT * FROM function_add_workplan(:_direction , :_tasks, :_result ,:_deadlines ,:_main);");
            myQuery.bindValue(":_direction", ui->direction_LineEdit->text());
            myQuery.bindValue(":_tasks", ui->tasks_LineEdit->text());
            myQuery.bindValue(":_result", ui->result_LineEdit->text());
            myQuery.bindValue(":_deadlines", ui->deadlines_LineEdit->text());
            myQuery.bindValue(":_main", ui->main_LineEdit->text());
            checker = myQuery.exec();
            if (checker)
            {
                QMessageBox::about(this,"Welcome!", "Новый план методической работы!");
                ui->direction_LineEdit->setText("");
                ui->tasks_LineEdit->setText("");
                ui->result_LineEdit->setText("");
                ui->deadlines_LineEdit->setText("");
                ui->main_LineEdit->setText("");
            }
            if (!checker)
                QMessageBox::about(this,"Error!", "Что-то пошло не так!");
        }
        else
        {
            myQuery.prepare("SELECT * FROM function_change_workplan(:_prevdirection ,:_newdirection , :_newtasks , :_newresult ,:_newdeadlines ,:_newmain);");
            myQuery.bindValue(":_prevdirection", _prevdirection);
            myQuery.bindValue(":_newdirection", ui->direction_LineEdit->text());
            myQuery.bindValue(":_newtasks", ui->tasks_LineEdit->text());
            myQuery.bindValue(":_newresult", ui->result_LineEdit->text());
            myQuery.bindValue(":_newdeadlines", ui->deadlines_LineEdit->text());
            myQuery.bindValue(":_newmain", ui->main_LineEdit->text());
            checker = myQuery.exec();
            if (checker)
            {
                trayIcon = new QSystemTrayIcon(this);
                trayIcon->setVisible(true);
                trayIcon->showMessage("Well done!", "планы работы были обновлены");
                ui->direction_LineEdit->setText("");
                ui->tasks_LineEdit->setText("");
                ui->result_LineEdit->setText("");
                ui->deadlines_LineEdit->setText("");
                ui->main_LineEdit->setText("");
            }
            if (!checker)
                QMessageBox::about(this,"Error!", "Что-то полшло не так!"+_prevdirection);
        }
    }
}
