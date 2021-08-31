#ifndef EDITIONS_H
#define EDITIONS_H

#include <QWidget>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include <QSqlQuery>
#include <QSystemTrayIcon>

namespace Ui {
class editions;
}

class editions : public QDialog
{
    Q_OBJECT

public:
    explicit editions(QString title, bool isEditing);
    ~editions();

private slots:
    void on_saveButton_clicked();

private:
    Ui::editions *ui;
    QSqlDatabase myApplicationDB;
    QString _prevtitle;
    bool Editing;
    QSystemTrayIcon* trayIcon;

};

#endif // EDITIONS_H
