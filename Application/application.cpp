#include "application.h"
#include "ui_application.h"

#include "mainwindow.h"
#include <QMessageBox>
#include <QShortcut>
#include <QSqlQuery>

application::application ():

    ui(new Ui::application)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    application::setWindowTitle("application");
    ui->tableView->verticalHeader()->hide();

    QSqlDatabase myApplicationDB = QSqlDatabase::database("database");
    myTeacher = new class teachers ("", false);
    myWorkplan = new class workplans ("", false);
    myEdition = new class editions("", false);
    myPulpit  = new class pulpits(0, false);
    chosenTable = "none";
}

application::~application()
{
    delete ui;
    delete myTeacher;
    delete myWorkplan;
}

void application::on_showTeachers_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    teachers = new QSqlTableModel(this,myApplicationDB);
    teachers->setTable("teachers");
    teachers->select();
    teachers->setHeaderData(0, Qt::Horizontal, tr("ID"));
    teachers->setHeaderData(1, Qt::Horizontal, tr("ФИО"));
    teachers->setHeaderData(2, Qt::Horizontal, tr("Дисциплина"));
    teachers->setHeaderData(3, Qt::Horizontal, tr("Должность"));
    teachers->setHeaderData(4, Qt::Horizontal, tr("Телефон"));
    ui->tableView->setModel(teachers);
    chosenTable = "teachers";
    myWorkplan->hide();
    myPulpit->hide();
    myEdition->hide();

    comboBoxModel = new QSqlQueryModel;
    QSqlQuery get_teachers = QSqlQuery(myApplicationDB);
    get_teachers.prepare("SELECT teacher_name FROM teachers");
    get_teachers.exec();
    comboBoxModel->setQuery(get_teachers);
    ui->comboBox->setModel(comboBoxModel);
    ui->tableView->setColumnHidden(0, true);
}

void application::on_showWorkplans_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    workplans = new QSqlTableModel(this,myApplicationDB);
    workplans->setTable("workplans");
    workplans->select();
    workplans->setHeaderData(0, Qt::Horizontal, tr("ID"));
    workplans->setHeaderData(1, Qt::Horizontal, tr("Направление деятельн."));
    workplans->setHeaderData(2, Qt::Horizontal, tr("Задачи"));
    workplans->setHeaderData(3, Qt::Horizontal, tr("Ожидаемый результат"));
    workplans->setHeaderData(4, Qt::Horizontal, tr("Срок сдачи"));
    workplans->setHeaderData(5, Qt::Horizontal, tr("Ответственный"));
    ui->tableView->setModel(workplans);
    chosenTable = "workplans";
    myTeacher->hide();
    myPulpit->hide();
    myEdition->hide();

    comboBoxModel = new QSqlQueryModel;
    QSqlQuery get_workplans = QSqlQuery(myApplicationDB);
    get_workplans.prepare("SELECT workplan_direction FROM workplans");
    get_workplans.exec();
    comboBoxModel->setQuery(get_workplans);
    ui->comboBox->setModel(comboBoxModel);
    ui->tableView->setColumnHidden(0, true);
}

void application::on_showPulpits_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    pulpits = new QSqlTableModel(this,myApplicationDB);
    QSqlQuery get_pulpits = QSqlQuery(myApplicationDB);
    get_pulpits.prepare("SELECT pulpit_id, pulpit_title, pulpit_telephone,pulpit_head, (select teacher_name from teachers where teacher_id=pulpit_teacher_id),(select workplan_direction from workplans where workplan_id=pulpit_workplan_id),(select edition_title from editions where edition_id=pulpit_edition_id) FROM pulpits");
    get_pulpits.exec();
    pulpits->setQuery(get_pulpits);
    pulpits->setHeaderData(0, Qt::Horizontal, tr("ID"));
    pulpits->setHeaderData(1, Qt::Horizontal, tr("Название кафедры"));
    pulpits->setHeaderData(2, Qt::Horizontal, tr("Телефон"));
    pulpits->setHeaderData(3, Qt::Horizontal, tr("Заведующий"));
    pulpits->setHeaderData(4, Qt::Horizontal, tr("ФИО преподавателя"));
    pulpits->setHeaderData(5, Qt::Horizontal, tr("Название плана работы"));
    pulpits->setHeaderData(6, Qt::Horizontal, tr("Название произведения"));
    ui->tableView->setModel(pulpits);
    chosenTable = "pulpits";
    myWorkplan->hide();
    myTeacher->hide();
    myEdition->hide();
    ui->tableView->setColumnHidden(0, true);

    comboBoxModel = new QSqlQueryModel;
    QSqlQuery get_pulpit = QSqlQuery(myApplicationDB);
    get_pulpit.prepare("SELECT pulpit_id FROM pulpits");
    get_pulpit.exec();
    comboBoxModel->setQuery(get_pulpit);
    ui->comboBox->setModel(comboBoxModel);
}

