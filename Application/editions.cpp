#include "editions.h"
#include "ui_editions.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include <QSystemTrayIcon>
#include <QSqlQuery>
#include <QMessageBox>

editions::editions(QString title, bool isEditing) :
    ui(new Ui::editions)
{
    ui->setupUi(this);
    editions::setWindowTitle("Editions");
    ui->title_LineEdit->setText(title);
    _prevtitle = title;
    Editing = isEditing;
    QSqlDatabase myApplicationDB = QSqlDatabase::database("database");

}

editions::~editions()
{
    delete ui;
}
