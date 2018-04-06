/*Creado por Mario Nelson Torres Mena*/
/*Fecha 5 de abril de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float limites = 4.0;
float hora = -270;
float minutos = -268;
float segundos =-272;
float X=0;

//agujas se mueven al tener precionado el 1
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
  glPointSize(6.0f);
  // glPointSize(1.0f);
  glBegin(GL_POINTS);
  GLfloat cx=xp1;
  GLfloat cy=yp1;
  GLfloat angulo;
  for (GLfloat i=anguloI; i<anguloF; i+=0.1){
    angulo= i*M_PI/180.0f;
    cx=ra*cos(angulo)+xp1;
    cy=ra*sin(angulo)+yp1;
    glVertex2f(cx,cy);

  }

   glEnd();
}

void num(float x, float y, float d, float angulo, float t){
  glPointSize(t);
  glBegin(GL_POINTS);
  float cx=0;//punto en x
  float cy=0;//punto en y
  // cx y cy hacen referencia al centro del circulo

  float a; //aqui guardaremos la operacion de i*pi/180
  for (GLfloat i=0; i>=angulo; i-=0.1){
    //este for solo lo utilizaremos para encontrar el punto final de las lineas inclinadas
    //en este for no impimiremos nada en pantala por cada iteracion
        a= i*M_PI/180.0f;
        //la letra d hace referencia a la distancia que va a tener nuestra linea de un punto a otro
        cx=d*cos(i*M_PI/180.0f)+x;
        cy=d*sin(i*M_PI/180.0f)+y;

  }
  glVertex2f(cx,cy);

  glEnd();
}
void agujas(float x, float y, float d, float angulo, float t){
  //para hacer las linias inclinadas usaremos el algoritmo de hacer el circulo
  //enviaremos el angulo hasta donde terminara nuestro for
  float cx=0;//punto en x
  float cy=0;//punto en y
  float a; //aqui guardaremos la operacion de i*pi/180
  for (GLfloat i=0; i>=angulo; i-=0.1){
    //este for solo lo utilizaremos para encontrar el punto final de las lineas inclinadas
    //en este for no impimiremos nada en pantala por cada iteracion
        a= i*M_PI/180.0f;
        //la letra d hace referencia a la distancia que va a tener nuestra linea de un punto a otro
        cx=d*cos(i*M_PI/180.0f)+x;
        cy=d*sin(i*M_PI/180.0f)+y;

  }
  //terminando el for las variables cx, cy contienen el punto final que necesitamos para inclinar nuestra linea
  Lineas(x,y,cx, cy, 0.1,0.0,0.2,t);//dibujamos nuestra linea del punto de origen al punto final
}

void display(void)
{
	  glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // cuadros(1,1,0.5,0.5,0.05);//x,y,alto, ancho,angulo

    Circulos(0,0,0,360,2,0,0,0); //
/*
parametros de aguja, punto central del circulo x,y, distancia , angulo, tamamio de agujas
paramentros de num punto central del circulo x,y, distancia del centro, angulo, tamamio del punto
*/
    agujas(0,0,1.5,segundos,0.8); //aguja segundo
    agujas(0,0,1.5,minutos,5); //aguja minutos
    agujas(0,0,1,hora,10); //aguja hora
    num(0,0,1.8,-270,15); //12
    num(0,0,1.8,-300,10); //1
    num(0,0,1.8,-330,10); //2
    num(0,0,1.8,-360,15); //3
    num(0,0,1.8,-30,10); //4
    num(0,0,1.8,-60,10); //5
    num(0,0,1.8,-90,15); //6
    num(0,0,1.8,-120,10); //7
    num(0,0,1.8,-150,10); //8
    num(0,0,1.8,-180,15); //9
    num(0,0,1.8,-210,10); //10
    num(0,0,1.8,-240,10); //11
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
      segundos-=1;
      if(segundos<-359){
        segundos =-1;
      }
      if(segundos==-270){
        minutos-=2;
      }

      if(minutos<-360){
        minutos =-2;
      }
      if(minutos==-270){
        hora-=30;
        minutos-=2;
      }
      if(hora<=-360){
        hora =0;
      }
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
