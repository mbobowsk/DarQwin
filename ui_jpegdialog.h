/********************************************************************************
** Form generated from reading UI file 'jpegdialog.ui'
**
** Created: Mon Oct 8 13:38:50 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JPEGDIALOG_H
#define UI_JPEGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JPEGDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QDialog *JPEGDialog)
    {
        if (JPEGDialog->objectName().isEmpty())
            JPEGDialog->setObjectName(QString::fromUtf8("JPEGDialog"));
        JPEGDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(JPEGDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 190, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(JPEGDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 271, 31));
        widget = new QWidget(JPEGDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 70, 231, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(58, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        widget1 = new QWidget(JPEGDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 110, 261, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(100);
        spinBox->setValue(95);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSlider = new QSlider(widget1);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(95);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);


        retranslateUi(JPEGDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), JPEGDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), JPEGDialog, SLOT(reject()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(JPEGDialog);
    } // setupUi

    void retranslateUi(QDialog *JPEGDialog)
    {
        JPEGDialog->setWindowTitle(QApplication::translate("JPEGDialog", "JPEG Compression", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JPEGDialog", "Balance picture quality and compression", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JPEGDialog", "Low quality", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JPEGDialog", "High quality", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JPEGDialog: public Ui_JPEGDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JPEGDIALOG_H