void application::on_showEditions_clicked()
{

    ui->comboBox->setCurrentIndex(0);
    editions = new QSqlTableModel(this,myApplicationDB);
    editions->setTable("editions");
    editions->select();
    editions->setHeaderData(0, Qt::Horizontal, tr("ID"));
    editions->setHeaderData(1, Qt::Horizontal, tr("ФИО"));
    editions->setHeaderData(2, Qt::Horizontal, tr("Тип произведения"));
    editions->setHeaderData(3, Qt::Horizontal, tr("Название произведения"));
    editions->setHeaderData(4, Qt::Horizontal, tr("Источник"));
    editions->setHeaderData(5, Qt::Horizontal, tr("Кол-во страниц"));
    editions->setHeaderData(6, Qt::Horizontal, tr("Статус"));
    editions->setHeaderData(7, Qt::Horizontal, tr("Контактные данные"));
    ui->tableView->setModel(editions);
    chosenTable = "editions";
    myTeacher->hide();
    myPulpit->hide();
    myWorkplan->hide();

    comboBoxModel = new QSqlQueryModel;
    QSqlQuery get_editions = QSqlQuery(myApplicationDB);
    get_editions.prepare("SELECT edition_title FROM editions");
    get_editions.exec();
    comboBoxModel->setQuery(get_editions);
    ui->comboBox->setModel(comboBoxModel);
    ui->tableView->setColumnHidden(0, true);

}

void application::on_addButton_clicked()
{
    if (chosenTable == "none")
    {
        QMessageBox::about(this, "Error", "Выберите таблицу, в которую вы хотите добавить в первую очередь!");
    }

    if (chosenTable == "teachers")
    {
        delete myTeacher;
        myTeacher = new class teachers ("", false);
        myTeacher->show();
    }

    if (chosenTable == "workplans")
    {
        delete myWorkplan;
        myWorkplan = new class workplans ("", false);
        myWorkplan->show();
    }

    if (chosenTable == "editions")
    {
        delete myEdition;
        myEdition = new class editions ("", false);
        myEdition->show();
    }

    if (chosenTable == "pulpits")
    {
        myPulpit->show();
    }
}


void application::on_editButton_clicked()
{
    if (chosenTable == "none")
    {
        QMessageBox::about(this, "Error", "Выберите таблицу, которую вы хотите отредактировать в первую очередь!");
    }

    if (chosenTable == "teachers")
    {
        delete myTeacher;
        myTeacher = new class teachers (ui->comboBox->currentText(), true);
        myTeacher->show();
    }

    if (chosenTable == "workplans")
    {
        delete myWorkplan;
        myWorkplan = new class workplans (ui->comboBox->currentText(), true);
        myWorkplan->show();
    }

    if (chosenTable == "pulpits")
    {
        delete myPulpit;
        myPulpit = new class pulpits(ui->comboBox->currentText().toInt(), true);
        myPulpit->show();
    }

    if (chosenTable == "editions")
    {
        delete myEdition;
        myEdition = new class editions (ui->comboBox->currentText(), true);
        myEdition->show();
    }
}

