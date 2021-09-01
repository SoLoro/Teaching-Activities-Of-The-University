/********************************************************************************
** Form generated from reading UI file 'workplans.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKPLANS_H
#define UI_WORKPLANS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workplans
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *saveButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *direction_LineEdit;
    QLineEdit *tasks_LineEdit;
    QLineEdit *result_LineEdit;
    QLineEdit *deadlines_LineEdit;
    QLineEdit *main_LineEdit;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QWidget *workplans)
    {
        if (workplans->objectName().isEmpty())
            workplans->setObjectName(QString::fromUtf8("workplans"));
        workplans->resize(1061, 434);
        workplans->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 250);"));
        verticalLayoutWidget_3 = new QWidget(workplans);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(460, 320, 271, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(verticalLayoutWidget_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(18);
        saveButton->setFont(font);
        saveButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));

        verticalLayout_3->addWidget(saveButton);

        verticalLayoutWidget = new QWidget(workplans);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(18, 50, 301, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(14);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(workplans);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(320, 50, 591, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        direction_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        direction_LineEdit->setObjectName(QString::fromUtf8("direction_LineEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font2.setPointSize(12);
        direction_LineEdit->setFont(font2);
        direction_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(direction_LineEdit);

        tasks_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        tasks_LineEdit->setObjectName(QString::fromUtf8("tasks_LineEdit"));
        tasks_LineEdit->setFont(font2);
        tasks_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(tasks_LineEdit);

        result_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        result_LineEdit->setObjectName(QString::fromUtf8("result_LineEdit"));
        result_LineEdit->setFont(font2);
        result_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(result_LineEdit);

        deadlines_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        deadlines_LineEdit->setObjectName(QString::fromUtf8("deadlines_LineEdit"));
        deadlines_LineEdit->setFont(font2);
        deadlines_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(deadlines_LineEdit);

        main_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        main_LineEdit->setObjectName(QString::fromUtf8("main_LineEdit"));
        main_LineEdit->setFont(font2);
        main_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(main_LineEdit);

        label_10 = new QLabel(workplans);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(920, 220, 121, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font3.setPointSize(10);
        label_10->setFont(font3);
        label_11 = new QLabel(workplans);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(920, 270, 51, 31));
        label_11->setFont(font3);

        retranslateUi(workplans);

        QMetaObject::connectSlotsByName(workplans);
    } // setupUi

    void retranslateUi(QWidget *workplans)
    {
        workplans->setWindowTitle(QCoreApplication::translate("workplans", "Form", nullptr));
        saveButton->setText(QCoreApplication::translate("workplans", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("workplans", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\265\321\217\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("workplans", "\320\227\320\260\320\264\320\260\321\207\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("workplans", "\320\236\320\266\320\270\320\264\320\260\320\265\320\274\321\213\320\271 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("workplans", "\320\241\321\200\320\276\320\272 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\264\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("workplans", "\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        label_10->setText(QCoreApplication::translate("workplans", "(YYYY-MM-DD)", nullptr));
        label_11->setText(QCoreApplication::translate("workplans", "(\320\244\320\230\320\236)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class workplans: public Ui_workplans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKPLANS_H
