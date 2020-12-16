#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

static int useRGB = 1;
static int useLighting = 1;
static int useFog = 0;
static int useDB = 1;
static int useLogo = 0;
static int useQuads = 1;

static int tick = -1;
static int moving = 1;

#define GREY	0
#define RED	1
#define GREEN	2
#define BLUE	3
#define CYAN	4
#define MAGENTA	5
#define YELLOW	6
#define BLACK	7
#define WHITE	8



/*************************************************/
static float materialColor[8][4] =
{
  {0.8, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.0, 1.0},
  {0.0, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.8, 1.0},
  {0.0, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.8, 1.0},
  {0.8, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.0, 0.6},
};

static float lightPos[4] =
{2.0, 4.0, 2.0, 1.0};
#if 0
static float lightDir[4] =
{-2.0, -4.0, -2.0, 1.0};
#endif
static float lightAmb[4] =
{0.2, 0.2, 0.2, 1.0};
static float lightDiff[4] =
{0.8, 0.8, 0.8, 1.0};
static float lightSpec[4] =
{0.4, 0.4, 0.4, 1.0};

static float groundPlane[4] =
{0.0, 1.0, 0.0, 1.499};
static float backPlane[4] =
{0.0, 0.0, 1.0, 0.899};

static float fogColor[4] =
{0.0, 0.0, 0.0, 0.0};
static float fogIndex[1] =
{0.0};

static unsigned char shadowPattern[128] =
{
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,  /* 50% Grey */
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55
};

static unsigned char sgiPattern[128] =
{
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  /* SGI Logo */
  0xff, 0xbd, 0xff, 0x83, 0xff, 0x5a, 0xff, 0xef,
  0xfe, 0xdb, 0x7f, 0xef, 0xfd, 0xdb, 0xbf, 0xef,
  0xfb, 0xdb, 0xdf, 0xef, 0xf7, 0xdb, 0xef, 0xef,
  0xfb, 0xdb, 0xdf, 0xef, 0xfd, 0xdb, 0xbf, 0x83,
  0xce, 0xdb, 0x73, 0xff, 0xb7, 0x5a, 0xed, 0xff,
  0xbb, 0xdb, 0xdd, 0xc7, 0xbd, 0xdb, 0xbd, 0xbb,
  0xbe, 0xbd, 0x7d, 0xbb, 0xbf, 0x7e, 0xfd, 0xb3,
  0xbe, 0xe7, 0x7d, 0xbf, 0xbd, 0xdb, 0xbd, 0xbf,
  0xbb, 0xbd, 0xdd, 0xbb, 0xb7, 0x7e, 0xed, 0xc7,
  0xce, 0xdb, 0x73, 0xff, 0xfd, 0xdb, 0xbf, 0xff,
  0xfb, 0xdb, 0xdf, 0x87, 0xf7, 0xdb, 0xef, 0xfb,
  0xf7, 0xdb, 0xef, 0xfb, 0xfb, 0xdb, 0xdf, 0xfb,
  0xfd, 0xdb, 0xbf, 0xc7, 0xfe, 0xdb, 0x7f, 0xbf,
  0xff, 0x5a, 0xff, 0xbf, 0xff, 0xbd, 0xff, 0xc3,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static float cube_vertexes[6][4][4] =
{
  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0}}
};

static float cube_normals[6][4] =
{
  {-1.0, 0.0, 0.0, 0.0},
  {1.0, 0.0, 0.0, 0.0},
  {0.0, -1.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, -1.0, 0.0},
  {0.0, 0.0, 1.0, 0.0}
};

static void
usage(void)
{
  printf("\n");
  printf("usage: scube [options]\n");
  printf("\n");
  printf("    display a spinning cube and its shadow\n");
  printf("\n");
  printf("  Options:\n");
  printf("    -geometry  window size and location\n");
  printf("    -c         toggle color index mode\n");
  printf("    -l         toggle lighting\n");
  printf("    -f         toggle fog\n");
  printf("    -db        toggle double buffering\n");
  printf("    -logo      toggle sgi logo for the shadow pattern\n");
  printf("    -quads     toggle use of GL_QUADS to draw the checkerboard\n");
  printf("\n");
#ifndef EXIT_FAILURE    /* should be defined by ANSI C
                           <stdlib.h> */
#define EXIT_FAILURE 1
#endif
  exit(EXIT_FAILURE);
}

