/* Este programa dibuja una "Tetera", este objeto esta definido
 * en GLUT, se crea una fuente de luz, y un material */
/************2020-1*******************/
//ALUMNO: Padilla Herrera Carlos Ignacio
//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
#include "Main.h"

float rot = 0.0f;

void init(void)
{
	 // Ubicamos la fuente de luz en el punto (1.0, 1.0, 1.0)
	 //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	 // Activamos la fuente de luz
	 glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);

	 glClearDepth(1.0f);					// Activamos el valor de inicio del buffer de profundidad
	 glEnable(GL_DEPTH_TEST);				// Hacemos la prueba de profundidad
	 glDepthFunc(GL_LEQUAL);				// Tipo de prueba de profundidad a hacer
	 return;
}

void reshape(int w, int h)
{
	 if (!h)
		return;

	 glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
	 // Activamos la matriz de proyeccion.
	 glMatrixMode(GL_PROJECTION);
	 // "limpiamos" esta con la matriz identidad.
	 glLoadIdentity();
	 // Usamos proyeccion ortogonal
	  //glOrtho(-200, 200, -200, 200, -200, 200);
	 gluPerspective(30.0f, (GLfloat)800/(GLfloat)600, 0.03, 1000.0);
	 // Activamos la matriz de modelado/visionado. 
	 glMatrixMode(GL_MODELVIEW);
	 // "Limpiamos" la matriz
	 glLoadIdentity();
	 return;
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{ 
	 // Propiedades del material
	 GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	 GLfloat mat_diffuse[] = { 1.0f,1.0f, 0.0f, 1.0f };
	 GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	 GLfloat mat_shininess[] = { 100.0f };

	 GLfloat mat_diffuse2[] = { 0.0f,1.0f, 0.0f, 1.0f };

	 // "Limpiamos" el frame buffer con el color de "Clear", en este 
	 // caso negro. 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glMatrixMode( GL_MODELVIEW_MATRIX );
	 glLoadIdentity();
 
	 glTranslatef(0.0,0.0,-20.0);
	 // Rotacion de 30 grados en torno al eje x
	 glRotated(30.0 + rot, 1.0, 0.0, 0.0);
	 // Rotacion de -30 grados en torno al eje y
	 //glRotated(-30.0, 0.0, 1.0, 0.0);
	 glRotated(-30, 0.0, 1.0, 0.0);
	 // Dibujamos una "Tetera" y le aplico el material
	 //aqu� le aplica al material mat ambient y as� 

	 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	 glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	 glutSolidTeapot(1.0);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	 glutWireCube(2.0f);
	 //cubo dibujo lineas
	 //gluit solid teapot dibuja la tetera. recibe como argumento el radio de la tetera. quiero construir una tetera con radio de una unidad
	 //
	 //glFlush();
	 glutSwapBuffers ( );
	 return;
} 

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;

		case 'x':
			rot += 10;
			// hace un incremento 
			break;
		case 'X':
			rot -= 10;
			// hace un incremento 
			break;
	 }
	  glutPostRedisplay();
	  //genera un evento de dibujo. Vuelve a dibujar lo qu ehay en el escenario.
	  //
	  return;
}    

// Main del programa.
int main(int argc, char **argv)
{ 
	 // Inicializo OpenGL
	//crea un canvas mediante glut
	 glutInit(&argc, argv);
	 
	 // Activamos buffer simple y colores del tipo RGB  
	 //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
	 //Indica los recursos para canvas de dibujo. Le indica trabajar con un buffer doble. Opengl tiene muchos buffers, estos de aqui son para almacenar informaci�n
	 //buffer doble para trabajar en paralelo
	 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);

	 // Definimos una ventana de medidas 300 x 300 como ventana 
	 // de visualizacion en pixels
	 //indica el tamaa�o inicial de mi ventana
	 glutInitWindowSize (300, 300);
	 
	 // Posicionamos la ventana en la esquina superior izquierda de 
	 // la pantalla.
	 // Se refiere a la esquina superior izquierda de la ventana 
	 glutInitWindowPosition (300, 400);

	 // Creamos literalmente la ventana y le adjudicamos el nombre que se
	 // observara en su barra de titulo.
	 glutCreateWindow ("Tetera");

	 // Inicializamos el sistema 
	 // init puede llamarse como guste
	 init();
	 //callbacks
	 //funciones para mandar a  llamar otra funcion
	 //cuando glut determine que se cre+o un evento de dibujo , este glut lo va a atrapar
	 //
	 glutDisplayFunc(display); 
	 glutReshapeFunc(reshape);
	 glutKeyboardFunc(keyboard);
	 glutMainLoop();
	 
	 // ANSI C requiere que main retorne un valor entero.
	 return 0;
}



