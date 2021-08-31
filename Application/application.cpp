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
