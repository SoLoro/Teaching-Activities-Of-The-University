#ifndef MYVARIANT_H
#define MYVARIANT_H

#include <QWidget>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <teachers.h>
#include <workplans.h>
#include <editions.h>
#include <pulpits.h>
#include <QSystemTrayIcon>

namespace Ui {
class application;
}

class application : public QDialog
{
    Q_OBJECT
public slots:
public:
    explicit application();
    ~application();

private slots:
    void on_showTeachers_clicked();

    void on_showWorkplans_clicked();

    void on_showPulpits_clicked();

    void on_showEditions_clicked();

    void on_showLogs_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_funcButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);


private:
    Ui::application *ui;
    QSqlDatabase myApplicationDB;
    QSqlTableModel* teachers;
    QSqlTableModel* workplans;
    QSqlTableModel* editions;
    QSqlTableModel* pulpits;
    QSqlTableModel* logs;
    class teachers* myTeacher;
    class workplans* myWorkplan;
    class editions* myEdition;
    class pulpits* myPulpit;

    QString chosenTable;
    QSystemTrayIcon* trayIcon;

    QSqlQueryModel* comboBoxModel;
    QSqlQueryModel* myView;
};

#endif // MYVARIANT_H
