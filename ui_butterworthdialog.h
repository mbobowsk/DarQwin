/********************************************************************************
** Form generated from reading UI file 'butterworthdialog.ui'
**
** Created: Mon Dec 17 11:38:47 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTERWORTHDIALOG_H
#define UI_BUTTERWORTHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ButterworthDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *cutoffSpinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *orderSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ButterworthDialog)
    {
        if (ButterworthDialog->objectName().isEmpty())
            ButterworthDialog->setObjectName(QString::fromUtf8("ButterworthDialog"));
        ButterworthDialog->resize(415, 117);
        gridLayout = new QGridLayout(ButterworthDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(ButterworthDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cutoffSpinBox = new QSpinBox(ButterworthDialog);
        cutoffSpinBox->setObjectName(QString::fromUtf8("cutoffSpinBox"));
        cutoffSpinBox->setMinimum(1);
        cutoffSpinBox->setMaximum(999);

        horizontalLayout_2->addWidget(cutoffSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(ButterworthDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        orderSpinBox = new QSpinBox(ButterworthDialog);
        orderSpinBox->setObjectName(QString::fromUtf8("orderSpinBox"));
        orderSpinBox->setMinimum(1);
        orderSpinBox->setMaximum(100);

        horizontalLayout_3->addWidget(orderSpinBox);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        helpButton = new QPushButton(ButterworthDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout->addWidget(helpButton);

        previewButton = new QPushButton(ButterworthDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(ButterworthDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(ButterworthDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ButterworthDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ButterworthDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ButterworthDialog);
    } // setupUi

    void retranslateUi(QDialog *ButterworthDialog)
    {
        ButterworthDialog->setWindowTitle(QApplication::translate("ButterworthDialog", "Butterworth Filter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ButterworthDialog", "Cutoff (pix)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ButterworthDialog", "Order (pix)", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("ButterworthDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("ButterworthDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ButterworthDialog: public Ui_ButterworthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTERWORTHDIALOG_H
