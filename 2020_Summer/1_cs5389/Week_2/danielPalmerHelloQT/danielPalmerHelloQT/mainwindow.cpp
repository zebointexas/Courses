/*

 Author: Daniel Palmer
*/

#include <QtGui>

#include "globj.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    globj = new GLobj(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(globj);

    setLayout(mainLayout);

    setWindowTitle(tr("Hello QGL"));

}

