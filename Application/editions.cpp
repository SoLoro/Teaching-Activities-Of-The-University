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

void editions::on_saveButton_clicked()
{
    QSqlQuery myQuery = QSqlQuery(myApplicationDB);
    bool checker = true;

    if (ui->name_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No name !");
    }

    if (ui->type_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No type !");
    }

    if (ui->title_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No title !");
    }

    if (ui->source_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No source!");
    }
    if (ui->pages_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No pages !");
    }
    if (ui->status_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No status !");
    }
    if (ui->contacts_LineEdit->text() == "")
    {
        checker = false;
        QMessageBox::about(this,"Error!", "No contacts !");
    }
    if(checker){
    if (!Editing)
    {
        myQuery.prepare("SELECT * FROM function_add_edition(:_name , :_type , :_title , :_source , :_pages , :_status , :_contacts );");
        myQuery.bindValue(":_name", ui->name_LineEdit->text());
        myQuery.bindValue(":_type", ui->type_LineEdit->text());
        myQuery.bindValue(":_title", ui->title_LineEdit->text());
        myQuery.bindValue(":_source", ui->source_LineEdit->text());
        myQuery.bindValue(":_pages", ui->pages_LineEdit->text());
        myQuery.bindValue(":_status", ui->status_LineEdit->text());
        myQuery.bindValue(":_contacts", ui->contacts_LineEdit->text());
        checker = myQuery.exec();
        if (checker)
        {
            QMessageBox::about(this,"Welcome!", "Новое издание!");
            ui->name_LineEdit->setText("");
            ui->type_LineEdit->setText("");
            ui->title_LineEdit->setText("");
            ui->source_LineEdit->setText("");
            ui->pages_LineEdit->setText("");
            ui->status_LineEdit->setText("");
            ui->contacts_LineEdit->setText("");
        }
        if (!checker){
            QMessageBox::about(this,"Error!", "Неправльно!");}

    }
    else
    {

        myQuery.prepare("SELECT * FROM function_change_edition(:_prevtitle ,:_newname, :_newtype, :_newtitle, :_newsource , :_newpages , :_newstatus , :_newcontacts );");
        myQuery.bindValue(":_prevtitle", _prevtitle);
        myQuery.bindValue(":_newname", ui->name_LineEdit->text());
        myQuery.bindValue(":_newtype", ui->type_LineEdit->text());
        myQuery.bindValue(":_newtitle", ui->title_LineEdit->text());
        myQuery.bindValue(":_newsource", ui->source_LineEdit->text());
        myQuery.bindValue(":_newpages", ui->pages_LineEdit->text());
        myQuery.bindValue(":_newstatus", ui->status_LineEdit->text());
        myQuery.bindValue(":_newcontacts", ui->contacts_LineEdit->text());
        checker = myQuery.exec();
        if (checker)
        {
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->showMessage("Mistake","bad");
            ui->name_LineEdit->setText("");
            ui->type_LineEdit->setText("");
            ui->title_LineEdit->setText("");
            ui->source_LineEdit->setText("");
            ui->pages_LineEdit->setText("");
            ui->status_LineEdit->setText("");
            ui->contacts_LineEdit->setText("");
        }
        if (!checker){
            QMessageBox::about(this,"Error!", "Неверный!" + _prevtitle);}
    }
    }

}
