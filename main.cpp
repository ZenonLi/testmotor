#include "Car_Control.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
              QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    Car_Control w;
    w.show();
    return a.exec();
}
