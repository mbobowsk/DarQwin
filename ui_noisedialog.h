/********************************************************************************
** Form generated from reading UI file 'noisedialog.ui'
**
** Created: Sun Dec 16 22:23:58 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISEDIALOG_H
#define UI_NOISEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NoiseDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *meanSpinBox;
    QLabel *label_2;
    QSpinBox *devSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NoiseDialog)
    {
        if (NoiseDialog->objectName().isEmpty())
            NoiseDialog->setObjectName(QString::fromUtf8("NoiseDialog"));
        NoiseDialog->resize(248, 111);
        gridLayout = new QGridLayout(NoiseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NoiseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        meanSpinBox = new QSpinBox(NoiseDialog);
        meanSpinBox->setObjectName(QString::fromUtf8("meanSpinBox"));
        meanSpinBox->setMinimum(-256);
        meanSpinBox->setMaximum(256);

        gridLayout->addWidget(meanSpinBox, 0, 1, 1, 1);

        label_2 = new QLabel(NoiseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        devSpinBox = new QSpinBox(NoiseDialog);
        devSpinBox->setObjectName(QString::fromUtf8("devSpinBox"));
        devSpinBox->setMaximum(999);

        gridLayout->addWidget(devSpinBox, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(NoiseDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(NoiseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NoiseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NoiseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NoiseDialog);
    } // setupUi

    void retranslateUi(QDialog *NoiseDialog)
    {
        NoiseDialog->setWindowTitle(QApplication::translate("NoiseDialog", "Add Gaussian Noise", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NoiseDialog", "Mean value (expectation)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NoiseDialog", "Standard deviation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NoiseDialog: public Ui_NoiseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISEDIALOG_H
