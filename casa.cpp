/*Creado por Mario Nelson Torres Mena*/
/*Fecha 26 de marzo de 2018*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float limites = 10.0;//tamanio del glOrtho
void Lineas(GLfloat xp1, GLfloat yp1, GLfloat xp2, GLfloat yp2, GLfloat r, GLfloat g, GLfloat b) {
  //recibe los dos puntos (x,y,z) (x,y,z) y color rgb
  glBegin(GL_LINES);
  glColor3f(r,g,b); // parametros a enviar rojo, verde, azul (0.0,0.0,0.0)
  glVertex2f(xp1,yp1); //punto inicio
  glVertex2f(xp2,yp2); //punto fin
  glEnd();
}
void Lineas_inclinadas(float x, float y, float d, float angulo){
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
  Lineas(x,y,cx, cy, 0.1,0.0,0.2);//dibujamos nuestra linea del punto de origen al punto final

}
void cuadros(float x, float y, float h, float w, float angulo){
  //funcion para dibujar cuadros con inclinacion
  //parametros a recibir punto inicial (x,y) alto (h) y ancho (w) y el angulo de inclinacion
  //al igual que la funcion Lineas_inclinadas usaremos el algoritmo de circulo
  Lineas(x,y,x,y+h, 0.1,0.0,0.2); //dibujamos la primer linea a 90 grados solo necesitamos los puntos iniciales
  //x,y y para el punto final solo le sumamos el alto (h) a la variable 'y'
  float cx=0;
  float cy=0;
  float a;
  for (GLfloat i=0; i<angulo; i+=0.01){
    //este for solo lo utilizaremos para encontrar el punto final de las lineas inclinadas
    //en este for no impimiremos nada en pantala por cada iteracion
        a= i*M_PI/180.0f;
        //la letra w hace referencia al ancho del cuadro
        cx=w*cos(a)+x;
        cy=w*sin(a)+y;
  }
  Lineas(x,y,cx, cy, 0.1,0.0,0.2);// dibujamos la primer linea inclinada desde el punto inicial al punto encontrado en el for
  Lineas(x,y+h,cx, cy+h, 0.1,0.0,0.2);//segunda linea inclinada desde el punto inicial sumandole h a y hasta el punto final sumandole h a cy
  Lineas(cx, cy+h,cx, cy, 0.1,0.0,0.2);//dibujamos la segunda linea, estara paralela a la primer linea dibujada

}
void ventanas(float x, float y, float h, float w, float angulo, float numero){
  //funcion para crear marco de ventanas y el numero de ventanas
  //parametros a recibir punto inicial (x,y) alto (h) y ancho (w) y el angulo de inclinacion, numero de ventanas
  //marco 1.0 marco exterior
  Lineas(x,y,x,y+h, 0.1,0.0,0.2);
  float cx=0;
  float cy=0;
  float a;
  for (GLfloat i=0; i<=angulo; i+=0.01){
        a= i*M_PI/180.0f;
        cx=w*cos(a)+x;
        cy=w*sin(a)+y;
  }
  Lineas(x,y,cx, cy, 0.1,0.0,0.2);
  Lineas(x,y+h,cx, cy+h, 0.1,0.0,0.2);
  Lineas(cx, cy+h,cx, cy, 0.1,0.0,0.2);
  //hasta aqui seria el mismo algoritmo de la creacion de cuadros

//marco 1.1 marco interior
// para este marco necesitamos alejar el punto inicial posicionandolo adentro del marco 1.0
// le sumaremos a 'x,y' una candidad considerada , al alto y al ancho le quitaremos
if(angulo<=90){
  //para este if nuestro angulo de 0 a 90 la linea desde el punto inicial al punto final se movera hacia la derecha
  //entonces a nuestra x le sumaremos
x+=0.2; //sumar candidad considerable para alejar un poco del marco 1.0
y+=0.3; //sumemar cantidad considerable para alejar un poco del marco 1.0
w-=0.5; //restamos a nuestro ancho
h-=0.5;} // restamos a nuestro alto
if(angulo>90 && angulo<=180){
  //en este if si el angulo de mayor a 90 y menos o igual a 180 la linea desde el punto inicial al punto final se movera hacia la izquierda
  //entonces a nuestra x le restamos
  x-=0.2;//restar candidad considerable para alejar un poco del marco 1.0
  y+=0.3;//sumar una cantidad considerable para alejar un poco del marco 1.0
  w-=0.5;//restamos a nuestro ancho
  h-=0.5;//restamos a nuestro alto
}
Lineas(x,y,x,y+h, 0.1,0.0,0.2);//dibujamos nuestra primer linea  de 90 grados del marco 1.1 o marco interior

for (GLfloat i=0; i<angulo; i+=0.01){
      a= i*M_PI/180.0f;
      cx=w*cos(a)+x;
      cy=w*sin(a)+y;
}
//hacemos el mismo algoritmo para encontrar la inclinacion
Lineas(x,y,cx, cy, 0.1,0.0,0.2); //dibujamos nuestra primer linea inclinada
float cx1=cx,cy1=cy;
Lineas(x,y+h,cx, cy+h, 0.1,0.0,0.2); // dibujamos la segunda linea inclinada paralela a la primera
Lineas(cx, cy+h,cx, cy, 0.1,0.0,0.2);// dibujamos la segunda linea de 90 grados paralela a la primer linea

//marco 1.2
//en este marcho nuestra x sera la misma solo nos alejaremos en 'y'
  y+=0.3; //sumamos en y para alejarnos del marcho 1.1
  w-=0.2; // restamos nuestro ancho para alejarnos del marco 1.1
  h-=0.3; // restamos el alto para que nos quede en la mismo alto de nuestro marcho 1.1
  //recordar que al alejar y del marco 1.1 nuestro alto antes de restarle 0.3 se pasara del marco 1.1
Lineas(x,y,x,y+h, 0.1,0.0,0.2);// dibijamos la primero linea de 90 de nuestro marco 1.2
for (GLfloat i=0; i<angulo; i+=0.01){
      a= i*M_PI/180.0f;
      cx=w*cos(a)+x;
      cy=w*sin(a)+y;
}
//hacemos el mismo algoritmo para encontrar la inclinacion
Lineas(x,y,cx, cy, 0.1,0.0,0.2); //primer linea inclinada
Lineas(cx, cy,cx1,cy1, 0.1,0.0,0.2);//linea paralela a linea de 90 grados
Lineas(cx, cy+h,cx, cy, 0.1,0.0,0.2);//linea paralela a linea inclinada

//ventanas
//algoritmo para dibujar numero de ventanas dentro del marco 1.2

float ancho= (w/numero); //ancho del marcho entre numero de ventanas
//ancho entre numero nos dara en ancho de cada ventana
float nx,ny; //nx y ny nuestros nuevos puntos
for(float j=1;j<=numero;j++){
  //Lineas(x,y,cx, cy, 0.1,0.0,0.2);
  if(j>1){
    // en este if entra si el numero de ventanas a dibujar es 1
  w=ancho; // el ancho de ventana sera todo el ancho del marco 1.2
  y=ny; // y = ny = 0;  en la primera iteracion
  x=nx; // x = nx = 0; en la primera iteracion
}else{
  // entrando al else es porque nos dibujara mas de una ventana
  y+=0.2; // nos alejaremos en y
  w=ancho-0.1; // le quitaremos un poco al ancho
  h-=0.2; // le quitaremos a nuestro alto

}

  for (GLfloat i=0; i<angulo; i+=0.01){
        a= i*M_PI/180.0f;
        cx=w*cos(a)+x;
        cy=w*sin(a)+y;
  }
// algoritmo para encontrar lineas inclinadas
  Lineas(x,y,cx, cy, 0.1,0.0,0.2); // linea inclinada
  Lineas(cx, cy+h,cx, cy, 0.1,0.0,0.2);
  nx=cx; // cambiamos valores de nx para la siguiente iteracion
  ny=cy; // cambiamos valores de ny para la siguiente iteracion
}


}
void display(void)
{
	glClearColor(0.2,0.2,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //plano
    // Lineas(-(limites),0.0f, (limites),-0.0f, 1.0,0.0,0.0);
    // Lineas(0.0f,(limites),0.0f,-(limites), 0.0,0.0,1.0);

    //cochera
    Lineas_inclinadas(-8,-6,3.9,90); // paramentros punto inicial (x,y), distancia, angulo de inclinacion
    Lineas_inclinadas(-8,-6,4,320);
    Lineas_inclinadas(-4.95,-8.56,4.1,90);
      //ventana
      ventanas(-5.5,-7,2,1.5,136,1); // parametros punto inicial (x,y), alto, ancho, angulo de inclinacion, numero de ventanas
      //techo
      Lineas_inclinadas(-8.1,-6+4,3.99,317);
      Lineas_inclinadas(-5.2,-4.7,3,40);
      Lineas_inclinadas(-5.2,-4.7,0.4,90);
      Lineas_inclinadas(-8.1,-6+4,0.4,90);
      Lineas_inclinadas(-8.1,-1.6,3.99,317);
      Lineas_inclinadas(-5.2,-4.3,3,40);
      Lineas_inclinadas(-8.1,-1.6,3,40);
      Lineas_inclinadas(-5.84,0.35,3.99,317);

      Lineas_inclinadas(-2.93,-2.4,1.5,350);
      Lineas_inclinadas(-2.93,-2.77,1.5,350);
      Lineas_inclinadas(-5.84,0.35,5.3,326);
      Lineas_inclinadas(-1.45,-3,0.4,90);
      Lineas_inclinadas(-4.95,-8.56,0.3,15);
      Lineas_inclinadas(-4.65,-8.53,3.5,90);
      Lineas_inclinadas(-4.65,-5.03,3.2,25);



      //porton
        Lineas_inclinadas(-4.65,-5.3,2,300);
        Lineas_inclinadas(-3.66,-7.05,3.1,23);
        Lineas_inclinadas(-2,-3.8,2.4,300);
        Lineas_inclinadas(-1.45,-4.7,1.8,90);
        Lineas_inclinadas(-1.45,-7.15,1,90);
        Lineas_inclinadas(-1.75,-7.2,1,90);
        Lineas_inclinadas(-1.75,-4.2,0.5,90);
        Lineas_inclinadas(-1.85,-4.05,0.3,90);
        Lineas_inclinadas(-1.85,-7.05,0.75,90);
        Lineas_inclinadas(-1.75,-7.2,0.3,15);
        Lineas_inclinadas(-1.75,-7.2,0.2,120);

        //planta baja
        Lineas_inclinadas(-1.45,-7.15,0.9,320);
        Lineas_inclinadas(-0.78,-7.69,10,90);
        Lineas_inclinadas(-0.78,-7.69,0.7,15);
        Lineas_inclinadas(-5.1,-0.2,1.5,90);
        Lineas_inclinadas(-5.1,1.3,5.6,320);
        Lineas_inclinadas(-0.78,-2.3,2.5,15);

        //techo puerta
          Lineas_inclinadas(-0.2,-3,1.6,15);
          Lineas_inclinadas(0.4,-4.0,1.6,15);
          Lineas_inclinadas(0.4,-4.0,1.15,121);
          Lineas_inclinadas(1.9,-3.55,1.15,121);
          Lineas_inclinadas(0.3,-4.0,1,121);
          Lineas_inclinadas(-0.2,-4.0,1,90);
          Lineas_inclinadas(-0.2,-4.0,0.7,0);
          //puerta
          Lineas_inclinadas(-0.1,-7.55,3.55,90);
          Lineas_inclinadas(-0.1,-7.55,0.5,320);
          Lineas_inclinadas(-0.1,-7.4,0.5,320);
          Lineas_inclinadas(0.29,-7.9,0.2,90);
          Lineas_inclinadas(-0.1,-7.4,1.27,15);
          Lineas_inclinadas(1.1,-7.1,0.5,320);
          Lineas_inclinadas(0.3,-7.7,1.22,15);
          Lineas_inclinadas(0.3,-7.9,1.22,15);
          Lineas_inclinadas(1.5,-7.6,0.2,90);
          Lineas_inclinadas(1.6,-3,1.4,90);
          Lineas_inclinadas(1.6,-7.1,3.45,90);
          Lineas_inclinadas(1.25,-7.16,0.4,15);
          Lineas_inclinadas(1.1,-7.1,3.3,90);
          Lineas_inclinadas(1,-7,3.18,90);
          Lineas_inclinadas(-0.1,-7.3,1.15,15);
          cuadros(0.1,-6.99,1.5,0.3,15); // parametros punto inicial (x,y), alto, ancho, angulo de inclinacion
          cuadros(0.56,-6.8,1.5,0.3,15);
          cuadros(0.3,-5,0.2,0.4,15);
          cuadros(0.56,-4.4,0.46,0.3,15);
          Lineas_inclinadas(0.1,-4.5,0.3,15);
          Lineas_inclinadas(0.1,-4.5,0.49,90);
          Lineas_inclinadas(0.4,-4.47,0.49,90);
          Lineas_inclinadas(1.6,-7.1,0.9,320);
          Lineas_inclinadas(1.6,-1.6,0.9,320);
          Lineas_inclinadas(2.3,-7.7,5.55,90);
          Lineas_inclinadas(2.3,-7.7,5,15);
          Lineas_inclinadas(2.3,-2.15,5,15);
          ventanas(3,-6.4,3,3.5,15,3);

        Lineas_inclinadas(7.1,-6.4,5.55,90);
        //segunda planta
        ventanas(-3.5,1,3,1.5,140,2);
        ventanas(-1.5,-0.5,3,1.5,140,2);
        Lineas_inclinadas(-0.78,2.35,2.5,15);
        ventanas(3,-0.5,3,3.5,15,3);
        ventanas(-0.3,-0.5,3,1.5,15,1);
        Lineas_inclinadas(1.6,-1.6,4.6,90);
        Lineas_inclinadas(2.3,-2.15,4.8,90);
        Lineas_inclinadas(1.6,3,0.9,320);
        Lineas_inclinadas(7.1,-0.9,4.5,90);
        Lineas_inclinadas(-5.1,1.3,4.1,90);
        //techo casa
        Lineas_inclinadas(1.6,3.2,0.9,320);
        Lineas_inclinadas(2.3,2.64,4,55);
        Lineas_inclinadas(2.3,2.4,4,55);
        Lineas_inclinadas(7.3,3.4,3.55,140);
        Lineas_inclinadas(7.3,3.67,3.55,140);
        Lineas_inclinadas(7.3,3.4,0.21,180);
        Lineas_inclinadas(7.3,3.4,0.25,90);
        Lineas_inclinadas(1.6,3.2,3,80);
        Lineas_inclinadas(2.12,6.2,2.5,354);
        cuadros(0,6.7,0.8,0.5,15);
        Lineas_inclinadas(0.1,7.95,0.5,320);
        Lineas_inclinadas(-0.4,7.85,0.5,320);
        Lineas_inclinadas(-0.4,7.85,0.5,15);
        Lineas_inclinadas(-0.4,7.85,0.6,270);
        Lineas_inclinadas(0,6.7,0.65,110);
        Lineas_inclinadas(1.6,3.2,2.5,195);
        Lineas_inclinadas(-0.78,2.5,4.5,110);
        Lineas_inclinadas(-0.78,2.3,4.5,110);
        Lineas_inclinadas(4,6,2.35,110);
        Lineas_inclinadas(-5.5,5.57,3.4,20);
        Lineas_inclinadas(-5.5,5.3,3.4,20);
        Lineas_inclinadas(-5.3,5.3,3.25,20);
        Lineas_inclinadas(-5.5,5.3,0.4,358);
        Lineas_inclinadas(-5.5,5.3,0.3,90);
        Lineas_inclinadas(0.5,7.5,2.8,15);
        Lineas_inclinadas(-2.4,6.7,2.3,15);
glFlush();
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
    glutInitWindowSize (600, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("CASA");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
