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
 
        glClearColor(1.0,0.0,1.0,0.0);       // set white background color
        glColor3f(0,0,0);          // set the drawing color 
 	glPointSize(4.0);		       // a ?dot? is 4 by 4 pixels
 	glLineWidth(4.0);
		      
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
//	glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0);
	glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);    //   3D parallel projection  //  Define a "viewing volume" which is a cube centered at the origin with edge length of 3.
	glShadeModel(GL_SMOOTH);
//	glViewport(0,0,800,600); 

}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{

	glLoadIdentity();  // reset the axis system
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glScalef(1,1,1);

	glColor3f(0,1,1);
  	
	glBegin(GL_LINES);
 
	glVertex2f(0.5,  0.5) ;
	glVertex2f(-0.5,  -0.5) ;
 
 
	glEnd();
	glFlush();          // send all output to display 
}
 
//<<<<<<<<<<<<<<<<<<<<<<<< ngon >>>>>>>>>>>>>>


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



//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{

glLoadIdentity();

		if(theKey == 't'){    // Triangle
			glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glScalef(1,1,1);
			glTranslatef(0,0,0);
			glColor3f(0,0,1);
			glBegin(GL_TRIANGLES);
				glVertex2f(0.5,  0) ;
				glVertex2f(0,  0.5) ;
				glVertex2f(-0.3,  -0.3) ;
			glEnd();
			glFlush();          // send all output to display 

		} else if(theKey == 'p'){  // point
			glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glScalef(1,1,1);
			glColor3f(0,1,0);
			glBegin(GL_POINTS);
				glVertex2i(0,  0) ;
			glEnd();
			glFlush();          // send all output to display 
		}else if(theKey == 'l'){   // Line
			glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glScalef(1,1,1);
			glColor3f(0,0,1);
			glBegin(GL_LINES);
				glVertex2f(-0.5,  -0.5);
				glVertex2f(0.5,  0.5);
			glEnd();
			glFlush();          // send all output to display 

	       }else if(theKey == 's'){   // Square 
			glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
			glScalef(1,1,1);
			ngon(4,1,0,0);

  
		}else if(theKey == 'h'){   //  Hexagon

		 	glClear(GL_COLOR_BUFFER_BIT); 

			glScalef(1,1,1);
			ngon(6,0,0,0);

		}else if(theKey == 'c'){  // Circle 

		 	glClear(GL_COLOR_BUFFER_BIT); 

			glScalef(1,1,1);
			ngon(30,0,1,1);
 
		}else if(theKey == 'u'){   //  Cube
  
		    glClear(GL_COLOR_BUFFER_BIT);

		    glRotatef(20,-40,30,-20);
		    glScalef(1,1,1);
		    
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
                    glFlush();    // display image to windows
 
		
		} else if (theKey == 'q'){
 
			exit(-1); //terminate the program
		} 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int	 main(int argc, char** argv)
{

	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(800,600);     // set window size  //  Define a window of 800x600
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("Bigg Deep - Type Q or q to quit") ; // open the screen window 
	glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
 
}


