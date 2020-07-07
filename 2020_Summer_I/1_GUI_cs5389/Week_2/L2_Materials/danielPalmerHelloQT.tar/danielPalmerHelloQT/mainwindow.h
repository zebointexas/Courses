/*

 Author: Daniel Palmer

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QCheckBox>

class GLobj;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    GLobj *globj;
};

#endif
