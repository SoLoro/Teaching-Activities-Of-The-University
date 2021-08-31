#ifndef WORKPLANS_H
#define WORKPLANS_H

#include <QWidget>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include <QSqlQuery>
#include <QSystemTrayIcon>

namespace Ui {
class workplans;
}

class workplans : public QDialog
{
    Q_OBJECT

public:
    explicit workplans(QString direction,bool isEditing);
    ~workplans();

private slots:
    void on_saveButton_clicked();

private:
    Ui::workplans *ui;
    QSqlDatabase myApplicationDB;
    bool Editing;
    QString _prevdirection;
    QSystemTrayIcon* trayIcon;


};

#endif // WORKPLANS_H
