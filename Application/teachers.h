#ifndef TEACHERS_H
#define TEACHERS_H

#include <QWidget>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include <QSqlQuery>
#include <QSystemTrayIcon>

namespace Ui {
class teachers;
}

class teachers : public QDialog
{
    Q_OBJECT

public:
    explicit teachers(QString name, bool isEditing);
    ~teachers();

private slots:
    void on_saveButton_clicked();

private:
    Ui::teachers *ui;
    QSqlDatabase myApplicationDB;
    bool Editing;
    QString _prevname;
    QSystemTrayIcon* trayIcon;

};

#endif // TEACHERS_H
