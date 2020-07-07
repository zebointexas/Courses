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
    
   //glOrtho(-1, 3, -3, 1, -1, 1);
gluLookAt(1.2,-1.9,0,  
	  -20,-5,-15,
	  -100,50,35);
gluPerspective(1,0.1,10,10);




/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

GLfloat light_position[] = { 0.0, 0.0, 0.0, 0.0 }; 
GLfloat light_ambient [] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse [] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
glLightfv(GL_LIGHT0, GL_AMBIENT , light_ambient );
glLightfv(GL_LIGHT0, GL_DIFFUSE , light_diffuse ); 
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
 
 
GLfloat ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};  // 环境强度
GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};  // 散射强度
GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; // 镜面强度

// 点光源, GL_POSITION属性的最后一个参数为1
GLfloat position[] = {-3.0f, -3.4f, -8.8f, 1.0f};
glLightfv(GL_LIGHT0, GL_POSITION, position);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

// 平行光源, GL_POSITION属性的最后一个参数为0
GLfloat direction[] = {-3.0f, -3.4f, -8.8f, 0.0f};
glLightfv(GL_LIGHT1, GL_POSITION, direction);
glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
 
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// 创建灯光的位置
GLfloat posMain[]={10.0,14.0,6.0,1.0};
GLfloat posFill1[]={-20.0,90.0,0.0,1.0};
GLfloat posFill2[]={-300.0,-4.0,1.0,1.0};
GLfloat white[]={0.5,0.5,0.5,0.5};

// 定义几种颜色值
GLfloat dimblue[]={0.0,0.0,.2,1.0};
GLfloat cyan[]={0.0,1.0,0.3,0.8};
GLfloat yellow[]={0.7,.5,0.0,1.0};
GLfloat dimmagenta[]={.75,0.8,.25,1.0};
GLfloat dimcyan[]={0.0,.5,.5,1.0};

//设置反射光的位置和颜色
glLightfv(GL_LIGHT0,GL_POSITION,posMain);
glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);

// 设置镜面光的颜色，它的光源和反射光是同一个光源
glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);

// 设置光源2的位置和类型
glLightfv(GL_LIGHT1,GL_POSITION,posFill1);
glLightfv(GL_LIGHT1,GL_AMBIENT,dimblue);
glLightfv(GL_LIGHT1,GL_DIFFUSE,dimcyan);

// 设置光源3 的位置和类型以及
glLightfv(GL_LIGHT2,GL_POSITION,posFill2);
glLightfv(GL_LIGHT2,GL_DIFFUSE,dimmagenta);
glLightfv(GL_LIGHT2,GL_DIFFUSE,dimblue);

//设置衰减因子
glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION,.3);

//设置材料在反射光下的颜色
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);

// 设置材料在镜面光下的颜色
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10);

// 设置光照模式 GL_SMOOTH 代表均匀的颜色涂在表面上
glShadeModel(GL_SMOOTH);
glLightModelf(GL_LIGHT_MODEL_TWO_SIDE,0.0);

// 开启灯光模式
glEnable(GL_LIGHTING);
// 打开灯光123
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHT2);








/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

const GLfloat glfLightAmbient1[4] = {0.1, 0.1, 0.1, 1.0};  
const GLfloat glfLightAmbient2[4] = {0.4, 0.4, 0.4, 1.0};  
const GLfloat glfLightDiffuse1[4] = {0, 0.8, 0.8, 1.0};  
const GLfloat glfLightDiffuse2[4] = {0.8, 0.8, 0.8, 1.0};  
const GLfloat glfLightSpecular1[4] = {0, 0.8, 0.8, 1.0};  
const GLfloat glfLightSpecular2[4] = {0.8, 0.8, 0.8, 1.0};  
const GLfloat glPosition1[4]={0,0,1,0};  
const GLfloat glPosition2[4]={0.6,0.6,-0.6,1}; 
 
glLightfv(GL_LIGHT0, GL_AMBIENT,  glfLightAmbient1);  
glLightfv(GL_LIGHT0, GL_DIFFUSE,  glfLightDiffuse1);  
glLightfv(GL_LIGHT0, GL_SPECULAR, glfLightSpecular1);  
glLightfv(GL_LIGHT0,GL_POSITION,glPosition1);  
glLightfv(GL_LIGHT1, GL_AMBIENT,  glfLightAmbient2);  
glLightfv(GL_LIGHT1, GL_DIFFUSE,  glfLightDiffuse2);  
glLightfv(GL_LIGHT1, GL_SPECULAR, glfLightSpecular2);  
glLightfv(GL_LIGHT1,GL_POSITION,glPosition2);  
glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);//两面照亮  
glEnable(GL_LIGHTING);//启用光照  
glEnable(GL_LIGHT0);  
glEnable(GL_LIGHT1);//打开光源  

