/********************************************************************************
** Form generated from reading UI file 'thresholddialog.ui'
**
** Created: Wed Sep 26 18:51:40 2012
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
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QRadioButton *binaryInvButton;
    QRadioButton *binaryButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSlider *threshSlider;
    QSpinBox *threshBox;

    void setupUi(QDialog *ThresholdDialog)
    {
        if (ThresholdDialog->objectName().isEmpty())
            ThresholdDialog->setObjectName(QString::fromUtf8("ThresholdDialog"));
        ThresholdDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(ThresholdDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ThresholdDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 301, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        binaryInvButton = new QRadioButton(groupBox);
        binaryInvButton->setObjectName(QString::fromUtf8("binaryInvButton"));
        binaryInvButton->setGeometry(QRect(0, 60, 131, 22));
        binaryButton = new QRadioButton(groupBox);
        binaryButton->setObjectName(QString::fromUtf8("binaryButton"));
        binaryButton->setGeometry(QRect(0, 30, 109, 22));
        binaryButton->setChecked(true);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 281, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        threshSlider = new QSlider(layoutWidget1);
        threshSlider->setObjectName(QString::fromUtf8("threshSlider"));
        threshSlider->setMinimum(1);
        threshSlider->setMaximum(256);
        threshSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(threshSlider);

        threshBox = new QSpinBox(layoutWidget1);
        threshBox->setObjectName(QString::fromUtf8("threshBox"));
        threshBox->setMinimum(1);
        threshBox->setMaximum(256);

        horizontalLayout->addWidget(threshBox);


        verticalLayout->addWidget(groupBox_2);


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
