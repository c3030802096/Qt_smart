/********************************************************************************
** Form generated from reading UI file 'device_curtain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_CURTAIN_H
#define UI_DEVICE_CURTAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_device_curtain
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_background;
    QWidget *widget_pic;
    QLabel *label_curtain;
    QLabel *lbl_data;
    QLabel *label_text_curtain;
    QPushButton *btn_down;
    QLabel *label_onoff;
    QPushButton *btn_up;
    QLabel *label_lan;

    void setupUi(QWidget *device_curtain)
    {
        if (device_curtain->objectName().isEmpty())
            device_curtain->setObjectName(QString::fromUtf8("device_curtain"));
        device_curtain->resize(343, 590);
        device_curtain->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(device_curtain);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        frame_background = new QFrame(device_curtain);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        widget_pic = new QWidget(frame_background);
        widget_pic->setObjectName(QString::fromUtf8("widget_pic"));
        widget_pic->setGeometry(QRect(60, 200, 227, 184));
        label_curtain = new QLabel(widget_pic);
        label_curtain->setObjectName(QString::fromUtf8("label_curtain"));
        label_curtain->setGeometry(QRect(0, 0, 227, 184));
        label_curtain->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 85, 195);"));
        lbl_data = new QLabel(frame_background);
        lbl_data->setObjectName(QString::fromUtf8("lbl_data"));
        lbl_data->setGeometry(QRect(130, 500, 81, 41));
        lbl_data->setAlignment(Qt::AlignCenter);
        label_text_curtain = new QLabel(frame_background);
        label_text_curtain->setObjectName(QString::fromUtf8("label_text_curtain"));
        label_text_curtain->setGeometry(QRect(20, 10, 111, 51));
        QFont font;
        font.setPointSize(20);
        label_text_curtain->setFont(font);
        btn_down = new QPushButton(frame_background);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        btn_down->setGeometry(QRect(240, 500, 46, 44));
        label_onoff = new QLabel(frame_background);
        label_onoff->setObjectName(QString::fromUtf8("label_onoff"));
        label_onoff->setGeometry(QRect(30, 60, 81, 31));
        QFont font1;
        font1.setPointSize(16);
        label_onoff->setFont(font1);
        btn_up = new QPushButton(frame_background);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        btn_up->setGeometry(QRect(50, 500, 46, 44));
        label_lan = new QLabel(frame_background);
        label_lan->setObjectName(QString::fromUtf8("label_lan"));
        label_lan->setGeometry(QRect(60, 190, 231, 31));

        gridLayout->addWidget(frame_background, 0, 0, 1, 1);


        retranslateUi(device_curtain);

        QMetaObject::connectSlotsByName(device_curtain);
    } // setupUi

    void retranslateUi(QWidget *device_curtain)
    {
        device_curtain->setWindowTitle(QApplication::translate("device_curtain", "Form", nullptr));
        label_curtain->setText(QApplication::translate("device_curtain", "\344\270\212\345\261\202\345\233\276", nullptr));
        lbl_data->setText(QApplication::translate("device_curtain", "100%", nullptr));
        label_text_curtain->setText(QApplication::translate("device_curtain", "\347\231\276\345\217\266\347\252\227", nullptr));
        btn_down->setText(QString());
        label_onoff->setText(QApplication::translate("device_curtain", "ON", nullptr));
        btn_up->setText(QString());
        label_lan->setText(QApplication::translate("device_curtain", "\347\252\227\346\240\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class device_curtain: public Ui_device_curtain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_CURTAIN_H
