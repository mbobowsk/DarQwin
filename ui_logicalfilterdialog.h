/********************************************************************************
** Form generated from reading UI file 'logicalfilterdialog.ui'
**
** Created: Sat Nov 24 13:54:53 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICALFILTERDIALOG_H
#define UI_LOGICALFILTERDIALOG_H

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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_logicalFilterDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_16;
    QLineEdit *ifTextLine;
    QLabel *label_17;
    QLineEdit *thenTextLine;
    QSpacerItem *horizontalSpacer;
    QLabel *label_18;
    QLineEdit *elseTextLine;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *helpButton;
    QPushButton *previewButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *logicalFilterDialog)
    {
        if (logicalFilterDialog->objectName().isEmpty())
            logicalFilterDialog->setObjectName(QString::fromUtf8("logicalFilterDialog"));
        logicalFilterDialog->resize(460, 261);
        gridLayout = new QGridLayout(logicalFilterDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(logicalFilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        label_16 = new QLabel(logicalFilterDialog);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        ifTextLine = new QLineEdit(logicalFilterDialog);
        ifTextLine->setObjectName(QString::fromUtf8("ifTextLine"));

        gridLayout->addWidget(ifTextLine, 1, 1, 1, 2);

        label_17 = new QLabel(logicalFilterDialog);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 2, 0, 1, 1);

        thenTextLine = new QLineEdit(logicalFilterDialog);
        thenTextLine->setObjectName(QString::fromUtf8("thenTextLine"));

        gridLayout->addWidget(thenTextLine, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        label_18 = new QLabel(logicalFilterDialog);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 3, 0, 1, 1);

        elseTextLine = new QLineEdit(logicalFilterDialog);
        elseTextLine->setObjectName(QString::fromUtf8("elseTextLine"));

        gridLayout->addWidget(elseTextLine, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        helpButton = new QPushButton(logicalFilterDialog);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_4->addWidget(helpButton);

        previewButton = new QPushButton(logicalFilterDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_4->addWidget(previewButton);

        buttonBox = new QDialogButtonBox(logicalFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 3);


        retranslateUi(logicalFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), logicalFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), logicalFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(logicalFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *logicalFilterDialog)
    {
        logicalFilterDialog->setWindowTitle(QApplication::translate("logicalFilterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("logicalFilterDialog", "Analysis window", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("logicalFilterDialog", "A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("logicalFilterDialog", "B", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("logicalFilterDialog", "C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("logicalFilterDialog", "D", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("logicalFilterDialog", "E", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("logicalFilterDialog", "F", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("logicalFilterDialog", "G", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("logicalFilterDialog", "H", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("logicalFilterDialog", "I", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("logicalFilterDialog", "IF", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("logicalFilterDialog", "THEN", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("logicalFilterDialog", "ELSE", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("logicalFilterDialog", "Help", 0, QApplication::UnicodeUTF8));
        previewButton->setText(QApplication::translate("logicalFilterDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class logicalFilterDialog: public Ui_logicalFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICALFILTERDIALOG_H
