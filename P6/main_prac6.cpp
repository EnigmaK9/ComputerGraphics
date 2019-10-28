//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************					Padilla Herrera Carlos Ignacio						******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int	mercurio = 0; 
int	tierra = 0;
int dia = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int luna2 = 0;
int saturno = 0;
int luna3 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara


	//Aqui empieza el codigo de la sesion
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7f, 0.4f, 0.2f);
		glRotatef(mercurio, 0.0f, 0.0f, 1.0);
		glTranslatef(3.5f, 0.0f, 0.0f);
		glutSolidSphere(0.9f, 12, 12);  //Mercurio
	glPopMatrix();

	glPushMatrix();

		glColor3f(0.0f, 0.0f, 1.0f);
		glRotatef(tierra, 0.0f, 1.0f, 0.0f);
		glTranslatef(6.3f, 0.0f, 0.0f);
		glPushMatrix();
			glRotatef(dia, 0.0f, 1.0f, 0.0f); // Movimiento alrededor de su propio eje
			glutSolidSphere(1.5f, 12, 12); //Tierra
		glPopMatrix();

		glColor3f(0.7f, 0.7f, 0.7f);
		glRotatef(luna, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 2.5f, 0.0f);
		glutSolidSphere(0.4f, 12, 12); //Luna

	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0f, 0.2f, 0.0f);
		glRotatef(73.3f, 0.0f, 0.0f, 1.0f);
		glRotatef(marte, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 12.5f, 0.0f);
		glutSolidSphere(1.0f, 12, 12);   //Marte
	glPopMatrix();

	glPushMatrix();

		glColor3f(1.0f,0.8f, 0.0f);
		glRotatef(153.2, 0.0f, 0.0f, 1.0f);
		glRotatef(jupiter, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 16.3f, 0.0f);
		//glPushMatrix();
			
			glutSolidSphere(2.0f, 12.0f, 12.0f); //Jupiter
		//glPopMatrix();

		glColor3f(0.7f, 0.7f, 0.7f);
		glRotatef(luna2, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 2.5f, 0.0f);
		glutSolidSphere(0.4f, 12, 12); //Luna2

	glPopMatrix();

	glPushMatrix();

		glColor3f(1.0f, 0.5f, 0.0f);
		glRotatef(299.5, 0.0f, 0.0f, 1.0f);
		glRotatef(saturno, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 21.5f, 0.0f);
		//glPushMatrix();
			
			glutSolidSphere(2.0f, 12.0f, 12.0f); //Saturno
		//glPopMatrix();

		glColor3f(0.7f, 0.7f, 0.7f);
		glRotatef(luna3, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 2.5f, 0.0f);
		glutSolidSphere(0.4f, 12, 12); //Luna3

	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 7) % 360;
		tierra = (tierra + 4) % 360;
		dia = (dia - 10) % 360;
		luna = (luna + 13) % 360;
		marte = (marte - 6) % 360;
		jupiter = (jupiter + 5) % 360;
		saturno = (saturno + 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6 Sistema Solar 20201"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}