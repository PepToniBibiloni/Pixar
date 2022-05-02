// Etapa3.cpp
// Fichero principal 
////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawFunctions.cpp"
const int W_WIDTH = 500; // Tama�o incial de la ventana
const int W_HEIGHT = 500;
GLfloat fAngRotacion=0.0f, fAnguloInferior=90.0f,fAnguloLampara=0.0f;
// Funci�n que visualiza la escena OpenGL
void reshape(int w, int h) {

	if (h == 0) { 
		h = 1;
	}
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    GLfloat aspectRatio = (GLfloat) w / (GLfloat) h;
	if (w > h){
        glFrustum(aspectRatio,aspectRatio, 1.0, 1.0, 2.0, 2.0);
    }else{
		glFrustum(1,1,1/aspectRatio,1/aspectRatio, 2.0, 2.0);
	}
    glMatrixMode(GL_MODELVIEW);
}

// Funci�n que visualiza la escena OpenGL
void Display(void)
{
	// Borramos la escena
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.1, 0.1, 0.1, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0);
    referenceAxis();
    dibujarLampara(fAngRotacion,fAnguloInferior);
	glutSwapBuffers();
    glFlush();
}
// Función para captar teclas pulsadas
void inputKeyboard(unsigned char key, int x, int y)
{
	float speed = 0.1f;
	switch(key){
		case 'w':
			if(fAnguloInferior>60){
				fAnguloInferior-=0.5f;
			}
			break;
		case 's':
			if (fAnguloInferior<140){	
				fAnguloInferior+=0.5f;
			}
			break;
	}
}
// Funci�n que se ejecuta cuando el sistema no esta ocupado
void Idle (void)
{
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
    glutKeyboardFunc(inputKeyboard);

	glEnable(GL_DEPTH_TEST);

	// El color de fondo ser� el negro (RGBA, RGB + Alpha channel)
	glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
	// Comienza la ejecuci�n del core de GLUT
	glutMainLoop();
	return 0; 
}