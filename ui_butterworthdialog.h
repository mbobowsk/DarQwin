/********************************************************************************
** Form generated from reading UI file 'butterworthdialog.ui'
**
** Created: Fri Nov 16 17:54:28 2012
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
#include <QtGui/QFormLayout>
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
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *cutoffSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *orderSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ButterworthDialog)
    {
        if (ButterworthDialog->objectName().isEmpty())
            ButterworthDialog->setObjectName(QString::fromUtf8("ButterworthDialog"));
        ButterworthDialog->resize(384, 141);
        formLayout = new QFormLayout(ButterworthDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
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


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(ButterworthDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        orderSpinBox = new QSpinBox(ButterworthDialog);
        orderSpinBox->setObjectName(QString::fromUtf8("orderSpinBox"));
        orderSpinBox->setMinimum(1);
        orderSpinBox->setMaximum(10);

        horizontalLayout_3->addWidget(orderSpinBox);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

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


        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout);


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
