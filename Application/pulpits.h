#ifndef PULPITS_H
#define PULPITS_H

#include <QWidget>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class pulpits;
}

class pulpits : public QDialog
{
    Q_OBJECT

public:
    explicit pulpits(int real, bool isEditing);
    ~pulpits();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pulpits *ui;
    QSqlQueryModel* workplans;
    QSqlQueryModel* teachers;
    QSqlQueryModel* editions;
    bool Editing;
    QSqlDatabase myApplicationDB;
    int realID;
};

#endif // PULPITS_H
