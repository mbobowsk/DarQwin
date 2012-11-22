/********************************************************************************
** Form generated from reading UI file 'cannydialog.ui'
**
** Created: Thu Nov 22 15:00:47 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANNYDIALOG_H
#define UI_CANNYDIALOG_H

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
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CannyDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CannyDialog)
    {
        if (CannyDialog->objectName().isEmpty())
            CannyDialog->setObjectName(QString::fromUtf8("CannyDialog"));
        CannyDialog->resize(390, 118);
        gridLayout = new QGridLayout(CannyDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(CannyDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(256);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(256);

        horizontalLayout->addWidget(spinBox);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        helpButton = new QPushButton(CannyDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_2->addWidget(helpButton);

        previewButton = new QPushButton(CannyDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(CannyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(CannyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CannyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CannyDialog, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(CannyDialog);
    } // setupUi

    void retranslateUi(QDialog *CannyDialog)
    {
        CannyDialog->setWindowTitle(QApplication::translate("CannyDialog", "Canny Edge Detection", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CannyDialog", "Low Threshold Value", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("CannyDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("CannyDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CannyDialog: public Ui_CannyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNYDIALOG_H
