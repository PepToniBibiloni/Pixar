// Etapa2.cpp
// Fichero principal 
////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
const int W_WIDTH = 500; // Tama�o incial de la ventana
const int W_HEIGHT = 500;
const int w_aux = 2;
const int h_aux = 2;
GLfloat fAngulo; // Variable que indica el �ngulo de rotaci�n de los ejes. 

// Funci�n que visualiza la escena OpenGL
void reshape(int w, int h) {

	if (h == 0) { 
		h = 1;
	}
	float aspectRatio = (float) W_WIDTH / (float) W_HEIGHT;  
	float aspectRatioV = (float)w / (float)h;	
	glLoadIdentity();
	if (aspectRatioV > aspectRatio){
		glOrtho(-(aspectRatioV/aspectRatio),(aspectRatioV/aspectRatio),-1,1,-1,1);
	}else{
		glOrtho(-1,1,-(aspectRatio/aspectRatioV),(aspectRatio/aspectRatioV),-1,1);
	}
	glViewport(0, 0, w, h);
}

// Funci�n que visualiza la escena OpenGL
void Display(void)
{
	// Borramos la escena
	glClear (GL_COLOR_BUFFER_BIT);

	glPushMatrix();
		// Creamos a continuaci�n dibujamos los tres poligonos
		glBegin (GL_POLYGON);
			glColor3f (1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glColor3f (0.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glColor3f (0.0f, 1.0f, 0.0f);
			glVertex3f(-0.5f, 0.866f, 0.0f);
		glEnd();

		glBegin (GL_POLYGON);
			glColor3f (1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glColor3f (1.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glColor3f (0.0f, 0.0f, 1.0f);
			glVertex3f(-0.5f, -0.866f, 0.0f);
		glEnd();

		glBegin (GL_POLYGON);
			glColor3f (1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glColor3f (0.0f, 1.0f, 1.0f);
			glVertex3f(-0.5f, 0.866f, 0.0f);
			glColor3f (0.0f, 0.0f, 1.0f);
			glVertex3f(-0.5f, -0.866f, 0.0f);
		glEnd();
	glPopMatrix();
	glRotatef (fAngulo, 0.0f, 0.0f, 1.0f);
	glFlush();
	glutSwapBuffers();
}

// Funci�n que se ejecuta cuando el sistema no esta ocupado
void Idle (void)
{
	// Incrementamos el �ngulo
	fAngulo += 0.3f;
	// Si es mayor que dos pi la decrementamos
	if (fAngulo > 360)
		fAngulo -= 360;
	// Indicamos que es necesario repintar la pantalla
	glutPostRedisplay();
}


// Funci�n principal
int main(int argc, char **argv) 
{
	// Inicializamos la librer�a GLUT
	glutInit (&argc, argv);

	// Indicamos como ha de ser la nueva ventana
	glutInitWindowPosition (100,100);
	glutInitWindowSize (W_WIDTH, W_HEIGHT);
	glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE);

	// Creamos la nueva ventana
	glutCreateWindow ("Mi primera Ventana");

	// Indicamos cuales son las funciones de redibujado e idle
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutReshapeFunc(reshape);

	// El color de fondo ser� el negro (RGBA, RGB + Alpha channel)
	glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
	glOrtho (-1.0, 1.0f, -1.0, 1.0f, -1.0, 1.0f);

	// Comienza la ejecuci�n del core de GLUT
	glutMainLoop();
	return 0; 
}