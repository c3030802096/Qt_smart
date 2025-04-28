/********************************************************************************
** Form generated from reading UI file 'device_ac.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_AC_H
#define UI_DEVICE_AC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_device_ac
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_background;
    QPushButton *btn_xiao;
    QPushButton *btn_speed;
    QPushButton *btn_high;
    QPushButton *btn_auto;
    QPushButton *btn_mid;
    QLabel *label_ac;
    QPushButton *btn_dry;
    QPushButton *btn_low;
    QPushButton *btn_cold;
    QPushButton *btn_mode;
    QPushButton *btn_wind;
    QLabel *label_text_ac;
    QLabel *label_onoff;
    QLabel *label_fenge;

    void setupUi(QWidget *device_ac)
    {
        if (device_ac->objectName().isEmpty())
            device_ac->setObjectName(QString::fromUtf8("device_ac"));
        device_ac->resize(343, 590);
        device_ac->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(device_ac);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        frame_background = new QFrame(device_ac);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        frame_background->setStyleSheet(QString::fromUtf8(""));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        btn_xiao = new QPushButton(frame_background);
        btn_xiao->setObjectName(QString::fromUtf8("btn_xiao"));
        btn_xiao->setGeometry(QRect(180, 410, 100, 35));
        btn_speed = new QPushButton(frame_background);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setGeometry(QRect(240, 350, 27, 28));
        btn_high = new QPushButton(frame_background);
        btn_high->setObjectName(QString::fromUtf8("btn_high"));
        btn_high->setGeometry(QRect(180, 530, 100, 35));
        btn_auto = new QPushButton(frame_background);
        btn_auto->setObjectName(QString::fromUtf8("btn_auto"));
        btn_auto->setGeometry(QRect(30, 410, 100, 35));
        btn_mid = new QPushButton(frame_background);
        btn_mid->setObjectName(QString::fromUtf8("btn_mid"));
        btn_mid->setGeometry(QRect(180, 490, 100, 35));
        label_ac = new QLabel(frame_background);
        label_ac->setObjectName(QString::fromUtf8("label_ac"));
        label_ac->setGeometry(QRect(0, 90, 343, 240));
        label_ac->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 186, 186);"));
        btn_dry = new QPushButton(frame_background);
        btn_dry->setObjectName(QString::fromUtf8("btn_dry"));
        btn_dry->setGeometry(QRect(30, 490, 100, 35));
        btn_low = new QPushButton(frame_background);
        btn_low->setObjectName(QString::fromUtf8("btn_low"));
        btn_low->setGeometry(QRect(180, 450, 100, 35));
        btn_cold = new QPushButton(frame_background);
        btn_cold->setObjectName(QString::fromUtf8("btn_cold"));
        btn_cold->setGeometry(QRect(30, 450, 100, 35));
        btn_mode = new QPushButton(frame_background);
        btn_mode->setObjectName(QString::fromUtf8("btn_mode"));
        btn_mode->setGeometry(QRect(80, 350, 27, 28));
        btn_wind = new QPushButton(frame_background);
        btn_wind->setObjectName(QString::fromUtf8("btn_wind"));
        btn_wind->setGeometry(QRect(30, 530, 100, 35));
        label_text_ac = new QLabel(frame_background);
        label_text_ac->setObjectName(QString::fromUtf8("label_text_ac"));
        label_text_ac->setGeometry(QRect(20, 16, 81, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        label_text_ac->setFont(font);
        label_onoff = new QLabel(frame_background);
        label_onoff->setObjectName(QString::fromUtf8("label_onoff"));
        label_onoff->setGeometry(QRect(20, 60, 72, 21));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        label_onoff->setFont(font1);
        label_fenge = new QLabel(frame_background);
        label_fenge->setObjectName(QString::fromUtf8("label_fenge"));
        label_fenge->setGeometry(QRect(20, 390, 301, 20));

        gridLayout->addWidget(frame_background, 0, 0, 1, 1);


        retranslateUi(device_ac);

        QMetaObject::connectSlotsByName(device_ac);
    } // setupUi

    void retranslateUi(QWidget *device_ac)
    {
        device_ac->setWindowTitle(QApplication::translate("device_ac", "Form", nullptr));
        btn_xiao->setText(QString());
        btn_speed->setText(QString());
        btn_high->setText(QString());
        btn_auto->setText(QString());
        btn_mid->setText(QString());
        label_ac->setText(QApplication::translate("device_ac", "\347\251\272\350\260\203\345\233\276\347\211\207", nullptr));
        btn_dry->setText(QString());
        btn_low->setText(QString());
        btn_cold->setText(QString());
        btn_mode->setText(QString());
        btn_wind->setText(QString());
        label_text_ac->setText(QApplication::translate("device_ac", "\347\251\272\350\260\203", nullptr));
        label_onoff->setText(QApplication::translate("device_ac", "ON", nullptr));
        label_fenge->setText(QApplication::translate("device_ac", "\345\210\206\345\211\262\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class device_ac: public Ui_device_ac {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_AC_H
