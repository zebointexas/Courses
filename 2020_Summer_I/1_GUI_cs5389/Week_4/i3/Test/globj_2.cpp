/*

 Author: Daniel Palmer

*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj_2::GLobj_2(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj_2::~GLobj_2()
{

}

//Initialize the GL settings
void GLobj_2::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj_2::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/4, 0, h, h);
    else
        glViewport(0, (h-w)/4, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-1, 1, -1, 1, -1, 1);
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene

void GLobj_2::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
  
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	setWindow(-9.0, 9.0, -0.3, 1.0);		 // set the window
	setViewport(0, 800, 0, 600);			// set the viewport
	glBegin(GL_LINE_STRIP);

        for(GLfloat x = -5.0; x < 5.0; x += 0.01)     // draw the plot
		glVertex2f(x, 0.2*cos(2*3.14159 * x)); 

	glEnd();
	glFlush();          // send all output to display 

}


//--------------- setWindow ---------------------
void GLobj_2::setWindow(double left, double right, double bottom, double top)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(left, right, bottom, top); 
}
//---------------- setViewport ------------------
void GLobj_2::setViewport(int left, int right, int bottom, int top)
{
glViewport(left, bottom, right - left, top - bottom);
}
  
