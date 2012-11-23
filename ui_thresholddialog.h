/********************************************************************************
** Form generated from reading UI file 'thresholddialog.ui'
**
** Created: Fri Nov 23 14:20:17 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDDIALOG_H
#define UI_THRESHOLDDIALOG_H

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
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ThresholdDialog
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *binaryButton;
    QRadioButton *binaryInvButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *threshSlider;
    QSpinBox *threshBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ThresholdDialog)
    {
        if (ThresholdDialog->objectName().isEmpty())
            ThresholdDialog->setObjectName(QString::fromUtf8("ThresholdDialog"));
        ThresholdDialog->resize(428, 240);
        gridLayout_3 = new QGridLayout(ThresholdDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ThresholdDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        binaryButton = new QRadioButton(groupBox);
        binaryButton->setObjectName(QString::fromUtf8("binaryButton"));
        binaryButton->setChecked(true);

        gridLayout_2->addWidget(binaryButton, 0, 0, 1, 1);

        binaryInvButton = new QRadioButton(groupBox);
        binaryInvButton->setObjectName(QString::fromUtf8("binaryInvButton"));

        gridLayout_2->addWidget(binaryInvButton, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ThresholdDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        threshSlider = new QSlider(groupBox_2);
        threshSlider->setObjectName(QString::fromUtf8("threshSlider"));
        threshSlider->setMinimum(1);
        threshSlider->setMaximum(256);
        threshSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(threshSlider);

        threshBox = new QSpinBox(groupBox_2);
        threshBox->setObjectName(QString::fromUtf8("threshBox"));
        threshBox->setMinimum(1);
        threshBox->setMaximum(256);

        horizontalLayout->addWidget(threshBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        helpButton = new QPushButton(ThresholdDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_2->addWidget(helpButton);

        previewButton = new QPushButton(ThresholdDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(ThresholdDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(ThresholdDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ThresholdDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ThresholdDialog, SLOT(reject()));
        QObject::connect(threshSlider, SIGNAL(valueChanged(int)), threshBox, SLOT(setValue(int)));
        QObject::connect(threshBox, SIGNAL(valueChanged(int)), threshSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(ThresholdDialog);
    } // setupUi

    void retranslateUi(QDialog *ThresholdDialog)
    {
        ThresholdDialog->setWindowTitle(QApplication::translate("ThresholdDialog", "Threshold", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ThresholdDialog", "Threshold Mode", 0, QApplication::UnicodeUTF8));
        binaryButton->setText(QApplication::translate("ThresholdDialog", "Binary", 0, QApplication::UnicodeUTF8));
        binaryInvButton->setText(QApplication::translate("ThresholdDialog", "Binary Inverted", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ThresholdDialog", "Thresh Value", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("ThresholdDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("ThresholdDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThresholdDialog: public Ui_ThresholdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDDIALOG_H
