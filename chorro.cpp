/*Creado por Mario Nelson Torres Mena*/
/*Fecha 26 de marzo de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void Lineas(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, GLfloat r, GLfloat g, GLfloat b) {
  //recibe los dos puntos (x,y,z) (x,y,z) y color rgb
  glBegin(GL_LINES);
  glColor3f(r,g,b);
  glVertex2f(xp1,yp1);
  glVertex2f(xp2,yp2);
  glEnd();
}
void Circulos(GLfloat xp1, GLfloat yp1, GLfloat anguloI, GLfloat anguloF, float r){
  //recibe un punto (centro del Circulo) y el angulo que iniciara , y el angulo donde finalizara
  glPointSize(1.0f);
  glBegin(GL_POINTS);
  GLfloat cx=0;
  GLfloat cy=0;
  GLfloat angulo;
  for (GLfloat i=anguloI; i<anguloF; i+=0.01){
    angulo= i*M_PI/180.0f;
    cx=r*cos(angulo)+xp1;
    cy=r*sin(angulo)+yp1;
    glVertex2f(cx,cy);
  }
   glEnd();
}


void display(void)
{
	glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    Lineas(-4.5,-1.9,-4.5,-2.9, 0,0,1);
    Lineas(-7.5,-1.9,-7.5,-2.9, 0,0,1);
    Lineas(-7.5,-2.9,-4.5,-2.9, 0,0,1);
    Lineas(-0.94,8.3,-2.5,8.6, 0,0,1);
    Lineas(-0.98,8.0,-2.5,7.8, 0,0,1);
    Circulos(0,8,290,610, 1);// puntos(x,y) angulo inicial, angulo final, radio
    Lineas(0.35,5.5,0.35,7.08, 0,0,1);
    Lineas(-0.35,5.5,-0.35,7.08, 0,0,1);
    Lineas(-1.5,5.5,1.5,5.5, 0,0,1);
    Lineas(-1.5,5.5,-1.5,4.5, 0,0,1);
    Lineas(1.5,5.5,1.5,4.5, 0,0,1);
    Lineas(-2,4.5,2,4.5, 0,0,1);
    Lineas(-2,4.5,-2,3.5, 0,0,1);
    Lineas(2,4.5,2,3.5, 0,0,1);
    Circulos(3.99,3.5,180,270, 2);
    Lineas(3.99,1.505,6,1.505, 0,0,1);
    Circulos(5.99,2,270,360, 0.5);
    Lineas(-2.5,8.6,-2.5,7.8, 0,0,1);
    Lineas(0.94,8.3,2.5,8.6, 0,0,1);
    Lineas(0.98,8.0,2.5,7.8, 0,0,1);
    Lineas(2.5,8.6,2.5,7.8, 0,0,1);
    Lineas(6.5,2, 7,2, 0,0,1);
    Lineas(7,2, 7,-2, 0,0,1);
    Lineas(6.5,-2, 7,-2, 0,0,1);
    Circulos(5.99,-2,0,90, 0.5);
    Lineas(1.5,-1.505,6,-1.505, 0,0,1);
    Circulos(0,-2,180,360, 1);
    Circulos(1.5,-2,90,180, 0.5);
    Circulos(-1.5,-2,0,90, 0.5);
    Circulos(-4.0,3.5,270,360, 2);
    Lineas(-1.5,-1.505,-4,-1.505, 0,0,1);
    Circulos(-4,-2,90,180, 0.5);
    Circulos(-4,-2,90,180, 3.5);
    glFlush();
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10,10);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 420);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("ejercicio 4");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
