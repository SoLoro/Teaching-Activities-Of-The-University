/********************************************************************************
** Form generated from reading UI file 'pulpits.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULPITS_H
#define UI_PULPITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pulpits
{
public:
    QComboBox *teacherComboBox;
    QComboBox *editionCombobox;
    QLabel *label_7;
    QComboBox *workplanComboBox;
    QLineEdit *titleEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *telephoneEdit;
    QLineEdit *headEdit;
    QLabel *label_8;

    void setupUi(QWidget *pulpits)
    {
        if (pulpits->objectName().isEmpty())
            pulpits->setObjectName(QString::fromUtf8("pulpits"));
        pulpits->resize(954, 511);
        pulpits->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 250);"));
        teacherComboBox = new QComboBox(pulpits);
        teacherComboBox->setObjectName(QString::fromUtf8("teacherComboBox"));
        teacherComboBox->setGeometry(QRect(290, 220, 381, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Helvetica Neue"));
        font.setPointSize(14);
        teacherComboBox->setFont(font);
        teacherComboBox->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        editionCombobox = new QComboBox(pulpits);
        editionCombobox->setObjectName(QString::fromUtf8("editionCombobox"));
        editionCombobox->setGeometry(QRect(290, 330, 381, 31));
        editionCombobox->setFont(font);
        editionCombobox->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        label_7 = new QLabel(pulpits);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(690, 110, 241, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(10);
        label_7->setFont(font1);
        workplanComboBox = new QComboBox(pulpits);
        workplanComboBox->setObjectName(QString::fromUtf8("workplanComboBox"));
        workplanComboBox->setGeometry(QRect(290, 280, 381, 31));
        workplanComboBox->setFont(font);
        workplanComboBox->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        titleEdit = new QLineEdit(pulpits);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setGeometry(QRect(290, 60, 381, 31));
        titleEdit->setFont(font);
        titleEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget = new QWidget(pulpits);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(56, 50, 231, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font2.setPointSize(14);
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(pulpits);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 400, 211, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Helvetica Neue"));
        font3.setPointSize(18);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));
        telephoneEdit = new QLineEdit(pulpits);
        telephoneEdit->setObjectName(QString::fromUtf8("telephoneEdit"));
        telephoneEdit->setGeometry(QRect(290, 110, 381, 31));
        telephoneEdit->setFont(font);
        telephoneEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        headEdit = new QLineEdit(pulpits);
        headEdit->setObjectName(QString::fromUtf8("headEdit"));
        headEdit->setGeometry(QRect(290, 170, 381, 31));
        headEdit->setFont(font);
        headEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(pulpits);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(690, 170, 51, 31));
        label_8->setFont(font1);

        retranslateUi(pulpits);

        QMetaObject::connectSlotsByName(pulpits);
    } // setupUi

    void retranslateUi(QWidget *pulpits)
    {
        pulpits->setWindowTitle(QCoreApplication::translate("pulpits", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("pulpits", "(\320\264\320\276\320\261\320\260\320\262\320\276\321\207\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\272\320\260\321\204\320\265\320\264\321\200\321\213)", nullptr));
        titleEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("pulpits", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("pulpits", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_5->setText(QCoreApplication::translate("pulpits", "\320\227\320\260\320\262\320\265\320\264\321\203\321\216\321\211\320\270\320\271 ", nullptr));
        label_6->setText(QCoreApplication::translate("pulpits", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("pulpits", "\320\237\320\273\320\260\320\275 \320\274\320\265\321\202\320\276\320\264. \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        label->setText(QCoreApplication::translate("pulpits", "\320\230\320\267\320\264. \320\264\320\265\321\217\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("pulpits", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("pulpits", "(\320\244\320\230\320\236)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pulpits: public Ui_pulpits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULPITS_H
