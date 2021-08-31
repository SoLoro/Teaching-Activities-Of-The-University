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
}

pulpits::~pulpits()
{
    delete ui;
}
