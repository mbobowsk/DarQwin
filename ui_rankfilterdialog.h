/********************************************************************************
** Form generated from reading UI file 'rankfilterdialog.ui'
**
** Created: Sat Oct 13 22:07:05 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKFILTERDIALOG_H
#define UI_RANKFILTERDIALOG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rankFilterDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *previewButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *button3x3;
    QSpacerItem *horizontalSpacer;
    QRadioButton *button5x5;
    QGroupBox *groupBox_2;
    QSpinBox *spinBox;

    void setupUi(QDialog *rankFilterDialog)
    {
        if (rankFilterDialog->objectName().isEmpty())
            rankFilterDialog->setObjectName(QString::fromUtf8("rankFilterDialog"));
        rankFilterDialog->resize(320, 212);
        gridLayout = new QGridLayout(rankFilterDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(rankFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        previewButton = new QPushButton(rankFilterDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        gridLayout->addWidget(previewButton, 2, 0, 1, 1);

        groupBox = new QGroupBox(rankFilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 30, 160, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button3x3 = new QRadioButton(layoutWidget);
        button3x3->setObjectName(QString::fromUtf8("button3x3"));
        button3x3->setChecked(true);

        horizontalLayout->addWidget(button3x3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button5x5 = new QRadioButton(layoutWidget);
        button5x5->setObjectName(QString::fromUtf8("button5x5"));

        horizontalLayout->addWidget(button5x5);

        layoutWidget->raise();

        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(rankFilterDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(0, 30, 55, 27));
        spinBox->setMinimum(1);
        spinBox->setMaximum(9);

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(rankFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), rankFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rankFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(rankFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *rankFilterDialog)
    {
        rankFilterDialog->setWindowTitle(QApplication::translate("rankFilterDialog", "Rank Filter", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("rankFilterDialog", "Preview", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("rankFilterDialog", "Window Size", 0, QApplication::UnicodeUTF8));
        button3x3->setText(QApplication::translate("rankFilterDialog", "3x3", 0, QApplication::UnicodeUTF8));
        button5x5->setText(QApplication::translate("rankFilterDialog", "5x5", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("rankFilterDialog", "Rank Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rankFilterDialog: public Ui_rankFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKFILTERDIALOG_H
