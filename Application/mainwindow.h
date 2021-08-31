#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include <application.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    application* myApplication;
    QSqlDatabase myApplicationDB;
    QString login;
    QString password;
};
#endif // MAINWINDOW_H
