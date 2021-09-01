/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myvariant
{
public:
    QPushButton *showPulpits;
    QPushButton *showEditions;
    QPushButton *showTeachers;
    QComboBox *comboBox;
    QPushButton *showWorkplans;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QTableView *tableView;
    QPushButton *showLogs;
    QPushButton *editButton;
    QComboBox *comboBox_2;
    QPushButton *funcButton;

    void setupUi(QWidget *myvariant)
    {
        if (myvariant->objectName().isEmpty())
            myvariant->setObjectName(QString::fromUtf8("myvariant"));
        myvariant->resize(1017, 538);
        myvariant->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 250);"));
        showPulpits = new QPushButton(myvariant);
        showPulpits->setObjectName(QString::fromUtf8("showPulpits"));
        showPulpits->setGeometry(QRect(820, 260, 141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(10);
        showPulpits->setFont(font);
        showPulpits->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        showPulpits->setAutoDefault(false);
        showEditions = new QPushButton(myvariant);
        showEditions->setObjectName(QString::fromUtf8("showEditions"));
        showEditions->setGeometry(QRect(820, 320, 171, 41));
        showEditions->setFont(font);
        showEditions->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        showEditions->setAutoDefault(false);
        showTeachers = new QPushButton(myvariant);
        showTeachers->setObjectName(QString::fromUtf8("showTeachers"));
        showTeachers->setGeometry(QRect(820, 140, 141, 41));
        showTeachers->setFont(font);
        showTeachers->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        showTeachers->setAutoDefault(false);
        showTeachers->setFlat(false);
        comboBox = new QComboBox(myvariant);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(480, 440, 321, 31));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        showWorkplans = new QPushButton(myvariant);
        showWorkplans->setObjectName(QString::fromUtf8("showWorkplans"));
        showWorkplans->setGeometry(QRect(820, 200, 181, 41));
        showWorkplans->setFont(font);
        showWorkplans->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        showWorkplans->setAutoDefault(false);
        showWorkplans->setFlat(false);
        deleteButton = new QPushButton(myvariant);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(320, 440, 121, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(14);
        deleteButton->setFont(font1);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        addButton = new QPushButton(myvariant);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(40, 440, 121, 41));
        addButton->setFont(font1);
        addButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        tableView = new QTableView(myvariant);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 120, 761, 301));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Helvetica Neue"));
        tableView->setFont(font2);
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setWordWrap(false);
        showLogs = new QPushButton(myvariant);
        showLogs->setObjectName(QString::fromUtf8("showLogs"));
        showLogs->setGeometry(QRect(820, 381, 131, 41));
        showLogs->setFont(font);
        showLogs->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        editButton = new QPushButton(myvariant);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(180, 440, 121, 41));
        editButton->setFont(font1);
        editButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        comboBox_2 = new QComboBox(myvariant);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(360, 70, 441, 31));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        funcButton = new QPushButton(myvariant);
        funcButton->setObjectName(QString::fromUtf8("funcButton"));
        funcButton->setGeometry(QRect(820, 70, 141, 41));
        funcButton->setFont(font);
        funcButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));

        retranslateUi(myvariant);

        QMetaObject::connectSlotsByName(myvariant);
    } // setupUi

    void retranslateUi(QWidget *myvariant)
    {
        myvariant->setWindowTitle(QCoreApplication::translate("myvariant", "Form", nullptr));
        showPulpits->setText(QCoreApplication::translate("myvariant", "\320\232\320\260\321\204\320\265\320\264\321\200\321\213", nullptr));
        showEditions->setText(QCoreApplication::translate("myvariant", "\320\230\320\267\320\264. \320\264\320\265\321\217\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));
        showTeachers->setText(QCoreApplication::translate("myvariant", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        showWorkplans->setText(QCoreApplication::translate("myvariant", "\320\237\320\273\320\260\320\275\321\213 \320\274\320\265\321\202\320\276\320\264. \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        deleteButton->setText(QCoreApplication::translate("myvariant", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        addButton->setText(QCoreApplication::translate("myvariant", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        showLogs->setText(QCoreApplication::translate("myvariant", "\320\233\320\276\320\263\320\270", nullptr));
        editButton->setText(QCoreApplication::translate("myvariant", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("myvariant", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\265\320\271 \320\275\320\260 \320\272\320\260\321\204\320\265\320\264\321\200\320\265 \320\262\321\213\321\201\321\210\320\265\320\271 \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\320\272\320\270", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("myvariant", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\260\321\217 \320\264\320\265\321\217\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\272\320\260\320\266\320\264\320\276\320\263\320\276 \320\270\320\267 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("myvariant", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\270\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\270\321\205 \320\264\320\265\321\217\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\265\320\271 \320\272\320\260\321\204\320\265\320\264\321\200 \320\277\320\276 \320\264\320\276\320\261\320\260\320\262\320\276\321\207\320\275\321\213\320\274 \320\275\320\276\320\274\320\265\321\200\320\260\320\274 \320\272\320\260\321\204\320\265\320\264\321\200", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("myvariant", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217\321\205 \320\272\320\260\321\204\320\265\320\264\321\200\321\213 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260 \320\272\320\260\321\204\320\265\320\264\321\200\321\213 <4000", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("myvariant", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\272\320\260\321\204\320\265\320\264\321\200\320\265, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\320\276\320\271 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214 \320\226\321\203\320\272\320\276\320\262", nullptr));

        funcButton->setText(QCoreApplication::translate("myvariant", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myvariant: public Ui_myvariant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
