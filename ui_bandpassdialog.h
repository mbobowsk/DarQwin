/********************************************************************************
** Form generated from reading UI file 'bandpassdialog.ui'
**
** Created: Sun Nov 18 00:43:05 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANDPASSDIALOG_H
#define UI_BANDPASSDIALOG_H

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

class Ui_BandPassDialog
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *innerSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *outerSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BandPassDialog)
    {
        if (BandPassDialog->objectName().isEmpty())
            BandPassDialog->setObjectName(QString::fromUtf8("BandPassDialog"));
        BandPassDialog->resize(384, 141);
        formLayout = new QFormLayout(BandPassDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(BandPassDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        innerSpinBox = new QSpinBox(BandPassDialog);
        innerSpinBox->setObjectName(QString::fromUtf8("innerSpinBox"));
        innerSpinBox->setMinimum(1);
        innerSpinBox->setMaximum(999);
        innerSpinBox->setValue(10);

        horizontalLayout_2->addWidget(innerSpinBox);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(BandPassDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        outerSpinBox = new QSpinBox(BandPassDialog);
        outerSpinBox->setObjectName(QString::fromUtf8("outerSpinBox"));
        outerSpinBox->setMinimum(1);
        outerSpinBox->setMaximum(999);
        outerSpinBox->setValue(20);

        horizontalLayout_3->addWidget(outerSpinBox);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        helpButton = new QPushButton(BandPassDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout->addWidget(helpButton);

        previewButton = new QPushButton(BandPassDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(BandPassDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout);


        retranslateUi(BandPassDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BandPassDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BandPassDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BandPassDialog);
    } // setupUi

    void retranslateUi(QDialog *BandPassDialog)
    {
        BandPassDialog->setWindowTitle(QApplication::translate("BandPassDialog", "Band-pass Filter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BandPassDialog", "Inner radius (pix)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BandPassDialog", "Outer radius (pix)", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("BandPassDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("BandPassDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BandPassDialog: public Ui_BandPassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANDPASSDIALOG_H
