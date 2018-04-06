/*Creado por Mario Nelson Torres Mena
	Fecha 4 de abril de 2018
*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float limites = 4.0;

GLfloat X = 1;//direccion de movimiento en plano X si es en 1 se movera hacia la derecha
GLfloat W = 1;//direccion hacia donde se dibujaran los cuadros si es en 1 se dibujaran hacia deracha

void cuadros(float x, float y, float h, float w, float r, float g, float b) {
  //creacion de cuadros puntos x,y alto h, ancho w, color r,g,b
glColor3f(r,g,b);
glBegin(GL_QUADS);
glVertex2f(x,y);//puntos iniciales
glVertex2f(x,y+h); //linea recta a 90 grados sumamos alto (h) a y
glVertex2f(x+w,y+h);//linea paralela al eje x le sumamos ancho (w) a 'x' y sumamos alto (h)a y
glVertex2f(x+w,y);//linea recta en angulo 0 sumamos ancho (w) a x
glEnd();//finalizacion de trazos
}
void dino(GLfloat x, GLfloat y){
  /* dibujo del dino, utilizando la funcion cuadros
    para hacer el dino invertido al parametro w lo multiplicaremos por W
    w es el valor del parametro de la funcion cuadros
    W es el valor que cambiamos por el teclado
    si W esta en 1 los cuadros se dibujaran hacia la derecha
    si W esta en -1 los cuadros se dibujaran hacian la izquirda
  */
cuadros(x,y,1.5,1.5*W,0,0,0);// valores a enviar (x,y, h,w , r,g,b)
cuadros(x,y+1.3,0.2,0.2*W,1,1,1);
cuadros(x+1.3*W,y+1.3,0.2,0.2*W,1,1,1);
cuadros(x+0.3*W,y+0.9,0.2,0.2*W,1,1,1);
cuadros(x+0.8*W,y+0.2,0.2,0.7*W,1,1,1);
cuadros(x+1.25*W,y,0.2,0.5*W,1,1,1);
cuadros(x-0.2*W,y-1.5,1.5,0.8*W,0,0,0);
cuadros(x+.55*W,y-0.9,0.2,0.3*W,0,0,0);//mano
cuadros(x+0.8*W,y-1.2,0.5,0.2*W,0,0,0);//mano
cuadros(x-.3*W,y-1.7,1.4,0.8*W,0,0,0);
cuadros(x-0.5*W,y-1.9,1.4,0.8*W,0,0,0);
cuadros(x-0.7*W,y-2.1,1.4,0.8*W,0,0,0);
//patas
cuadros(x-0.7*W,y-2.7,1.4,0.1*W,0,0,0);
cuadros(x-0.7*W,y-2.7,0.2,0.2*W,0,0,0);
cuadros(x-0.7*W,y-2.4,0.4,0.2*W,0,0,0);
cuadros(x-0.55*W,y-2.3,0.4,0.15*W,0,0,0);
cuadros(x-0.2*W,y-2.3,0.4,0.15*W,0,0,0);
cuadros(x-0.1*W,y-2.7,1.4,0.1*W,0,0,0);
cuadros(x-0.1*W,y-2.7,0.2,0.15*W,0,0,0);
//cola
cuadros(x-1.5*W,y-1.0,1,0.11*W,0,0,0);
cuadros(x-1.45*W,y-1.3,1,0.25*W,0,0,0);
cuadros(x-1.30*W,y-1.6,1,0.25*W,0,0,0);
cuadros(x-1.20*W,y-1.7,1,0.25*W,0,0,0);
cuadros(x-1.*W,y-1.8,1,0.3*W,0,0,0);

//Nota: porque W tambien lo multiplique por X no me acuerdo xDDDD
// lo hice a la carrera asi pero salio lo que queria ....
}


void display(void)
{
	  glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    dino(X,1);//enviamos el valor X que se modifica por el teclado
    glFlush ();
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(limites), (limites), -(limites), (limites), -(limites),(limites));
}
void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        X+= 0.2;
    else if (key == GLUT_KEY_LEFT)
        X-= 0.2;
    else if (key == GLUT_KEY_UP)
        W= -1;
    else if (key == GLUT_KEY_DOWN)
        W*= -1;
    glutPostRedisplay();

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 420);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 2 ");
    init ();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
