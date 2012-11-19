/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created: Mon Nov 19 22:44:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ResizeDialog
{
public:
    QGridLayout *gridLayout;
    QRadioButton *scaleButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *scaleXSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *scaleYSpinBox;
    QRadioButton *customButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *customXSpinBox;
    QLabel *label_4;
    QSpinBox *customYSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeDialog)
    {
        if (ResizeDialog->objectName().isEmpty())
            ResizeDialog->setObjectName(QString::fromUtf8("ResizeDialog"));
        ResizeDialog->resize(289, 183);
        gridLayout = new QGridLayout(ResizeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scaleButton = new QRadioButton(ResizeDialog);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setChecked(true);

        gridLayout->addWidget(scaleButton, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ResizeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        scaleXSpinBox = new QDoubleSpinBox(ResizeDialog);
        scaleXSpinBox->setObjectName(QString::fromUtf8("scaleXSpinBox"));
        scaleXSpinBox->setDecimals(1);
        scaleXSpinBox->setMinimum(0.1);
        scaleXSpinBox->setMaximum(10);
        scaleXSpinBox->setSingleStep(0.1);
        scaleXSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleXSpinBox);

        label_2 = new QLabel(ResizeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        scaleYSpinBox = new QDoubleSpinBox(ResizeDialog);
        scaleYSpinBox->setObjectName(QString::fromUtf8("scaleYSpinBox"));
        scaleYSpinBox->setDecimals(1);
        scaleYSpinBox->setMinimum(0.1);
        scaleYSpinBox->setMaximum(10);
        scaleYSpinBox->setSingleStep(0.1);
        scaleYSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleYSpinBox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        customButton = new QRadioButton(ResizeDialog);
        customButton->setObjectName(QString::fromUtf8("customButton"));

        gridLayout->addWidget(customButton, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(ResizeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        customXSpinBox = new QSpinBox(ResizeDialog);
        customXSpinBox->setObjectName(QString::fromUtf8("customXSpinBox"));
        customXSpinBox->setMinimum(1);
        customXSpinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(customXSpinBox);

        label_4 = new QLabel(ResizeDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        customYSpinBox = new QSpinBox(ResizeDialog);
        customYSpinBox->setObjectName(QString::fromUtf8("customYSpinBox"));
        customYSpinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(customYSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ResizeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(ResizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeDialog)
    {
        ResizeDialog->setWindowTitle(QApplication::translate("ResizeDialog", "Resize Image", 0, QApplication::UnicodeUTF8));
        scaleButton->setText(QApplication::translate("ResizeDialog", "Scale Factors", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ResizeDialog", "  X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ResizeDialog", "  Y", 0, QApplication::UnicodeUTF8));
        customButton->setText(QApplication::translate("ResizeDialog", "Custom Size", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ResizeDialog", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ResizeDialog", "Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ResizeDialog: public Ui_ResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
