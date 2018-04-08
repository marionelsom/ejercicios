/*Creado por Mario Nelson Torres Mena*/
/*Fecha 26 de marzo de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float limites = 2.0;
void Lineas(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, GLfloat r, GLfloat g, GLfloat b) {
  //recibe los dos puntos (x,y,z) (x,y,z) y color rgb
  glBegin(GL_LINES);
  glColor3f(r,g,b);
  glVertex2f(xp1,yp1);
  glVertex2f(xp2,yp2);
  glEnd();
}
void Puntos(GLfloat xp1, GLfloat yp1, GLfloat r, GLfloat g, GLfloat b) {
  //recibe puntos (x,y,z) (x,y,z)
  glBegin(GL_POINTS);
  glColor3f(r,g,b);
  glVertex2f(xp1,yp1);
  glEnd();
}

void lineas_espejo(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, GLfloat r, GLfloat g, GLfloat b){
  glBegin(GL_LINES);
  glColor3f(r,g,b);
  glVertex2f(xp1,yp1);
  glVertex2f(xp2,yp2);
  glVertex2f(xp1*-1,yp1);
  glVertex2f(xp2*-1,yp2);
  glEnd();
}

void display(void)
{
	  glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //base angosto
    Lineas(-0.97,0, 0.97, 0, 0.0,0.0,1.0); //linea superior
    Lineas(-1.0,-0.05,1.0, -0.05, 0.0,0.0,1.0);//linea inferior
    lineas_espejo(-1.9,0, -1.12, 0, 0.0,0.0,1.0);
    lineas_espejo(-1.9,-0.05, -1.145, -0.05, 0.0,0.0,1.0);
    lineas_espejo(-1.9,0, -1.9, -0.05, 0.0,0.0,1.0);
    //base gruesa
    lineas_espejo(-1.83,-0.15, -1.2, -0.15, 0.0,0.0,1.0);
    Lineas(-1.05,-0.15, 1.05, -0.15, 0.0,0.0,1.0); // linea
    lineas_espejo(-1.83,-0.15, -1.83, -0.05, 0.0,0.0,1.0);
//soporte
    //lado dere
    lineas_espejo(1.65,-0.15, 1.65, -1.18, 0.0,0.0,1.0);
    lineas_espejo(1.50,-0.15, 1.50, -0.80, 0.0,0.0,1.0);
      //pequenio
      lineas_espejo(1.25,-0.15, 1.25, -0.25, 0.0,0.0,1.0);
      lineas_espejo(1.27,-0.15, 1.27, -0.30, 0.0,0.0,1.0);
    lineas_espejo(1.45,-0.15, 1.50, -0.25, 0.0,0.0,1.0);
    lineas_espejo(1.40,-0.15, 1.50, -0.35, 0.0,0.0,1.0);
    lineas_espejo(1.70,-0.15, 1.65, -0.25, 0.0,0.0,1.0);
    lineas_espejo(1.75,-0.15, 1.65, -0.35, 0.0,0.0,1.0);
//soporte superior
    lineas_espejo(-0.80,0, -0.80, 0.27, 0.0,0.0,1.0);
    lineas_espejo(-0.78,0, -0.78, 0.30, 0.0,0.0,1.0);
    lineas_espejo(-0.60,0, -0.60, 0.53, 0.0,0.0,1.0);
    lineas_espejo(-0.58,0, -0.58, 0.55, 0.0,0.0,1.0);
    lineas_espejo(-0.38,0, -0.38, 0.72, 0.0,0.0,1.0);
    lineas_espejo(-0.40,0, -0.40, 0.70, 0.0,0.0,1.0);
    lineas_espejo(-0.20,0, -0.20, 0.82, 0.0,0.0,1.0);
    lineas_espejo(-0.18,0, -0.18, 0.825, 0.0,0.0,1.0);
    lineas_espejo(-0.02,0, -0.02, 0.85, 0.0,0.0,1.0);
//arcos del puente

    Lineas(1.5,-1.18, 1.65, -1.18, 0.0,0.0,1.0);
    Lineas(-1.5,-1.18, -1.65, -1.18, 0.0,0.0,1.0);
    float y;
    float xinicio=0.0;
    float yinicio=1.0;
    float yinicio2=0.85;
    for (float x = -1.65; x<=1.65; x+=0.001) {
      y = pow(x,2);
      y=0.8*y;
      Puntos(xinicio - x,yinicio - y, 0.0,0.0,1.0);
    }
    for (float x = -1.50; x<=1.50; x+=0.001) {
      y = pow(x,2);
      y=0.9*y;
      Puntos(xinicio - x,yinicio2 - y, 0.0,0.0,1.0);
    }



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
    glutCreateWindow ("Puente ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
