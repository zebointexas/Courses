
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_ANDROID
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(dockwidgets);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}