void
buildColormap(void)
{
  if (useRGB) {
    return;
  } else {
    int mapSize = 1 << glutGet(GLUT_WINDOW_BUFFER_SIZE);
    int rampSize = mapSize / 8;
    int entry;
    int i;

    for (entry = 0; entry < mapSize; ++entry) {
      int hue = entry / rampSize;
      GLfloat val = (entry % rampSize) * (1.0 / (rampSize - 1));
      GLfloat red, green, blue;

      red = (hue == 0 || hue == 1 || hue == 5 || hue == 6) ? val : 0;
      green = (hue == 0 || hue == 2 || hue == 4 || hue == 6) ? val : 0;
      blue = (hue == 0 || hue == 3 || hue == 4 || hue == 5) ? val : 0;

      glutSetColor(entry, red, green, blue);
    }

    for (i = 0; i < 8; ++i) {
      materialColor[i][0] = i * rampSize + 0.2 * (rampSize - 1);
      materialColor[i][1] = i * rampSize + 0.8 * (rampSize - 1);
      materialColor[i][2] = i * rampSize + 1.0 * (rampSize - 1);
      materialColor[i][3] = 0.0;
    }

    fogIndex[0] = -0.2 * (rampSize - 1);
  }
}

static void
setColor(int c)
{
  if (useLighting) {
    if (useRGB) {
      glMaterialfv(GL_FRONT_AND_BACK,
        GL_AMBIENT_AND_DIFFUSE, &materialColor[c][0]);
    } else {
      glMaterialfv(GL_FRONT_AND_BACK,
        GL_COLOR_INDEXES, &materialColor[c][0]);
    }
  } else {
    if (useRGB) {
      glColor4fv(&materialColor[c][0]);
    } else {
      glIndexf(materialColor[c][1]);
    }
  }
}

static void
drawCube(int color)
{
  int i;

  setColor(color);

  for (i = 0; i < 6; ++i) {
    glNormal3fv(&cube_normals[i][0]);
    glBegin(GL_POLYGON);
    glVertex4fv(&cube_vertexes[i][0][0]);
    glVertex4fv(&cube_vertexes[i][1][0]);
    glVertex4fv(&cube_vertexes[i][2][0]);
    glVertex4fv(&cube_vertexes[i][3][0]);
    glEnd();
  }
}


static void
draw4P(int color)
{
  int i;

  setColor(color);

  for (i = 0; i < 4; ++i) {

    glNormal3fv(&cube_normals[i][0]);

    glBegin(GL_POLYGON);
	    glVertex4fv(&cube_vertexes[i][0][0]);
	    glVertex4fv(&cube_vertexes[i][1][0]);
	    glVertex4fv(&cube_vertexes[i][2][0]);
    glEnd();
  }
}


static void
drawCheck(int w, int h, int evenColor, int oddColor)
{
  static int initialized = 0;
  static int usedLighting = 0;
  static GLuint checklist = 0;

  if (!initialized || (usedLighting != useLighting)) {
    static float square_normal[4] =
    {0.0, 0.0, 1.0, 0.0};
    static float square[4][4];
    int i, j;

    if (!checklist) {
      checklist = glGenLists(1);
    }
    glNewList(checklist, GL_COMPILE_AND_EXECUTE);

    if (useQuads) {
      glNormal3fv(square_normal);
      glBegin(GL_QUADS);
    }
    for (j = 0; j < h; ++j) {
      for (i = 0; i < w; ++i) {
        square[0][0] = -1.0 + 2.0 / w * i;
        square[0][1] = -1.0 + 2.0 / h * (j + 1);
        square[0][2] = 0.0;
        square[0][3] = 1.0;

        square[1][0] = -1.0 + 2.0 / w * i;
        square[1][1] = -1.0 + 2.0 / h * j;
        square[1][2] = 0.0;
        square[1][3] = 1.0;

        square[2][0] = -1.0 + 2.0 / w * (i + 1);
        square[2][1] = -1.0 + 2.0 / h * j;
        square[2][2] = 0.0;
        square[2][3] = 1.0;

        square[3][0] = -1.0 + 2.0 / w * (i + 1);
        square[3][1] = -1.0 + 2.0 / h * (j + 1);
        square[3][2] = 0.0;
        square[3][3] = 1.0;

        if (i & 1 ^ j & 1) {
          setColor(oddColor);
        } else {
          setColor(evenColor);
        }

        if (!useQuads) {
          glBegin(GL_POLYGON);
        }
        glVertex4fv(&square[0][0]);
        glVertex4fv(&square[1][0]);
        glVertex4fv(&square[2][0]);
        glVertex4fv(&square[3][0]);
        if (!useQuads) {
          glEnd();
        }
      }
    }

    if (useQuads) {
      glEnd();
    }
    glEndList();

    initialized = 1;
    usedLighting = useLighting;
  } else {
    glCallList(checklist);
  }
}

