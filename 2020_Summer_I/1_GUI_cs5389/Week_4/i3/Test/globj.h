/*

 Author: Daniel Palmer

*/

#ifndef GLobj_H
#define GLobj_H

#include <QtOpenGL/QGLWidget>

class GLobj : public QGLWidget  {
    Q_OBJECT

public:
    GLobj(QWidget *parent = 0);
    ~GLobj();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void ngon(int, float, float, float); 
    void loop(int n, float r, float b, float g);
};

 


class GLobj_2 : public QGLWidget  {
    Q_OBJECT

public:
    GLobj_2(QWidget *parent = 0);
    ~GLobj_2();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void ngon(int, float, float, float); 
    void loop(int n, float r, float b, float g);
 
    void setWindow(double left, double right, double bottom, double top); 
    void setViewport(int left, int right, int bottom, int top); 
};





#endif






