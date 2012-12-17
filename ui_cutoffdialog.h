/********************************************************************************
** Form generated from reading UI file 'cutoffdialog.ui'
**
** Created: Mon Dec 17 11:38:47 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTOFFDIALOG_H
#define UI_CUTOFFDIALOG_H

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

class Ui_CutoffDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CutoffDialog)
    {
        if (CutoffDialog->objectName().isEmpty())
            CutoffDialog->setObjectName(QString::fromUtf8("CutoffDialog"));
        CutoffDialog->resize(402, 114);
        gridLayout = new QGridLayout(CutoffDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(CutoffDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(CutoffDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000);

        horizontalLayout_2->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(121, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(381, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        helpButton = new QPushButton(CutoffDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout->addWidget(helpButton);

        previewButton = new QPushButton(CutoffDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(CutoffDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(CutoffDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CutoffDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CutoffDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CutoffDialog);
    } // setupUi

    void retranslateUi(QDialog *CutoffDialog)
    {
        CutoffDialog->setWindowTitle(QApplication::translate("CutoffDialog", "Fourier Filter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CutoffDialog", "Set cutoff frequency in pixels", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("CutoffDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("CutoffDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CutoffDialog: public Ui_CutoffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTOFFDIALOG_H
