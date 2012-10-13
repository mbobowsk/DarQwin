/********************************************************************************
** Form generated from reading UI file 'cannydialog.ui'
**
** Created: Sat Oct 13 22:07:05 2012
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CannyDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *previewButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QDialog *CannyDialog)
    {
        if (CannyDialog->objectName().isEmpty())
            CannyDialog->setObjectName(QString::fromUtf8("CannyDialog"));
        CannyDialog->resize(320, 143);
        gridLayout = new QGridLayout(CannyDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(CannyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        previewButton = new QPushButton(CannyDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        gridLayout->addWidget(previewButton, 1, 0, 1, 1);

        groupBox = new QGroupBox(CannyDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 30, 271, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(100);

        horizontalLayout->addWidget(spinBox);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);


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
        previewButton->setText(QApplication::translate("CannyDialog", "Preview", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CannyDialog", "Low Threshold Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CannyDialog: public Ui_CannyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNYDIALOG_H
