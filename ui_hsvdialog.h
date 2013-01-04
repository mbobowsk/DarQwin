/********************************************************************************
** Form generated from reading UI file 'hsvdialog.ui'
**
** Created: Fri Jan 4 18:22:48 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVDIALOG_H
#define UI_HSVDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HSVDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *hueSpinBox;
    QSlider *hueSlider;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *saturationSpinBox;
    QSlider *saturationSlider;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HSVDialog)
    {
        if (HSVDialog->objectName().isEmpty())
            HSVDialog->setObjectName(QString::fromUtf8("HSVDialog"));
        HSVDialog->resize(355, 208);
        formLayout = new QFormLayout(HSVDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(HSVDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hueSpinBox = new QSpinBox(groupBox);
        hueSpinBox->setObjectName(QString::fromUtf8("hueSpinBox"));
        hueSpinBox->setMinimum(-180);
        hueSpinBox->setMaximum(180);

        horizontalLayout->addWidget(hueSpinBox);

        hueSlider = new QSlider(groupBox);
        hueSlider->setObjectName(QString::fromUtf8("hueSlider"));
        hueSlider->setMinimum(-180);
        hueSlider->setMaximum(180);
        hueSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hueSlider);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(HSVDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saturationSpinBox = new QSpinBox(groupBox_2);
        saturationSpinBox->setObjectName(QString::fromUtf8("saturationSpinBox"));
        saturationSpinBox->setMinimum(-100);
        saturationSpinBox->setMaximum(100);

        horizontalLayout_2->addWidget(saturationSpinBox);

        saturationSlider = new QSlider(groupBox_2);
        saturationSlider->setObjectName(QString::fromUtf8("saturationSlider"));
        saturationSlider->setMinimum(-100);
        saturationSlider->setMaximum(100);
        saturationSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(saturationSlider);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        previewButton = new QPushButton(HSVDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_3->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(HSVDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_3);


        retranslateUi(HSVDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HSVDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HSVDialog, SLOT(reject()));
        QObject::connect(hueSpinBox, SIGNAL(valueChanged(int)), hueSlider, SLOT(setValue(int)));
        QObject::connect(hueSlider, SIGNAL(valueChanged(int)), hueSpinBox, SLOT(setValue(int)));
        QObject::connect(saturationSpinBox, SIGNAL(valueChanged(int)), saturationSlider, SLOT(setValue(int)));
        QObject::connect(saturationSlider, SIGNAL(valueChanged(int)), saturationSpinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(HSVDialog);
    } // setupUi

    void retranslateUi(QDialog *HSVDialog)
    {
        HSVDialog->setWindowTitle(QApplication::translate("HSVDialog", "HSV", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("HSVDialog", "Hue", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("HSVDialog", "Saturation (%)", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("HSVDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HSVDialog: public Ui_HSVDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVDIALOG_H
