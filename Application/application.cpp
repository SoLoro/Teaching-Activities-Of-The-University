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