static void
myShadowMatrix(float ground[4], float light[4])
{
  float dot;
  float shadowMat[4][4];

  dot = ground[0] * light[0] +
    ground[1] * light[1] +
    ground[2] * light[2] +
    ground[3] * light[3];

  shadowMat[0][0] = dot - light[0] * ground[0];
  shadowMat[1][0] = 0.0 - light[0] * ground[1];
  shadowMat[2][0] = 0.0 - light[0] * ground[2];
  shadowMat[3][0] = 0.0 - light[0] * ground[3];

  shadowMat[0][1] = 0.0 - light[1] * ground[0];
  shadowMat[1][1] = dot - light[1] * ground[1];
  shadowMat[2][1] = 0.0 - light[1] * ground[2];
  shadowMat[3][1] = 0.0 - light[1] * ground[3];

  shadowMat[0][2] = 0.0 - light[2] * ground[0];
  shadowMat[1][2] = 0.0 - light[2] * ground[1];
  shadowMat[2][2] = dot - light[2] * ground[2];
  shadowMat[3][2] = 0.0 - light[2] * ground[3];

  shadowMat[0][3] = 0.0 - light[3] * ground[0];
  shadowMat[1][3] = 0.0 - light[3] * ground[1];
  shadowMat[2][3] = 0.0 - light[3] * ground[2];
  shadowMat[3][3] = dot - light[3] * ground[3];

  glMultMatrixf((const GLfloat *) shadowMat);
}

static char *windowNameRGBDB = "shadow cube (OpenGL RGB DB)";
static char *windowNameRGB = "shadow cube (OpenGL RGB)";
static char *windowNameIndexDB = "shadow cube (OpenGL Index DB)";
static char *windowNameIndex = "shadow cube (OpenGL Index)";

void
idle(void)
{
  tick++;
  if (tick >= 1200) {
    tick = 0;
  }
  glutPostRedisplay();
}

/* ARGSUSED1 */
void
keyboard(unsigned char ch, int x, int y)
{
  switch (ch) {
  case 27:             /* escape */
    exit(0);
    break;
  case 'L':
  case 'l':
    useLighting = !useLighting;
    useLighting ? glEnable(GL_LIGHTING) :
      glDisable(GL_LIGHTING);
    glutPostRedisplay();
    break;
  case 'F':
  case 'f':
    useFog = !useFog;
    useFog ? glEnable(GL_FOG) : glDisable(GL_FOG);
    glutPostRedisplay();
    break;
  case '1':
    glFogf(GL_FOG_MODE, GL_LINEAR);
    glutPostRedisplay();
    break;
  case '2':
    glFogf(GL_FOG_MODE, GL_EXP);
    glutPostRedisplay();
    break;
  case '3':
    glFogf(GL_FOG_MODE, GL_EXP2);
    glutPostRedisplay();
    break;
  case ' ':
    if (!moving) {
      idle();
      glutPostRedisplay();
    }
  }
}


void
fog_select(int fog)
{
  glFogf(GL_FOG_MODE, fog);
  glutPostRedisplay();
}

void
menu_select(int mode)
{
  switch (mode) {
  case 1:
    moving = 1;
    glutIdleFunc(idle);
    break;
  case 2:
    moving = 0;
    glutIdleFunc(NULL);
    break;
  case 3:
    useFog = !useFog;
    useFog ? glEnable(GL_FOG) : glDisable(GL_FOG);
    glutPostRedisplay();
    break;
  case 4:
    useLighting = !useLighting;
    useLighting ? glEnable(GL_LIGHTING) :
      glDisable(GL_LIGHTING);
    glutPostRedisplay();
    break;
  case 5:
    exit(0);
    break;
  }
}

void
visible(int state)
{
  if (state == GLUT_VISIBLE) {
    if (moving)
      glutIdleFunc(idle);
  } else {
    if (moving)
      glutIdleFunc(NULL);
  }
}
/*************************************************/




float PI  = 3.1415927;

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
	// gluPerspective(90,1,1,1000);
 
	glMatrixMode(GL_MODELVIEW); 
	
	glLoadIdentity();	
	gluLookAt(10,10,10,   10,10,10,   10,10,10);
 
	glShadeModel(GL_SMOOTH);
 	glViewport(0,0,500,500); 

}




