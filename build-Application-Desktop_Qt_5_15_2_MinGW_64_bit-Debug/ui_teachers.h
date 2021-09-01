/********************************************************************************
** Form generated from reading UI file 'teachers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERS_H
#define UI_TEACHERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teachers
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_LineEdit;
    QLineEdit *discipline_LineEdit;
    QLineEdit *position_LineEdit;
    QLineEdit *telephone_LineEdit;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *saveButton;
    QLabel *label_10;

    void setupUi(QWidget *teachers)
    {
        if (teachers->objectName().isEmpty())
            teachers->setObjectName(QString::fromUtf8("teachers"));
        teachers->resize(1072, 460);
        teachers->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 250);"));
        verticalLayoutWidget = new QWidget(teachers);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 50, 261, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(teachers);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(300, 40, 601, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        name_LineEdit->setObjectName(QString::fromUtf8("name_LineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(12);
        name_LineEdit->setFont(font1);
        name_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(name_LineEdit);

        discipline_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        discipline_LineEdit->setObjectName(QString::fromUtf8("discipline_LineEdit"));
        discipline_LineEdit->setFont(font1);
        discipline_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(discipline_LineEdit);

        position_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        position_LineEdit->setObjectName(QString::fromUtf8("position_LineEdit"));
        position_LineEdit->setFont(font1);
        position_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(position_LineEdit);

        telephone_LineEdit = new QLineEdit(verticalLayoutWidget_2);
        telephone_LineEdit->setObjectName(QString::fromUtf8("telephone_LineEdit"));
        telephone_LineEdit->setFont(font1);
        telephone_LineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(telephone_LineEdit);

        verticalLayoutWidget_3 = new QWidget(teachers);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(460, 320, 281, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(verticalLayoutWidget_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font2.setPointSize(18);
        saveButton->setFont(font2);
        saveButton->setStyleSheet(QString::fromUtf8("background-color:rgb(176, 196, 222);"));

        verticalLayout_3->addWidget(saveButton);

        label_10 = new QLabel(teachers);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(910, 260, 121, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font3.setPointSize(10);
        label_10->setFont(font3);

        retranslateUi(teachers);

        QMetaObject::connectSlotsByName(teachers);
    } // setupUi

    void retranslateUi(QWidget *teachers)
    {
        teachers->setWindowTitle(QCoreApplication::translate("teachers", "Form", nullptr));
        label->setText(QCoreApplication::translate("teachers", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("teachers", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("teachers", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("teachers", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        saveButton->setText(QCoreApplication::translate("teachers", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_10->setText(QCoreApplication::translate("teachers", "(8XXXXXXXXXX)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class teachers: public Ui_teachers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERS_H
