/********************************************************************************
** Form generated from reading UI file 'rankfilterdialog.ui'
**
** Created: Thu Dec 27 13:17:04 2012
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

QT_BEGIN_NAMESPACE

class Ui_rankFilterDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *button3x3;
    QRadioButton *button5x5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *rankFilterDialog)
    {
        if (rankFilterDialog->objectName().isEmpty())
            rankFilterDialog->setObjectName(QString::fromUtf8("rankFilterDialog"));
        rankFilterDialog->resize(440, 116);
        gridLayout_2 = new QGridLayout(rankFilterDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(rankFilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button3x3 = new QRadioButton(groupBox);
        button3x3->setObjectName(QString::fromUtf8("button3x3"));
        button3x3->setChecked(true);

        horizontalLayout->addWidget(button3x3);

        button5x5 = new QRadioButton(groupBox);
        button5x5->setObjectName(QString::fromUtf8("button5x5"));

        horizontalLayout->addWidget(button5x5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(rankFilterDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(9);

        gridLayout_3->addWidget(spinBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        helpButton = new QPushButton(rankFilterDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_2->addWidget(helpButton);

        previewButton = new QPushButton(rankFilterDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(rankFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        retranslateUi(rankFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), rankFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rankFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(rankFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *rankFilterDialog)
    {
        rankFilterDialog->setWindowTitle(QApplication::translate("rankFilterDialog", "Rank Filter", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("rankFilterDialog", "Window Size", 0, QApplication::UnicodeUTF8));
        button3x3->setText(QApplication::translate("rankFilterDialog", "3x3", 0, QApplication::UnicodeUTF8));
        button5x5->setText(QApplication::translate("rankFilterDialog", "5x5", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("rankFilterDialog", "Rank Value", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("rankFilterDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("rankFilterDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rankFilterDialog: public Ui_rankFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKFILTERDIALOG_H
