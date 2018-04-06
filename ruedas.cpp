/*Creado por Mario Nelson Torres Mena*/
/*Fecha 5 de abril de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float X=-5;
float vueltas =0;
float limites= 10;//tamanio del glOrtho
void Lineas(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, GLfloat r, GLfloat g, GLfloat b, float t) {
  //recibe los dos puntos (x,y,z) (x,y,z) y color rgb
  glLineWidth(t);
  glBegin(GL_LINES);
  glColor3f(r,g,b); // parametros a enviar rojo, verde, azul (0.0,0.0,0.0)
  glVertex2f(xp1,yp1); //punto inicio
  glVertex2f(xp2,yp2); //punto fin
  glEnd();
}
void Circulos(GLfloat xp1, GLfloat yp1, GLfloat anguloI, GLfloat anguloF,float ra, float r, float g, float b){
  //recibe un punto (centro del Circulo) y el angulo que iniciara , y el angulo donde finalizara
  //variable ra = radio
  glColor3f(r,g,b);
  glPointSize(3.0f);
  // glPointSize(1.0f);
  glBegin(GL_POINTS);
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
    Circulos(X,0,vueltas,vueltas+340,1,0,0,0);
    Circulos(X+5,0,vueltas,vueltas+340,1,0,0,0);
      glFlush ();
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(limites), (limites), -(limites), (limites), -(limites),(limites));
}

void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {

    case '1' :
        vueltas-=1;
        X+=0.01;
        break;
        exit(0);			// exit
    }
    glutPostRedisplay();
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