void Cube()
{
 
	glBegin(GL_QUAD_STRIP); 
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.0f, 1.0f, -1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
	 
 
}
void Circle()
{
	glBegin(GL_TRIANGLE_FAN);//扇形连续填充三角形串
	glVertex3f(0.0f, 0.0f, 0.0f);
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
}
void Cylinder()
{
	glBegin(GL_QUAD_STRIP);//连续填充四边形串
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(sin(p), cos(p), 1.0f);
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
	Circle();
	glTranslatef(0, 0, 1);
	Circle();
}
void Cone()
{
	glBegin(GL_QUAD_STRIP);//连续填充四边形串
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(0, 0, 1.0f);
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
	Circle();
}
void renderScene(void)
{
	static float i = 0;
	i += 0.1;
	if (i > 360)
		i = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(-2, 2.0, -12);
	glRotatef(i, 1, 1 ,1);
	Cylinder();
	glPopMatrix();
 
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(2, 2, -12);
	glRotatef(i, 1, 1, 1);
	Circle();
	glPopMatrix();
 
	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-2, -2, -12);
	glRotatef(i, 1, 1, 1);
	Cube();
	glPopMatrix();
 
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(2, -2, -12);
	glRotatef(i, 1, 1, 1);
	Cone();
	glPopMatrix();
	glutSwapBuffers();
}
void changeSize(int w, int h) {
 
	// 防止除数即高度为0
	// (你可以设置窗口宽度为0).
	if (h == 0)
		h = 1;
	float ratio = 1.0* w / h;
 
	// 单位化投影矩阵。
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
 
	// 设置视口大小为整个窗口大小
	glViewport(0, 0, w, h);
 
	// 设置正确的投影矩阵
	gluPerspective(45, ratio, 1, 1000);
	//下面是设置模型视图矩阵
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);//设置观测点
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


	glPushMatrix();		
 
		GLfloat ambient1[] = { 0.9*r, 0.7*g, 0.7*b, 1.0 };
		GLfloat diffuse1[] = { 0.9*r, 0.1*g, 0.8*b, 1.0 };
		GLfloat specular1[] = { 0.9*r, 0.1*g, 1.0*b, 1.0 };

		GLfloat shininess[] = { 30 };
		GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);

		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);

		glShadeModel(GL_SMOOTH);
	glPushMatrix();

 
	glEnd();

	glFlush(); 
}

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-40,G-70,B-90);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);

    glEnd();
}



void wall()
{


glBegin(GL_QUADS);

 

glVertex3f(-1,-1,-1);
glVertex3f(1,-1,-1);
glVertex3f(1,-1,1);
glVertex3f(-1,-1,1);
 
glVertex3f(-1,1,-1);
glVertex3f(1,1,-1);
glVertex3f(1,1,1);
glVertex3f(-1,1,1);
  
glVertex3f(-1,-1,1);
glVertex3f(1,-1,1);
glVertex3f(1,1,1);
glVertex3f(-1,1,1);

glVertex3f(-1,-1,-1);
glVertex3f(1,-1,-1);
glVertex3f(1,1,-1);
glVertex3f(-1,1,-1);

glVertex3f(1,1,1);
glVertex3f(1,-1,1);
glVertex3f(1,-1,-1);
glVertex3f(1,1,-1);

glVertex3f(-1,1,1);
glVertex3f(-1,-1,1);
glVertex3f(-1,-1,-1);
glVertex3f(-1,1,-1);
glEnd();

}

