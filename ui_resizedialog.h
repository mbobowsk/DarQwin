/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created: Wed Nov 21 19:54:59 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ResizeDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
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
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *bilinearButton;
    QRadioButton *nearestButton;
    QRadioButton *cubicButton;
    QRadioButton *lanczosButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeDialog)
    {
        if (ResizeDialog->objectName().isEmpty())
            ResizeDialog->setObjectName(QString::fromUtf8("ResizeDialog"));
        ResizeDialog->resize(387, 231);
        gridLayout_3 = new QGridLayout(ResizeDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(ResizeDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scaleButton = new QRadioButton(groupBox_2);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setChecked(true);

        gridLayout_2->addWidget(scaleButton, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        scaleXSpinBox = new QDoubleSpinBox(groupBox_2);
        scaleXSpinBox->setObjectName(QString::fromUtf8("scaleXSpinBox"));
        scaleXSpinBox->setDecimals(1);
        scaleXSpinBox->setMinimum(0.1);
        scaleXSpinBox->setMaximum(10);
        scaleXSpinBox->setSingleStep(0.1);
        scaleXSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleXSpinBox);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        scaleYSpinBox = new QDoubleSpinBox(groupBox_2);
        scaleYSpinBox->setObjectName(QString::fromUtf8("scaleYSpinBox"));
        scaleYSpinBox->setDecimals(1);
        scaleYSpinBox->setMinimum(0.1);
        scaleYSpinBox->setMaximum(10);
        scaleYSpinBox->setSingleStep(0.1);
        scaleYSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleYSpinBox);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        customButton = new QRadioButton(groupBox_2);
        customButton->setObjectName(QString::fromUtf8("customButton"));

        gridLayout_2->addWidget(customButton, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        customXSpinBox = new QSpinBox(groupBox_2);
        customXSpinBox->setObjectName(QString::fromUtf8("customXSpinBox"));
        customXSpinBox->setMinimum(1);
        customXSpinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(customXSpinBox);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        customYSpinBox = new QSpinBox(groupBox_2);
        customYSpinBox->setObjectName(QString::fromUtf8("customYSpinBox"));
        customYSpinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(customYSpinBox);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(ResizeDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bilinearButton = new QRadioButton(groupBox);
        bilinearButton->setObjectName(QString::fromUtf8("bilinearButton"));
        bilinearButton->setChecked(true);

        gridLayout->addWidget(bilinearButton, 0, 0, 1, 1);

        nearestButton = new QRadioButton(groupBox);
        nearestButton->setObjectName(QString::fromUtf8("nearestButton"));

        gridLayout->addWidget(nearestButton, 1, 0, 1, 1);

        cubicButton = new QRadioButton(groupBox);
        cubicButton->setObjectName(QString::fromUtf8("cubicButton"));

        gridLayout->addWidget(cubicButton, 2, 0, 1, 1);

        lanczosButton = new QRadioButton(groupBox);
        lanczosButton->setObjectName(QString::fromUtf8("lanczosButton"));

        gridLayout->addWidget(lanczosButton, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ResizeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(ResizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeDialog)
    {
        ResizeDialog->setWindowTitle(QApplication::translate("ResizeDialog", "Resize Image", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ResizeDialog", "Resize type", 0, QApplication::UnicodeUTF8));
        scaleButton->setText(QApplication::translate("ResizeDialog", "Scale Factors", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ResizeDialog", "  X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ResizeDialog", "  Y", 0, QApplication::UnicodeUTF8));
        customButton->setText(QApplication::translate("ResizeDialog", "Custom Size", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ResizeDialog", "X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ResizeDialog", "Y", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ResizeDialog", "Interpolation", 0, QApplication::UnicodeUTF8));
        bilinearButton->setText(QApplication::translate("ResizeDialog", "Bilinear", 0, QApplication::UnicodeUTF8));
        nearestButton->setText(QApplication::translate("ResizeDialog", "Nearest-neighbor", 0, QApplication::UnicodeUTF8));
        cubicButton->setText(QApplication::translate("ResizeDialog", "Cubic 4x4", 0, QApplication::UnicodeUTF8));
        lanczosButton->setText(QApplication::translate("ResizeDialog", "Lanczos 8x8", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ResizeDialog: public Ui_ResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
