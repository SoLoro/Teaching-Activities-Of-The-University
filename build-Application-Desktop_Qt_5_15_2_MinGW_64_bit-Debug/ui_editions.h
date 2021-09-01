/********************************************************************************
** Form generated from reading UI file 'editions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITIONS_H
#define UI_EDITIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editions
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_LineEdit;
    QLineEdit *type_LineEdit;
    QLineEdit *title_LineEdit;
    QLineEdit *source_LineEdit;
    QLineEdit *pages_LineEdit;
    QLineEdit *status_LineEdit;
    QLineEdit *contacts_LineEdit;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *saveButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *editions)
    {
        if (editions->objectName().isEmpty())
            editions->setObjectName(QString::fromUtf8("editions"));
        editions->resize(1077, 596);
        editions->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 250);"));
        verticalLayoutWidget_2 = new QWidget(editions);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(330, 20, 601, 461));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        name_LineEdit->setObjectName(QString::fromUtf8("name_LineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(12);
        name_LineEdit->setFont(font);
        name_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(name_LineEdit);

        type_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        type_LineEdit->setObjectName(QString::fromUtf8("type_LineEdit"));
        type_LineEdit->setFont(font);
        type_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(type_LineEdit);

        title_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        title_LineEdit->setObjectName(QString::fromUtf8("title_LineEdit"));
        title_LineEdit->setFont(font);
        title_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(title_LineEdit);

        source_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        source_LineEdit->setObjectName(QString::fromUtf8("source_LineEdit"));
        source_LineEdit->setFont(font);
        source_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(source_LineEdit);

        pages_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        pages_LineEdit->setObjectName(QString::fromUtf8("pages_LineEdit"));
        pages_LineEdit->setFont(font);
        pages_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pages_LineEdit);

        status_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        status_LineEdit->setObjectName(QString::fromUtf8("status_LineEdit"));
        status_LineEdit->setFont(font);
        status_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(status_LineEdit);

        contacts_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        contacts_LineEdit->setObjectName(QString::fromUtf8("contacts_LineEdit"));
        contacts_LineEdit->setFont(font);
        contacts_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(contacts_LineEdit);

        verticalLayoutWidget_3 = new QWidget(editions);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(480, 480, 281, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(verticalLayoutWidget_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(18);
        saveButton->setFont(font1);
        saveButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));

        verticalLayout_3->addWidget(saveButton);

        verticalLayoutWidget = new QWidget(editions);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(38, 30, 291, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font2.setPointSize(14);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(editions);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(940, 360, 121, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font3.setPointSize(10);
        label_9->setFont(font3);
        label_10 = new QLabel(editions);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(940, 410, 121, 31));
        label_10->setFont(font3);

        retranslateUi(editions);

        QMetaObject::connectSlotsByName(editions);
    } // setupUi

    void retranslateUi(QWidget *editions)
    {
        editions->setWindowTitle(QCoreApplication::translate("editions", "Form", nullptr));
        saveButton->setText(QCoreApplication::translate("editions", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("editions", "\320\244\320\230\320\236 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("editions", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("editions", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("editions", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 (\320\270\320\267\320\264\320\260\320\275\320\270\320\265)", nullptr));
        label_6->setText(QCoreApplication::translate("editions", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        label_7->setText(QCoreApplication::translate("editions", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_8->setText(QCoreApplication::translate("editions", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 (\321\202\320\265\320\273.)", nullptr));
        label_9->setText(QCoreApplication::translate("editions", "(true \320\270\320\273\320\270 false)", nullptr));
        label_10->setText(QCoreApplication::translate("editions", "(8XXXXXXXXXX)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editions: public Ui_editions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITIONS_H
