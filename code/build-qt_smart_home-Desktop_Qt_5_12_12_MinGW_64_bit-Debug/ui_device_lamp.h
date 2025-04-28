/********************************************************************************
** Form generated from reading UI file 'device_lamp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_LAMP_H
#define UI_DEVICE_LAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceLamp
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_background;
    QLabel *label_name_lamp;
    QLabel *label_lamp;
    QLabel *label_onoff;

    void setupUi(QWidget *DeviceLamp)
    {
        if (DeviceLamp->objectName().isEmpty())
            DeviceLamp->setObjectName(QString::fromUtf8("DeviceLamp"));
        DeviceLamp->resize(282, 280);
        gridLayout = new QGridLayout(DeviceLamp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        frame_background = new QFrame(DeviceLamp);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        label_name_lamp = new QLabel(frame_background);
        label_name_lamp->setObjectName(QString::fromUtf8("label_name_lamp"));
        label_name_lamp->setGeometry(QRect(200, 190, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\261\211\344\273\252\346\227\227\351\273\221-45S"));
        font.setPointSize(20);
        label_name_lamp->setFont(font);
        label_lamp = new QLabel(frame_background);
        label_lamp->setObjectName(QString::fromUtf8("label_lamp"));
        label_lamp->setGeometry(QRect(10, 10, 175, 255));
        label_lamp->setStyleSheet(QString::fromUtf8("background-color: rgb(171, 171, 171);"));
        label_onoff = new QLabel(frame_background);
        label_onoff->setObjectName(QString::fromUtf8("label_onoff"));
        label_onoff->setGeometry(QRect(200, 230, 71, 31));
        QFont font1;
        font1.setPointSize(16);
        label_onoff->setFont(font1);

        gridLayout->addWidget(frame_background, 0, 0, 1, 1);


        retranslateUi(DeviceLamp);

        QMetaObject::connectSlotsByName(DeviceLamp);
    } // setupUi

    void retranslateUi(QWidget *DeviceLamp)
    {
        DeviceLamp->setWindowTitle(QApplication::translate("DeviceLamp", "Form", nullptr));
        label_name_lamp->setText(QApplication::translate("DeviceLamp", "\345\220\212\347\201\257", nullptr));
        label_lamp->setText(QApplication::translate("DeviceLamp", "\347\201\257\345\233\276\347\211\207", nullptr));
        label_onoff->setText(QApplication::translate("DeviceLamp", "ON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceLamp: public Ui_DeviceLamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_LAMP_H
