#include "dockwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DockWindow dockWindow;
    dockWindow.show();
    
    return app.exec();
}
