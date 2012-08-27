/********************************************************************************
** Form generated from reading UI file 'brightnessdialog.ui'
**
** Created: Fri May 11 15:39:18 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSDIALOG_H
#define UI_BRIGHTNESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_brightnessDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *brightnessGroupBox;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QGroupBox *channelGroupBox;
    QFormLayout *formLayout_2;
    QRadioButton *rgbButton;
    QRadioButton *rButton;
    QRadioButton *gButton;
    QRadioButton *bButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *brightnessDialog)
    {
        if (brightnessDialog->objectName().isEmpty())
            brightnessDialog->setObjectName(QString::fromUtf8("brightnessDialog"));
        brightnessDialog->resize(397, 219);
        gridLayout_3 = new QGridLayout(brightnessDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        brightnessGroupBox = new QGroupBox(brightnessDialog);
        brightnessGroupBox->setObjectName(QString::fromUtf8("brightnessGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(brightnessGroupBox->sizePolicy().hasHeightForWidth());
        brightnessGroupBox->setSizePolicy(sizePolicy);
        brightnessGroupBox->setMinimumSize(QSize(0, 0));
        gridLayout_4 = new QGridLayout(brightnessGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        spinBox = new QSpinBox(brightnessGroupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setMinimum(-256);
        spinBox->setMaximum(256);

        gridLayout_4->addWidget(spinBox, 0, 0, 1, 1);

        horizontalSlider = new QSlider(brightnessGroupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setMinimumSize(QSize(0, 0));
        horizontalSlider->setMinimum(-256);
        horizontalSlider->setMaximum(256);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider, 0, 1, 1, 1);

        spinBox->raise();
        horizontalSlider->raise();

        gridLayout_3->addWidget(brightnessGroupBox, 0, 0, 1, 1);

        channelGroupBox = new QGroupBox(brightnessDialog);
        channelGroupBox->setObjectName(QString::fromUtf8("channelGroupBox"));
        channelGroupBox->setMinimumSize(QSize(0, 0));
        formLayout_2 = new QFormLayout(channelGroupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rgbButton = new QRadioButton(channelGroupBox);
        rgbButton->setObjectName(QString::fromUtf8("rgbButton"));
        rgbButton->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rgbButton);

        rButton = new QRadioButton(channelGroupBox);
        rButton->setObjectName(QString::fromUtf8("rButton"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rButton);

        gButton = new QRadioButton(channelGroupBox);
        gButton->setObjectName(QString::fromUtf8("gButton"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, gButton);

        bButton = new QRadioButton(channelGroupBox);
        bButton->setObjectName(QString::fromUtf8("bButton"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, bButton);

        rgbButton->raise();
        gButton->raise();
        bButton->raise();
        rButton->raise();
        rgbButton->raise();
        rButton->raise();
        gButton->raise();
        bButton->raise();

        gridLayout_3->addWidget(channelGroupBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(brightnessDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(brightnessDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), brightnessDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), brightnessDialog, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(brightnessDialog);
    } // setupUi

    void retranslateUi(QDialog *brightnessDialog)
    {
        brightnessDialog->setWindowTitle(QApplication::translate("brightnessDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        brightnessGroupBox->setTitle(QApplication::translate("brightnessDialog", "Brightness", 0, QApplication::UnicodeUTF8));
        channelGroupBox->setTitle(QApplication::translate("brightnessDialog", "Channel", 0, QApplication::UnicodeUTF8));
        rgbButton->setText(QApplication::translate("brightnessDialog", "RGB", 0, QApplication::UnicodeUTF8));
        rButton->setText(QApplication::translate("brightnessDialog", "R", 0, QApplication::UnicodeUTF8));
        gButton->setText(QApplication::translate("brightnessDialog", "G", 0, QApplication::UnicodeUTF8));
        bButton->setText(QApplication::translate("brightnessDialog", "B", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class brightnessDialog: public Ui_brightnessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSDIALOG_H
