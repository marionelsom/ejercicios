/*Creado por Mario Nelson Torres Mena*/
/*Fecha 26 de marzo de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float limites = 4.0;

void Lineas(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, float t) {
  //recibe los dos puntos (x,y,z) (x,y,z) y color rgb
    glLineWidth(t);
  glBegin(GL_LINES);
  glColor3f(1,1,1); // parametros a enviar rojo, verde, azul (0.0,0.0,0.0)
  glVertex2f(xp1,yp1); //punto inicio
  glVertex2f(xp2,yp2); //punto fin
  glEnd();
}

void Circulos(GLfloat xp1, GLfloat yp1, float ra, float r, float g, float b){
  //recibe un punto (centro del Circulo) y el angulo que iniciara , y el angulo donde finalizara
  //variable ra = radio
  glColor3f(r,g,b);
  // glPointSize(1.0f);
  glBegin(GL_POLYGON);
  GLfloat cx=xp1;
  GLfloat cy=yp1;
  GLfloat angulo;
  for (GLfloat i=0; i<=360; i+=0.01){
    glVertex2f(cx,cy);
    angulo= i*M_PI/180.0f;
    cx=ra*cos(angulo)+xp1;
    cy=ra*sin(angulo)+yp1;
    glVertex2f(cx,cy);
  }
   glEnd();
}

void Lineas_inclinadas(float x, float y, float d, float angulo, float t){
  //para hacer las linias inclinadas usaremos el algoritmo de hacer el circulo
  //enviaremos el angulo hasta donde terminara nuestro for
  float cx=0;//punto en x
  float cy=0;//punto en y
  float a; //aqui guardaremos la operacion de i*pi/180
  for (GLfloat i=0; i<=angulo; i+=0.01){
    //este for solo lo utilizaremos para encontrar el punto final de las lineas inclinadas
    //en este for no impimiremos nada en pantala por cada iteracion
        a= i*M_PI/180.0f;
        //la letra d hace referencia a la distancia que va a tener nuestra linea de un punto a otro
        cx=d*cos(i*M_PI/180.0f)+x;
        cy=d*sin(i*M_PI/180.0f)+y;
  }
  //terminando el for las variables cx, cy contienen el punto final que necesitamos para inclinar nuestra linea
  Lineas(x,y,cx, cy,t);//dibujamos nuestra linea del punto de origen al punto final

}

void display(void)
{
	  glClearColor(1,1,1,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    Circulos(0,0,3,0,0,0);
    Circulos(0,0,2.7,1,1,1);

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    GLfloat cx=0;
    GLfloat cy=0;
    GLfloat angulo;
    for (GLfloat i=0; i<=360; i+=0.01){
      glVertex2f(cx,cy);
      angulo= i*M_PI/180.0f;
      cx=2.6*cos(angulo)+0;
      cy=2.6*sin(angulo)+0;
      glVertex2f(cx,cy);
    }
     glEnd();

     glColor3f(1,1,1);
     glBegin(GL_POLYGON);
     cx=0;
     cy=-0.5;
    angulo=0;
     for (GLfloat i=40; i<=140; i+=0.01){
       glVertex2f(cx,cy);
       angulo= i*M_PI/180.0f;
       cx=2.6*cos(angulo)+0;
       cy=2.6*sin(angulo)+0;
       glVertex2f(cx,cy);
     }
      glEnd();

      glBegin(GL_POLYGON);
      glVertex2f(-1.6,-2.1);
      glVertex2f(-0.2,0.15);
      glVertex2f(-0.5,0.15);
      glVertex2f(-1.8,-1.9);
      glEnd();
      // 0.3 x
      //0.1516
      // Lineas_inclinadas(-1.6,-2.1,2.6,60,50);
      // Lineas_inclinadas(-1.65,-2.1,2.6,60,50);
      // Lineas_inclinadas(-1.67,-2.1,2.6,60,50);
      // Lineas_inclinadas(1.6,-2.1,2.6,120,20);
      glFlush ();

      glBegin(GL_POLYGON);
      glVertex2f(1.6,-2.1);
      glVertex2f(0.2,0.15);
      glVertex2f(0.5,0.15);
      glVertex2f(1.8,-1.9);
      glEnd();
      // 0.3 x
      //0.1516
      // Lineas_inclinadas(-1.6,-2.1,2.6,60,50);
      // Lineas_inclinadas(-1.65,-2.1,2.6,60,50);
      // Lineas_inclinadas(-1.67,-2.1,2.6,60,50);
      // Lineas_inclinadas(1.6,-2.1,2.6,120,20);

      Lineas_inclinadas(-2.45,-1,2.5,50,20);
      Lineas_inclinadas(-2.65,0,2,50,20);

      Lineas_inclinadas(2.45,-1,2.5,130,20);
      Lineas_inclinadas(2.65,0,2,130,20);

      glColor3f(0,0,0);
      glBegin(GL_POLYGON);
      cx=-0;
      cy=-0.35;
      for (GLfloat i=43; i<=55; i+=0.01){
        glVertex2f(cx,cy);
        angulo= i*M_PI/180.0f;
        cx=2.6*cos(angulo)+0;
        cy=2.6*sin(angulo)+0;
        glVertex2f(cx,cy);
      }
      glVertex2f(0,1);
      cx=0;
      cy=1;
      for (GLfloat i=125; i<=138; i+=0.01){
        glVertex2f(cx,cy);
        angulo= i*M_PI/180.0f;
        cx=2.6*cos(angulo)+0;
        cy=2.6*sin(angulo)+0;
        glVertex2f(cx,cy);
      }
      glEnd();

      glBegin(GL_POLYGON);
      glVertex2f(-0.6,1.1);
      glVertex2f(0,2.3);
      glVertex2f(0.6,1.1);
      glVertex2f(0,0);
      glEnd();
      glBegin(GL_POLYGON);
      glVertex2f(0,2.3);
      glVertex2f(0.6,2.3);
      glVertex2f(0,1.7);

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
