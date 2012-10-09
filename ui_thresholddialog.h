/********************************************************************************
** Form generated from reading UI file 'thresholddialog.ui'
**
** Created: Tue Oct 9 23:39:23 2012
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
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QRadioButton *binaryInvButton;
    QRadioButton *binaryButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *threshSlider;
    QSpinBox *threshBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ThresholdDialog)
    {
        if (ThresholdDialog->objectName().isEmpty())
            ThresholdDialog->setObjectName(QString::fromUtf8("ThresholdDialog"));
        ThresholdDialog->resize(320, 240);
        gridLayout = new QGridLayout(ThresholdDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ThresholdDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        binaryInvButton = new QRadioButton(groupBox);
        binaryInvButton->setObjectName(QString::fromUtf8("binaryInvButton"));
        binaryInvButton->setGeometry(QRect(0, 60, 131, 22));
        binaryButton = new QRadioButton(groupBox);
        binaryButton->setObjectName(QString::fromUtf8("binaryButton"));
        binaryButton->setGeometry(QRect(0, 30, 109, 22));
        binaryButton->setChecked(true);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ThresholdDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 281, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        threshSlider = new QSlider(layoutWidget);
        threshSlider->setObjectName(QString::fromUtf8("threshSlider"));
        threshSlider->setMinimum(1);
        threshSlider->setMaximum(256);
        threshSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(threshSlider);

        threshBox = new QSpinBox(layoutWidget);
        threshBox->setObjectName(QString::fromUtf8("threshBox"));
        threshBox->setMinimum(1);
        threshBox->setMaximum(256);

        horizontalLayout->addWidget(threshBox);


        verticalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ThresholdDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


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
        binaryInvButton->setText(QApplication::translate("ThresholdDialog", "Binary Inverted", 0, QApplication::UnicodeUTF8));
        binaryButton->setText(QApplication::translate("ThresholdDialog", "Binary", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ThresholdDialog", "Thresh Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ThresholdDialog: public Ui_ThresholdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDDIALOG_H
