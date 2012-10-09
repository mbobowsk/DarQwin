/********************************************************************************
** Form generated from reading UI file 'bilateraldialog.ui'
**
** Created: Tue Oct 9 23:39:23 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILATERALDIALOG_H
#define UI_BILATERALDIALOG_H

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
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BilateralDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *diameterLabel;
    QSlider *diameterSlider;
    QSpinBox *diameterSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sigmaCLabel;
    QSlider *sigmaCSlider;
    QSpinBox *sigmaCSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *sigmaSLabel;
    QSlider *sigmaSSlider;
    QSpinBox *sigmaSSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BilateralDialog)
    {
        if (BilateralDialog->objectName().isEmpty())
            BilateralDialog->setObjectName(QString::fromUtf8("BilateralDialog"));
        BilateralDialog->resize(379, 183);
        gridLayout = new QGridLayout(BilateralDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        diameterLabel = new QLabel(BilateralDialog);
        diameterLabel->setObjectName(QString::fromUtf8("diameterLabel"));

        horizontalLayout_3->addWidget(diameterLabel);

        diameterSlider = new QSlider(BilateralDialog);
        diameterSlider->setObjectName(QString::fromUtf8("diameterSlider"));
        diameterSlider->setMinimum(3);
        diameterSlider->setMaximum(11);
        diameterSlider->setSingleStep(1);
        diameterSlider->setPageStep(2);
        diameterSlider->setOrientation(Qt::Horizontal);
        diameterSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(diameterSlider);

        diameterSpinBox = new QSpinBox(BilateralDialog);
        diameterSpinBox->setObjectName(QString::fromUtf8("diameterSpinBox"));
        diameterSpinBox->setMinimum(3);
        diameterSpinBox->setMaximum(11);
        diameterSpinBox->setSingleStep(1);

        horizontalLayout_3->addWidget(diameterSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sigmaCLabel = new QLabel(BilateralDialog);
        sigmaCLabel->setObjectName(QString::fromUtf8("sigmaCLabel"));

        horizontalLayout_2->addWidget(sigmaCLabel);

        sigmaCSlider = new QSlider(BilateralDialog);
        sigmaCSlider->setObjectName(QString::fromUtf8("sigmaCSlider"));
        sigmaCSlider->setMaximum(200);
        sigmaCSlider->setSliderPosition(10);
        sigmaCSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sigmaCSlider);

        sigmaCSpinBox = new QSpinBox(BilateralDialog);
        sigmaCSpinBox->setObjectName(QString::fromUtf8("sigmaCSpinBox"));
        sigmaCSpinBox->setMaximum(200);
        sigmaCSpinBox->setValue(10);

        horizontalLayout_2->addWidget(sigmaCSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sigmaSLabel = new QLabel(BilateralDialog);
        sigmaSLabel->setObjectName(QString::fromUtf8("sigmaSLabel"));

        horizontalLayout->addWidget(sigmaSLabel);

        sigmaSSlider = new QSlider(BilateralDialog);
        sigmaSSlider->setObjectName(QString::fromUtf8("sigmaSSlider"));
        sigmaSSlider->setMaximum(200);
        sigmaSSlider->setValue(10);
        sigmaSSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sigmaSSlider);

        sigmaSSpinBox = new QSpinBox(BilateralDialog);
        sigmaSSpinBox->setObjectName(QString::fromUtf8("sigmaSSpinBox"));
        sigmaSSpinBox->setMaximum(200);
        sigmaSSpinBox->setValue(10);

        horizontalLayout->addWidget(sigmaSSpinBox);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BilateralDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(BilateralDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BilateralDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BilateralDialog, SLOT(reject()));
        QObject::connect(diameterSlider, SIGNAL(valueChanged(int)), diameterSpinBox, SLOT(setValue(int)));
        QObject::connect(sigmaCSlider, SIGNAL(valueChanged(int)), sigmaCSpinBox, SLOT(setValue(int)));
        QObject::connect(sigmaSSlider, SIGNAL(valueChanged(int)), sigmaSSpinBox, SLOT(setValue(int)));
        QObject::connect(diameterSpinBox, SIGNAL(valueChanged(int)), diameterSlider, SLOT(setValue(int)));
        QObject::connect(sigmaCSpinBox, SIGNAL(valueChanged(int)), sigmaCSlider, SLOT(setValue(int)));
        QObject::connect(sigmaSSpinBox, SIGNAL(valueChanged(int)), sigmaSSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(BilateralDialog);
    } // setupUi

    void retranslateUi(QDialog *BilateralDialog)
    {
        BilateralDialog->setWindowTitle(QApplication::translate("BilateralDialog", "Bilateral Filter", 0, QApplication::UnicodeUTF8));
        diameterLabel->setText(QApplication::translate("BilateralDialog", "Diameter", 0, QApplication::UnicodeUTF8));
        sigmaCLabel->setText(QApplication::translate("BilateralDialog", "Sigma Color", 0, QApplication::UnicodeUTF8));
        sigmaSLabel->setText(QApplication::translate("BilateralDialog", "Sigma Space", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BilateralDialog: public Ui_BilateralDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILATERALDIALOG_H
