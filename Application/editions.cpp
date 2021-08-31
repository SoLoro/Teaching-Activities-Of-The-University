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

    if (Editing)
    {
        QSqlQuery thisQuery = QSqlQuery(myApplicationDB);

        thisQuery.prepare("SELECT edition_name from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->name_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery.prepare("SELECT edition_type from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->type_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery.prepare("SELECT edition_source from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->source_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery.prepare("SELECT edition_pages from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->pages_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery.prepare("SELECT edition_status from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->status_LineEdit->setText(thisQuery.value(0).toString());


        thisQuery.prepare("SELECT edition_contacts from editions WHERE edition_title = :_newtitle");
        thisQuery.bindValue(":_newtitle", _prevtitle);
        thisQuery.exec();
        thisQuery.first();
        ui->contacts_LineEdit->setText(thisQuery.value(0).toString());

    }

}

editions::~editions()
{
    delete ui;
}
