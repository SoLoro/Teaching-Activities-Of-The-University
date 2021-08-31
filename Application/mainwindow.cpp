#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Password_lineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
    login = "";
    password = "";
}


void MainWindow::on_pushButton_clicked()
{
    login = ui->Login_lineEdit->text();
    password = ui->Password_lineEdit->text();
    myApplicationDB = QSqlDatabase::addDatabase("QPSQL");
    myApplicationDB.setHostName("localhost");
    myApplicationDB.setDatabaseName("database");
    myApplicationDB.setUserName(login);
    myApplicationDB.setPassword(password);
    bool checker = myApplicationDB.open();
    if (checker)
    {
        myApplication = new application();
        myApplication->show();
        this->close();
    }
    else
        QMessageBox::about(this, "Error", "Возникла ошибка входа (Неверное сочетание логин + пароль)");
    ui->Login_lineEdit->setText("");
    ui->Password_lineEdit->setText("");
}

