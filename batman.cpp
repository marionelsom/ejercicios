/*Creado por Mario Nelson Torres Mena*/
/*Fecha 4 de abril de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float limites = 4.0;

void Circulos(GLfloat xp1, GLfloat yp1, GLfloat anguloI, GLfloat anguloF,float ra, float r, float g, float b){
  //recibe un punto (centro del Circulo) y el angulo que iniciara , y el angulo donde finalizara
  //variable ra = radio
  glColor3f(r,g,b);
  // glPointSize(1.0f);
  glBegin(GL_POLYGON);
  GLfloat cx=xp1;
  GLfloat cy=yp1;
  GLfloat angulo;
  for (GLfloat i=anguloI; i<anguloF; i+=0.01){
    angulo= i*M_PI/180.0f;
    cx=ra*cos(angulo)+xp1;
    cy=ra*sin(angulo)+yp1;
    glVertex2f(cx,cy);
  }
   glEnd();
}

void display(void)
{
	  glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    Circulos(0,0, 0,360,2, 0,0,0);
    Circulos(0,1.5, 0,360,1, 0.2,0.2,0.2);
    Circulos(-0.7,-1.7, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(0.7,-1.7, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(0,-2.5, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(-1.6,-0.7, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(-1.6,-0.9, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(1.6,-0.7, 0,360,0.7, 0.2,0.2,0.2);
    Circulos(1.6,-0.9, 0,360,0.7, 0.2,0.2,0.2);

    glColor3f(0,0,0);
    // glPointSize(1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,0);
    glVertex2f(-0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    // glPointSize(1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.3,0);
    glVertex2f(0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    // glPointSize(1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,0);
    glVertex2f(-0.1,1);
    glVertex2f(0.1,1);
    glVertex2f(0.1,0);
    glEnd();

      glFlush ();
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(limites), (limites), -(limites), (limites), -(limites),(limites));
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 420);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 1 ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