void application::on_deleteButton_clicked()
{
    QSqlQuery deleteQuery = QSqlQuery(myApplicationDB);
    QString item = ui->comboBox->currentText();
    bool checker;
    if (chosenTable == "teachers")
    {
        deleteQuery.prepare("SELECT * FROM public.function_delete_teacher(:_name);");
        deleteQuery.bindValue(":_name", item);
        checker = deleteQuery.exec();
        if (!checker)
            QMessageBox::about(this,"Error", "Ошибка! Преподаватель " + item + " не может быть удален!");
        else
        {
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->showMessage("We will miss them!", "Вы успешно удалили" +item + " преподователя.");
        }
    }
    else
    {
        if (chosenTable == "workplans")
        {
            deleteQuery.prepare("SELECT * FROM public.function_delete_workplan(:_direction);");
            deleteQuery.bindValue(":_direction", item);
            checker = deleteQuery.exec();
            if (!checker)
                QMessageBox::about(this,"Error", "Error! Направление деятельности " + item + " не может быть удалено!");
            else
            {
                trayIcon = new QSystemTrayIcon(this);
                trayIcon->setVisible(true);
                trayIcon->showMessage("Hope to see them again!", "You succesfully deleted " +item);
            }
        }
    }
    if (chosenTable == "pulpits")
    {
        deleteQuery.prepare("SELECT * FROM public.function_delete_pulpit(:_id);");
        deleteQuery.bindValue(":_id", item.toInt());
        checker = deleteQuery.exec();
        if (!checker)
            QMessageBox::about(this,"Error", "Ошибка!" + item + "Вы успешно удалили!");
        else
        {
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->showMessage("Lost!", "Кафедра была удалена");
        }
    }

    if (chosenTable == "editions")
    {
        deleteQuery.prepare("SELECT * FROM public.function_delete_edition(:_title);");
        deleteQuery.bindValue(":_title", item);
        checker = deleteQuery.exec();
        if (!checker)
            QMessageBox::about(this,"Error", "Ошибка!" + item + " Издание не может быть удалено!");
        else
        {
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->showMessage("It's been great!", "Метод издания был удален");
        }
    }
}

void application::on_funcButton_clicked()
{
    ui->tableView->setColumnHidden(0, false);
    QSqlQuery function = QSqlQuery(myApplicationDB);
    QString item = ui->comboBox_2->currentText();
    if(item=="Количество преподавателей на кафедре высшей математики")
    {
        function.prepare("SELECT workplan_direction,SUM (CASE WHEN pulpit_workplan_id = 2 THEN 1 ELSE  0 END) AS workplan_pulpits FROM workplans, pulpits WHERE 	pulpit_workplan_id = workplan_id AND workplan_id = 2 GROUP BY workplan_direction");
        function.exec();

        QSqlQueryModel *myModel = new QSqlQueryModel;
        myModel->setQuery(function);
        ui->tableView->setModel(myModel);
    }
    if(item=="Издательская деятельность каждого из преподавателей")
    {
        function.prepare("SELECT * FROM edition_pulpits ORDER BY amount");
        function.exec();

        QSqlQueryModel *myModel = new QSqlQueryModel;
        myModel->setQuery(function);
        ui->tableView->setModel(myModel);
    }
    if(item=="Значения издательских деятельностей кафедр по добавочным номерам кафедр")
    {
        function.prepare("SELECT pulpit_id, pulpit_telephone, (select edition_title from editions where edition_id=pulpit_edition_id) from pulpits");
        function.exec();

        QSqlQueryModel *myModel = new QSqlQueryModel;
        myModel->setQuery(function);
        ui->tableView->setModel(myModel);
    }
    if(item=="Данные о преподавателях кафедры по номеру телефона кафедры <4000")
    {
        function.prepare("SELECT  pulpit_teacher_id , min(pulpit_telephone),pulpit_title, teacher_name,teacher_discipline FROM   pulpits, teachers WHERE teacher_id = pulpit_teacher_id GROUP BY pulpit_teacher_id,pulpit_title, teacher_name,teacher_discipline HAVING (min(pulpit_telephone)<='4000');");
        function.exec();

        QSqlQueryModel *myModel = new QSqlQueryModel;
        myModel->setQuery(function);
        ui->tableView->setModel(myModel);
    }
    if(item=="Данные о кафедре, на которой работает преподаватель Жуков")
    {
        function.prepare("SELECT pulpit_title, pulpit_telephone, pulpit_head FROM	pulpits  WHERE pulpit_teacher_id = ANY (SELECT teacher_id FROM teachers WHERE teacher_name = 'Жуков Даниил Семёнович') ");
        function.exec();

        QSqlQueryModel *myModel = new QSqlQueryModel;
        myModel->setQuery(function);
        ui->tableView->setModel(myModel);
    }
}

void application::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->comboBox->setCurrentIndex(index.row());
}

void application::on_showLogs_clicked()
{
    logs = new QSqlTableModel(this,myApplicationDB);
    logs->setTable("logs");
    logs->select();
    ui->tableView->setModel(logs);
    chosenTable = "logs";

    comboBoxModel = new QSqlQueryModel;
    ui->comboBox->setModel(comboBoxModel);
}