void cube(float scale, float degree, float x, float y, float z, float t, float tt, float ttt){

 		    glLoadIdentity();		

		    glTranslatef(t,tt,ttt);

		    glRotatef(degree,x,y,z);
		    glScalef(scale,scale,scale);
		    
		    glBegin(GL_POLYGON); //face #1
 
			glPushMatrix();		 
				GLfloat ambient6[] = { 1, 0.4, 0.8, 1.0 };
				GLfloat diffuse6[] = { 1, 0.1, 0.3, 1.0 };
				GLfloat specular6[] = { 1, 0.3, 0.3, 1.0 };

				GLfloat shininess6[] = { 30 };
				GLfloat emission6[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient6);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse6);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular6);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess6);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission6);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();


			glColor3f (1, 0.5, 1);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #2


			glPushMatrix();		 
				GLfloat ambient5[] = { 1, 0.4, 0.8, 1.0 };
				GLfloat diffuse5[] = { 1, 0.1, 0.3, 1.0 };
				GLfloat specular5[] = { 1, 0.3, 0.3, 1.0 };

				GLfloat shininess5[] = { 30 };
				GLfloat emission5[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient5);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse5);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular5);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess5);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission5);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();




			glColor3f (1.0, 1.0, 1);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #3


			glPushMatrix();		 
				GLfloat ambient4[] = { 1, 0.4, 0.8, 1.0 };
				GLfloat diffuse4[] = { 1, 0.1, 0.3, 1.0 };
				GLfloat specular4[] = { 1, 0.3, 0.3, 1.0 };

				GLfloat shininess4[] = { 30 };
				GLfloat emission4[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient4);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse4);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular4);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess4);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission4);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();

			glColor3f(0.8,1,1);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #4

			glPushMatrix();		 
				GLfloat ambient3[] = { 0.9, 0.4, 0.8, 1.0 };
				GLfloat diffuse3[] = { 0.9, 0.1, 0.3, 1.0 };
				GLfloat specular3[] = { 0.8, 0.3, 0.3, 1.0 };

				GLfloat shininess3[] = { 30 };
				GLfloat emission3[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient3);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse3);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular3);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess3);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission3);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();
 
			glColor3f (0, 1, 0);
			glVertex3f(0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, -0.5);
		    glEnd();
 
		    glBegin(GL_POLYGON); //face #5


			glPushMatrix();		 
				GLfloat ambient2[] = { 0.4, 0.8, 0.4, 1.0 };
				GLfloat diffuse2[] = { 0.4, 0.4, 0.3, 1.0 };
				GLfloat specular2[] = { 0.9, 0.8, 0.3, 1.0 };

				GLfloat shininess2[] = { 30 };
				GLfloat emission2[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission2);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();

			glColor3f (0.5, 1, 1);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, -0.5);
			glVertex3f(-0.5, -0.5, -0.5);
			glVertex3f(-0.5, -0.5, 0.5);
		    glEnd();

		    glBegin(GL_POLYGON); //face #6

			glPushMatrix();		 
				GLfloat ambient1[] = { 0.2, 0.4, 0.8, 1.0 };
				GLfloat diffuse1[] = { 0.4, 0.1, 0.3, 1.0 };
				GLfloat specular1[] = { 0.8, 0.3, 0.3, 1.0 };

				GLfloat shininess1[] = { 30 };
				GLfloat emission1[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission1);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();
 
			glColor3f (1, 1.0, 0);
			glVertex3f(0.5, 0.5, -0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, -0.5);
		    glEnd();
 
                    glFlush(); 
 
}



//<<<<<<<<<<<<<<<<<<<<<<<< anotherDisplay >>>>>>>>>>>>>>>>>
void
anotherDisplay(void)
{
 
 


  GLfloat cubeXform[4][4];

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	  //////   cylinder 
	  glPushMatrix();
 
		  glTranslatef(-0.4, -0.2, -0.2);
 
		  glRotatef((360.0 / (30 * 1)) * tick * 0.01, 1, 0, 0);
		  glRotatef((360.0 / (30 * 2)) * tick * 0.011, 0, 1, 0);
		  glRotatef((360.0 / (30 * 4)) * tick * 0.01, 0, 0, 1);
 			
		   glScalef(2.0, 2.0, 2.0);
		  glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) cubeXform);
 
		  draw_cylinder(0.1, 0.4, 0, 160, 100);
 
	  glPopMatrix();



	  //////   cube 
	  glPushMatrix();
 
		  glTranslatef(-0.4, -0.2, -0.2);
 
		  glRotatef((360.0 / (30 * 1)) * tick * 0.01, 1, 0, 0);
		  glRotatef((360.0 / (30 * 2)) * tick * 0.011, 0, 1, 0);
		  glRotatef((360.0 / (30 * 4)) * tick * 0.01, 0, 0, 1);
 			
		   glScalef(2.0, 2.0, 2.0);
		  glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) cubeXform);
 
		  cube(0.25, 45, 1, 1, 1, 0.5, 0.5, 0.8);	   
 
	  glPopMatrix();
 
  glPushMatrix();

  glTranslatef(0.0, -1.5, 0.0);
  glRotatef(-90.0, 1, 0, 0);
  glScalef(2.0, 2.0, 2.0);

  drawCheck(9, 9, WHITE,YELLOW);  /* draw ground */
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0, 0.0, -0.9);
  glScalef(2.0, 2.0, 2.0);

  drawCheck(9, 9, BLUE, MAGENTA);  /* draw back */
  glPopMatrix();
 
  //////   cut line 
  glPushMatrix();

  glTranslatef(1, 0, 0.0);
  glScalef(0.2, 0.2, 0.2);

  glRotatef((360.0 / (30 * 1)) * tick * 0.05, 1, 0, 0);
  glRotatef((360.0 / (30 * 2)) * tick * 0.05, 0, 1, 0);
  glRotatef((360.0 / (30 * 4)) * tick * 0.05, 0, 0, 1);

  glScalef(0.5, 0.5, 2.0);

  glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) cubeXform);

  
  drawCube(GREEN);        /* draw cube */


  glPopMatrix();

  glDepthMask(GL_FALSE);

  if (useRGB) {
    glEnable(GL_BLEND);
  } else {
    glEnable(GL_POLYGON_STIPPLE);
  }
  if (useFog) {
    glDisable(GL_FOG);
  }

  glPushMatrix();

  myShadowMatrix(groundPlane, lightPos);
  glTranslatef(0.0, 0.0, 2.0);

  glMultMatrixf((const GLfloat *) cubeXform);

  drawCube(BLACK);      /* draw ground shadow */
  glPopMatrix();

  glPushMatrix();
  myShadowMatrix(backPlane, lightPos);
  glTranslatef(0.0, 0.0, 2.0);
  glMultMatrixf((const GLfloat *) cubeXform);

  drawCube(BLACK);      /* draw back shadow */
  glPopMatrix();

  glDepthMask(GL_TRUE);
  if (useRGB) {
    glDisable(GL_BLEND);
  } else {
    glDisable(GL_POLYGON_STIPPLE);
  }
  if (useFog) {
    glEnable(GL_FOG);
  }
  if (useDB) {
    glutSwapBuffers();
  } else {
    glFlush();
  }

  
	
	 
}



