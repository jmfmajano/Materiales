#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
//variable que sirve como bandera para pasar valores a las funciones de materiales
GLfloat vandera = 0.0f;
//variables de tipo OpenGL para los materiales ambiente, difusa y especular 
GLfloat amb1 = 0.329412f, amb2 = 0.223529f, amb3 = 0.027451f, dif1 = 0.780392f, dif2 = 0.568627f, dif3 = 0.113725f, spe1 = 0.992157f, spe2 = 0.941176f, spe3 = 0.807843f, shi =27.8974f; 

void init(void)
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}
void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}
void display(void)
{
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();
//Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
//Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
GLfloat mat_ambient[] = { amb1, amb2, amb3,1.0f };
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
GLfloat mat_diffuse[] = { dif1, dif2, dif3, 1.0f };
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
GLfloat mat_specular[] = { spe1, spe2, spe3, 1.0f };
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
GLfloat shine[] = {shi};
glMaterialfv(GL_FRONT, GL_SHININESS, shine);
glPushMatrix();
//setMaterial
glutSolidTeapot(125.0);
glFlush();
}
//procedimiento sobre los materiales
void tipoM(){
	//material tipo jade
	if (vandera == 1){
		amb1 = 0.135;
		amb2 = 0.2225;
		amb3 = 0.1575;
		dif1 = 0.54;
		dif2 = 0.89;
		dif3 = 0.63;
		spe1 = 0.316228;
		spe2 = 0.316228;
		spe3 = 0.316228;
		shi = 0.1;
		}
		//material tipo absidian
		if (vandera == 2){
		amb1 = 0.05375;
		amb2 = 0.05;
		amb3 = 0.06625;
		dif1 = 0.18275;
		dif2 = 0.17;
		dif3 = 0.22525;
		spe1 = 0.332741;
		spe2 = 0.328634;
		spe3 = 0.346435;
		shi = 0.3;
		}
		//material tipo pearl
		if (vandera == 3){
		amb1 = 0.25;
		amb2 = 0.20725;
		amb3 = 0.20725;
		dif1 = 1.0;
		dif2 = 0.829;
		dif3 = 0.829;
		spe1 = 0.296648;
		spe2 = 0.296648;
		spe3 = 0.296648;
		shi = 0.088;
		}
		//material tipo ruby
		if (vandera == 4){
		amb1 = 0.1745;
		amb2 = 0.01175;
		amb3 = 0.01175;
		dif1 = 0.61424;
		dif2 = 0.04136;
		dif3 = 0.04136;
		spe1 = 0.727811;
		spe2 = 0.626959;
		spe3 = 0.626959;
		shi = 0.6;
		}
		//material tipo turquoise
		if (vandera == 5){
		amb1 = 0.1;
		amb2 = 0.18725;
		amb3 = 0.1745;
		dif1 = 0.396;
		dif2 = 0.74151;
		dif3 = 0.69102;
		spe1 = 0.297254;
		spe2 = 0.30829;
		spe3 = 0.306678;
		shi = 0.1;
		}
	
	}

void keyboard(unsigned char key, int x, int y){
switch (key){
case '1':
vandera = 1;
tipoM();
break;
case '2':
vandera = 2;
tipoM();
break;
case '3' :
vandera = 3;
tipoM();
break;
case '4' :
vandera = 4;
tipoM();
break;
case '5' :
vandera = 5;
tipoM();
break;
case 27:
exit(0); // exit
}
glutPostRedisplay(); // actualización de visualización
}

int main(int argc, char **argv){
// Inicializo OpenGL
glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
glutCreateWindow ("Aplicacion de materiales a la TETERA");
// Inicializamos el sistema
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard); //invoca funcion de teclado
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}

