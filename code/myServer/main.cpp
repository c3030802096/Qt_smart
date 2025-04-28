#include "home.h"
#include <QApplication>
#include <QTextCodec>
#include <QStyleFactory>
#include <QDebug>
#include "my_custom/digital_scroller.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 设置全局字体
    QFont font("汉仪旗黑-55S");
    a.setFont(font);

/*解决中文乱码的问题*/
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForLocale((QTextCodec::codecForName("UTF_8")));
//    QApplication::setStyle(QStyleFactory::create("windows"));

    Home h;
    h.show();
    
    return a.exec();
}