//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{ 


GLfloat cubeXform[4][4];

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(0.0, -1.5, 0.0);
  glRotatef(-90.0, 1, 0, 0);
  glScalef(2.0, 2.0, 2.0);

  drawCheck(6, 6, BLUE, YELLOW);  /* draw ground */
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0, 0.0, -0.9);
  glScalef(2.0, 2.0, 2.0);

  drawCheck(6, 6, BLUE, YELLOW);  /* draw back */
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0, 0.2, 0.0);
  glScalef(0.3, 0.3, 0.3);
  glRotatef((360.0 / (30 * 1)) * tick, 1, 0, 0);
  glRotatef((360.0 / (30 * 2)) * tick, 0, 1, 0);
  glRotatef((360.0 / (30 * 4)) * tick, 0, 0, 1);
  glScalef(1.0, 2.0, 1.0);
  glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) cubeXform);

  drawCube(RED);        /* draw cube */
  glPopMatrix();

  glDepthMask(GL_FALSE);
  if (useRGB) {
    glEnable(GL_BLEND);
  } else {
    glEnable(GL_POLYGON_STIPPLE);
  }
  if (useFog) {
    glDisable(GL_FOG);
  }
  glPushMatrix();
  myShadowMatrix(groundPlane, lightPos);
  glTranslatef(0.0, 0.0, 2.0);
  glMultMatrixf((const GLfloat *) cubeXform);

  drawCube(BLACK);      /* draw ground shadow */
  glPopMatrix();

  glPushMatrix();
  myShadowMatrix(backPlane, lightPos);
  glTranslatef(0.0, 0.0, 2.0);
  glMultMatrixf((const GLfloat *) cubeXform);

  drawCube(BLACK);      /* draw back shadow */
  glPopMatrix();

  glDepthMask(GL_TRUE);
  if (useRGB) {
    glDisable(GL_BLEND);
  } else {
    glDisable(GL_POLYGON_STIPPLE);
  }
  if (useFog) {
    glEnable(GL_FOG);
  }
  if (useDB) {
    glutSwapBuffers();
  } else {
    glFlush();
  }


        glClear(GL_COLOR_BUFFER_BIT);   

	GLfloat shininess[] = { 30 };
	GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};

	//Enable the light
	  
	    

















































    	  glEnable(GL_LIGHTING); 
          glEnable(GL_LIGHT1);  
          glEnable(GL_LIGHT2);  
          glEnable(GL_LIGHT3);  
          glEnable(GL_LIGHT4);  

	glTranslatef(5,6,8);
	    

    
	// set the light1 details
	GLfloat light_diffuse1[] = { 0.4f, 0.8f, 0.6f,1.0f };
	GLfloat light_ambient1[] = { 0.1, 0.8f, 0.3f, 1.0f };
	GLfloat light_specular1[] ={0.1, 0.5, 0.6, 1.0};

	GLfloat light1_pos[]={1,100,100,1};

	glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

        // set the light2 details

	GLfloat light_diffuse2[] = { 0.1f, 0.8f, 0.3f,1.0f };
	GLfloat light_ambient2[] = { 0.3, 0.5, 0.6, 1.0f };
	GLfloat light_specular2[] ={ 0.4f, 0.8f, 0.6f, 1.0};
	
	GLfloat light2_pos[]={4.0, 8.0, 6,0, 1};

	glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);
 	 
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 70.0);
	  
        // set the light3 details
	GLfloat light_diffuse3[] = { 0.5f, 0.3f, 0.6f,1.0f };
	GLfloat light_ambient3[] = { 0.1f, 0.3f, 0.8f, 1.0f };
	GLfloat light_specular3[] ={ 0.3, 0.5, 0.6, 1.0};

	glLightfv(GL_LIGHT3, GL_POSITION, light1_pos);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular3);

	GLfloat light3_pos[]={3.0, 8.0, 3,0, 1.0};
 	 
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 70);

       // set the light4 details	 
	GLfloat light_ambient4[] = { 0.3, 0.5, 0.6, 1.0f };
	GLfloat light4_pos[]={-0.7,0,-0.7, 1.0};
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient4);
	
	GLfloat visible_Ambient_light[] = {  0.3, 0.5, 0.6, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, visible_Ambient_light);
  
	// deep test
	glEnable(GL_DEPTH_TEST);
	// set the background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////
 
	glShadeModel(GL_SMOOTH);
	
	glShadeModel(GL_FLAT);
 

	


	///  Wall
 
	    glLoadIdentity();

	    glTranslatef(0,0,0);
	    glRotatef(-40, 1.0, 0.0, 0.0);
 
	    wall();

	    glFlush();

 

	///  Cylinder
 
	    glLoadIdentity();

	    glTranslatef(-0.5,-0.7,-0.5);
	    glRotatef(-40, 1.0, 0.0, 0.0);

	    draw_cylinder(0.1, 0.4, 0, 160, 100);

	    glFlush();

	///  Here is the sphere~!!!!!!!!!!!

        glLoadIdentity();
 
	glColor3f(0.7,0.6,.5); 
  
	glTranslatef(-0.7,0,-0.7);
 
	int color = 0; 
        PI = atan(1.0) * 4.0;
	float a, b, x, y, z;
	float da = 6.0, db = 6.0;
	float radius = 0.2;

	for (a = -90.0; a + da <= 90.0; a += da) {

		glBegin(GL_QUAD_STRIP);
 
		glPushMatrix();		 
			GLfloat ambient1[] = { 0.1, 0.4, 0.8, 1.0 };
			GLfloat diffuse1[] = { 0.0, 0.1, 0.3, 1.0 };
			GLfloat specular1[] = { 0.2, 0.3, 0.3, 1.0 };

			GLfloat shininess[] = { 30 };
			GLfloat emission[] =  {0.3, -0.2, 0.3, 0.0};

			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);

			glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, emission);

			glShadeModel(GL_SMOOTH);
		glPushMatrix();
 
		for (b = 0.0; b <= 360.0; b += db) {
   
			if(color){
				
				glIndexi(1); 

				glColor3f(1,0,1);
			}else {
	
				glIndexi(255); 

				glColor3f(1,1,0);		
			}
	 
			x = radius * cos(b * PI / 180) * cos(a * PI / 180);
			y = radius * sin(b * PI / 180) * cos(a * PI / 180);
			z = radius * sin(a * PI / 180);
			glVertex3f(x, y, z);

			x = radius * cos(b * PI / 180) * cos((a + da) * PI / 180);
			y = radius * sin(b * PI / 180) * cos((a + da) * PI / 180);
			z = radius * sin((a + da) * PI / 180);
			glVertex3f(x, y, z);

			color = 1 - color; 
			 
		 }
 		glEnd();
		glFlush();
	 }
  
	glLoadIdentity();

	//////////////////////////////////
	//////////////////////////////////
 
	//  // clear the screen 
	glScalef(0.4,0.4,0.4);

	glColor3f(1,0,1);
  	
        glRotatef(20,-40,30,-20);

        glTranslatef(-0.7,0,-0.7);
 
	glBegin(GL_LINES);
 
 		glPushMatrix();		 
		GLfloat ambient[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
		GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
 
		 
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glShadeModel(GL_FLAT);
 		glPushMatrix();

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
 
			glPushMatrix();		 
				GLfloat ambient2[] = { 1, 0.8, 0.4, 1.0 };
				GLfloat diffuse2[] = { 1, 0.4, 0.3, 1.0 };
				GLfloat specular2[] = { 1, 0.8, 0.3, 1.0 };

				GLfloat shininess2[] = { 30 };
				GLfloat emission2[] =  {0.3, -0.2, 0.3, 0.0};

				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);

				glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
				glMaterialfv(GL_FRONT, GL_EMISSION, emission2);

				glShadeModel(GL_SMOOTH);
			glPushMatrix();


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

		glPushMatrix();		 
		GLfloat ambient1[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat diffuse1[] = { 0.1, 0.5, 0.8, 1.0 };
		GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0 };
 
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);

		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glShadeModel(GL_FLAT);
 		glPushMatrix();

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


 
  int width = 800, height = 600;
  int i;
  char *name;
  int fog_menu;

  glutInitWindowSize(width, height);
 
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
 
  /* process commmand line args */
  for (i = 1; i < argc; ++i) {
    if (!strcmp("-c", argv[i])) {
      useRGB = !useRGB;
    } else if (!strcmp("-l", argv[i])) {
      useLighting = !useLighting;
    } else if (!strcmp("-f", argv[i])) {
      useFog = !useFog;
    } else if (!strcmp("-db", argv[i])) {
      useDB = !useDB;
    } else if (!strcmp("-logo", argv[i])) {
      useLogo = !useLogo;
    } else if (!strcmp("-quads", argv[i])) {
      useQuads = !useQuads;
    } else {
      usage();
    }
  }

  /* choose visual */
  if (useRGB) {
    if (useDB) {
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
      name = windowNameRGBDB;
    } else {
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
      name = windowNameRGB;
    }
  } else {
    if (useDB) {
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_INDEX | GLUT_DEPTH);
      name = windowNameIndexDB;
    } else {
      glutInitDisplayMode(GLUT_SINGLE | GLUT_INDEX | GLUT_DEPTH);
      name = windowNameIndex;
    }
  }

  glutCreateWindow(name);

  buildColormap();

  glutKeyboardFunc(keyboard);
  glutDisplayFunc(anotherDisplay);



  glutVisibilityFunc(visible);

  fog_menu = glutCreateMenu(fog_select);
  glutAddMenuEntry("Linear fog", GL_LINEAR);
  glutAddMenuEntry("Exp fog", GL_EXP);
  glutAddMenuEntry("Exp^2 fog", GL_EXP2);

  glutCreateMenu(menu_select);
  glutAddMenuEntry("Start motion", 1);
  glutAddMenuEntry("Stop motion", 2);
  glutAddMenuEntry("Toggle fog", 3);
  glutAddMenuEntry("Toggle lighting", 4);
  glutAddSubMenu("Fog type", fog_menu);
  glutAddMenuEntry("Quit", 5);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  /* setup context */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 3.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -2.0);

  glEnable(GL_DEPTH_TEST);

  if (useLighting) {
    glEnable(GL_LIGHTING);
  }
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
#if 0
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDir);
  glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 80);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25);
#endif

  glEnable(GL_NORMALIZE);

  if (useFog) {
    glEnable(GL_FOG);
  }
  glFogfv(GL_FOG_COLOR, fogColor);
  glFogfv(GL_FOG_INDEX, fogIndex);
  glFogf(GL_FOG_MODE, GL_EXP);
  glFogf(GL_FOG_DENSITY, 0.5);
  glFogf(GL_FOG_START, 1.0);
  glFogf(GL_FOG_END, 3.0);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  glShadeModel(GL_SMOOTH);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  if (useLogo) {
    glPolygonStipple((const GLubyte *) sgiPattern);
  } else {
    glPolygonStipple((const GLubyte *) shadowPattern);
  }

  glClearColor(0.0, 0.0, 0.0, 1);
  glClearIndex(0);
  glClearDepth(1);

  glutMainLoop();
  
 
	// glutInitWindowSize(800,600);     // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Bigg Deep - Type Q or q to quit") ; // open the screen window 
	// glutDisplayFunc(myDisplay);     // register redraw function
     //   glutKeyboardFunc(myKeyboard); // register the keyboard action function

 
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop

return 0;             /* ANSI C requires main to return int. */
 
 


 
}


