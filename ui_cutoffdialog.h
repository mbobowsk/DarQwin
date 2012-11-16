/********************************************************************************
** Form generated from reading UI file 'cutoffdialog.ui'
**
** Created: Thu Nov 15 17:48:31 2012
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
#include <QtGui/QFormLayout>
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
    QFormLayout *formLayout;
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
        CutoffDialog->resize(402, 133);
        formLayout = new QFormLayout(CutoffDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
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


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(121, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::FieldRole, horizontalSpacer);

        verticalSpacer = new QSpacerItem(381, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::SpanningRole, verticalSpacer);

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


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);


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
