﻿//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************        Padilla Herrera Carlos Ignacio                                ******//
//*************                                                                                        ******//
//************************************************************//


//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


float yellow[3] = (1.0f, 1.0f, 0.0f);
float red[3] = (1.0f, 0.0f, 0.0f);
float magenta[3] = (1.0f,1.0f,1.0f);
float orange[3] = (1.0f, 0.5f, 0.0f);
float brown[3] = (0.5f, 0.35f, 0.05f);
float white[3] = (1.0f, 1.0f, 1.0f);


void InitGL ( GLvoid )     // Inicializamos parametros
{
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                                // Negro de fondo
        glClearDepth(1.0f);                                                                        // Configuramos Depth Buffer
        glEnable(GL_DEPTH_TEST);                                                        // Habilitamos Depth Testing
        glDepthFunc(GL_LEQUAL);                                                                // Tipo de Depth Testing a realizar
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void prisma(float yellow, float brown, float orange, float red, float white)
{
        GLfloat vertice [8][3] = {
                                {0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
                                {-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
                                {-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
                                {0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
                                {0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
                                {0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
                                {-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
                                {-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
                                };




                glBegin(GL_POLYGON);        //Front
                        glColor3f(yellow,green ,blue);
                        glVertex3fv(vertice[0]);
                        glVertex3fv(vertice[4]);
                        glVertex3fv(vertice[7]);
                        glVertex3fv(vertice[1]);
                glEnd();


                glBegin(GL_POLYGON);        //Right
                        glColor3f(0.0,0.0,1.0);
                        glVertex3fv(vertice[0]);
                        glVertex3fv(vertice[3]);
                        glVertex3fv(vertice[5]);
                        glVertex3fv(vertice[4]);
                glEnd();


                glBegin(GL_POLYGON);        //Back
                        glColor3f(0.0,1.0,0.0);
                        glVertex3fv(vertice[6]);
                        glVertex3fv(vertice[5]);
                        glVertex3fv(vertice[3]);
                        glVertex3fv(vertice[2]);
                glEnd();


                glBegin(GL_POLYGON);  //Left
                        glColor3f(1.0,1.0,1.0);
                        glVertex3fv(vertice[1]);
                        glVertex3fv(vertice[7]);
                        glVertex3fv(vertice[6]);
                        glVertex3fv(vertice[2]);
                glEnd();


                glBegin(GL_POLYGON);  //Bottom
        
                glColor3f(0.4,0.2,0.6);
                        glVertex3fv(vertice[0]);
                        glVertex3fv(vertice[1]);
                        glVertex3fv(vertice[2]);
                        glVertex3fv(vertice[3]);
                glEnd();


                glBegin(GL_POLYGON);  //Top
                        glColor3f(0.8,0.2,0.4);
                        glVertex3fv(vertice[4]);
                        glVertex3fv(vertice[5]);
                        glVertex3fv(vertice[6]);
                        glVertex3fv(vertice[7]);
                glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Limpiamos pantalla y Depth Buffer
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


                //Poner Código Aquí.
        glTranslatef(transX, transY, transZ); //con la figura prisma, la voy a desfasar dos unidades sobre el eje negativo de las z
        
        prisma(yellow);


        glTranslatef(0.0f, 0.0f, 0.0f);
        
        prisma();        //B


        glTranslatef(-3.0f, 2.5f, 0.0f);
        
        prisma(); //C
                
        glTranslatef(1.5f, -5.25f, 0.0f);
        prisma();


    glutSwapBuffers ( );
    // Swap The Buffers
}


void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)                                                                                // Prevenir division entre cero
        {
                height=1;
        }


        glViewport(0,0,width,height);        


        glMatrixMode(GL_PROJECTION);                                                // Seleccionamos Projection Matrix
        glLoadIdentity();


        // Tipo de Vista                                                                //Seleccionamos una a la vez
        //glOrtho(-5,5,-5,5,0.1,20);        
        glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
}


void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
        switch ( key ) {
                case 'w':
                case 'W':
                        transZ +=0.2f;
                        printf("Posicion en Z: %f\n", transZ);
                        break;
                case 's':
                case 'S':
                        transZ -=0.2f;
                        printf("Posicion en Z: %f\n", transZ);
                        break;
                case 'a':
                case 'A':
                        transX -=0.2f;
                        break;
                case 'd':
                case 'D':
                        transX +=0.2f;
                        break;


                case 'r': 
                case 'R':
                        transY += 0.2f;
                        break;
                case 'f':
                case 'F':
                        transY -= 0.2f;
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
                angleX += 1.0f;
                break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
                angleX -= 1.0f;
                break;
        case GLUT_KEY_LEFT:
                angleY += 1.0f;
                break;
        case GLUT_KEY_RIGHT:
                angleY -= 1.0f;
                break;
    default:
      break;
  }
  glutPostRedisplay();
}




int main ( int argc, char** argv )   // Main Function
{
        //New
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1500, 1500);        // Tamaño de la Ventana
  glutInitWindowPosition (0, 0);        //Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();                                                // Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );        //Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );        //Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );        //Otras
  glutMainLoop        ( );          // 


  return 0;
}