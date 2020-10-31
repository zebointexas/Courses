#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
const int screenHeight = 480; // window height is 480
const int screenWidth = 640 ; //window width is 640
//<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
	void exit(int) ;
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 { 
 
        glClearColor(1.0,1.0,1.0,1.0);       // set white background color
        glColor3f(0,0,0);          // set the drawing color 
 	glPointSize(4.0);		       // a ?dot? is 4 by 4 pixels
 	glLineWidth(4.0);
		      
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
  

	gluLookAt(0,0,0,    0,0,0,    0,0,0);
	
	glShadeModel(GL_SMOOTH);
 	glViewport(0,0,500,500); 

}
void ngon(int n, float r, float b, float g){

	float degree, vertx, verty, rotate, degToRad; 
 
	rotate = 360.0/n; 
		
	degree = rotate/2 + 100; 
	degToRad = 180/3.14159; 

	glColor3f(r,b,g); 
	glBegin(GL_POLYGON); 

	for(int i = 0; i < n; i++, degree += rotate){
		vertx = 0.5 * sin(degree/degToRad); 
		verty = 0.5 * sin( (90 - degree)/degToRad); 
		glVertex3f(vertx, verty, 0);

	}

glEnd();
glFlush(); 
}

// function to let you create cubes with vector and translation 
void cube(float scale, float degree, float x, float y, float z, float t, float tt, float ttt){

 		    glLoadIdentity();		

		    glTranslatef(t,tt,ttt);

		    glRotatef(degree,x,y,z);
		    glScalef(scale,scale,scale);
		    
		    glBegin(GL_POLYGON); //face #1
			glColor3f (1, 0.5, 1);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #2
			glColor3f (1.0, 1.0, 1);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #3
			glColor3f(0.8,1,1);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #4
			glColor3f (0, 1, 0);
			glVertex3f(0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #5
			glColor3f (0.5, 1, 1);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, 0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #6
			glColor3f (1, 1.0, 0);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
                    glFlush(); 


		



}



//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{

	glLoadIdentity();

	//////////////////////////////////
	//////////////////////////////////

		
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glScalef(0.4,0.4,0.4);

	glColor3f(1,0,1);
  	
        glRotatef(20,-40,30,-20);

        glTranslatef(-0.7,0,-0.7);

	glPushMatrix(); 

	glBegin(GL_LINES);
		glVertex2f(0.5,  0.5) ;
		glVertex2f(-0.5,  -0.5) ;
	glEnd();
	glFlush();          // send all output to display 

	
 
	//////////////////////////////////
	//////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	glLoadIdentity();

	glScalef(0.3,0.3,0.3);

        glRotatef(20,40,-30,20);


        glPopMatrix();
	glTranslatef(-1,-1,-1);
	 	
	 
	glColor3f(0,1,1);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.5,  0) ;
		glVertex2f(0,  0.5) ;
		glVertex2f(-0.3,  -0.3) ;
	glEnd();
	glFlush();          // send all output to display 
 
	//////////////////////////////////
	//////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	glLoadIdentity();

	glScalef(0.3,0.3,0.3);
        glRotatef(20,-40,30,-20);

	glTranslatef(0,-3,0);
	glColor3f(0,0,1);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.5,  0) ;
		glVertex2f(0,  0.5) ;
		glVertex2f(-0.3,  -0.3) ;
	glEnd();
	glFlush();          // send all output to display 

        //////////////////////////////////
	//////////////////////////////////
		//	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
glLoadIdentity();
			glScalef(0.3,0.3,0.3);
glTranslatef(1,-1,2);

        glRotatef(20,-40,30,-20);
			glColor3f(0,1,0);
			glBegin(GL_POINTS);
				glVertex2i(0,  0) ;
			glEnd();
			glFlush();          // send all output to display 
        //////////////////////////////////
	//////////////////////////////////
 
        //////////////////////////////////
	//////////////////////////////////
		//	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glLoadIdentity();
			glTranslatef(0.5,0.5,-1);
			glScalef(0.3,0.3,0.3);
			ngon(4,1,0,0);
 
        //////////////////////////////////
	//////////////////////////////////
		// 	glClear(GL_COLOR_BUFFER_BIT); 
			glLoadIdentity();
			glTranslatef(0,0,1);

 glRotatef(20,-40,30,-20);
			glScalef(0.3,0.3,0.3);
			ngon(6,0,0,0);

        //////////////////////////////////
	//////////////////////////////////
		//      glClear(GL_COLOR_BUFFER_BIT); 
		
			glLoadIdentity();

		 	glTranslatef(0.7,-0.2,-0.7);

 glRotatef(20,-40,30,-20);

			glScalef(0.3,0.3,0.3);
			ngon(30,0,1,1);
 
        //////////////////////////////////
	//////////////////////////////////
		 //   glClear(GL_COLOR_BUFFER_BIT);

		cube(0.25, 45, 1, 1, 1, 0.5, 0.5, 0.8);	   

		cube(0.25, 15, 1, 2, 2, -0.5, 0.5, 0.8);

		cube(0.25, 30, 1, 2, 2, 0.5, -0.5, 0);	  
  
}
 
//<<<<<<<<<<<<<<<<<<<<<<<< ngon >>>>>>>>>>>>>>




 
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int	 main(int argc, char** argv)
{

	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode



	glutInitWindowSize(800,600);     // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Bigg Deep - Type Q or q to quit") ; // open the screen window 
	glutDisplayFunc(myDisplay);     // register redraw function
     //   glutKeyboardFunc(myKeyboard); // register the keyboard action function






	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
 
}


