/********************************************************************************
** Form generated from reading UI file 'customfilterdialog.ui'
**
** Created: Fri Nov 23 14:20:17 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMFILTERDIALOG_H
#define UI_CUSTOMFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CustomFilterDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBox00;
    QSpinBox *spinBox01;
    QSpinBox *spinBox02;
    QSpinBox *spinBox03;
    QSpinBox *spinBox04;
    QSpinBox *spinBox10;
    QSpinBox *spinBox11;
    QSpinBox *spinBox12;
    QSpinBox *spinBox13;
    QSpinBox *spinBox14;
    QSpinBox *spinBox20;
    QSpinBox *spinBox21;
    QSpinBox *spinBox22;
    QSpinBox *spinBox23;
    QSpinBox *spinBox24;
    QSpinBox *spinBox30;
    QSpinBox *spinBox31;
    QSpinBox *spinBox32;
    QSpinBox *spinBox33;
    QSpinBox *spinBox34;
    QSpinBox *spinBox40;
    QSpinBox *spinBox41;
    QSpinBox *spinBox42;
    QSpinBox *spinBox43;
    QSpinBox *spinBox44;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CustomFilterDialog)
    {
        if (CustomFilterDialog->objectName().isEmpty())
            CustomFilterDialog->setObjectName(QString::fromUtf8("CustomFilterDialog"));
        CustomFilterDialog->resize(418, 297);
        gridLayout_3 = new QGridLayout(CustomFilterDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(CustomFilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox00 = new QSpinBox(groupBox);
        spinBox00->setObjectName(QString::fromUtf8("spinBox00"));
        spinBox00->setMinimum(-20);
        spinBox00->setMaximum(20);

        gridLayout->addWidget(spinBox00, 0, 0, 1, 1);

        spinBox01 = new QSpinBox(groupBox);
        spinBox01->setObjectName(QString::fromUtf8("spinBox01"));
        spinBox01->setMinimum(-20);
        spinBox01->setMaximum(20);

        gridLayout->addWidget(spinBox01, 0, 1, 1, 1);

        spinBox02 = new QSpinBox(groupBox);
        spinBox02->setObjectName(QString::fromUtf8("spinBox02"));
        spinBox02->setMinimum(-20);
        spinBox02->setMaximum(20);

        gridLayout->addWidget(spinBox02, 0, 2, 1, 1);

        spinBox03 = new QSpinBox(groupBox);
        spinBox03->setObjectName(QString::fromUtf8("spinBox03"));
        spinBox03->setMinimum(-20);
        spinBox03->setMaximum(20);

        gridLayout->addWidget(spinBox03, 0, 3, 1, 1);

        spinBox04 = new QSpinBox(groupBox);
        spinBox04->setObjectName(QString::fromUtf8("spinBox04"));
        spinBox04->setMinimum(-20);
        spinBox04->setMaximum(20);

        gridLayout->addWidget(spinBox04, 0, 4, 1, 1);

        spinBox10 = new QSpinBox(groupBox);
        spinBox10->setObjectName(QString::fromUtf8("spinBox10"));
        spinBox10->setMinimum(-20);
        spinBox10->setMaximum(20);

        gridLayout->addWidget(spinBox10, 1, 0, 1, 1);

        spinBox11 = new QSpinBox(groupBox);
        spinBox11->setObjectName(QString::fromUtf8("spinBox11"));
        spinBox11->setMinimum(-20);
        spinBox11->setMaximum(20);
        spinBox11->setValue(1);

        gridLayout->addWidget(spinBox11, 1, 1, 1, 1);

        spinBox12 = new QSpinBox(groupBox);
        spinBox12->setObjectName(QString::fromUtf8("spinBox12"));
        spinBox12->setMinimum(-20);
        spinBox12->setMaximum(20);
        spinBox12->setValue(1);

        gridLayout->addWidget(spinBox12, 1, 2, 1, 1);

        spinBox13 = new QSpinBox(groupBox);
        spinBox13->setObjectName(QString::fromUtf8("spinBox13"));
        spinBox13->setMinimum(-20);
        spinBox13->setMaximum(20);
        spinBox13->setValue(1);

        gridLayout->addWidget(spinBox13, 1, 3, 1, 1);

        spinBox14 = new QSpinBox(groupBox);
        spinBox14->setObjectName(QString::fromUtf8("spinBox14"));
        spinBox14->setMinimum(-20);
        spinBox14->setMaximum(20);
        spinBox14->setValue(0);

        gridLayout->addWidget(spinBox14, 1, 4, 1, 1);

        spinBox20 = new QSpinBox(groupBox);
        spinBox20->setObjectName(QString::fromUtf8("spinBox20"));
        spinBox20->setMinimum(-20);
        spinBox20->setMaximum(20);

        gridLayout->addWidget(spinBox20, 2, 0, 1, 1);

        spinBox21 = new QSpinBox(groupBox);
        spinBox21->setObjectName(QString::fromUtf8("spinBox21"));
        spinBox21->setMinimum(-20);
        spinBox21->setMaximum(20);
        spinBox21->setValue(1);

        gridLayout->addWidget(spinBox21, 2, 1, 1, 1);

        spinBox22 = new QSpinBox(groupBox);
        spinBox22->setObjectName(QString::fromUtf8("spinBox22"));
        spinBox22->setMinimum(-20);
        spinBox22->setMaximum(20);
        spinBox22->setValue(1);

        gridLayout->addWidget(spinBox22, 2, 2, 1, 1);

        spinBox23 = new QSpinBox(groupBox);
        spinBox23->setObjectName(QString::fromUtf8("spinBox23"));
        spinBox23->setMinimum(-20);
        spinBox23->setMaximum(20);
        spinBox23->setValue(1);

        gridLayout->addWidget(spinBox23, 2, 3, 1, 1);

        spinBox24 = new QSpinBox(groupBox);
        spinBox24->setObjectName(QString::fromUtf8("spinBox24"));
        spinBox24->setMinimum(-20);
        spinBox24->setMaximum(20);

        gridLayout->addWidget(spinBox24, 2, 4, 1, 1);

        spinBox30 = new QSpinBox(groupBox);
        spinBox30->setObjectName(QString::fromUtf8("spinBox30"));
        spinBox30->setMinimum(-20);
        spinBox30->setMaximum(20);

        gridLayout->addWidget(spinBox30, 3, 0, 1, 1);

        spinBox31 = new QSpinBox(groupBox);
        spinBox31->setObjectName(QString::fromUtf8("spinBox31"));
        spinBox31->setMinimum(-20);
        spinBox31->setMaximum(20);
        spinBox31->setValue(1);

        gridLayout->addWidget(spinBox31, 3, 1, 1, 1);

        spinBox32 = new QSpinBox(groupBox);
        spinBox32->setObjectName(QString::fromUtf8("spinBox32"));
        spinBox32->setMinimum(-20);
        spinBox32->setMaximum(20);
        spinBox32->setValue(1);

        gridLayout->addWidget(spinBox32, 3, 2, 1, 1);

        spinBox33 = new QSpinBox(groupBox);
        spinBox33->setObjectName(QString::fromUtf8("spinBox33"));
        spinBox33->setMinimum(-20);
        spinBox33->setMaximum(20);
        spinBox33->setValue(1);

        gridLayout->addWidget(spinBox33, 3, 3, 1, 1);

        spinBox34 = new QSpinBox(groupBox);
        spinBox34->setObjectName(QString::fromUtf8("spinBox34"));
        spinBox34->setMinimum(-20);
        spinBox34->setMaximum(20);

        gridLayout->addWidget(spinBox34, 3, 4, 1, 1);

        spinBox40 = new QSpinBox(groupBox);
        spinBox40->setObjectName(QString::fromUtf8("spinBox40"));
        spinBox40->setMinimum(-20);
        spinBox40->setMaximum(20);

        gridLayout->addWidget(spinBox40, 4, 0, 1, 1);

        spinBox41 = new QSpinBox(groupBox);
        spinBox41->setObjectName(QString::fromUtf8("spinBox41"));
        spinBox41->setMinimum(-20);
        spinBox41->setMaximum(20);

        gridLayout->addWidget(spinBox41, 4, 1, 1, 1);

        spinBox42 = new QSpinBox(groupBox);
        spinBox42->setObjectName(QString::fromUtf8("spinBox42"));
        spinBox42->setMinimum(-20);
        spinBox42->setMaximum(20);

        gridLayout->addWidget(spinBox42, 4, 2, 1, 1);

        spinBox43 = new QSpinBox(groupBox);
        spinBox43->setObjectName(QString::fromUtf8("spinBox43"));
        spinBox43->setMinimum(-20);
        spinBox43->setMaximum(20);

        gridLayout->addWidget(spinBox43, 4, 3, 1, 1);

        spinBox44 = new QSpinBox(groupBox);
        spinBox44->setObjectName(QString::fromUtf8("spinBox44"));
        spinBox44->setMinimum(-20);
        spinBox44->setMaximum(20);

        gridLayout->addWidget(spinBox44, 4, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CustomFilterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(CustomFilterDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setValue(9);

        horizontalLayout->addWidget(spinBox);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        helpButton = new QPushButton(CustomFilterDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_2->addWidget(helpButton);

        previewButton = new QPushButton(CustomFilterDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(CustomFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(CustomFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CustomFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CustomFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CustomFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomFilterDialog)
    {
        CustomFilterDialog->setWindowTitle(QApplication::translate("CustomFilterDialog", "Custom Filter", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CustomFilterDialog", "Define Filter Mask", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CustomFilterDialog", "Divide by:", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("CustomFilterDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("CustomFilterDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CustomFilterDialog: public Ui_CustomFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMFILTERDIALOG_H
