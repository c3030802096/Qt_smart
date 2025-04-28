/********************************************************************************
** Form generated from reading UI file 'scene_manager_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENE_MANAGER_WINDOW_H
#define UI_SCENE_MANAGER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scene_manager_window
{
public:
    QLabel *label;
    QLineEdit *lineEditSceneName;
    QPushButton *btnAddScene;
    QPushButton *btnRemoveScene;
    QPushButton *btnTriggerScene;
    QListWidget *listWidgetScenes;

    void setupUi(QWidget *scene_manager_window)
    {
        if (scene_manager_window->objectName().isEmpty())
            scene_manager_window->setObjectName(QString::fromUtf8("scene_manager_window"));
        scene_manager_window->resize(439, 320);
        label = new QLabel(scene_manager_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 54, 12));
        lineEditSceneName = new QLineEdit(scene_manager_window);
        lineEditSceneName->setObjectName(QString::fromUtf8("lineEditSceneName"));
        lineEditSceneName->setGeometry(QRect(110, 30, 113, 20));
        btnAddScene = new QPushButton(scene_manager_window);
        btnAddScene->setObjectName(QString::fromUtf8("btnAddScene"));
        btnAddScene->setGeometry(QRect(30, 100, 75, 23));
        btnRemoveScene = new QPushButton(scene_manager_window);
        btnRemoveScene->setObjectName(QString::fromUtf8("btnRemoveScene"));
        btnRemoveScene->setGeometry(QRect(130, 100, 75, 23));
        btnTriggerScene = new QPushButton(scene_manager_window);
        btnTriggerScene->setObjectName(QString::fromUtf8("btnTriggerScene"));
        btnTriggerScene->setGeometry(QRect(230, 100, 75, 23));
        listWidgetScenes = new QListWidget(scene_manager_window);
        listWidgetScenes->setObjectName(QString::fromUtf8("listWidgetScenes"));
        listWidgetScenes->setGeometry(QRect(50, 160, 256, 121));

        retranslateUi(scene_manager_window);

        QMetaObject::connectSlotsByName(scene_manager_window);
    } // setupUi

    void retranslateUi(QWidget *scene_manager_window)
    {
        scene_manager_window->setWindowTitle(QApplication::translate("scene_manager_window", "Form", nullptr));
        label->setText(QApplication::translate("scene_manager_window", "\345\234\272\346\231\257\345\220\215\347\247\260\357\274\232", nullptr));
        btnAddScene->setText(QApplication::translate("scene_manager_window", "\346\267\273\345\212\240\345\234\272\346\231\257", nullptr));
        btnRemoveScene->setText(QApplication::translate("scene_manager_window", "\345\210\240\351\231\244\345\234\272\346\231\257", nullptr));
        btnTriggerScene->setText(QApplication::translate("scene_manager_window", "\350\247\246\345\217\221\345\234\272\346\231\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scene_manager_window: public Ui_scene_manager_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENE_MANAGER_WINDOW_H
