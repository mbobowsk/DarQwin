/********************************************************************************
** Form generated from reading UI file 'morphdialog.ui'
**
** Created: Wed Jan 2 22:28:26 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPHDIALOG_H
#define UI_MORPHDIALOG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MorphDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *sizeSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpinBox *iterationsSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MorphDialog)
    {
        if (MorphDialog->objectName().isEmpty())
            MorphDialog->setObjectName(QString::fromUtf8("MorphDialog"));
        MorphDialog->resize(412, 123);
        gridLayout = new QGridLayout(MorphDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MorphDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        sizeSpinBox = new QSpinBox(MorphDialog);
        sizeSpinBox->setObjectName(QString::fromUtf8("sizeSpinBox"));
        sizeSpinBox->setMinimum(3);
        sizeSpinBox->setMaximum(15);
        sizeSpinBox->setSingleStep(2);

        gridLayout->addWidget(sizeSpinBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(MorphDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        iterationsSpinBox = new QSpinBox(MorphDialog);
        iterationsSpinBox->setObjectName(QString::fromUtf8("iterationsSpinBox"));
        iterationsSpinBox->setMinimum(1);
        iterationsSpinBox->setValue(1);

        gridLayout->addWidget(iterationsSpinBox, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        helpButton = new QPushButton(MorphDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout->addWidget(helpButton);

        previewButton = new QPushButton(MorphDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(MorphDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);


        retranslateUi(MorphDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MorphDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MorphDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MorphDialog);
    } // setupUi

    void retranslateUi(QDialog *MorphDialog)
    {
        MorphDialog->setWindowTitle(QApplication::translate("MorphDialog", "Morphological Operation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MorphDialog", "Size", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MorphDialog", "Iterations", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("MorphDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("MorphDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MorphDialog: public Ui_MorphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPHDIALOG_H
