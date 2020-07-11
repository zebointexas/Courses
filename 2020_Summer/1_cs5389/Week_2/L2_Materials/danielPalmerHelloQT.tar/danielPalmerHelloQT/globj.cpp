/*

 Author: Daniel Palmer

*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 3, -3, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene

void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glPointSize(2); // define the point size 
    glLineWidth(4); // define the line width

    float radius = 1;
  
    //1
    glLoadIdentity();
    glTranslatef(0, 0, 0);    // move the object to certain place
    
    glScalef(0.3,0.3,0.3);    // adjust the object size 
    glBegin(GL_TRIANGLES);    // draw the triangles
        glColor3f (0.5, 1.0, 0.0); // define the coloar
        glVertex3f(-radius, -radius,  radius);
        glVertex3f( radius, -radius,  -radius);
        glVertex3f(-radius,  radius,  radius);
    glEnd(); 
   
    //2
    glLoadIdentity();
    glTranslatef(1, 0, 0);
    glScalef(0.3,0.3,0.3);
    glBegin(GL_POLYGON);  // draw triangles using polygon
        glColor3f (1, 0.0, 1);
        glVertex3f(1,  -1,  -1);
        glVertex3f(1,  1,  -1);
        glVertex3f(-1,  1,  1);
    glEnd(); 

    //3
    glLoadIdentity();
    glTranslatef(2.5, -2, 0);
    glScalef(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
        glColor3f (1, 0, 0.5);
        glVertex3f(-1, 1,  1);
        glVertex3f(-1, -1,  1);
        glVertex3f(1, 1,  -1);
        glVertex3f(1, -1,  1);
    glEnd(); 
 
    //4 - Polygon 6
    glLoadIdentity();
    glTranslatef(2, -1, 0);
    glScalef(0.5,0.5,0.5);
    ngon(6,1, 0, 1); 

    //5 - Polygon 8
    glLoadIdentity();
    glTranslatef(0, -1, 0);
    glScalef(0.6,0.6,0.6);
    ngon(8,0.3, 0.8, 0.5);  

    //6 - Polygon 4
    glLoadIdentity();
    glTranslatef(1, -1, 0);
    glScalef(0.3,0.3,0.5);
    ngon(4, 0.1, 0, 1); 

    //7 - Point
    glLoadIdentity();
    glTranslatef(0, -3, 0);
    glScalef(0.3,0.3,0.3);
    glBegin(GL_POINT);
       glColor3f (0.5, 1.0, 1.0);
       for(float x = 1; x<2; x = x+0.2){
          float y = 4*x;
          glVertex2f(x, y); 
       }
    glEnd(); 
 
    //7 - Line
    glLoadIdentity();
    glTranslatef(0, -3, 0);
    glScalef(0.3,0.3,0.3);
    glBegin(GL_LINE);
       glColor3f (1, 0, 0);
       for(int x = 1; x<3; x = x+1){
          int y = 1.5*x;
          glVertex2f(x, y); 
       }
    glEnd(); 
 
    //8 - Circle
    glLoadIdentity();
    glTranslatef(2.5, 0, 0);
    glScalef(0.4,0.4,0.4);
    ngon(50, 1, 1, 1); 
 
    //9 - Cube
    glLoadIdentity();
 
    glRotatef(30,1,0,2);
    glScalef(0.5,0.5,0.5);
    glTranslatef(-2, -3, 0.7f);

    glBegin(GL_POLYGON); //face #1
        glColor3f (0.0, 0.5, 0.0);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    glBegin(GL_POLYGON); //face #2
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
    glEnd();

 
    glBegin(GL_POLYGON); //face #3
        glColor3f(0.8,0.5,0.0);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON); //face #4
        glColor3f (0.0, 0.0, 1.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();


    glBegin(GL_POLYGON); //face #5
        glColor3f (0.5, 1.0, 0.3);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON); //face #6
        glColor3f (0.0, 1.0, 0);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, -0.5);
    glEnd();













 
    glFlush();
}

 
void GLobj::ngon(int n, float r, float b, float g){

	float degree, vertx, verty, rotate, degToRad;

	rotate = 360.0/n; //Vertex rotation increment 

	degree = rotate/2 + 180; 
	degToRad = 180/3.14159;  

	glColor3f(r, b, g);
	glBegin(GL_POLYGON);
		for(int i = 0; i < n; i++, degree += rotate) {
			vertx = 0.5 * sin(degree/degToRad);  
 			verty = 0.5 * sin((90 - degree)/degToRad);  
			glVertex3f(vertx, verty, 0); 
		}

	glEnd();
}
 

 




