/********************************************************************************
** Form generated from reading UI file 'logicalfilterdialog.ui'
**
** Created: Mon Oct 29 16:07:18 2012
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
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_logicalFilterDialog
{
public:
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout;
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
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSplitter *splitter_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QGridLayout *gridLayout_3;
    QLabel *label_16;
    QLineEdit *ifTextLine;
    QLabel *label_17;
    QLineEdit *elseTextLine;
    QSpacerItem *horizontalSpacer;
    QLabel *label_18;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *logicalFilterDialog)
    {
        if (logicalFilterDialog->objectName().isEmpty())
            logicalFilterDialog->setObjectName(QString::fromUtf8("logicalFilterDialog"));
        logicalFilterDialog->resize(394, 261);
        gridLayout_4 = new QGridLayout(logicalFilterDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
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


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(logicalFilterDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(groupBox_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(splitter);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        splitter->addWidget(label_10);
        label_11 = new QLabel(splitter);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        splitter->addWidget(label_11);
        label_12 = new QLabel(splitter);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        splitter->addWidget(label_12);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        splitter_2->addWidget(label_13);
        label_14 = new QLabel(splitter_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        splitter_2->addWidget(label_14);
        label_15 = new QLabel(splitter_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        splitter_2->addWidget(label_15);

        gridLayout->addWidget(splitter_2, 1, 0, 1, 1);

        label_15->raise();
        label_12->raise();
        label_13->raise();
        label_11->raise();
        label_14->raise();
        label_10->raise();
        label_10->raise();
        label_11->raise();
        splitter->raise();
        splitter_2->raise();

        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox_2);


        gridLayout_4->addLayout(formLayout, 0, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_16 = new QLabel(logicalFilterDialog);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 0, 0, 1, 1);

        ifTextLine = new QLineEdit(logicalFilterDialog);
        ifTextLine->setObjectName(QString::fromUtf8("ifTextLine"));

        gridLayout_3->addWidget(ifTextLine, 0, 1, 1, 2);

        label_17 = new QLabel(logicalFilterDialog);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 1, 0, 1, 1);

        elseTextLine = new QLineEdit(logicalFilterDialog);
        elseTextLine->setObjectName(QString::fromUtf8("elseTextLine"));

        gridLayout_3->addWidget(elseTextLine, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        label_18 = new QLabel(logicalFilterDialog);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(logicalFilterDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_3->addWidget(lineEdit_3, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(logicalFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 2, 1, 1, 1);

        pushButton = new QPushButton(logicalFilterDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(logicalFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), logicalFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), logicalFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(logicalFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *logicalFilterDialog)
    {
        logicalFilterDialog->setWindowTitle(QApplication::translate("logicalFilterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("logicalFilterDialog", "Analyze window", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("logicalFilterDialog", "A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("logicalFilterDialog", "B", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("logicalFilterDialog", "C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("logicalFilterDialog", "D", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("logicalFilterDialog", "E", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("logicalFilterDialog", "F", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("logicalFilterDialog", "G", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("logicalFilterDialog", "H", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("logicalFilterDialog", "I", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("logicalFilterDialog", "Operators", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("logicalFilterDialog", "J = 0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("logicalFilterDialog", "OR - |", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("logicalFilterDialog", "EQUAL - =", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("logicalFilterDialog", "K = 255", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("logicalFilterDialog", "AND - &", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("logicalFilterDialog", "NOT EQUAL - !", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("logicalFilterDialog", "IF", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("logicalFilterDialog", "THEN E =", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("logicalFilterDialog", "ELSE  E =", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("logicalFilterDialog", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class logicalFilterDialog: public Ui_logicalFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICALFILTERDIALOG_H