glEnable(GL_COLOR_MATERIAL);//启用颜色追踪  
glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);  
glShadeModel(GL_FLAT);//设置颜色填充模式  
 
/////////////////////////////////////////////////////
 
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
    glLineWidth(3); // define the line width

    float radius = 1;
  
    //1
    glLoadIdentity();
    glTranslatef(1.7, -2, -0.2);    // move the object to certain place
    
    glScalef(0.1,0.1,0.3);    // adjust the object size 
    glRotatef(30,1,0,2);
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
    glRotatef(30,1,0,2);	
    glBegin(GL_POLYGON);  // draw triangles using polygon
        glColor3f (1, 0.0, 1);
        glVertex3f(1,  -1,  -1);
        glVertex3f(1,  1,  -1);
        glVertex3f(-1,  1,  1);
    glEnd(); 

    //3  4 sides 
    glLoadIdentity();
    glTranslatef(2, -2.8, 0);
    glScalef(0.3,0.3,0.3);
    glRotatef(30,1,0,2);
    glBegin(GL_POLYGON);
        glColor3f (1, 0, 0.5);
        glVertex3f(-1, 1,  1);
        glVertex3f(-1, -1,  1);
        glVertex3f(1, 1,  -1);
        glVertex3f(1, -1,  1);
    glEnd(); 
 
    //3 - Triangle_Fan
    glLoadIdentity();
    glTranslatef(2.3, -2, -0.5);
    glScalef(0.1,0.1,0.1);
    glRotatef(30,1,0,2);
    glBegin(GL_TRIANGLE_FAN);
        glColor3f (0.6, 0.8, 1);
        glVertex3f(-0.11, 1,  1);
        glVertex3f(-1, -0.11,  1);
        glVertex3f(1, 0.11,  -1);
        glVertex3f(0.51, -0.51,  -0.2);
        glVertex3f(-1, -1,  -0.5);
        glVertex3f(0.5, -1,  1);
    glEnd(); 


    //4 - Polygon 6
    glLoadIdentity();
    glTranslatef(1.7, -2, -0.3);
    glScalef(0.5,0.5,0.5);
    glRotatef(30,1,0,2);
    ngon(6,1, 0, 1); 

    //5 - Polygon 8
    glLoadIdentity();
    glTranslatef(1, -2, 0);
    glScalef(0.6,0.6,0.6);
    glRotatef(-30,1,0,2);
    loop(8,0.3, 0.8, 0.5);  

    //6 - Polygon 4
    glLoadIdentity();
    glTranslatef(1, -3, 0);
    glScalef(0.3,0.3,0.5);
    glRotatef(30,1,0,2);
    glTranslatef(0, 2, 0);
    ngon(4, 0.1, 1, 1); 

    //7 - Point
    glLoadIdentity();
    glTranslatef(1, -4, -0.5);
    glScalef(0.3,0.3,0.3);
    glRotatef(30,1,0,2);
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
    glRotatef(30,1,0,2);
    glBegin(GL_LINE);
       glColor3f (1, 0, 0);
       for(int x = 1; x<3; x = x+1){
          int y = 1.5*x;
          glVertex2f(x, y); 
       }
    glEnd(); 
 
    //7 - Sphere
    glLoadIdentity();
    glTranslatef(1, -1, -0.5);
    glScalef(0.15,0.3,0.1);
    glRotatef(50,1,0,2);
    glTranslatef(0.5, -1, 0.5);
    glBegin(GL_LINE_STRIP);
       glColor3f (1, 0, 0);

       for(int u = 1; u<365; u = u+1){
	  for(int v = 1; v<365; v = v+1){

		float m = cos(u)*sin(v);
		float n = sin(u)*sin(v);
		float k = cos(v);

		glVertex3f(m, n, k); 
           }
	}

    glEnd();
 
    //8 - Circle
    glLoadIdentity();
    glTranslatef(3, 1, 0);
    glScalef(0.6,0.6,0.6);
    loop(50, 1, 1, 1); 
 
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
 
void GLobj::loop(int n, float r, float b, float g){

	float degree, vertx, verty, rotate, degToRad;

	rotate = 360.0/n; //Vertex rotation increment 

	degree = rotate/2 + 180; 
	degToRad = 180/3.14159;  

	glColor3f(r, b, g);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i < n; i++, degree += rotate) {
			vertx = 0.5 * sin(degree/degToRad);  
 			verty = 0.5 * sin((90 - degree)/degToRad);  
			glVertex3f(vertx, verty, 0); 
		}

	glEnd();
}
  
