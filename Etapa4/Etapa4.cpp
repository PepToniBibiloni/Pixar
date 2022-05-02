// Etapa4.cpp
// Fichero principal 
////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawFunctions.cpp"
#include <glm/glm.hpp>
#include <string>
const int W_WIDTH = 500; // Tama�o incial de la ventana
const int W_HEIGHT = 500;
GLfloat fAngRotacion=0.0f, fAnguloInferior=90.0f,fAnguloLampara=0.0f;

// Cámara
glm::vec3 pos = glm::vec3(0.0f,1.5f,5.0f);
glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);

bool perspAct = false;
float speed = 0;
int height, width;
GLfloat pitch = 0.0f;
GLfloat yaw = 90.0f;
enum Perspective {Cenital,Picado,Normal,Contrapicado,Nadir};
Perspective perspective;

// Funci�n que visualiza la escena OpenGL
void reshape(int w, int h) {
    height=h;
    width=w;
	if (h == 0) { 
		h = 1;
	}
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat) w / (GLfloat) h, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// Perspectiva
void perspectiva(Perspective p) {
	switch (p){
        case Cenital:
			gluLookAt(0,3,0.15,0,0,0,0,1,0); 
            break;
        case Picado:
            gluLookAt(0,2.5,3,0,0,0,0,1,0);
            break;
        case Normal:
            gluLookAt(0,1.3,4,0,0,0,0,1,0);  
            break;
        case Contrapicado:
            gluLookAt(0,-1.5,3,0,0,0,0,1,0); 
            break;
        case Nadir:
            gluLookAt(0,-2,0.15,0,0,0,0,1,0);
            break;
	}
}

// Funci�n que visualiza la escena OpenGL
void Display() {
	// Borramos la escena
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if (!perspAct){
        gluLookAt(pos.x,pos.y,pos.z,pos.x+front.x,pos.y+front.y,pos.z+front.z,up.x,up.y,up.z);
        glTranslatef(0.0, 0.75f, 0.0);
    }else{
        perspectiva(perspective);
    }
	referenceAxis();
    dibujarLampara(fAngRotacion,fAnguloInferior);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
    glFlush();
}

// Función para captar teclas pulsadas
void inputKeyboard(unsigned char key, int x, int y)
{
	switch(key){
		case 'w':
			fAnguloInferior += 0.5f;
			break;
		case 's':
			fAnguloInferior -= 0.5f;
			break;
		case '+':
			speed = 0.5f;
			break;
		case '-':
			speed = -0.5f;
			break;
	}
}

void turn(){
	front.x = (GLfloat) (sin(pitch)*sin(yaw));
	front.y = (GLfloat) cos(yaw);
	front.z = (GLfloat) (-cos(pitch)*sin(yaw));
}

void pressKey(int key, int x, int y) {
	switch(key){
        case GLUT_KEY_UP:
            yaw -= 0.02f;
			turn();
            break;
        case GLUT_KEY_DOWN:
            yaw += 0.02f;
			turn();
            break;
		case GLUT_KEY_LEFT:
			pitch -= 0.02f;
			turn();
			break;
		case GLUT_KEY_RIGHT:
			pitch += 0.02f;
			turn();
			break;
        case GLUT_KEY_F1:
            perspective = Cenital;
            perspAct = true;
            break;
        case GLUT_KEY_F2:
            perspAct = true;
            perspective = Picado;
            break;
        case GLUT_KEY_F3:
            perspAct = true;
            perspective = Normal;
            break;
        case GLUT_KEY_F4:
            perspAct = true;
            perspective = Contrapicado;
            break;
        case GLUT_KEY_F5:
            perspAct = true;
            perspective = Nadir;
            break;
	}
	glutPostRedisplay();
}

void releaseKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: speed = 0; break;
	}
}
// Funci�n que se ejecuta cuando el sistema no esta ocupado
void Idle (void)
{
	if (!perspAct){
		if (speed) {
			pos.x += speed * front.x * 0.1f;
			pos.y = 1.5;
			pos.z += speed * front.z * 0.1f;
			speed=0;
		}
	}
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
	glutInitDisplayMode (GLUT_DEPTH | GLUT_RGBA | GLUT_SINGLE);

	// Creamos la nueva ventana
	glutCreateWindow ("Mi primera Ventana");

	// Indicamos cuales son las funciones de redibujado e idle
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutIdleFunc(Idle);
	
    glutKeyboardFunc(inputKeyboard);
    glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// El color de fondo ser� el negro (RGBA, RGB + Alpha channel)
	glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
	// Comienza la ejecuci�n del core de GLUT
	glutMainLoop();
	return 0; 
}